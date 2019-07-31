#include "parseXml.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <regex>
using std::cout;
using std::endl;

using namespace tinyxml2;

RssReader::RssReader()
    : _rss()
{
    _rss.reserve(1024);
}

void getMessage(RssItem_t &item, XMLElement *&itemNode)
{
    std::regex reg1("<.*?>");
    std::regex reg2("&.*;");
    string temp;
    item.title = itemNode->FirstChildElement("title")->GetText();
    item.link = itemNode->FirstChildElement("link")->GetText();
    temp = itemNode->FirstChildElement("description")->GetText();
    temp = std::regex_replace(temp, reg1, "\0");
    item.description = temp;
    temp = itemNode->FirstChildElement("content:encoded")->GetText();
    temp = std::regex_replace(temp, reg1, "");
    temp = std::regex_replace(temp, reg2, "");
    item.content = temp;
}

void RssReader::parseRss()
{
    XMLDocument doc;
    RssItem_t item;
    if (doc.LoadFile("coolshell.xml") != 0)
    {
        cout << "loadfile failed" << endl;
        return;
    }
    XMLElement *root = doc.RootElement();
    XMLElement *itemNode = root->FirstChildElement("channel")->FirstChildElement("item");
    while (itemNode)
    {
        getMessage(item, itemNode);
        _rss.push_back(item);
        itemNode = itemNode->NextSiblingElement("item");
    }
    // cout << "title " << endl;
    // cout << _rss[0].title << endl;
    // cout << "link " << endl;
    // cout << _rss[0].link << endl;
    // cout << "discription " << endl;
    // cout << _rss[0].description << endl;
    // cout << "content " << endl;
    // cout << _rss[0].content << endl;
}

int createFile(const string &fileName)
{
    const char *declaration = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>";
    XMLDocument doc;
    doc.Parse(declaration);
    XMLElement *root = doc.NewElement("PAGES");
    doc.InsertEndChild(root);
    return doc.SaveFile(fileName.c_str());
}

void RssReader::dump(const string &fileName)
{
    if (createFile(fileName) != 0)
    {
        cout << "create file failed" << endl;
        return;
    }
    XMLDocument doc;
    doc.LoadFile(fileName.c_str());
    XMLElement *root = doc.RootElement();
    for (int i = 0; i < _rss.size(); i++)
    {
        XMLElement *itemNode = doc.NewElement("doc");
        
        root->InsertEndChild(itemNode);
        std::stringstream ss;
        ss << (i+1);
        XMLElement *docId = doc.NewElement("docid");
        XMLText *docIdText = doc.NewText(ss.str().c_str());
        docId->InsertFirstChild(docIdText);
        itemNode->InsertFirstChild(docId);

        XMLElement *title = doc.NewElement("title");
        XMLText *titleText = doc.NewText((_rss[i].title).c_str());
        title->InsertEndChild(titleText);
        itemNode->InsertEndChild(title);

        XMLElement *link = doc.NewElement("link");
        XMLText *linkText = doc.NewText(_rss[i].link.c_str());
        link->InsertEndChild(linkText);
        itemNode->InsertEndChild(link);

        XMLElement *description = doc.NewElement("description");
        XMLText *descriptionText = doc.NewText(_rss[i].description.c_str());
        description->InsertEndChild(descriptionText);
        itemNode->InsertEndChild(description);

        XMLElement *content = doc.NewElement("content");
        XMLText *contentText = doc.NewText(_rss[i].content.c_str());
        content->InsertEndChild(contentText);
        itemNode->InsertEndChild(content);
    }
    doc.SaveFile(fileName.c_str());
}