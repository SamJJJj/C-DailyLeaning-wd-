//PIMPL设计模式模板，用line作为例子实现
#pragma once

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;


class Line{
public:
    Line(int, int, int, int);
    ~Line();

    void printLine() const;
private:
    class LineImpl;
    LineImpl * _pimpl;
};