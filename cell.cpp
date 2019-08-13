#pragma once
#include"cell.h"
Cell::Cell()
{
    position_r = 0;
    position_c = 0;
    value = nullptr;
}
Cell::Cell(int r, int c, const char* val)
{
    position_r = r;
    position_c = c;
    value = new char[strlen(val) + 1];
    strcpy(value, val);
}
Cell::Cell(const Cell& src)
{
    position_r = src.position_r;
    position_c = src.position_c;
    value = new char[strlen(src.value) + 1];
    strcpy(value, src.value);
}
Cell& Cell::operator=(const Cell& src)
{
    if(this == &src) return *this;
    position_r = src.position_r;
    position_c = src.position_c;
    delete[] value;
    value = new char[strlen(src.value) + 1];
    strcpy(value, src.value);
    return *this;
}
int Cell::get_r() const
{
    return position_r;
}
char* Cell::get_val() const
{
    char* val = new char[strlen(value) + 1];
    strcpy(val, value);
    return val;
}
void Cell::set_val(const char* val)
{
    delete[] value;
    value = new char[strlen(val) + 1];
    strcpy(value,val);
}
void Cell::print() const
{

    std::cout<<value;
}
double Cell::show_numeric_value() const
{
    return 0;
}
int Cell::get_c() const
{
    return position_c;
}
Cell::~Cell(){};
int power(int num)
{
    int result = 1;
    for(int i = 0; i < num - 1; i++)
    {

        result = result*10;
    }
    return result;
}
