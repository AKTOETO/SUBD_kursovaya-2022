#include "music_stuff_list.h"

DataBaseManager::DataBaseManager()
{
}

void DataBaseManager::SaveDBToFile(string _file_path)
{
}

void DataBaseManager::ResetDBFromDefaultDB()
{
}

void DataBaseManager::ReadDBNodeFromString(string _str)
{
	// добавление элемента в список
	m_default_db.push(_str);
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
			//m_default_db.push(data_str);
			ReadDBNodeFromString(data_str);
		}
	}
}

void DataBaseManager::PrintDBToConsole(ostream& _out_stream)
{
	// печатаем список, если он не пуст
	if (m_default_db.get_size() != 0)
	{
		_out_stream << table_cap;
		_out_stream << m_default_db;
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
