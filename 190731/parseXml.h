#pragma once
#include "tinyxml2.h"
#include <string>
#include <vector>

using std::string;
using std::vector;
typedef struct RssItem
{
    string title;
    string link;
    string description;
    string content;
} RssItem_t;

class RssReader
{
public:
    RssReader();

    void parseRss();
    void dump(const string &fileName);
private:
    vector<RssItem_t> _rss;
};