#pragma once
#include "../../constants.h"

// ��������� ��� �������
struct NameSurname
{
	string m_name;
	string m_surname;

	// ����������� �� ���������
	NameSurname();

	// ����������� � �����������
	NameSurname(string _surname, string _name);

	// ����������
	~NameSurname();

	// �������� ������
	friend ostream& operator<<(ostream& _out_stream, const NameSurname& _name);
};
