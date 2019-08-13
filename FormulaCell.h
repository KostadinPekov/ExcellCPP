#pragma once
#include "cell.h"
#include"CheckTypes.h"
#include"doubleCell.h"
#include"IntCell.h"
#include"Table.h"
#include<cmath>
class FormulaCell : public Cell
{
public:
    FormulaCell();
    FormulaCell(int, int, const char*);
    FormulaCell(const FormulaCell&);
    FormulaCell& operator=(const FormulaCell&);
    char* get_val() const;
    void set_val(const char*);
    ~FormulaCell();
    void print() const;
    double show_numeric_value() const;
};
