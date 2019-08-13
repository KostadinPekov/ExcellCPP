#pragma once
#include"intCell.h"
IntCell::IntCell() : Cell() {}
IntCell::IntCell(int r, int c, const char* val) : Cell(r,c,val) {}
IntCell::IntCell(const IntCell& source) : Cell(source) {}
IntCell& IntCell::operator=(const IntCell& source)
{
    Cell::operator=(source);
}
IntCell::~IntCell()
{
    delete[] value;
}
void IntCell::print() const
{
    std::cout<<value;
}
char* IntCell::get_val() const
{
    char* val = new char[strlen(value) + 1];
    strcpy(val, value);
    return val;
}

void IntCell::set_val(const char* val)
{
    if(check_type_int(val) == 1)
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

double IntCell::show_numeric_value() const
{
    //std::cout<<"num ";
    double result = 0;
    if(value[0] == '+')
    {
        int number_length = ceil(pow(10.0, strlen(value) - 2));

        for(int i = 1; i < strlen(value); i++)
        {
            if(value[i]>='0'&&value[i]<='9')
            {
                result = result + (value[i]-'0')*number_length;

                number_length = number_length/10;
            }
        }
    }
    if(value[0] == '-')
    {
        int number_length = ceil(pow(10.0, strlen(value) - 2));

        for(int i = 1; i < strlen(value); i++)
        {
            if(value[i]>='0'&&value[i]<='9')
            {
                result = result + (value[i]-'0')*number_length;

                number_length = number_length/10;
            }
        }
        result = result* (-1);
    }
    if(value[0]>='0'&&value[0]<='9')
    {
        int number_length = ceil(pow(10.0, strlen(value) - 1));
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
    }
    //std::cout<<result<<" ";
    return ceil(result);
}
