#pragma once
#include "../music_stuff/music_stuff.h"
#include "../../../list/my_list/my_list.hpp"

class DataBaseManager
{
	// ���� ������ �� ����� �������
	my_list<MusicStuff> m_default_db;

public:
	// ����������� �� ���������
	DataBaseManager();
	// ���������� �� ���������
	~DataBaseManager();

	// �������� ��������� �������
	node<MusicStuff>* GetLastNode() const;

	// ��������� ������� ���������� �������� �� ������
	int GetLastIndexOfNode() const;

	// ���������� ���� ������ � ����
	void SaveDBToFile(ostream& _out_stream);

	// ������� ���� ������ �� �����
	void ReadDBFromFile(ifstream& _read_stream);

	// ������� ������� �� ������
	void ReadDBNodeFromString(string _node);

	// ������� ������� �� ��� �������������
	void ReadDBNodeFromNode(MusicStuff);

	// ������� ������� �� ���� ������
	void DeleteDBNode(string _str);

	// ������ � �����
	void PrintDBToConsole() const;

	// �������� ���� ������
	void ClearDB();

	// ����������� ���� ������
	void SortDB(string _str);

	// ������� ���������
	void SelectDB(string _str);
};