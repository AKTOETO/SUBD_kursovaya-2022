#pragma once
/****************************************************************
*							C O N S T					        *
****************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// вывод в консоль сообщения
#define INFO(str) cout<<"\t"<<str<<"\n";

// Показывать логотип в начале
// Если не нужно показывать, закоментировать строку
//#define SHOW_LOGO

// логотип
const string PATH_TO_LOGO_FOLDER = "assets/logo_slides/";
const string PATH_TO_LOGO = PATH_TO_LOGO_FOLDER + "logo.txt";

// время отображения одного кадра логотипа
const int TIME_TO_SHOW_FRAME = 10;

// строка слева от введенной команды
const string DBMS_CONSOLE_REQUEST_COMMAND = "[СУБД v1.0]> ";

// справка о программе
const string DBMS_DESCRIPTION =
"СУБД была разработана Плоцким Богданом в качестве Курсовой Работы\n\
После появления строки " +
DBMS_CONSOLE_REQUEST_COMMAND +
"начинайте вводить команды\n\
Если неизвестны команды, введите \"помощь\"\n\n";

// количество команд
const int NUMBERS_OF_COMMANDS = 4;

// массив с файлами, в которых лежит описание команд
const string COMMAND_DESCRIPTION_FILES[NUMBERS_OF_COMMANDS] =
{
	"exit.txt",
	"help.txt",
	"read.txt",
	"print.txt"
};

// сообщение об ошибочном вводе команды
const string NOT_CORRECT_COMMAND = " такой команды не существует\n\
Если неизвестны команды, введите: помощь\n\
Если не знаете, как пользоваться командой, введите: помощь <неизвестная команда>";

// сообщение о некорректных данных
const string not_correct_data = "----";

// путь до файла с базой данных
const string db_file_path = "assets/db.txt";

// файл с выводом программы
const string db_output_path = "assets/subd_log.txt";

// заполнение len элементов элементом symb
#define OUT_W(symb, len) fixed << setfill(symb) << setw(len)

// получение токена из строки и проерка этой строки
#define GET_DATA(str) IsStringNotEmpty(GetToken(str,':'))
#define GET_INT_DATA(str) atoi(GET_DATA(str).c_str());

// шапка таблицы
const string table_cap = "| НОМЕР | НОСИТЕЛЬ | НАЗВАНИЕ |\
 ИМЯ/ФАМИЛИЯ ИСПОЛНИТЕЛЯ | ВРЕМЯ | КОЛ-ВО ВОСПР. | ЦЕНА |\n";

// ширина полей таблицы при выводе
const int width_of_fields[8] =
{
	7,10,10,12,13,7,15,6
};