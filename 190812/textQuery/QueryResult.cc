#include "QueryResult.h"

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
    os << qr._sought << " occurs " << qr._lines->size() << " "
       << " times" << std::endl;
    for(auto num : *qr._lines)
    {
        os << "\t(line" << num + 1 << ") "
           << *(qr._file->begin() + num) << std::endl;
    }
    return os;
}