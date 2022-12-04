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
const string NOT_CORRECT_COMMAND = " ����� ������� �� ����������\n\
���� ���������� �������, �������: ������\n\
���� �� ������, ��� ������������ ��������, �������: ������ <����������� �������>";

// ��������� � ������������ ������
const string not_correct_data = "----";

// ���� �� ����� � ����� ������
const string db_file_path = "assets/db.txt";

// ���� � ������� ���������
const string db_output_path = "assets/subd_log.txt";

// ���������� len ��������� ��������� symb
#define OUT_W(symb, len) fixed << setfill(symb) << setw(len)

// ��������� ������ �� ������ � ������� ���� ������
#define GET_DATA(str) IsStringNotEmpty(GetToken(str,':'))
#define GET_INT_DATA(str) atoi(GET_DATA(str).c_str());

// ����� �������
const string table_cap = "| ����� | �������� | �������� |\
 ���/������� ����������� | ����� | ���-�� �����. | ���� |\n";

// ������ ����� ������� ��� ������
const int width_of_fields[8] =
{
	7,10,10,12,13,7,15,6
};