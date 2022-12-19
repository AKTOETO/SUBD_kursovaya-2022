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

	// Get ������

	// �������� ��������� �������
	node<MusicStuff>* GetLastNode() const;

	// �������� ������ �������
	node<MusicStuff>* GetFirstNode() const;

	// ��������� ������� ���������� �������� �� ������
	int GetLastIndexOfNode() const;

	// ��������� ������ ��������� � ����� ������������� ��������
	my_list<node<MusicStuff>*>& GetSelectedList();

	// ��������� ��������� ������ ���������
	my_list<MusicStuff>& GetDefaultList();

	// ������ �������� ���� �� �������
	my_list<string>* GetDataInField(int _index) const;

	// ������� ���������

	// ���������� ���� ������ � ����
	void SaveDBToFile(ostream& _out_stream);

	// ������� ���� ������ �� �����
	void ReadDBFromFile(ifstream& _read_stream);

	// ������� ������� �� ��� �������������
	void ReadDBNodeFromNode(MusicStuff);

	// ����� �������� ��� ��������
	node<MusicStuff>* FindNodeToDelete(int _index);

	// ������� ������� �� ���� ������
	void DeleteDBNode(node<MusicStuff>* _node);
	void DeleteDBSelectedList();

	// ������ � �����
	void PrintDBToConsole() const;

	// ������ ���������� �� � �����
	void PrintSelectedDBToConsole() const;

	// �������� ���� ������
	void ClearDB();

	// ����������� ���� ������
	void SortDB(int _field_index, bool(string, string) = COMPARE::IsLower);

	// ������� ���������
	void SelectDB(int _field_index, string _value
		, bool(string, string) = COMPARE::IsEqual);

	// ������ �������� ���� ������ ���, ������� � �������
	void ReplaceDefaultDataBase();

	// ���������� ��������
	void IndexesRecalculation();
};
