#pragma once
#include<iostream>
#include<cstring>
class Cell
{
private:
    int position_r;
    int position_c;
protected:
    char *value;
public:
    Cell();
    Cell(int, int, const char*);
    Cell(const Cell&);
    Cell& operator=(const Cell&);
    int get_r() const;
    int get_c() const;
    virtual char* get_val() const ;
    virtual void set_val(const char*) ;
    virtual ~Cell();
    virtual void print() const ;
    virtual double show_numeric_value() const ;
};
