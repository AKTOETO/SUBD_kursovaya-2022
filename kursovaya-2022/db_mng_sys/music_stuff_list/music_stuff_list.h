#pragma once
#include "../music_stuff/music_stuff.h"
#include "../../../list/my_list/my_list.hpp"

class DataBaseManager
{
	// база данных со всеми данными
	my_list<MusicStuff> m_default_db;

	// база данных дл€ изменени€
	my_list<MusicStuff> m_db_for_modifications;

public:
	//  онструктор по умолчанию
	DataBaseManager();

	// сохранение базы данных в файл
	void SaveDBToFile(string _file_path);

	// считать базу данных из файла
	void ReadDBFromFile(ifstream& _read_stream);

	// сброс модификацированной базы данных
	// до изначального состо€ни€
	void ResetDBFromDefaultDB();

	// считать элемент из строки
	void ReadDBNodeFromString(string _node);

	// удалить элемент из базы данных
	void DeleteDBNode(string _str);

	// печать в поток
	void PrintDBToConsole(ostream& _out_stream);

	// очистить базу данных
	void ClearDB();

	// сортировать базу данных
	void SortDB(string _str);

	// выборка элементов
	void SelectDB(string _str);
};