#pragma once
#include <iostream>
#include <fstream>
#include "../support_func/support_func.hpp"

using namespace std;

// объявление струкутры меню
struct Menu;

// структура, содержащая описание каждой команды
struct command
{
	int m_number_of_commands;	// количество команд

	string m_name;				// имя команды
	string m_short_description;	// краткое описание
	string m_full_description;	// полное описание

	string** m_str_arr;			// массив с указателями на поля структуры

	string m_path_to_file_msg_folder;	// путь до папки c описанием команд

	// указатель на функцию обработки
	void (Menu::*m_check_func)(string);

	// конструкторы
	command(string _file_name);
	command();

	// деструктор
	~command();

	// заполнение команды данными из файла
	void FillCommandData(string _file_name);

	// оператор вывода
	friend ostream& operator<<(ostream& _out_stream, const command& _cmd);
};