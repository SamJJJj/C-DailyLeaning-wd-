#include "parseXml.h"

int main(int argc, char **argv)
{
    RssReader reader;
    reader.parseRss();
    reader.dump("pagelib.dat");
    return 0;
}