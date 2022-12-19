#pragma once
#include "../music_stuff/music_stuff.h"
#include "../../../list/my_list/my_list.hpp"
	
class DataBaseManager
{
	// база данных со всеми данными
	my_list<MusicStuff> m_default_db;

	// списоск с выбранными элеметами
	my_list<node<MusicStuff>*> m_selected_nodes;

public:
	// Конструктор по умолчанию
	DataBaseManager();
	// Деструктор по умолчанию
	~DataBaseManager();

	// Get Методы

	// получить последний элемент
	node<MusicStuff>* GetLastNode() const;

	// получить первый элемент
	node<MusicStuff>* GetFirstNode() const;

	// получение индекса последнего элемента из списка
	int GetLastIndexOfNode() const;

	// получение списка элементов с полем определенного значения
	my_list<node<MusicStuff>*>& GetSelectedList();

	// получение основного списка элементов
	my_list<MusicStuff>& GetDefaultList();

	// печать значений поля по индексу
	my_list<string>* GetDataInField(int _index) const;

	// Функции менеджера

	// сохранение базы данных в файл
	void SaveDBToFile(ostream& _out_stream);

	// считать базу данных из файла
	void ReadDBFromFile(ifstream& _read_stream);

	// считать элемень из уже существующего
	void ReadDBNodeFromNode(MusicStuff);

	// поиск элемента для удаления
	node<MusicStuff>* FindNodeToDelete(int _index);

	// удалить элемент из базы данных
	void DeleteDBNode(node<MusicStuff>* _node);
	void DeleteDBSelectedList();

	// печать в поток
	void PrintDBToConsole() const;

	// печать выборочной БД в поток
	void PrintSelectedDBToConsole() const;

	// очистить базу данных
	void ClearDB();

	// сортировать базу данных
	void SortDB(int _field_index, bool(string, string) = COMPARE::IsLower);

	// выборка элементов
	void SelectDB(int _field_index, string _value
		, bool(string, string) = COMPARE::IsEqual);

	// замена основной базы данных той, которая в выборке
	void ReplaceDefaultDataBase();

	// перерасчет индексов
	void IndexesRecalculation();
};
