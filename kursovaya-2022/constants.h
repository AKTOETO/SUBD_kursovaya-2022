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

// вывод сообщения от имени функции
#define FUNC_INFO(str) cout<<"\t" + string(__FUNCTION__) + ": " + str + "\n";


// логотип
const string PATH_TO_LOGO_FOLDER = "assets/logo_slides/";
const string PATH_TO_LOGO = PATH_TO_LOGO_FOLDER + "logo.txt";

// строка слева от введенной команды
const string DBMS_CONSOLE_REQUEST_COMMAND = "\n[СУБД v0.1]> ";

// справка о программе
const string DBMS_DESCRIPTION =
"СУБД была разработана Плоцким Богданом в качестве Курсовой Работы\n\
После появления строки " +
DBMS_CONSOLE_REQUEST_COMMAND +
"начинайте вводить команды\n\
Если неизвестны команды, введите \"помощь\"\n";

// сообщение об ошибочном вводе команды
const string NOT_CORRECT_COMMAND = " такой команды не существует\n\
Если неизвестны команды, введите: помощь\n\
Если не знаете, как пользоваться командой, \
введите: помощь <неизвестная команда>\n";

// сообщение о некорректных данных
const string NOT_CORRECT_DATA = "-";

// путь до ппаки с базами данных
const string DB_FOLDER_PATH = "assets/databases/";

// путь до файла с базой данных
const string DB_FILE_PATH = DB_FOLDER_PATH + "db.txt";

// заполнение len элементов элементом symb
#define OUT_W(symb, len) fixed << setfill(symb) << setw(len)

// получение токена из строки и проерка этой строки
#define GET_DATA(str) IsStringNotEmpty(GetToken(str,':'))
#define GET_INT_DATA(str) atoi(GET_DATA(str).c_str());

// количество команд
const int NUMBER_OF_COMMANDS = 10;

// ПРИ ДОБАВЛЕНИИ КОМАНДЫ НАДО ЕЩЕ ДОБАВИТЬ 
// В COMMAND_CHECK_FUNCTIONS УКАЗАТЕЛИ НА СОТВЕТСТВУЮЩИЕ 
// ФУНКЦИИ В КОНСТРУКТОРЕ Menu()
// массив с файлами, в которых лежит описание команд
const string COMMAND_DESCRIPTION_FILES[NUMBER_OF_COMMANDS] =
{
	"exit.txt",
	"help.txt",
	"read.txt",
	"print.txt",
	"save.txt",
	"delete.txt",
	"clear.txt",
	"select.txt",
	"replace.txt",
	"sort.txt"
};

// Количество полей в базе данных
const int NUMBER_OF_FIELDS = 8;

// названия полей
const string NAMES_OF_FIELDS[NUMBER_OF_FIELDS] =
{
	"НОСИТЕЛЬ",
	"ПОРЯДКОВЫЙ НОМЕР",
	"НАЗВАНИЕ ПЕСНИ",
	"ИМЯ ИСПОЛНИТЕЛЯ",
	"ФАМИЛИЯ ИСПОЛНИТЕЛЯ",
	"ВРЕМЯ ЗВУЧАНИЯ",
	"КОЛИЧЕСТВО ВОСПРОИЗВЕДЕНИЙ",
	"ЦЕНА",
};


// шапка таблицы
const string TABLE_CAP =
"|   " + NAMES_OF_FIELDS[1] +
"   |   " + NAMES_OF_FIELDS[0] +
"   |    " + NAMES_OF_FIELDS[2] +
"   |     " + NAMES_OF_FIELDS[3] +
"     |   " + NAMES_OF_FIELDS[4] +
"   |   " + NAMES_OF_FIELDS[5] +
"   |   " + NAMES_OF_FIELDS[6] +
"   |   " + NAMES_OF_FIELDS[7] +
"   |\n";

// ширина полей таблицы при выводе
const int FIELDS_WIDTH[9] =
{
	NAMES_OF_FIELDS[1].length() + 6,
	NAMES_OF_FIELDS[0].length() + 6,
	NAMES_OF_FIELDS[2].length() + 7,
	NAMES_OF_FIELDS[3].length() + 10,
	NAMES_OF_FIELDS[4].length() + 6,
	NAMES_OF_FIELDS[5].length() + 6,
	NAMES_OF_FIELDS[6].length() + 6,
	NAMES_OF_FIELDS[7].length() + 6,
};

// количество функций сортировки
const int NUMBER_OF_SORTS = 2;

// названия сортировок
const string NAMES_OF_SORTS[2] =
{
	"по убыванию",
	"по возрастанию"
};

// количество функций сравнения
const int NUMBER_OF_COMPARISONS = 5;

// названия функций сравнения
const string NAMES_OF_COMPARISONS[NUMBER_OF_COMPARISONS] =
{
	">",
	"<",
	"==",
	"<=",
	">=",
};
