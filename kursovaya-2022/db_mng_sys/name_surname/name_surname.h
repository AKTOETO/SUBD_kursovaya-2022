#pragma once
#include "../../constants.h"

// —труктура »ћя ‘јћ»Ћ»я
struct NameSurname
{
	string m_name;
	string m_surname;

	// конструктор по умолчанию
	NameSurname();

	// конструктор с параметрами
	NameSurname(string _surname, string _name);

	// деструктор
	~NameSurname();

	// оператор вывода
	friend ostream& operator<<(ostream& _out_stream, const NameSurname& _name);
};
