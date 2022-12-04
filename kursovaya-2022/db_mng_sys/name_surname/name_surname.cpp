#include "name_surname.h"

ostream& operator<<(ostream& _out_stream, const NameSurname& _name)
{
	_out_stream <<
		OUT_W(' ', width_of_fields[3]) << _name.m_name <<
		OUT_W(' ', width_of_fields[4]) << _name.m_surname;
	return _out_stream;
}

NameSurname::NameSurname()
	:m_name(not_correct_data), m_surname(not_correct_data)
{
}

NameSurname::NameSurname(string _surname, string _name)
	:m_name(_name), m_surname(_surname)
{
}

NameSurname::~NameSurname()
{
}
