#pragma once
#include "../../support_func/support_func.hpp"

// Структура ИМЯ ФАМИЛИЯ
class NameSurname
{
private:
	string m_name;
	string m_surname;

public:
	// конструктор по умолчанию
	NameSurname();

	// конструктор копирования
	NameSurname(const NameSurname&);

	// конструктор с параметрами
	NameSurname(string _surname, string _name);

	// деструктор
	~NameSurname();

	// оператор присваивания
	NameSurname& operator= (const NameSurname&);

	// оператор вывода
	friend ostream& operator<<(ostream& _out_stream, const NameSurname& _name);

	// Оператор ввода
	friend istream& operator>> (istream& _in_stream, NameSurname& _obj);

	// Get методы
	string GetName()const;
	string GetSurname()const;
};
