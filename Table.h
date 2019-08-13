#pragma once
#include"Cell.h"
#include"intCell.h"
#include"doubleCell.h"
#include"stringCell.h"
#include"CheckTypes.h"
#include"FormulaCell.h"
#include<vector>
class Table
{
private:
    std::vector<Cell*> cells;
public:
    std::vector<Cell*> get_table();
    void addCell(int c, int r, char* val);
    void edit(int c, int r, char* val);
    void print();
    ~Table();
    void sort_by_r_c();
    double show_numeric_value_of_formula(Table t,char *val) const;
//    void swapCells(Cell* , Cell*);
};
