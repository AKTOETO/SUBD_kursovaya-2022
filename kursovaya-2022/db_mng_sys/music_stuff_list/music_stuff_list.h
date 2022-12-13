#pragma once
#include "../music_stuff/music_stuff.h"
#include "../../../list/my_list/my_list.hpp"

class DataBaseManager
{
	// ���� ������ �� ����� �������
	my_list<MusicStuff> m_default_db;

	// ���� ������ ��� ���������
	my_list<MusicStuff> m_db_for_modifications;

public:
	// ����������� �� ���������
	DataBaseManager();

	// ���������� ���� ������ � ����
	void SaveDBToFile(string _file_path);

	// ������� ���� ������ �� �����
	void ReadDBFromFile(ifstream& _read_stream);

	// ����� ������������������ ���� ������
	// �� ������������ ���������
	void ResetDBFromDefaultDB();

	// ������� ������� �� ������
	void ReadDBNodeFromString(string _node);

	// ������� ������� �� ���� ������
	void DeleteDBNode(string _str);

	// ������ � �����
	void PrintDBToConsole(ostream& _out_stream);

	// �������� ���� ������
	void ClearDB();

	// ����������� ���� ������
	void SortDB(string _str);

	// ������� ���������
	void SelectDB(string _str);
};