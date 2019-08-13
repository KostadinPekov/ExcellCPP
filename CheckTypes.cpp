#include"cell.h"
#include"intCell.h"
#include"CheckTypes.h"
#include"stringCell.h"
#include"doubleCell.h"
#include"FormulaCell.h"
#include<vector>
#include<string>
#include"Table.h"
#include <cstdlib>
#include <fstream>
bool check_type_double(const char* val)
{
    int number_dots = 0;
    if(((val[0] == '+') || (val[0] == '-')) || ((val[0] >= '0') && (val[0] <= '9') ))
    {
        for(int i = 1; i < strlen(val); i++)
        {
            if(val[i] == '.') number_dots++;
            if((((val[i] < '0') || (val[i] > '9'))&&val[i]!='.') || number_dots > 1)
            {
                return 0;
            }
        }
        if(number_dots == 0) return 0;
        return 1;
    }
    else return 0;
}
bool check_type_int(const char* val)
{
    if(((val[0] == '+') || (val[0] == '-')) || ((val[0] >= '0') && (val[0] <= '9') ))
    {
        for(int i = 1; i < strlen(val); i++)
        {
            if(val[i]<'0' || val[i]>'9')
            {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
bool check_type_string(const char* val)
{
    if(val[0] == '"' && val[strlen(val) - 1] == '"')
    {
        for(int i = 1; i < strlen(val) - 1; i++)
        {
            if(val[i] == '"' && (val[i-1] != '\\')) return 0;
        }
        return 1;
    }
    else  return 0;
}
bool check_correct_row_col(const char* val)
{
    int Cols_position = 0;
    if(val[0] == 'R')
    {
        int i = 1;
        if(val[i] < '0' || val[i] > '9')
        {
            //std::cout<<val[1]<<std::endl;
            return 0;
        }
        else
        {
            for(i = 2; i < strlen(val)&& val[i]!= 'C'; i++)
            {
                //std::cout<<val[i]<<std::endl;
                if(val[i] < '0' || val[i] > '9')
                {
                    if(val[i] == 'C')
                    {
                        Cols_position = i;
                    }
                    else return 0;
                }
            }
            if(val[i]=='C')
            {
                Cols_position = i;
                //std::cout<<Cols_position<<std::endl;
            }
            if(Cols_position == 0 || Cols_position == strlen(val)- 1)
            {
                //std::cout<<"asdf";
                return 0;
            }
        }
        for(int j = Cols_position + 1; j < strlen(val); j++)
        {
            //std::cout<<val[j];
            if(val[j] < '0' || val[j] > '9')
            {

                return 0;
            }
        }
    }
    else return 0;
    return 1;
}
bool check_type_formula(const char* val)
{
    int number_of_signs = 0;
    int position_of_sign = 0;
    for(int i = 1; i <= strlen(val); i++)
    {
        if(number_of_signs > 1 ) return 0;
        if(val[i] == '+' || val[i] == '-' || val[i] == '*' || val[i] == '/' || val[i] == '^')
        {
            number_of_signs++;
            position_of_sign = i;
        }
    }
    char* first_literal = new char[position_of_sign];
    //std::cout<<position_of_sign<<std::endl;
    char* second_literal = new char[strlen(val) - position_of_sign];
    for(int j = 0; j < position_of_sign - 1; j++)
    {
        first_literal[j] = val[j + 1];
        //std::cout<<"inside ";
    }
    first_literal[position_of_sign - 1] = 0;
    for(int k = 0; k <= strlen(val) - position_of_sign; k++)
    {
        second_literal[k] = val[position_of_sign + k + 1 ];
    }
    second_literal[strlen(val) - position_of_sign] = 0;
    return ((check_correct_row_col(first_literal) ||
            check_type_int(first_literal) ||
            check_type_double(first_literal)) &&
           (check_correct_row_col(second_literal) ||
            check_type_int(second_literal) ||
            check_type_double(second_literal)));

    //std::cout<<"first: "<<first_literal<<"  second: "<<second_literal<<std::endl;
}
