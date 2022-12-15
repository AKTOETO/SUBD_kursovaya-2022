#pragma once
#include "../../support_func/support_func.hpp"

// ��������� ��� �������
class NameSurname
{
private:
	string m_name;
	string m_surname;

public:
	// ����������� �� ���������
	NameSurname();

	// ����������� �����������
	NameSurname(const NameSurname&);

	// ����������� � �����������
	NameSurname(string _surname, string _name);

	// ����������
	~NameSurname();

	// �������� ������������
	NameSurname& operator= (const NameSurname&);

	// �������� ������
	friend ostream& operator<<(ostream& _out_stream, const NameSurname& _name);

	// �������� �����
	friend istream& operator>> (istream& _in_stream, NameSurname& _obj);

	// Get ������
	string GetName()const;
	string GetSurname()const;
};
