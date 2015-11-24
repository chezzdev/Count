#include "settings.h"

#include "details/server.h"

#include <sys/time.h>

#include "details/globals.h"
#include "details/handlerset.h"

#include "fastcgi2/logger.h"

#ifdef HAVE_DMALLOC_H
#include <dmalloc.h>
#endif

namespace fastcgi
{
	
Server::Server()
{}

Server::~Server()
{}

void
Server::handleRequest(RequestTask task) {
	handleRequestInternal(getHandler(task), task);
}

void
Server::handleRequestInternal(const HandlerSet::HandlerDescription* handler, RequestTask task) {
	if (NULL == handler || handler->handlers.empty()) {
		task.request->sendError(404);
		return;
	}

	try {
		task.handlers = handler->handlers;
		RequestsThreadPool* pool = globals()->pools().find(handler->poolName)->second.get();
    	if (pool->delay()) {
    		struct timeval now;
    		gettimeofday(&now, 0);
    		task.start = (now.tv_sec * 1000) + (now.tv_usec / 1000);
    	}
    	else {
    		task.start = 0;
    	}
		pool->addTask(task);
	}
	catch (const std::exception &e) {
		task.request->sendError(503);
		logger()->error("cannot add request to pool: %s", e.what());
	}
}

const HandlerSet::HandlerDescription*
Server::getHandler(RequestTask task) const {
	return globals()->handlers()->findURIHandler(task.request.get());
}

} // namespace fastcgi
