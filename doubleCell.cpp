#pragma once
#include"doubleCell.h"
DoubleCell::DoubleCell() : Cell() {}
DoubleCell::DoubleCell(int r, int c, const char* val) : Cell(r,c,val) {}
DoubleCell::DoubleCell(const DoubleCell& source) : Cell(source) {}
DoubleCell& DoubleCell::operator=(const DoubleCell& source)
{
    Cell::operator=(source);
}
char* DoubleCell::get_val() const
{
    char* val = new char[strlen(value) + 1];
    strcpy(val, value);
    return val;
}
void DoubleCell::set_val(const char* val)
{
    if(check_type_double(val) == 1)
    {
        delete[] value;
        value = new char[strlen(val) + 1];
        strcpy(value,val);
    }
    else std::cout<<"ERROR!!! not the right type try again"<<std::endl;
//    int number_dots = 0;
//    if(((val[0] == '+') || (val[0] == '-')) || ((val[0] >= '0') && (val[0] <= '9') ))
//    {
//        for(int i = 1; i < strlen(val); i++)
//        {
//            if(val[i] == '.') number_dots++;
//            if((((val[i] < '0') || (val[i] > '9'))&&val[i]!='.') || number_dots > 1)
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
DoubleCell::~DoubleCell()
{
    delete[] value;
}
void DoubleCell::print() const
{
    std::cout<<value;
}

double DoubleCell::show_numeric_value() const
{
    int number_dots = 0;
    int place_of_dot = 0;
    if(((value[0] == '+') || (value[0] == '-')) || ((value[0] >= '0') && (value[0] <= '9') ))
    {
        for(int i = 1; i < strlen(value); i++)
        {
            if(value[i] == '.')
            {
                number_dots++;
                place_of_dot = i;
            }
            if((((value[i] < '0') || (value[i] > '9'))&&value[i]!='.') || number_dots > 1)
            {
                std::cout<<"ERROR!"<<std::endl;
            }
        }
    }
    double result = 0;
    if(value[0] == '+')
    {
        int number_length = ceil(pow(10.0, place_of_dot + 1));
        for(int i = 1; i < strlen(value); i++)
        {
            if(value[i]>='0'&&value[i]<='9')
            {
                result = result + (value[i]-'0')*number_length;

                number_length = number_length/10;
            }
        }
        result = result/(pow(10.0,strlen(value)-place_of_dot - 1));
    }
    if(value[0] == '-')
    {
        int number_length = ceil(pow(10.0, place_of_dot + 1));

        for(int i = 1; i < strlen(value); i++)
        {
            if(value[i]>='0'&&value[i]<='9')
            {
                result = result + (value[i]-'0')*number_length;

                number_length = number_length/10;
            }
        }
        result = result/(pow(10.0,strlen(value)-place_of_dot - 1));
        result = result* (-1);
    }
    if(value[0]>='0'&&value[0]<='9')
    {
        int number_length = ceil(pow(10.0, place_of_dot + 2));
        result = result + (value[0]-'0')*number_length;
        number_length = number_length/10;
        for(int i = 1; i < strlen(value); i++)
        {
            if(value[i]>='0'&&value[i]<='9')
            {

                result = result + (value[i]-'0')*number_length;
                number_length = number_length/10;
            }
        }
        result = result/(pow(10.0,strlen(value) - place_of_dot - 1));
    }
    return result;
}
