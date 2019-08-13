#include"Table.h"
#include<cstring>
double Table::show_numeric_value_of_formula(Table t, char* val) const
{
    double first_in_formula = 0;
    double second_in_formula = 0;
    char sign;
    int number_of_signs = 0;
    int position_of_sign = 0;
    for(int i = 1; i <= strlen(val); i++)
    {
        if(number_of_signs > 1 ) return 0;
        if(val[i] == '+' || val[i] == '-' || val[i] == '*' || val[i] == '/' || val[i] == '^')
        {
            number_of_signs++;
            position_of_sign = i;
            sign = val[i];
        }
    }
    char* first_literal = new char[position_of_sign];
    char* second_literal = new char[strlen(val) - position_of_sign];
    for(int j = 0; j < position_of_sign - 1; j++)
    {
        first_literal[j] = val[j + 1];
    }
    first_literal[position_of_sign - 1] = 0;
    for(int k = 0; k <= strlen(val) - position_of_sign; k++)
    {
        second_literal[k] = val[position_of_sign + k + 1 ];
    }
    second_literal[strlen(val) - position_of_sign] = 0;
    if(check_correct_row_col(first_literal))
    {
        int cols = 0;
        int rows = 0;
        bool c_met = 0;
        for(int i = 1; i<strlen(first_literal) - 1; i++)
        {
            if(first_literal[i] == 'C')
                c_met = 1;
            if(c_met == 0)
                cols = cols*10 + (first_literal[i]-48);
            if(c_met == 1)
                rows = rows*10 + (first_literal[i+1]-48);
        }
        for(int i = 0; i < t.get_table().size(); i++)
        {
            if((t.get_table()[i]->get_r() == rows) && (t.get_table()[i]->get_c() == cols))
            {
                first_in_formula = t.get_table()[i]->show_numeric_value();
            }
        }
    }
    if(check_type_int(first_literal))
    {
        IntCell holder(0,0,first_literal);
        first_in_formula = holder.show_numeric_value();
    }
    if(check_type_double(first_literal))
    {
        DoubleCell holder(0,0,first_literal);
        first_in_formula = holder.show_numeric_value();
    }
    if(check_correct_row_col(second_literal))
    {
        int cols = 0;
        int rows = 0;
        bool c_met = 0;
        for(int i = 1; i<strlen(second_literal) - 1; i++)
        {
            if(second_literal[i] == 'C')
                c_met = 1;
            if(c_met == 0)
                cols = cols*10 + (second_literal[i]-48);
            if(c_met == 1)
                rows = rows*10 + (second_literal[i+1]-48);
        }
        for(int i = 0; i < t.get_table().size(); i++)
        {
            if((t.get_table()[i]->get_r() == rows) && (t.get_table()[i]->get_c() == cols))
            {
                first_in_formula = t.get_table()[i]->show_numeric_value();
            }
        }
    }
    if(check_type_int(second_literal))
    {
        IntCell holder(0,0,second_literal);
        second_in_formula = holder.show_numeric_value();
    }
    if(check_type_double(second_literal))
    {

        DoubleCell holder(0,0,second_literal);
        second_in_formula = holder.show_numeric_value();
    }

    switch(sign)
    {
        case '+':
            {
                //std::cout<<first_in_formula + second_in_formula;
                return first_in_formula + second_in_formula;
            }
        case '-':
            {
                //std::cout<<first_in_formula - second_in_formula;
                return first_in_formula - second_in_formula;
            }
        case '*': return first_in_formula * second_in_formula;
        case '^': return pow (first_in_formula, second_in_formula);
        case '/':
            {
                if(second_in_formula == 0)
                {
                    return 0;
                }
                else return first_in_formula / second_in_formula;
            }
    }
}

void Table::addCell(int r, int c, char* val)
{
    if(check_type_double(val) == 1)
    {
//std::cout<<"ba4ka 1 "<<val<<std::endl;
        cells.push_back (new DoubleCell(r,c,val));
    }
    else if(check_type_int(val) == 1)
    {
        //std::cout<<"ba4ka 2 "<<val<<std::endl;
        cells.push_back (new IntCell(r,c,val));
    }
    else if (check_type_string(val) == 1 )
    {
        //std::cout<<"ba4ka 3 "<<val<<std::endl;
        cells.push_back (new StringCell(r,c,val));
    }
    else if(check_type_formula(val) == 1)
    {
        //std::cout<<"ba4ka 4 "<<val<<std::endl;
        cells.push_back (new FormulaCell(r,c,val));
    }
    else cells.push_back (new Cell(r,c,val));
}
std::vector<Cell*> Table::get_table()
{
    return cells;
}
void Table::edit(int r, int c, char* val)
{
    for(int i = 0; i < cells.size(); i++)
    {
        if((cells[i]->get_r() == r) && (cells[i]->get_c() == c))
        {
            delete cells[i];
            if(check_type_double(val) == 1)
            {
                cells[i] = new DoubleCell (r,c,val);
            }
            else if(check_type_int(val) == 1)
            {

                cells[i] = new IntCell (r,c,val);
            }
            else if(check_type_string(val) == 1)
            {
                cells[i] = new StringCell (r,c,val);
            }
            else if(check_type_formula(val) == 1)
            {
                cells[i] = new FormulaCell (r,c,val);
            }
            else
            {
                cells[i] = new Cell (r,c,val);
            }
        }
    }
}
void Table::sort_by_r_c()
{
    for (int i = 0; i < cells.size()-1; i++)
        for (int j = 0; j < cells.size()-i-1; j++)
        {
            if(cells[j]->get_r() > cells[j+1]->get_r())
            {
                Cell* holder = cells[j];
                cells[j] = cells[j + 1];
                cells[j + 1] = holder;
            }
            if(cells[j]->get_r() == cells[j+1]->get_r())
            {
                if(cells[j]->get_c() > cells[j+1]->get_c())
                {
                    Cell* holder = cells[j];
                    cells[j] = cells[j + 1];
                    cells[j + 1] = holder;
                }
            }
        }
}
void Table::print()
{
    int current_c = 1;
    int prev_r = 1;
    sort_by_r_c();
    for (Cell *c : cells)
    {
        if(prev_r < c->get_r())
        {
            current_c = 1;
            std::cout<<std::endl;
            for(;current_c < c->get_c() ;current_c++)
            {
                std::cout<<" , ";
            }

            //std::cout<<std::endl<<check_correct_row_col(c->get_val())<<std::endl;
            if(check_type_formula(c->get_val()) == 1)
            {
                //std::cout<<c->get_c()<<" "<<c->get_r()<<" ";
                c->print();
            }
            else
            {
                //std::cout<<c->get_c()<<" "<<c->get_r()<<" ";
                c->print();
            }
            prev_r =  c->get_r();
        }
        else
        {
            for(;current_c < c->get_c();current_c++)std::cout<<" , ";
            if(check_type_formula(c->get_val()) == 1)
            {
                //std::cout<<c->get_c()<<" "<<c->get_r()<<" ";
                c->print();
            }
            else
            {
                //std::cout<<c->get_c()<<" "<<c->get_r()<<" ";
                c->print();
            }
        }
    }

}
Table::~Table()
{
    for (Cell* c : cells)
    {
        delete c;
    }
}
