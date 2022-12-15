#pragma once
#include "../music_stuff/music_stuff.h"
#include "../../../list/my_list/my_list.hpp"

class DataBaseManager
{
	// база данных со всеми данными
	my_list<MusicStuff> m_default_db;

public:
	//  онструктор по умолчанию
	DataBaseManager();

	// сохранение базы данных в файл
	void SaveDBToFile(ostream& _out_stream);

	// считать базу данных из файла
	void ReadDBFromFile(ifstream& _read_stream);

	// считать элемент из строки
	void ReadDBNodeFromString(string _node);

	// считать элемень из уже существующего
	void ReadDBNodeFromNode(MusicStuff);

	// удалить элемент из базы данных
	void DeleteDBNode(string _str);

	// печать в поток
	void PrintDBToConsole() const;

	// очистить базу данных
	void ClearDB();

	// сортировать базу данных
	void SortDB(string _str);

	// выборка элементов
	void SelectDB(string _str);
};