#include "music_stuff_list.h"

DataBaseManager::DataBaseManager()
{
	//m_selected_nodes = NULL;
}

DataBaseManager::~DataBaseManager()
{
	//delete m_selected_nodes;
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

my_list<node<MusicStuff>*>& DataBaseManager::GetSelectedList()
{
	return m_selected_nodes;
}

my_list<MusicStuff>& DataBaseManager::GetDefaultList()
{
	return m_default_db;
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

	IndexesRecalculation();
}

void DataBaseManager::ReadDBNodeFromNode(MusicStuff _obj)
{
	m_default_db.push(_obj);

	IndexesRecalculation();
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

void DataBaseManager::DeleteDBSelectedList()
{
	node<node<MusicStuff>*>* el = m_selected_nodes.get_begin();
	while (el)
	{
		node<node<MusicStuff>*>* next = el->get_next();
		m_default_db.delete_node(el->get_data());
		m_selected_nodes.delete_node(el);
		el = next;
	}

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
		cout << TABLE_CAP;
		cout << m_default_db;
	}
	else
	{
		FUNC_INFO("Список пуст");
	}
}

void DataBaseManager::PrintSelectedDBToConsole() const
{
	// печатаем список, если он не пуст
	if (m_default_db.get_size() != 0)
	{
		cout << TABLE_CAP;
		// создаем элемент для чтения данных из list'а
		node<node<MusicStuff>*>* cur_el = m_selected_nodes.get_begin();

		// идем по list'у, пока на наткнемся на конечный элемент
		while (cur_el != nullptr)
		{
			// вывод данных элемента
			cout << cur_el->get_data()->get_data() << '\n';

			// переход к следующему элементу
			cur_el = cur_el->get_next();
		}
	}
	else
	{
		FUNC_INFO("Список пуст");
	}
}

my_list<string>* DataBaseManager::GetDataInField(int _index) const
{
	// выходной список
	my_list<string>* out = new my_list<string>;

	// элемент для прохода всего списка
	node<MusicStuff>* el = m_default_db.get_begin();

	while (el)
	{
		string str = el->get_data().GetField(_index).GetValue();
		if (!out->is_there_element(str))
		{
			out->push(str);
		}
		el = el->get_next();
	}
	return out;
}

void DataBaseManager::ClearDB()
{
	m_default_db.clear();
}

void DataBaseManager::SortDB(int _field_index, bool _comp(string, string))
{
	node<MusicStuff>* el = m_default_db.get_begin();

	while (el)
	{
		node<MusicStuff>* el2 = m_default_db.get_begin();
		while (el2)
		{
			if (
				_comp(
					el->get_data().GetField(_field_index).GetValue(),
					el2->get_data().GetField(_field_index).GetValue()
					)
				)
			{
				MusicStuff temp = el->get_data();
				el->set_data(el2->get_data());
				el2->set_data(temp);
			}
			el2 = el2->get_next();
		}
		el = el->get_next();
	}

	IndexesRecalculation();
}

void DataBaseManager::SelectDB(int _field_index, string _value, bool _comp(string, string))
{
	// очистка выборочной базы данных
	m_selected_nodes.clear();

	// элемент для прохождения по списку
	node<MusicStuff>* temp = m_default_db.get_begin();

	// проходимся по всей базе данных и 
	// отбираем элементы со значением _value
	// в поле с индексом _field_index
	while (temp)
	{
		if (
			_comp(
				temp->get_data().GetField(_field_index).GetValue(),
				_value
				)
			)
		{
			m_selected_nodes.push(temp);
		}
		temp = temp->get_next();
	}
}

void DataBaseManager::ReplaceDefaultDataBase()
{
	node<MusicStuff>* elem = m_default_db.get_begin();

	while (elem)
	{
		node<MusicStuff>* next = elem->get_next();
		if (!m_selected_nodes.is_there_element(elem))
		{
			m_default_db.delete_node(elem);
		}
		elem = next;
	}

	IndexesRecalculation();
}

void DataBaseManager::IndexesRecalculation()
{
	node<MusicStuff>* temp = m_default_db.get_begin();
	int index = 1;
	while (temp)
	{
		MusicStuff temp_ms = temp->get_data();
		temp_ms.SetSerialNumber(index);

		temp->set_data(temp_ms);// на этой строке ошибка

		index++;
		temp = temp->get_next();
	}
}
