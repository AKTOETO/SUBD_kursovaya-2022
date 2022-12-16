#pragma once
/****************************************************************
*							C O N S T					        *
****************************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// ����� � ������� ���������
#define INFO(str) cout<<"\t"<<str<<"\n";

// ����� ��������� �� ����� �������
#define FUNC_INFO(str) cout<<"\t" + string(__FUNCTION__) +": " str + "\n";

// ���������� ����� � ���� ������
const int NUMBER_OF_FIELDS = 8;

// �������� �����
const string NAMES_OF_FIELDS[NUMBER_OF_FIELDS] =
{
	"��������",
	"���������� �����",
	"��������",
	"��� �����������",
	"������� �����������",
	"����� ��������",
	"���������� ���������������",
	"����",
};

// �������
const string PATH_TO_LOGO_FOLDER = "assets/logo_slides/";
const string PATH_TO_LOGO = PATH_TO_LOGO_FOLDER + "logo.txt";

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
const int NUMBER_OF_COMMANDS = 6;

// ������ � �������, � ������� ����� �������� ������
const string COMMAND_DESCRIPTION_FILES[NUMBER_OF_COMMANDS] =
{
	"exit.txt",
	"help.txt",
	"read.txt",
	"print.txt",
	"save.txt",
	"delete.txt",
};

// ��������� �� ��������� ����� �������
const string NOT_CORRECT_COMMAND = " ����� ������� �� ����������\n\
���� ���������� �������, �������: ������\n\
���� �� ������, ��� ������������ ��������, \
�������: ������ <����������� �������>\n";

// ��������� � ������������ ������
const string NOT_CORRECT_DATA = "-";

// ���� �� ����� � ������ ������
const string DB_FOLDER_PATH = "assets/databases/";

// ���� �� ����� � ����� ������
const string DB_FILE_PATH = DB_FOLDER_PATH + "db.txt";

// ���������� len ��������� ��������� symb
#define OUT_W(symb, len) fixed << setfill(symb) << setw(len)

// ��������� ������ �� ������ � ������� ���� ������
#define GET_DATA(str) IsStringNotEmpty(GetToken(str,':'))
#define GET_INT_DATA(str) atoi(GET_DATA(str).c_str());

// ����� �������
const string table_cap = "| ����� | �������� | �������� |\
 ��� ����������� | ������� ����������� | ����� | ���-�� �����. | ���� |\n";

// ������ ����� ������� ��� ������
const int width_of_fields[9] =
{
	7,10,10,17,21,7,15,6
};