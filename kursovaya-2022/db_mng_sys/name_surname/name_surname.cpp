#include "name_surname.h"

NameSurname::NameSurname()
	:m_name(NOT_CORRECT_DATA), m_surname(NOT_CORRECT_DATA)
{
}

NameSurname::NameSurname(const NameSurname& _obj)
{
	m_name = _obj.m_name;
	m_surname = _obj.m_surname;
}

NameSurname::NameSurname(string _surname, string _name)
	:m_name(_name), m_surname(_surname)
{
}

NameSurname::~NameSurname()
{
}

NameSurname& NameSurname::operator=(const NameSurname& _obj)
{
	// проверка на самоприсваивание
	if (this == &_obj)
	{
		return *this;
	}

	// копирование всех полей
	m_name = _obj.m_name;
	m_surname = _obj.m_surname;

	// возвращение объекта
	return *this;
}

void NameSurname::SetName(string _str)
{
	m_name = _str;
}

void NameSurname::SetSurname(string _str)
{
	m_surname = _str;
}

string NameSurname::GetName() const
{
	return m_name;
}

string NameSurname::GetSurname() const
{
	return m_surname;
}

ostream& operator<<(ostream& _out_stream, const NameSurname& _name)
{
	_out_stream <<
		OUT_W(' ', FIELDS_WIDTH[3]) << _name.m_name <<
		OUT_W(' ', FIELDS_WIDTH[4]) << _name.m_surname;
	return _out_stream;
}

istream& operator>>(istream& _in_stream, NameSurname& _obj)
{
	_obj.m_name = CheckableRead(
		"\t[Введите ИМЯ исполнителя]> "
		);
	_obj.m_surname = CheckableRead(
		"\t[Введите ФАМИЛИЮ исполнителя]> "
		);

	return _in_stream;
}