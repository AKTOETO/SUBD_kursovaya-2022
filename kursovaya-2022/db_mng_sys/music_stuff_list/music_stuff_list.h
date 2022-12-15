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

	// ������� ������ �������
	node<MusicStuff>* GetFirstNode() const;

	// ��������� ������� ���������� �������� �� ������
	int GetLastIndexOfNode() const;

	// ��������� ������� ������
	int GetSizeOfDataBase() const;

	// ���������� ���� ������ � ����
	void SaveDBToFile(ostream& _out_stream);

	// ������� ���� ������ �� �����
	void ReadDBFromFile(ifstream& _read_stream);

	// ������� ������� �� ������
	void ReadDBNodeFromString(string _node);

	// ������� ������� �� ��� �������������
	void ReadDBNodeFromNode(MusicStuff);

	// ����� �������� ��� ��������
	node<MusicStuff>* FindNodeToDelete(int _index);

	// ������� ������� �� ���� ������
	void DeleteDBNode(string _str);
	void DeleteDBNode(int _index);
	void DeleteDBNode(node<MusicStuff>* _node);

	// ������ � �����
	void PrintDBToConsole() const;

	// �������� ���� ������
	void ClearDB();

	// ����������� ���� ������
	void SortDB(string _str);

	// ������� ���������
	void SelectDB(string _str);

	// ���������� ��������
	void IndexesRecalculation();
};