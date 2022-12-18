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
	//  онструктор по умолчанию
	DataBaseManager();
	// ƒеструктор по умолчанию
	~DataBaseManager();

	// получить последний элемент
	node<MusicStuff>* GetLastNode() const;

	// получит первый элемент
	node<MusicStuff>* GetFirstNode() const;

	// получение индекса последнего элемента из списка
	int GetLastIndexOfNode() const;

	// получение списка элементов с полем определенного значени€
	my_list<node<MusicStuff>*>& GetSelectedList();

	// получение основного списка элементов
	my_list<MusicStuff>& GetDefaultList();

	// сохранение базы данных в файл
	void SaveDBToFile(ostream& _out_stream);

	// считать базу данных из файла
	void ReadDBFromFile(ifstream& _read_stream);

	// считать элемент из строки
	void ReadDBNodeFromString(string _node);

	// считать элемень из уже существующего
	void ReadDBNodeFromNode(MusicStuff);

	// поиск элемента дл€ удалени€
	node<MusicStuff>* FindNodeToDelete(int _index);

	// удалить элемент из базы данных
	void DeleteDBNode(string _str);
	void DeleteDBNode(int _index);
	void DeleteDBNode(node<MusicStuff>* _node);
	void DeleteDBSelectedList();

	// печать в поток
	void PrintDBToConsole() const;

	// печать выборочной Ѕƒ в поток
	void PrintSelectedDBToConsole() const;

	// печать значений пол€ по индексу
	my_list<string>* GetDataInField(int _index) const;

	// очистить базу данных
	void ClearDB();

	// сортировать базу данных
	void SortDB(int _field_index, bool(string, string) = COMPARE::IsLower);

	// выборка элементов
	void SelectDB(int _field_index, string _value
		, bool(string, string) = COMPARE::IsEqual);

	// замена основной базы данных той, котора€ в выборке
	void ReplaceDefaultDataBase();

	// перерасчет индексов
	void IndexesRecalculation();
};
