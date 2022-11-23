#pragma once
/****************************************************************
*							C O N S T					        *
****************************************************************/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// показыват ли логотип
//#define SHOW_LOGO

// логотип
const string PATH_TO_LOGO_FOLDER = "assets/logo_slides/";
const string PATH_TO_LOGO = PATH_TO_LOGO_FOLDER + "logo.txt";

// время отображения одного кадра логотипа
const int TIME_TO_SHOW_FRAME = 10;

// строка слева от введенной команды
const string DBMS_CONSOLE_REQUEST_COMMAND = "СУБД> ";

// справка о программе
const string DBMS_DESCRIPTION = 
"СУБД была разработана Плоцким Богданом в качестве Курсовой Работы\n\
После появления строки \"СУБД>\" начинайте вводить команды\n\
Если неизвестны команды, введите \"помощь\"\n\n";

// количество команд
const int NUMBERS_OF_COMMANDS = 4;

/*	возможные коды управления СУБД
* 0 выход
* 1 помощь
* 2 чтение_данных
* 3 печать_данных
* ...
* ...
*
*/
const string ALL_COMMANDS[NUMBERS_OF_COMMANDS] =
{
	"выход",
	"помощь",
	"чтендан",
	"печдан"
};

// описание команд
const string SHORT_COMM_DESCRIPTION[NUMBERS_OF_COMMANDS] =
{
	"завершение работы приложения",
	"вывод информации по неизвестной команде или вывод всех команд",
	"",
	""
};