#include "music_stuff_list.h"

DataBaseManager::DataBaseManager()
{
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

void DataBaseManager::DeleteDBNode(string _str)
{
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
