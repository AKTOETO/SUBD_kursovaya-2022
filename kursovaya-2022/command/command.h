#pragma once
#include <iostream>
#include <fstream>
#include "../support_func/support_func.hpp"

using namespace std;

// ���������� ��������� ����
class Menu;

// ���������, ���������� �������� ������ �������
class Command
{
	string m_path_to_cmd_descr_folder;	// ���� �� ����� c ��������� ������
	int m_number_of_descriptions;	// ���������� ������

	string m_name;				// ��� �������
	string m_short_description;	// ������� ��������
	string m_full_description;	// ������ ��������

	string** m_cmd_attributes;	// ������ � ����������� �� ���� ���������

	// ��������� �� ������� ���������
	typedef void (Menu::* CheckFunc)(string);
	CheckFunc m_check_func;

public:
	// ������������
	Command(string _file_name);
	Command();

	// ����������
	~Command();

	// ���������� ������� ��������� �������
	void SetCheckFunction(CheckFunc);

	// ������� ������� ��������� �������
	// ����� ��� ������ ������� ��������� �����
	CheckFunc GetCheckFunction() const;

	// ��������� ��������� ������� 
	// (���, �������� ��������, ������ ��������)
	string GetAttribute(int _index) const;

	// ���������� ������� ������� �� �����
	void FillCommandData(string _file_name);

	// �������� ������
	friend ostream& operator<<(ostream& _out_stream, const Command& _cmd);
};