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
	/* ������ � ���������
	*	��������� ���� ���������� ����
	* 0 �����
	* 1 ������
	* 2 ������
	* 3 ������
	* ...
	* ...
	**/	
	command* m_command;

	// ��� �������� ������� � ����� ���������
#define CMD_NAME(num) m_command[num].m_name
#define CMD_SH_DECR(num) m_command[num].m_short_description
#define CMD_FL_DECR(num) m_command[num].m_full_description
#define CMD_CHK_FUNC(in_name, in_arg) (this->*m_command[GetNumberOfCommand(in_name)].m_check_func)(in_arg)

	// ����������� � ����������
	Menu();
	~Menu();

	// ���������, �������� �� ��������� ������ �������� ����
	bool IsCommandCorrect(const string& _command);

	// ��������� ������ ������� � �������
	int GetNumberOfCommand(const string& _command);

	// ����������� ��������
	void ShowLogo();

	// �������� ������� �����
	void CheckExit(string _str);

	// �������� ������� ������
	void CheckHelp(string _str);

	// �������� �������	������������
	void CheckReadData(string _str);

	// �������� �������	������������
	void CheckPrintData(string _str);

	// ������� ����
	void ProgramMenu();
};
