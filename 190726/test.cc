#include "log.h"

using namespace mylog;

int main() 
{
    string s;

    LogInfo(PRE_ARGS,"hello test");
    LogError(PRE_ARGS, "hello test");
    LogWarn(PRE_ARGS, "hello test");
    LogDebug(PRE_ARGS, "hello test");
}
