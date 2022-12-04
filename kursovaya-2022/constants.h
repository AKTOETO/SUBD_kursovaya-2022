#pragma once
/****************************************************************
*							C O N S T					        *
****************************************************************/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

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
const string NOT_CORRECT_COMMAND = " - такой команды не существует\n";
