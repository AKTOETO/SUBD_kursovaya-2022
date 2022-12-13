#pragma once
#include "../../constants.h"

// ��������� ��� �������
class NameSurname
{
private:
	string m_name;
	string m_surname;

public:
	// ����������� �� ���������
	NameSurname();

	// ����������� � �����������
	NameSurname(string _surname, string _name);

	// ����������
	~NameSurname();

	// �������� ������
	friend ostream& operator<<(ostream& _out_stream, const NameSurname& _name);
};
