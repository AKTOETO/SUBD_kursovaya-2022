#pragma once
/****************************************************************
*							   M E N U					        *
****************************************************************/
#include "../support_func/support_func.hpp"
#include "../constants.h"
#include "../command/command.h"
#include "../db_mng_sys/music_stuff_list/music_stuff_list.h"
#include <fstream>
#include <Windows.h>

class Menu
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
	Command* m_command;

	// Список музыкальных товаров
	DataBaseManager m_db_manager;

	// Для быстрого доступа к полям структуры
#define CMD_NAME(num) m_command[num].GetAttribute(0)
#define CMD_SH_DECR(num) m_command[num].GetAttribute(1)
#define CMD_FL_DESCR(num) m_command[num].GetAttribute(2)
#define CMD_CHK_FUNC(in_name, in_arg) (this->*m_command[GetNumberOfCommand(in_name)].GetCheckFunction())(in_arg)
	// Выход из функции, если пуст лист
#define RETURN_IF_LIST_IS_EMPTY \
	if (m_db_manager.GetDefaultList().is_empty())\
	{\
		FUNC_INFO("база данных пуста");\
		return;\
	}

public:
	// конструктор и деструктор
	Menu();
	~Menu();

	// функция меню
	void ProgramMenu();

	// Проверяет, является ли введенная строка командой СУБД
	bool IsCommandCorrect(const string& _command);

	// Получение номера команды в массиве
	int GetNumberOfCommand(const string& _command);

	// печать нумерованного массива параметров
	void PrintNumberedArray(const string[], int);

	// ввод номера параметра из нумерованного
	// масива параметров
	int ReadIndexInNumberedArray(const string _msg, int _min, int _max);

	//****************************//
	//		ФУНКЦИИ ПРОВЕРОК	  //
	//****************************//
	
	// проверка команды ВЫХОД
	void CheckCMDExit(string _str);

	// проверка команды ПОМОЩЬ
	void CheckCMDHelp(string _str);

	// проверка команды	ЧТЕНИЕДАННЫХ
	void CheckCMDReadDB(string _str);

	// сохранить базу данных в файл
	void CheckCMDSaveDBToFile(string _str);

	// удалить элемент из базы данных
	void CheckCMDDeleteDBNode(string _str);

	// печать базы данных в консоль в читаемом виде
	void CheckCMDPrintDBToConsole(string _str);

	// очистка базы данных
	void CheckCMDClearDB(string _str);

	// сортировка базы данных
	void CheckCMDSelectFromDB(string _str);

	// замена исходной базы данных той, 
	// которая была получена из выборки
	void CheckCMDReplaceDefaultDB(string _str);

	// сортировка базы данных
	void CheckCMDSortDB(string _str);

	//****************************************//
	//		ФУНКЦИИ ДЛЯ ФУНКЦИЙ ПРОВЕРОК	  //
	//****************************************//

	// чтение из консоли
	void ReadFromConsole(string _str);

	// чтение из файла
	void ReadFromFile(string _str);

	// открытие файла по пути _str 
	// и запись данных в базу данных
	void OpenReadFileAndReadDataToDB(string _str);
};
