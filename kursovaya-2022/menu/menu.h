#pragma once
/****************************************************************
*							   M E N U					        *
****************************************************************/
#include "../support_func/support_func.hpp"
#include "../constants.h"
#include "../command/command.h"
#include <fstream>
#include <Windows.h>


struct Menu
{
	/* массив с командами
	*	возможные коды управления СУБД
	* 0 выход
	* 1 помощь
	* 2 чтение
	* 3 печать
	* ...
	* ...
	**/	
	command* m_command;

	// Для быстрого доступа к полям структуры
#define CMD_NAME(num) m_command[num].m_name
#define CMD_SH_DECR(num) m_command[num].m_short_description
#define CMD_FL_DECR(num) m_command[num].m_full_description
#define CMD_CHK_FUNC(in_name, in_arg) (this->*m_command[GetNumberOfCommand(in_name)].m_check_func)(in_arg)

	// конструктор и деструктор
	Menu();
	~Menu();

	// Проверяет, является ли введенная строка командой СУБД
	bool IsCommandCorrect(const string& _command);

	// Получение номера команды в массиве
	int GetNumberOfCommand(const string& _command);

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

	// функция меню
	void ProgramMenu();
};
