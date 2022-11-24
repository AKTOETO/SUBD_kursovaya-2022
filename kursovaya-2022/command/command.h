#pragma once
#include <iostream>
#include <fstream>
#include "../support_func/support_func.hpp"

using namespace std;

// ���������� ��������� ����
struct Menu;

// ���������, ���������� �������� ������ �������
struct command
{
	int m_number_of_commands;	// ���������� ������

	string m_name;				// ��� �������
	string m_short_description;	// ������� ��������
	string m_full_description;	// ������ ��������

	string** m_str_arr;			// ������ � ����������� �� ���� ���������

	string m_path_to_file_msg_folder;	// ���� �� ����� c ��������� ������

	// ��������� �� ������� ���������
	void (Menu::*m_check_func)(string);

	// ������������
	command(string _file_name);
	command();

	// ����������
	~command();

	// ���������� ������� ������� �� �����
	void FillCommandData(string _file_name);

	// �������� ������
	friend ostream& operator<<(ostream& _out_stream, const command& _cmd);
};