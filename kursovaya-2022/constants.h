#pragma once
/****************************************************************
*							C O N S T					        *
****************************************************************/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ��������� �� �������
//#define SHOW_LOGO

// �������
const string PATH_TO_LOGO_FOLDER = "assets/logo_slides/";
const string PATH_TO_LOGO = PATH_TO_LOGO_FOLDER + "logo.txt";

// ����� ����������� ������ ����� ��������
const int TIME_TO_SHOW_FRAME = 10;

// ������ ����� �� ��������� �������
const string DBMS_CONSOLE_REQUEST_COMMAND = "����> ";

// ������� � ���������
const string DBMS_DESCRIPTION = 
"���� ���� ����������� ������� �������� � �������� �������� ������\n\
����� ��������� ������ \"����>\" ��������� ������� �������\n\
���� ���������� �������, ������� \"������\"\n\n";

// ���������� ������
const int NUMBERS_OF_COMMANDS = 4;

/*	��������� ���� ���������� ����
* 0 �����
* 1 ������
* 2 ������_������
* 3 ������_������
* ...
* ...
*
*/
const string ALL_COMMANDS[NUMBERS_OF_COMMANDS] =
{
	"�����",
	"������",
	"�������",
	"������"
};

// �������� ������
const string SHORT_COMM_DESCRIPTION[NUMBERS_OF_COMMANDS] =
{
	"���������� ������ ����������",
	"����� ���������� �� ����������� ������� ��� ����� ���� ������",
	"",
	""
};