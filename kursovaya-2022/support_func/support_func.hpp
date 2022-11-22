#pragma once
#include <iostream>
#include <string>

using namespace std;

// ввод и проверка значений
template<class T, class FUNC>
inline T input_and_check(
	const FUNC& _comp,				// функция сравнения 
	const string _welcome_str,		// строка с запросом ввода
	const string _err_str			// строка с ошибкой
	= "Было введено некорректное значение"
)
{
	// размер массива
	T symb;

	// вывод сообщения
	cout << _welcome_str << "\n";

	cin >> symb;

	// если было введено некорректное значение
	if (!_comp(symb)) {
		// если была введено не то, что нужно было
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << _err_str << "\n";

		// рекурсивное обращение
		symb = input_and_check<T>(_comp, _welcome_str, _err_str);
	}
	return symb;
}

// является ли символ кириллическим
inline bool IsCyrillic(char _symb)
{
	return 'А' <= _symb && _symb <= 'я'
		|| _symb == 'ё' || _symb == 'Ё';
}

// получение подстроки отделенной с помощью delim
// и удаление этой подстроки из изначальной строки
inline string GetToken(string& _str, char _delim = ':')
{
	// позиция делителя
	int delim_pos = _str.find(_delim);

	// строка с нужной подстрокой
	// копирование нужной строки
	string new_str = _str.substr(0, delim_pos);

	// сдвиг всех символов в начало
	_str.erase(0, (delim_pos == INT_MAX - 1 ? delim_pos : delim_pos + 1));

	return new_str;
}

//бог         123                321
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

	// добавление _delim в конец
	// нужно для корректной работы алгоритма удаления
	_str += ' ';
}

/// <summary>
/// Перевод строки в нижний регистр
/// </summary>
/// <param name="_str"> Строка, которую нужно перевести в нижний регистр</param>
/// <returns></returns>
inline string ToLowerCase(const string _str)
{
	string out;
	for (int i = 0; i < _str.length(); i++)
	{
		if (IsCyrillic)
		{
			out += (char(_str[i] + 32));
		}
	}
	return out;
}

/// <summary>
/// Перевод строки в верхний регистр
/// </summary>
/// <param name="_str"> Строка, которую нужно перевести в верхний регистр</param>
/// <returns></returns>
inline string ToUpperCase(const string _str)
{
	string out;
	for (int i = 0; i < _str.length(); i++)
	{
		if (IsCyrillic(_str[i]))
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