#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "../constants.h"

using namespace std;

// Булевая функция по умолчанию
inline bool DefaultTrueFunc(string)
{
	return true;
}

// Проверка на число
inline bool IsThereANumber(string _str)
{
	// итератор на начало строки
	std::string::const_iterator it = _str.begin();

	// идем до символа, который окажется не цифрой
	while (it != _str.end() && std::isdigit(*it)) it++;

	// если строка не пустая и мы дошли до конца
	// значит это число
	return !_str.empty() && (_str.begin() - it != 0);
}

// проверка на не отрицательное число
inline bool IsThereANotNegativeNumber(string _str)
{
	// если это число и оно не отрицательно
	if (IsThereANumber(_str) && atoi(_str.c_str()) >= 0)
		return true;
	return false;
}

// ввод и проверка значений
template<class FUNC = bool(string)>
inline string CheckableRead(
	const string _welcome_str,		// строка с запросом ввода
	const FUNC& _comp				// функция сравнения 
	= DefaultTrueFunc,
	const string _err_str			// строка с ошибкой
	= "Было введено некорректное значение"
)
{
	// считываемый символ
	//T symb;
	string str;

	// вывод сообщения
	cout << _welcome_str;
	// считывание из консоли
	//cin >> symb;
	getline(cin, str);

	// если было введено не то, что нужно было
	if (!_comp(str))
	{
		// очистка потока
		cout << _err_str << "\n";
		// рекурсивный запрос значения
		str = CheckableRead<FUNC>(_welcome_str, _comp, _err_str);
	}
	return str;
}

// является ли символ кириллическим
inline bool IsCyrillic(char _symb)
{
	return 'А' <= _symb && _symb <= 'я'
		|| _symb == 'ё' || _symb == 'Ё';
}

// получение подстроки отделенной с помощью delim
// и удаление этой подстроки из изначальной строки
inline string GetToken(string& _str, char _delim = ' ')
{
	// позиция делителя
	size_t delim_pos = _str.find(_delim);

	// если делитель не был найден, переносим всю строку
	if (delim_pos == -1)
	{
		delim_pos = _str.size();
	}

	// строка с нужной подстрокой
	// копирование нужной строки
	string new_str = _str.substr(0, delim_pos);

	// сдвиг всех символов в начало
	_str.erase(0, delim_pos + 1);

	return new_str;
}

// проверка на корректность данных
inline string IsStringNotEmpty(const string& _str)
{
	// если строка не пустая, тогда возвращаем ее
	// иначе вернем ошибочное сообщение
	return (_str.length() ? _str : NOT_CORRECT_DATA);
}

/// <summary>
/// Подготовка строки для получения из нее слов
/// </summary>
/// <param name="_str"> строка, которую надо подготовить </param>
/// <param name="_delim"> символ, который делит строку на слова</param>
inline void RemoveUnnecessarySpaces(string& _str)
{
	// добавление _delim в конец
	// нужно для корректной работы алгоритма удаления
	_str += ' ';

	// уничтожение ненужных символов _delim
	size_t begin_del_pos = -1;
	size_t end_del_pos = 0;
	do
	{
		// поиск первого разделяющего символа
		begin_del_pos = _str.find(' ', begin_del_pos + 1);
		// поиск конца последовательности из разделяющих символов
		end_del_pos = _str.substr(begin_del_pos).find_first_not_of(' ');

		// удаление этих пробелов
		_str.erase(begin_del_pos, end_del_pos - 1);

	} while (
		end_del_pos != string::npos &&
		begin_del_pos != string::npos
		);

	// если первый символ - пробел
	if (_str[0] == ' ')
	{
		_str.erase(0, 1);
	}
}

/// <summary>
/// Перевод строки в нижний регистр
/// </summary>
/// <param name="_str"> Строка, которую нужно перевести в нижний регистр</param>
/// <returns>Вернет строку в нижнем регистре</returns>
inline string ToLowerCase(const string _str)
{
	string out;
	for (int i = 0; i < _str.length(); i++)
	{
		if (IsCyrillic(_str[i]) && _str[i] < 'а')
		{
			out += (char(_str[i] + 32));
		}
		else
		{
			out += tolower(_str[i]);
		}
	}
	return out;
}

/// <summary>
/// Перевод строки в верхний регистр
/// </summary>
/// <param name="_str"> Строка, которую нужно перевести в верхний регистр</param>
/// <returns>Вернет строку в верхнем регистре</returns>
inline string ToUpperCase(const string _str)
{
	string out;
	for (int i = 0; i < _str.length(); i++)
	{
		if (IsCyrillic(_str[i]) && _str[i] >= 'а')
		{
			out += (char(_str[i] - 32));
		}
		else
		{
			out += toupper(_str[i]);
		}
	}
	return out;
}