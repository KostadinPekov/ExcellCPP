#pragma once
#include "cell.h"
#include"CheckTypes.h"
#include"intCell.h"
#include"doubleCell.h"
class StringCell : public Cell
{
public:
    StringCell();
    StringCell(int, int, const char*);
    StringCell(const StringCell&);
    StringCell& operator=(const StringCell&);
    char* get_val() const;
    void set_val(const char*);
    ~StringCell();
    void print() const;
    double show_numeric_value() const;
};
