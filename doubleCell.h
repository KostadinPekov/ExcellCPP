#pragma once
#include<cmath>
#include "cell.h"
#include"CheckTypes.h"
class DoubleCell : public Cell
{
public:
    DoubleCell();
    DoubleCell(int, int, const char*);
    DoubleCell(const DoubleCell&);
    DoubleCell& operator=(const DoubleCell&);
    char* get_val() const;
     void set_val(const char*);
    ~DoubleCell();
    void print() const;
    double show_numeric_value() const;
};
