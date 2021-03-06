# Count
Count your money? Easy.

Implementation of distributed server system which tracks money transactions / balance summaries for high amout of users.

Technologies used:
- web-server: nginx
- client-server protocol: FastCGI ([FastCGI-Daemon](https://github.com/lmovsesjan/Fastcgi-Daemon))
- database: MongoDB

# API (REST)

## Notes:
- We don't care about numeration/sequence/timing of ids. So we expect server to generate them.
- I chose REST because my system well adapts to resource oriented paradigm.
- `timestamp` is Unix epoch time.

## Get user

Returns list of accounts representations for specific user.
Also provides overall balance for each used currency, e.g. if we have two accounts with 15$ and 25$ and three accounts with 20000BYR, 17000BYR, 13000BYR then we have 40$ and 50000BYR overall.

* **REQUEST**
    * **URL:** `/users/(user_id)`
    * **Method:** `GET`

* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:** `200 HTTP_OK`
    * **Body:**
    ```json
    {
        "user_id": "user123",
        "accounts": [
            {
                "account_id": "abcdefg12345",
                "name": "Personal",
                "balance": "40",
                "currency": "USD"
            },
            {
                "account_id": "abcdefg54321",
                "name": "Work",
                "balance": "50000",
                "currency": "BYR"
            }
        ],
        "overall": {
            "USD": "40",
            "BYR": "50000"
        }
    }
    ```
    
## Get accounts by user

Returns list of accounts for specific user.

* **REQUEST**
    * **URL:** `/users/(user_id)/accounts`
    * **Method:** `GET`

* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:** 
        *  Success: `200 HTTP_OK`
        *  Fail: `404 HTTP_NOT_FOUND`
    * **Body:**
    ```json
    [
        {
            "account_id": "abcdefg12345",
            "name": "Personal",
            "balance": "40",
            "currency": "USD"
        },
        {
            "account_id": "abcdefg54321",
            "name": "Work",
            "balance": "50000",
            "currency": "BYR"
        }
    ]
    ```
    
## Create account

Create account for specific user.

* **REQUEST**
    * **URL:** `/users/(user_id)/accounts`
    * **Method:** `POST`
    * **Body:**
    ```json
    {
        "name": "Personal",
        "balance": "40",
        "currency": "USD"
    }
    ```
    
* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:**
        *  Success: `201 HTTP_CREATED`
        *  Fail: `404 HTTP_NOT_FOUND`
    * **Headers:**
        *  Location: `/users/(user_id)/accounts`
    * **Body:**
    ```json
    {
        "account_id": "abcdefg12345",
    }
    ```

## Get account

Returns account representation.

* **REQUEST**
    * **URL:** `/users/(user_id)/accounts/(account_id)`
    * **Method:** `GET`

* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:**
        *  Success: `200 HTTP_OK`
        *  Fail: `404 HTTP_NOT_FOUND`
    * **Body:**
    ```json
        {
            "account_id": "abcdefg12345",
            "name": "Personal",
            "balance": "40",
            "currency": "USD",
            "transactions": [
                {
                    "transaction_id": "kjdsbkaljv342",
                    "timestamp": "145235412341",
                    "amount": "-40",
                    "note": "Lunch at KFC."
                }
            ]
        }
    ```
    
## Delete account

Deletes spectific account.

* **REQUEST**
    * **URL:** `/users/(user_id)/accounts/(account_id)`
    * **Method:** `DELETE`

* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:**
        *  Success: `200 HTTP_OK`
        *  Fail: `404 HTTP_NOT_FOUND`
    
## Add transaction

Adds transaction for specific account.

* **REQUEST**
    * **URL:** `/users/(user_id)/accounts/(account_id)/transactions`
    * **Method:** `POST`
    * **Body:**
    ```json
        {
            "timestamp": "145235412341",
            "amount": "-40",
            "note": "Lunch at KFC."
        }
    ```

* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:**
        *  Success: `201 HTTP_CREATED`
        *  Fail: `404 HTTP_NOT_FOUND`
    * **Headers:**
        *  Location: `/users/(user_id)/accounts/(account_id)/transactions`
    * **Body:**
    ```json
     {
        "transaction_id": "kjdsbkaljv342"
     }
    ```

## Delete transaction

Deletes spectific transaction.

* **REQUEST**
    * **URL:** `/users/(user_id)/accounts/(account_id)/transactions/(transaction_id)`
    * **Method:** `DELETE`

* **RESPONSE**
    * **Content-Type:** `application/json`
    * **Code:**
        *  Success: `200 HTTP_OK`
        *  Fail: `404 HTTP_NOT_FOUND`
