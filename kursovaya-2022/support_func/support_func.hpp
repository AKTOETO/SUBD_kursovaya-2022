#pragma once
#include "../constants.h"

using namespace std;

// ������� ������� �� ���������
inline bool DefaultTrueFunc(string)
{
	return true;
}

// �������� �� �����
inline bool IsItANumber(string _str)
{
	// �������� �� ������ ������
	std::string::const_iterator it = _str.begin();

	// ���� �� �������, ������� �������� �� ������
	while (it != _str.end() && std::isdigit(*it)) it++;

	// ���� ������ �� ������ � �� ����� �� �����
	// ������ ��� �����
	return (_str.end() == it);
}

// �������� �� ������� ����� � ������
inline bool IsThereANumber(string _str)
{
	// �������� �� ������ ������
	std::string::const_iterator it = _str.begin();

	// ���� �� �������, ������� �������� �� ������
	while (it != _str.end() && std::isdigit(*it)) it++;

	// ���� ������ �� ������ � �� ����� �� �����
	// ������ ��� �����
	return !_str.empty() && (_str.begin() - it != 0);
}

// �������� �� �� ������������� �����
inline bool IsThereANotNegativeNumber(string _str)
{
	// ���� ��� ����� � ��� �� ������������
	if (IsThereANumber(_str) && atoi(_str.c_str()) >= 0)
		return true;
	return false;
}

// ���� � �������� ��������
template<class FUNC = bool(string)>
inline string CheckableRead(
	const string _welcome_str,		// ������ � �������� �����
	const FUNC& _comp				// ������� ��������� 
	= DefaultTrueFunc,
	const string _err_str			// ������ � �������
	= "���� ������� ������������ ��������"
)
{
	// ����������� ������
	string str;

	// ����� ���������
	cout << _welcome_str;
	// ���������� �� �������
	getline(cin, str);

	// ���� ���� ������� �� ��, ��� ����� ����
	if (!_comp(str))
	{
		FUNC_INFO(_err_str);
		// ����������� ������ ��������
		str = CheckableRead<FUNC>(_welcome_str, _comp, _err_str);
	}
	return str;
}

// �������� �� ������ �������������
inline bool IsCyrillic(char _symb)
{
	return '�' <= _symb && _symb <= '�'
		|| _symb == '�' || _symb == '�';
}

// ��������� ��������� ���������� � ������� delim
// � �������� ���� ��������� �� ����������� ������
inline string GetToken(string& _str, char _delim = ' ')
{
	// ������� ��������
	size_t delim_pos = _str.find(_delim);

	// ���� �������� �� ��� ������, ��������� ��� ������
	if (delim_pos == -1)
	{
		delim_pos = _str.size();
	}

	// ������ � ������ ����������
	// ����������� ������ ������
	string new_str = _str.substr(0, delim_pos);

	// ����� ���� �������� � ������
	_str.erase(0, delim_pos + 1);

	return new_str;
}

// ������ ���� �������� �����
inline void PrintFieldsOfDataBase()
{
	for (int i = 0; i < NUMBER_OF_FIELDS; i++)
	{
		cout << "\t" << i + 1 << ") " << NAMES_OF_FIELDS[i] << "\n";
	}
}

// �������� �� ������������ ������
inline string IsStringNotEmpty(const string& _str)
{
	// ���� ������ �� ������, ����� ���������� ��
	// ����� ������ ��������� ���������
	return (_str.length() ? _str : NOT_CORRECT_DATA);
}

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
}

/// <summary>
/// ������� ������ � ������ �������
/// </summary>
/// <param name="_str"> ������, ������� ����� ��������� � ������ �������</param>
/// <returns>������ ������ � ������ ��������</returns>
inline string ToLowerCase(const string _str)
{
	string out;
	for (int i = 0; i < _str.length(); i++)
	{
		if (IsCyrillic(_str[i]) && _str[i] < '�')
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
/// ������� ������ � ������� �������
/// </summary>
/// <param name="_str"> ������, ������� ����� ��������� � ������� �������</param>
/// <returns>������ ������ � ������� ��������</returns>
inline string ToUpperCase(const string _str)
{
	string out;
	for (int i = 0; i < _str.length(); i++)
	{
		if (IsCyrillic(_str[i]) && _str[i] >= '�')
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

//**********************************//
//		������� ��������� �����		//
//**********************************//
namespace COMPARE
{
	inline bool IsLower(string s1, string s2)
	{
		if (IsItANumber(s1) && IsItANumber(s2))
			return atoi(s1.c_str()) < atoi(s2.c_str());

		return s1 < s2 && s1.length() <= s2.length();
	}

	inline bool IsGreater(string s1, string s2)
	{
		if (IsItANumber(s1) && IsItANumber(s2))
			return atoi(s1.c_str()) > atoi(s2.c_str());

		return s1 > s2 && s1.length() >= s2.length();
	}

	inline bool IsEqual(string s1, string s2)
	{
		if (IsItANumber(s1) && IsItANumber(s2))
			return atoi(s1.c_str()) == atoi(s2.c_str());

		return s1 == s2;
	}

	inline bool IsLowerEqual(string s1, string s2)
	{
		return IsLower(s1, s2) || IsEqual(s1, s2);
	}

	inline bool IsGreaterEqual(string s1, string s2)
	{
		return IsGreater(s1, s2) || IsEqual(s1, s2);
	}

	// ������ ������� ���������
	static bool (*COMPARISONS[])(string, string) =
	{
		IsGreater,
		IsLower,
		IsEqual,
		IsLowerEqual,
		IsGreaterEqual
	};
}
