#pragma once

#include <memory>

namespace web {

class QueryHandler {
public:
    virtual void process() {}
};

using QueryHandlerPtr = std::unique_ptr<QueryHandler>;

}