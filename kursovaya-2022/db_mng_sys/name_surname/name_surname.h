#pragma once
#include "../../constants.h"

// —труктура »ћя ‘јћ»Ћ»я
class NameSurname
{
private:
	string m_name;
	string m_surname;

public:
	// конструктор по умолчанию
	NameSurname();

	// конструктор с параметрами
	NameSurname(string _surname, string _name);

	// деструктор
	~NameSurname();

	// оператор вывода
	friend ostream& operator<<(ostream& _out_stream, const NameSurname& _name);
};
