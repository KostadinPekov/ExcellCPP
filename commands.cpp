#include"commands.h"
void partition_and_string(Table* t,std::string single_row,int row)
{
    int column = 1;
    int literal_counter = 0;
    char *literal = new char[single_row.length() + 1];
    for(int i = 0; i < single_row.length(); i++)
    {
        if(single_row[i]!=',')
        {
            literal[literal_counter] = single_row[i];
            literal_counter++;
        }
        if((single_row[i]==',') || (i == single_row.length() - 1))
        {

            literal[literal_counter] = 0;
            t->addCell(row, column, literal);
            delete[] literal;
            char* literal = new char[single_row.length() + 1];
            column++;
            literal_counter = 0;
        }
    }
    if(column == 1)
    {
        literal[single_row.length()] = 0;
        t->addCell(row, column, literal);
    }
}
void input(Table* t)
{
    std::string single_row;
    int row = 1;
    while ( std::getline(std::cin, single_row) && !single_row.empty())
    {
        partition_and_string(t,single_row,row);
        row++;
    }
}
void open_file(std::string file_path,Table* t)
{
//    std::string file_path;
//    std::getline(std::cin,file_path);
    std::ifstream file;
    file.open(file_path, std::ios::in);
    std::string single_row;
    int row = 1;
    while ( std::getline(file, single_row) && !single_row.empty())
    {
        partition_and_string(t,single_row,row);
        row++;
    }
    file.close();
    //t.print();
}
void Save(std::string file_path, Table t)
{
    int current_c = 1;
    int prev_r = 1;
    std::ofstream file;
    file.open(file_path, std::ios::trunc);
    for (Cell *c : t.get_table())
    {
        if(prev_r < c->get_r())
        {
            current_c = 1;
            file<<'\n';
            for(;current_c < c->get_c() ;current_c++)
            {
                file<<",";
            }
            std::cout<<c->get_val()<<std::endl;
            file<<c->get_val();
            prev_r =  c->get_r();
        }
        else
        {
            for(;current_c < c->get_c();current_c++)file<<",";
            std::cout<<c->get_val()<<std::endl;
            file<<c->get_val();
        }
    }
    file.close();
}
void save_as(Table t)
{
    std::string file_path;
    std::getline(std::cin,file_path);
    Save(file_path, t);
}
void exit()
{
    std::cout<<"Exiting the program";
}
