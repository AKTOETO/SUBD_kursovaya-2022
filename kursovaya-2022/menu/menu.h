#pragma once
/****************************************************************
*							   M E N U					        *
****************************************************************/
#include "../support_func/support_func.hpp"
#include "../constants.h"
#include <fstream>
#include <Windows.h>

// функция меню
void ProgramMenu();

// отображение логотипа
void ShowLogo();

// проверка команды ВЫХОД
void CheckExit(string _str);

// проверка команды ПОМОЩЬ
void CheckHelp(string _str);

// проверка команды	ЧТЕНИЕДАННЫХ
void CheckReadData(string _str);

// проверка команды	ПЕЧАТЬДАННЫХ
void CheckPrintData(string _str);