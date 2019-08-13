#include"stringCell.h"
StringCell::StringCell() : Cell() {}
StringCell::StringCell(int r, int c, const char* val) : Cell(r,c,val) {}
StringCell::StringCell(const StringCell& source) : Cell(source) {}
StringCell& StringCell::operator=(const StringCell& source)
{
    Cell::operator=(source);
}
char* StringCell::get_val() const
{
    char* val = new char[strlen(value) + 1];
    strcpy(val, value);
    return val;
}
void StringCell::set_val(const char* val)
{
    if(check_type_string(val) == 1)
    {
        delete[] value;
        value = new char[strlen(val) + 1];
        strcpy(value,val);
    }
    else std::cout<<"ERROR!!! not the right type try again"<<std::endl;
//    if(val[0] == '"' && val[strlen(val) - 1] == '"')
//    {
//        for(int i = 1; i < strlen(val) - 1; i++)
//        {
//            if(val[i] == '"' && (val[i-1] != '\\')) std::cout<<"ERROR!!!"<<std::endl;
//        }
//        delete[] value;
//        value = new char[strlen(val) + 1];
//        strcpy(value,val);
//    }
//    else  std::cout<<"ERROR!!!"<<std::endl;
}
StringCell::~StringCell()
{
    delete[] value;
}
void StringCell::print() const
{
    for(int i = 1; i < strlen(value) - 1; i++)
    {
        if(value[i+1]=='"'&&value[i]=='\\'&&i<=strlen(value) - 3) i = i + 1;
        if(value[i+1]=='\\'&&value[i]=='\\'&&i<=strlen(value) - 3) i = i + 1;
        std::cout<<value[i];
    }
}
double StringCell::show_numeric_value() const
{
    char* val = new char[strlen(value) - 2];
    for(int i = 1; i < strlen(value) - 1; i++)
    {
        val[i-1] = value[i];
    }
    val[strlen(value) - 2] = 0;
    //std::cout<<val<<std::endl;
    //std::cout<<check_type_double("")<<std::endl;
    if(check_type_int(val) == 1)
    {
        IntCell a(0,0,val);
        return a.show_numeric_value();
    }
    if(check_type_double(val) == 1)
    {
        DoubleCell a(0,0,val);
        return a.show_numeric_value();
    }
    return 0;

    // има ли как да направя всички show_num_val да са friend на класовете си за да мога да ги използвам тук
}
