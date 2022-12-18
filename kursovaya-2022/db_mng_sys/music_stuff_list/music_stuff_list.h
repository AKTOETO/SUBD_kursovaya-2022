#pragma once
#include "../music_stuff/music_stuff.h"
#include "../../../list/my_list/my_list.hpp"
	
class DataBaseManager
{
	// ���� ������ �� ����� �������
	my_list<MusicStuff> m_default_db;

	// ������� � ���������� ���������
	my_list<node<MusicStuff>*> m_selected_nodes;

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

	// ��������� ������ ��������� � ����� ������������� ��������
	my_list<node<MusicStuff>*>& GetSelectedList();

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
	void DeleteDBSelectedList();

	// ������ � �����
	void PrintDBToConsole() const;

	// ������ �������� ���� �� �������
	my_list<string>* GetDataInField(int _index) const;

	// �������� ���� ������
	void ClearDB();

	// ����������� ���� ������
	void SortDB(string _str);

	// ������� ���������
	void SelectDB(int _field_index, string _value);

	// ������ �������� ���� ������ ���, ������� � �������
	void ReplaceDefaultDataBase();

	// ���������� ��������
	void IndexesRecalculation();
};
