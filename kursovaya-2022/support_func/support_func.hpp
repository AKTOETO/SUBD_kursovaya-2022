#pragma once
#include <iostream>
#include <string>

using namespace std;

// ���� � �������� ��������
template<class T, class FUNC>
inline T input_and_check(
	const FUNC& _comp,				// ������� ��������� 
	const string _welcome_str,		// ������ � �������� �����
	const string _err_str			// ������ � �������
	= "���� ������� ������������ ��������"
)
{
	// ������ �������
	T symb;

	// ����� ���������
	cout << _welcome_str << "\n";

	cin >> symb;

	// ���� ���� ������� ������������ ��������
	if (!_comp(symb)) {
		// ���� ���� ������� �� ��, ��� ����� ����
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << _err_str << "\n";

		// ����������� ���������
		symb = input_and_check<T>(_comp, _welcome_str, _err_str);
	}
	return symb;
}

// �������� �� ������ �������������
inline bool IsCyrillic(char _symb)
{
	return '�' <= _symb && _symb <= '�'
		|| _symb == '�' || _symb == '�';
}

// ��������� ��������� ���������� � ������� delim
// � �������� ���� ��������� �� ����������� ������
inline string GetToken(string& _str, char _delim = ':')
{
	// ������� ��������
	int delim_pos = _str.find(_delim);

	// ������ � ������ ����������
	// ����������� ������ ������
	string new_str = _str.substr(0, delim_pos);

	// ����� ���� �������� � ������
	_str.erase(0, (delim_pos == INT_MAX - 1 ? delim_pos : delim_pos + 1));

	return new_str;
}

//���         123                321
/// <summary>
/// ���������� ������ ��� ��������� �� ��� ����
/// </summary>
/// <param name="_str"> ������, ������� ���� ����������� </param>
/// <param name="_delim"> ������, ������� ����� ������ �� �����</param>
inline void RemoveUnnecessarySpaces(string& _str)
{
	// ���������� _delim � �����
	// ����� ��� ���������� ������ ��������� ��������
	_str += ' ';

	// ����������� �������� �������� _delim
	size_t begin_del_pos = -1;
	size_t end_del_pos = 0;
	do
	{
		// ����� ������� ������������ �������
		begin_del_pos = _str.find(' ', begin_del_pos + 1);
		// ����� ����� ������������������ �� ����������� ��������
		end_del_pos = _str.substr(begin_del_pos).find_first_not_of(' ');

		// �������� ���� ��������
		_str.erase(begin_del_pos, end_del_pos - 1);

	} while (
		end_del_pos != string::npos &&
		begin_del_pos != string::npos
		);

	// ���� ������ ������ - ������
	if (_str[0] == ' ')
	{
		_str.erase(0, 1);
	}

	// ���������� _delim � �����
	// ����� ��� ���������� ������ ��������� ��������
	_str += ' ';
}

/// <summary>
/// ������� ������ � ������ �������
/// </summary>
/// <param name="_str"> ������, ������� ����� ��������� � ������ �������</param>
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
/// ������� ������ � ������� �������
/// </summary>
/// <param name="_str"> ������, ������� ����� ��������� � ������� �������</param>
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