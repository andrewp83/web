#include <iostream>
#include <memory>

#include "server.hpp"
#include "web/query_handler.hpp"

int main(int argc, char ** argv)
{
	web::QueryHandlerPtr web_handler = std::make_unique<web::QueryHandler>();
	net::Server srv(argc, argv, web_handler.get());
	return srv.run();
}

