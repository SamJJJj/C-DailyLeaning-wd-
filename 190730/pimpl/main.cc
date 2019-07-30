#include "line.h"
#include <iostream>

using std::cout;
using std::endl;


int main(int argc, char **argv)
{
    Line line(1, 2, 3, 4);
    line.printLine();
    return 0;
}