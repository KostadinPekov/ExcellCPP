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
#include"commands.h"
int main()
{
//std::cout<<check_type_formula("=12-2");
     Table table;
//        table.addCell(1,1,"1");
//        table.print();
//        table.edit(1,1,"asdf");
//        table.print();
//    a.addCell(3,5,"2.1");
//    a.addCell(1,1,"\"asdf\"");
//    a.addCell(1,2,"\"asdf\"");
//    a.addCell(5,9,"4");
//    a.addCell(1,1,"=12-2");
//    a.addCell(2,3,"6");
//    a.addCell(1,2,"=14-5");
//    a.addCell(1,5,"2");
//    a.print();
//    a.edit(1,2,"5");
    //input(&a);
    //Save("asd.txt", a);
//    open_file("asd.txt",&table);
//    table.print();
   std::string command;
   std::string path_open;
   while(std::cin>>command)
   {
       if(command == "new")
       {
           input(&table);
       }
       if(command == "edit")
       {
           int r,c;
           std::string new_val;
           std::cin>>r;
           std::cin>>c;
           std::cin>>new_val;
           char* new_val_inchar = new char[new_val.length() + 1];
           for(int i = 0; i<new_val.length(); i++)
           {
               new_val_inchar[i] = new_val[i];
           }
           new_val_inchar[new_val.length()] = 0;
           table.edit(r,c,new_val_inchar);
       }
       if(command == "print")
       {
           table.print();
       }
       if(command == "open")
       {
            std::cin>>path_open;
            open_file(path_open,&table);
       }
       if(command == "save")
       {
           Save(path_open, table);
       }
       if(command == "exit")
       {
           exit();
       }
       if(command == "saveas")
       {
           save_as(table);
       }
   }
//    a.print();
//    a.print();
//
//    StringCell a(1,2,"\"asdf\"");
//    a.print();
//    a.set_val("\"123\"");
//    std::cout<<std::endl;
//    a.print();
//    std::cout<<std::endl;
//    std::cout<<a.show_numeric_value()<<std::endl;
//    a.set_val("\"123.456\"");
//    std::cout<<a.show_numeric_value()<<std::endl;
//    Table b;
//    FormulaCell a(1,1,"=12*123");
    //a.print();
    //std::cout<<check_type_formula(a.get_val());
//    std::cout<<a.show_numeric_value(b);
    //std::cout<<a.show_numeric_value(b);
}
