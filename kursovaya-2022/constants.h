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
#define FUNC_INFO(str) cout<<"\t" + string(__FUNCTION__) + ": " + str + "\n";


// �������
const string PATH_TO_LOGO_FOLDER = "assets/logo_slides/";
const string PATH_TO_LOGO = PATH_TO_LOGO_FOLDER + "logo.txt";

// ������ ����� �� ��������� �������
const string DBMS_CONSOLE_REQUEST_COMMAND = "\n[���� v0.1]> ";

// ������� � ���������
const string DBMS_DESCRIPTION =
"���� ���� ����������� ������� �������� � �������� �������� ������\n\
����� ��������� ������ " +
DBMS_CONSOLE_REQUEST_COMMAND +
"��������� ������� �������\n\
���� ���������� �������, ������� \"������\"\n";

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

// ���������� ������
const int NUMBER_OF_COMMANDS = 10;

// ��� ���������� ������� ���� ��� �������� 
// � COMMAND_CHECK_FUNCTIONS ��������� �� �������������� 
// ������� � ������������ Menu()
// ������ � �������, � ������� ����� �������� ������
const string COMMAND_DESCRIPTION_FILES[NUMBER_OF_COMMANDS] =
{
	"exit.txt",
	"help.txt",
	"read.txt",
	"print.txt",
	"save.txt",
	"delete.txt",
	"clear.txt",
	"select.txt",
	"replace.txt",
	"sort.txt"
};

// ���������� ����� � ���� ������
const int NUMBER_OF_FIELDS = 8;

// �������� �����
const string NAMES_OF_FIELDS[NUMBER_OF_FIELDS] =
{
	"��������",
	"���������� �����",
	"�������� �����",
	"��� �����������",
	"������� �����������",
	"����� ��������",
	"���������� ���������������",
	"����",
};


// ����� �������
const string TABLE_CAP =
"|   " + NAMES_OF_FIELDS[1] +
"   |   " + NAMES_OF_FIELDS[0] +
"   |    " + NAMES_OF_FIELDS[2] +
"   |     " + NAMES_OF_FIELDS[3] +
"     |   " + NAMES_OF_FIELDS[4] +
"   |   " + NAMES_OF_FIELDS[5] +
"   |   " + NAMES_OF_FIELDS[6] +
"   |   " + NAMES_OF_FIELDS[7] +
"   |\n";

// ������ ����� ������� ��� ������
const int FIELDS_WIDTH[9] =
{
	NAMES_OF_FIELDS[1].length() + 6,
	NAMES_OF_FIELDS[0].length() + 6,
	NAMES_OF_FIELDS[2].length() + 7,
	NAMES_OF_FIELDS[3].length() + 10,
	NAMES_OF_FIELDS[4].length() + 6,
	NAMES_OF_FIELDS[5].length() + 6,
	NAMES_OF_FIELDS[6].length() + 6,
	NAMES_OF_FIELDS[7].length() + 6,
};

// ���������� ������� ����������
const int NUMBER_OF_SORTS = 2;

// �������� ����������
const string NAMES_OF_SORTS[2] =
{
	"�� ��������",
	"�� �����������"
};

// ���������� ������� ���������
const int NUMBER_OF_COMPARISONS = 5;

// �������� ������� ���������
const string NAMES_OF_COMPARISONS[NUMBER_OF_COMPARISONS] =
{
	">",
	"<",
	"==",
	"<=",
	">=",
};
