#pragma once
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
void partition_and_string(Table* t,std::string single_row,int row);
void input(Table* t);

void open_file(std::string file_path,Table* t);

void Save(std::string file_path, Table t);

void save_as(Table t);

void exit();
