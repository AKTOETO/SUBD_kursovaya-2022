#include "music_stuff_list.h"

DataBaseManager::DataBaseManager()
{
}

DataBaseManager::~DataBaseManager()
{
}

node<MusicStuff>* DataBaseManager::GetLastNode() const
{
	return m_default_db.get_end();
}

node<MusicStuff>* DataBaseManager::GetFirstNode() const
{
	return m_default_db.get_begin();
}

int DataBaseManager::GetLastIndexOfNode() const
{
	node<MusicStuff>* el = GetLastNode();
	int number = 1;
	if (el != NULL)
	{
		number = el->get_data().GetSerialNumber();
	}
	return number;
}

int DataBaseManager::GetSizeOfDataBase() const
{
	return m_default_db.get_size();
}

void DataBaseManager::SaveDBToFile(ostream& _out_stream)
{
	node<MusicStuff>* el = m_default_db.get_begin();
	while (el)
	{
		// вывод форматированной строки в файловый поток
		_out_stream <<
			el->get_data().GetFormattedFormToSaveToFile()
			<< endl;

		// переход к следующему элементу
		el = el->get_next();
	}
}

void DataBaseManager::ReadDBNodeFromString(string _str)
{
	// добавление элемента в список
	m_default_db.push(_str);
}

void DataBaseManager::ReadDBNodeFromNode(MusicStuff _obj)
{
	m_default_db.push(_obj);
}

node<MusicStuff>* DataBaseManager::FindNodeToDelete(int _index)
{
	// если индекс больше или равен размеру списка
	if (_index >= m_default_db.get_size())
	{
		FUNC_INFO(
			"индекс " + to_string(_index + 1) +
			" больше или равен размеру списка " +
			to_string(m_default_db.get_size())
		);
		return NULL;
	}

	// поиск элемента для удаления
	node<MusicStuff>* temp = m_default_db.get_begin();
	int index = 0;
	while (temp && index < _index)
	{
		index++;
		temp = temp->get_next();
	}

	return temp;
}

void DataBaseManager::DeleteDBNode(string _str)
{
	IndexesRecalculation();
}

void DataBaseManager::DeleteDBNode(int _index)
{
	// удаление необходимого элемента
	m_default_db.delete_node(FindNodeToDelete(_index));

	IndexesRecalculation();
}

void DataBaseManager::DeleteDBNode(node<MusicStuff>* _node)
{
	m_default_db.delete_node(_node);
	IndexesRecalculation();
}

void DataBaseManager::ReadDBFromFile(ifstream& _read_stream)
{
	// очистка базы данных перед чтением
	m_default_db.clear();

	// считывание данных
	while (_read_stream.peek() != EOF)
	{
		// пропуск ненужных переводов строк
		if (_read_stream.peek() == '\n')
		{
			_read_stream.get();
		}
		// если не нашли переход строки
		// (строка не пустая)
		else
		{
			// считываем строку с информацией
			string data_str;
			getline(_read_stream, data_str);

			// записываем эту информацию в список
			m_default_db.push(data_str);
		}
	}
}

void DataBaseManager::PrintDBToConsole() const
{
	// печатаем список, если он не пуст
	if (m_default_db.get_size() != 0)
	{
		cout << table_cap;
		cout << m_default_db;
	}
	else
	{
		INFO("Список пуст");
	}
}

void DataBaseManager::ClearDB()
{
}

void DataBaseManager::SortDB(string _str)
{
}

void DataBaseManager::SelectDB(string _str)
{
}

void DataBaseManager::IndexesRecalculation()
{
	node<MusicStuff>* temp = m_default_db.get_begin();
	int index = 1;
	while (temp)
	{
		MusicStuff temp_ms = temp->get_data();
		temp_ms.SetSerialNumber(index);
		temp->set_data(temp_ms);

		index++;
		temp = temp->get_next();
	}
}
