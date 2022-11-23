#pragma once
/****************************************************************
*							   M E N U					        *
****************************************************************/
#include "../support_func/support_func.hpp"
#include "../constants.h"
#include <fstream>
#include <Windows.h>

// ������� ����
void ProgramMenu();

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