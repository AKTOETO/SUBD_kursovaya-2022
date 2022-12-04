#pragma once
/****************************************************************
*							C O N S T					        *
****************************************************************/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// ���������� ������� � ������
// ���� �� ����� ����������, ��������������� ������
//#define SHOW_LOGO

// �������
const string PATH_TO_LOGO_FOLDER = "assets/logo_slides/";
const string PATH_TO_LOGO = PATH_TO_LOGO_FOLDER + "logo.txt";

// ����� ����������� ������ ����� ��������
const int TIME_TO_SHOW_FRAME = 10;

// ������ ����� �� ��������� �������
const string DBMS_CONSOLE_REQUEST_COMMAND = "[���� v1.0]> ";

// ������� � ���������
const string DBMS_DESCRIPTION =
"���� ���� ����������� ������� �������� � �������� �������� ������\n\
����� ��������� ������ " +
DBMS_CONSOLE_REQUEST_COMMAND +
"��������� ������� �������\n\
���� ���������� �������, ������� \"������\"\n\n";

// ���������� ������
const int NUMBERS_OF_COMMANDS = 4;

// ������ � �������, � ������� ����� �������� ������
const string COMMAND_DESCRIPTION_FILES[NUMBERS_OF_COMMANDS] =
{
	"exit.txt",
	"help.txt",
	"read.txt",
	"print.txt"
};


// ��������� �� ��������� ����� �������
const string NOT_CORRECT_COMMAND = " - ����� ������� �� ����������\n";
