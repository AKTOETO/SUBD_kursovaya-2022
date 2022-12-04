#include "music_stuff_list.h"

MusicStuffList::MusicStuffList()
{
}

void MusicStuffList::ReadFromConsole()
{
//	// количество строк
//	int numb_str = input_and_check<int>([](int num)
//		{
//			return 0 <= num && num <= INT_MAX;
//		}, "Введите количество строк: ");
//	cout << "Вводите в таком порядке:\n\
//<ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>\n";
//
//	cin.get();
//
//	// считывание данных
//	for (int i = 0; i < numb_str; i++)
//	{
//		m_list_ms.push(cin);
//	}
}

void MusicStuffList::ReadFromFile(ifstream& _read_stream)
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
			m_list_ms.push(data_str);
		}
	}
}

void MusicStuffList::ReadablePrintToStream(ostream& _out_stream)
{
	// печатаем список, если он не пуст
	if (m_list_ms.get_size() != 0)
	{
		_out_stream << table_cap;
		_out_stream << m_list_ms;
	}
	else
	{
		INFO("Список пуст");
	}
}
