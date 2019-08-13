#pragma once
#include<cmath>
#include "cell.h"
#include"CheckTypes.h"
class IntCell : public Cell
{
public:
    IntCell();
    IntCell(int, int, const char*);
    IntCell(const IntCell&);
    IntCell& operator=(const IntCell&);
    char* get_val() const;
     void set_val(const char*);
    ~IntCell();
    void print() const;
    double show_numeric_value() const;
};
