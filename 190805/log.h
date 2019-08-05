#pragma once

#include <string.h>
#include <stdlib.h>
#include <log4cpp/Category.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>
#include <string>


namespace mylog
{
using std::cout;
using std::endl;
using std::string;
using namespace log4cpp;

#define PRE_ARGS __LINE__, __FILE__, __FUNCTION__
#define INFO(...) LogInfo(PRE_ARGS, __VA_ARGS__)
#define WARN(...) LogWarn(PRE_ARGS, __VA_ARGS__)
#define ERROR(...) LogError(PRE_ARGS, __VA_ARGS__)
#define DEBUG(...) LogDebug(PRE_ARGS, __VA_ARGS__)

class MyLogger
{
public:
    static MyLogger * getInstance()
    {
        if(nullptr == _log)
        {
            _log = new MyLogger();
        }
        return _log;
    }

    static void destroy()
    {
        if(_log)
            delete _log;
    }

    void warn(const string & message)
    {
        _myCategory.warn(message);   
    }

    void error(const string & message)
    {
        _myCategory.error(message);
    }

    void debug(const string & message)
    {
        _myCategory.debug(message);
    }

    void info(const string & message)
    {
        _myCategory.info(message);
    }

private:
    Category & _myCategory;
    static MyLogger *_log;
    MyLogger()
    : _myCategory(Category::getRoot().getInstance("myCategory"))
    {
        PatternLayout *ptnLayout1 = new PatternLayout();
        ptnLayout1->setConversionPattern("%d [%p] %m %n");
        OstreamAppender * ostreamAppender = new OstreamAppender(
		"ostreamAppender",
		&cout);
        ostreamAppender->setLayout(ptnLayout1);
        PatternLayout *ptnLayout2 = new PatternLayout();
        ptnLayout2->setConversionPattern("%d [%p] %m %n");
        RollingFileAppender * rollingFileAppender = new RollingFileAppender(
		"rollingFileAppender",
		"running_info.log",
		16*1024*1024,
		5);
        rollingFileAppender->setLayout(ptnLayout2);
        _myCategory.setPriority(Priority::DEBUG);
        _myCategory.addAppender(ostreamAppender);
        _myCategory.addAppender(rollingFileAppender);
    }

    ~MyLogger()
    {
        Category::shutdown();
    }
};

MyLogger *MyLogger::_log = nullptr;


template <typename... Args>
void LogInfo(const int & line, const char * fileName ,const char* funcName, Args... args)
{
    char PrefixedMessage[256] = {0};
    char message[256] = {0};
    sprintf(message, args...);
    sprintf(PrefixedMessage, "%s(%d)-<%s>: %s", fileName, line, funcName, message);
    MyLogger *log = MyLogger::getInstance();
    log->info(PrefixedMessage);
}
template <typename... Args>
void LogWarn(const int & line, const char * fileName ,const char* funcName, Args... args)
{
    char PrefixedMessage[256] = {0};
    char message[256] = {0};
    sprintf(message, args...);
    sprintf(PrefixedMessage, "%s(%d)-<%s>: %s", fileName, line, funcName, message);
    MyLogger *log = MyLogger::getInstance();
    log->warn(PrefixedMessage);
}

template <typename... Args>
void LogError(const int & line, const char * fileName ,const char* funcName, Args... args)
{
    char PrefixedMessage[256] = {0};
    char message[256] = {0};
    sprintf(message, args...);
    sprintf(PrefixedMessage, "%s(%d)-<%s>: %s", fileName, line, funcName, message);
    MyLogger *log = MyLogger::getInstance();
    log->error(PrefixedMessage);
}

template <typename... Args>
void LogDebug(const int & line, const char * fileName ,const char* funcName, Args... args)
{
    char PrefixedMessage[256] = {0};
    char message[256] = {0};
    sprintf(message, args...);
    sprintf(PrefixedMessage, "%s(%d)-<%s>: %s", fileName, line, funcName, message);
    MyLogger *log = MyLogger::getInstance();
    log->debug(PrefixedMessage);
}



} //end of namespace mylog