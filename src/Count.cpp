#include <fastcgi2/component.h>
#include <fastcgi2/component_factory.h>
#include <fastcgi2/handler.h>
#include <fastcgi2/request.h>

#include <iostream>
#include <sstream>
#include <string>

#include "mongo/bson/bson.h"
#include "mongo/client/dbclient.h"

using namespace std;
using namespace mongo;

enum RequestType
{
    UNKNOWN,
    POST_TRANSACTION,
    GET_BALANCE
};

static const string user_path = "/user/";
static const string transaction_path = "/transactions";

#define USERS_COLLECTION_NAMESPASE "count.users"

class Count : virtual public fastcgi::Component, virtual public fastcgi::Handler
{
    DBClientConnection db;

public:
    Count(fastcgi::ComponentContext *context) : fastcgi::Component(context) {}

    virtual void onLoad() {
        cout << "start on load" << endl;
        mongo::client::initialize();
        db.connect("localhost:27017");
    }

    virtual void onUnload() {}

    virtual void handleRequest(fastcgi::Request *request, fastcgi::HandlerContext *context)
    {
        string path = request->getScriptName();
        string method = request->getRequestMethod();
        cout << path << "\t" << method << endl;

        request->setContentType("application/json");

        string user_id;

        RequestType requestType = GetRequestType(path, method, &user_id);

        if (requestType == UNKNOWN) {
            request->setStatus(404);
            return;
        } else if (requestType == GET_BALANCE) {

            cout << "get balance" << endl;
            string userJson = GetUserJson(user_id);
            cout << userJson << endl;

            if (!userJson.compare(""))
            {
                request->setStatus(404);
            }
            else
            {
                std::stringbuf bufferResults(userJson);
                request->write(&bufferResults);
                request->setStatus(200);
            }
        } else if (requestType == POST_TRANSACTION) {

            string body;
            request->requestBody().toString(body);

            string response_data = SaveTransactionJson(user_id, body);

            std::stringbuf buffer4(response_data);
            request->write(&buffer4);
            request->setStatus(200);
        }
    }

    RequestType GetRequestType(string path, string method, string *user_id) {

        cout << "get request" << endl;
        unsigned long base_position = path.find(user_path);
        if (base_position == 0 && path.length() - user_path.length() > 0) {
            path.erase(0, user_path.length());

            unsigned long transactions_position = path.find(transaction_path);
            if (transactions_position == string::npos && method.compare("GET") == 0) {
                *user_id = path;
                return GET_BALANCE;

            } else if (transactions_position != string::npos && method.compare("POST") == 0) {
                *user_id = path.substr(0, transactions_position);
                return POST_TRANSACTION;

            }
        }
        return UNKNOWN;
    }

    string GetUserJson(string user_id)
    {


        std::auto_ptr<DBClientCursor> cursor = db.query(USERS_COLLECTION_NAMESPASE, MONGO_QUERY("user_id" << user_id));
        if (cursor->more())
        {
            BSONObj user = cursor->next();
            string paymentJson = user.jsonString();
            return paymentJson;
        }
        return "";
    }

    string SaveTransactionJson(string user_id, string body)
    {
        string amount_entry = "amount\":\"";
        int amount = 0;
        unsigned long amount_position = body.find(amount_entry);
        if (amount_position != string::npos) {
            unsigned long after_position = amount_position + amount_entry.length();
            string sub_string = body.substr(after_position, body.find("}", after_position));
            amount = atoi(sub_string.c_str());
        }

        BSONObj userBSON = BSON(GENOID
                                << "user_id" << user_id
                                << "balance" << amount);

        db.insert(USERS_COLLECTION_NAMESPASE, userBSON);

        return userBSON.jsonString();
    }
};

FCGIDAEMON_REGISTER_FACTORIES_BEGIN()
FCGIDAEMON_ADD_DEFAULT_FACTORY("CountFactory", Count)
FCGIDAEMON_REGISTER_FACTORIES_END()
