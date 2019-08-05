#include "log.h"

using namespace mylog;

int main() 
{
    INFO("hello test %s %d", "hi", 2);
    WARN("hello test %s ", "hi");
    ERROR("hello test %s ", "hi");
    DEBUG("hello test %s ", "hi");

}
