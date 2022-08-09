#pragma once

#include "web/query_handler.hpp"    

namespace net {
    class Server {
    public:
        Server(int argc, char** argv, web::QueryHandler* handler);

        int run();

    private:
        int daemonize();
        void create_workers();
        void start_master_loop();
        void start_worker_loop();

    private:
        web::QueryHandler* handler {nullptr};
    };
}