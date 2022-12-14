#include "music_stuff_list.h"

DataBaseManager::DataBaseManager()
{
}

void DataBaseManager::SaveDBToFile(string _file_path)
{
}

void DataBaseManager::ResetDBFromDefaultDB()
{
	m_db_for_modifications = m_default_db;
}

void DataBaseManager::ReadDBNodeFromString(string _str)
{
	// добавление элемента в список
	m_db_for_modifications.push(_str);
}

void DataBaseManager::ReadDBNodeFromNode(MusicStuff _obj)
{
	m_db_for_modifications.push(_obj);
}

void DataBaseManager::DeleteDBNode(string _str)
{
}

void DataBaseManager::ReadDBFromFile(ifstream& _read_stream)
{
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

	// копирование основного списка в список
	// который можно будет модифицировать
	m_db_for_modifications = m_default_db;
}

void DataBaseManager::PrintDBToConsole() const
{
	// печатаем список, если он не пуст
	if (m_db_for_modifications.get_size() != 0)
	{
		cout << table_cap;
		cout << m_db_for_modifications;
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
