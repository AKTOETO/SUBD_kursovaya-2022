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
	/* ������ � ���������
	*	��������� ���� ���������� ����
	* 0 �����
	* 1 ������
	* 2 ������
	* 3 ������
	* ...
	* ...
	**/	
	Command* m_command;

	// ������ ����������� �������
	DataBaseManager m_db_manager;

	// ��� �������� ������� � ����� ���������
#define CMD_NAME(num) m_command[num].GetAttribute(0)
#define CMD_SH_DECR(num) m_command[num].GetAttribute(1)
#define CMD_FL_DESCR(num) m_command[num].GetAttribute(2)
#define CMD_CHK_FUNC(in_name, in_arg) (this->*m_command[GetNumberOfCommand(in_name)].GetCheckFunction())(in_arg)
	// ����� �� �������, ���� ���� ����
#define RETURN_IF_LIST_IS_EMPTY \
	if (m_db_manager.GetDefaultList().is_empty())\
	{\
		FUNC_INFO("���� ������ �����");\
		return;\
	}

public:
	// ����������� � ����������
	Menu();
	~Menu();

	// ������� ����
	void ProgramMenu();

	// ���������, �������� �� ��������� ������ �������� ����
	bool IsCommandCorrect(const string& _command);

	// ��������� ������ ������� � �������
	int GetNumberOfCommand(const string& _command);

	// ������ ������������� ������� ����������
	void PrintNumberedArray(const string[], int);

	// ���� ������ ��������� �� �������������
	// ������ ����������
	int ReadIndexInNumberedArray(const string _msg, int _min, int _max);

	//****************************//
	//		������� ��������	  //
	//****************************//
	
	// �������� ������� �����
	void CheckCMDExit(string _str);

	// �������� ������� ������
	void CheckCMDHelp(string _str);

	// �������� �������	������������
	void CheckCMDReadDB(string _str);

	// ��������� ���� ������ � ����
	void CheckCMDSaveDBToFile(string _str);

	// ������� ������� �� ���� ������
	void CheckCMDDeleteDBNode(string _str);

	// ������ ���� ������ � ������� � �������� ����
	void CheckCMDPrintDBToConsole(string _str);

	// ������� ���� ������
	void CheckCMDClearDB(string _str);

	// ���������� ���� ������
	void CheckCMDSelectFromDB(string _str);

	// ������ �������� ���� ������ ���, 
	// ������� ���� �������� �� �������
	void CheckCMDReplaceDefaultDB(string _str);

	// ���������� ���� ������
	void CheckCMDSortDB(string _str);

	//****************************************//
	//		������� ��� ������� ��������	  //
	//****************************************//

	// ������ �� �������
	void ReadFromConsole(string _str);

	// ������ �� �����
	void ReadFromFile(string _str);

	// �������� ����� �� ���� _str 
	// � ������ ������ � ���� ������
	void OpenReadFileAndReadDataToDB(string _str);
};
