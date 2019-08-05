#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>

#include <iostream>

using std::cout;
using std::endl;
using namespace log4cpp;

int main(int argc, char **argv)
{
    OstreamAppender *osAppender = new OstreamAppender("osAppender", &cout);
    osAppender->setLayout(new BasicLayout());
    Category &root = Category::getRoot();
    root.addAppender(osAppender);
    root.setPriority(Priority::DEBUG);
    root.alert("Hello a alert log");
    root.crit("Hello a crit log");
    root.error("Hello a error log");
    root.warn("Hello a warn log");
    root.notice("Hello a notice log");
    root.info("Hello a info log");

    Category::shutdown();
    return 0;
}