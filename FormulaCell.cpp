#pragma once
#include"FormulaCell.h"
FormulaCell::FormulaCell() : Cell() {}
FormulaCell::FormulaCell(int r, int c, const char* val) : Cell(r,c,val) {}
FormulaCell::FormulaCell(const FormulaCell& source) : Cell(source) {}
FormulaCell& FormulaCell::operator=(const FormulaCell& source)
{
    Cell::operator=(source);
}
FormulaCell::~FormulaCell()
{
    delete[] value;
}
void FormulaCell::print() const
{
    std::cout<<value;
}
char* FormulaCell::get_val() const
{
    char* val = new char[strlen(value) + 1];
    strcpy(val, value);
    return val;
}

void FormulaCell::set_val(const char* val)
{
    if(check_type_formula(val) == 1)
    {
        delete[] value;
        value = new char[strlen(val) + 1];
        strcpy(value,val);
    }
    else std::cout<<"ERROR!!! not the right type try again"<<std::endl;
//    if(((val[0] == '+') || (val[0] == '-')) || ((val[0] >= '0') && (val[0] <= '9') ))
//    {
//        for(int i = 1; i < strlen(val); i++)
//        {
//            if(val[i]<'0' || val[i]>'9')
//            {
//                std::cout<<"ERROR!"<<std::endl;
//            }
//        }
//        delete[] value;
//        value = new char[strlen(val) + 1];
//        strcpy(value,val);
//    }
//    else std::cout<<"ERROR!"<<std::endl;
}

double FormulaCell::show_numeric_value() const
{
    return 0;
}
