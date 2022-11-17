#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h> // для считывания кириллицы

// подключение файла со списком
#include"../list/my_list/my_list.hpp"

// заполнение len элементов элементом symb
#define OUT_W(symb, len) fixed << setfill(symb) << setw(len)

// получение токена из строки и проерка этой строки
#define GET_DATA(str) IsDataCorrect(GetToken(input_str))
#define GET_INT_DATA(str) atoi(GET_DATA(str).c_str());

// путь до файла с базой данных
const string db_file_path = "../database/db.txt";

// файл с выводом программы
const string output_data = "../database/log.txt";

// шапка таблицы
const string table_cap = "| НОМЕР | НОСИТЕЛЬ | НАЗВАНИЕ |\
 ИМЯ/ФАМИЛИЯ ИСПОЛНИТЕЛЯ | ВРЕМЯ | КОЛ-ВО ВОСПР. | ЦЕНА |\n";

// сообщение о некорректных данных
const string not_correct_data = "----";

// ширина полей таблицы при выводе
const int width_of_fields[8] =
{
	7,10,10,12,13,7,15,6
};

// строка с коммандами
const string command_str =
"\nВведите номер комманды:\n\
\t1. Выход.\n\
\t2. Считать базу данных из файла.\n\
\t3. Считать музыкальный товар из консоли.\n\
\t4. Сортировать....\n\
\t5. Вывести базу данных.\n\
\t6. \n\
\t7. \n\
\t8. \n\
\t9. \n\
\t10.";

// строка с запросом места печати
const string print_place_str =
"\nПечать в:\n\
\t1. Консоль.\n\
\t2. Файл.";

// коды для взаимодействия пользователья с программой
enum class input_codes
{
	exit = 1,
	file_read,
	console_read,
	sort,
	print
};

// коды для места печати
enum class print_codes
{
	console = 1,
	file
};

// ввод и проверка значений
template<class T, class FUNC>
T input_and_check(const FUNC& _comp,
	const string _welcome_str, const string _err_str
	= "Было введено некорректное значение")
{
	// размер массива
	T symb;

	// вывод сообщения
	cout << _welcome_str << "\n";
	cin >> symb;

	// если было введено некорректное значение
	if (!_comp(symb)) {
		// если была введено не то, что нужно было
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}
		cout << _err_str << "\n";

		// рекурсивное обращение
		symb = input_and_check<T>(_comp, _welcome_str, _err_str);
	}
	return symb;
}

// получение подстроки отделенной с помощью delim
// и удаление этой подстроки из изначальной строки
string GetToken(string& _str, char _delim = ':')
{
	// позиция делителя
	int delim_pos = _str.find(':');

	// строка с нужной подстрокой
	// копирование нужной строки
	string new_str = _str.substr(0, delim_pos);

	// сдвиг всех символов в начало
	_str.erase(0, delim_pos + 1);

	return new_str;
}

// проверка на корректность данных
string IsDataCorrect(const string& _str)
{
	// если строка не пустая, тогда возвращаем ее
	// иначе вернем ошибочное сообщение
	return (_str.length() ? _str : not_correct_data);
}

// Структура ИМЯ ФАМИЛИЯ
struct NameSurname
{
	string m_name;
	string m_surname;

	// конструктор по умолчанию
	NameSurname()
		:m_name(not_correct_data), m_surname(not_correct_data)
	{
	}

	// конструктор с параметрами
	NameSurname(string _surname, string _name)
		:m_name(_name), m_surname(_surname)
	{
	}

	// деструктор
	~NameSurname()
	{
	}

	// оператор вывода
	friend ostream& operator<<(ostream& _out_stream, const NameSurname& _name)
	{
		_out_stream <<
			OUT_W(' ', width_of_fields[3]) << _name.m_name <<
			OUT_W(' ', width_of_fields[4]) << _name.m_surname;
		return _out_stream;
	}
};

// Структура данных МУЗЫКАЛЬНЫЙ ТОВАР
struct MusicStuff
{
	string m_storage;			// носитель
	int m_serial_number;		// порядковый номер
	string m_name;				// название
	NameSurname m_artist_name;	// имя исполнителя
	int m_sound_time;			// время звучания в минутах
	int m_number_of_plays;		// количество воспросизведений
	int m_price;				// цена

	// конструктор без параметров
	MusicStuff()
		:m_storage(not_correct_data),
		m_serial_number(0),
		m_name(not_correct_data),
		m_artist_name(),
		m_sound_time(0),
		m_number_of_plays(0),
		m_price(0)
	{
	}

	// конструктор с параметрами
	MusicStuff(
		string _st, int _sn, string _name,
		NameSurname _an, int _stime, int _nop, int _price)
		:m_storage(_st), m_serial_number(_sn), m_name(_name),
		m_artist_name(_an), m_sound_time(_stime),
		m_number_of_plays(_nop), m_price(_price)
	{
	}

	// конструктор считывающий данные из потока
	MusicStuff(istream& _input_stream)
	{
		// Cтруктура данных при считывании из потока ввода должна выглядеть так
		// Предполагается, что максимальная длина строки с данными не превышает
		// 
		// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
		// ....
		// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
		//

		// строка с веденной информацией
		string input_str;

		// считывание инфорамции из потока
		getline(_input_stream, input_str);
		input_str += ":";

		// заполнение класса MusicStuff
		m_serial_number = GET_INT_DATA(input_str);
		m_storage = GET_DATA(input_str);
		m_name = GET_DATA(input_str);
		m_artist_name = {
			GET_DATA(input_str),
			GET_DATA(input_str)
		};
		m_sound_time = GET_INT_DATA(input_str);
		m_number_of_plays = GET_INT_DATA(input_str);
		m_price = GET_INT_DATA(input_str);
	}

	// деструктор
	~MusicStuff()
	{
	}

	// оператор вывода в консоль
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff)
	{
		_out_stream
			<< "|" << OUT_W(' ', width_of_fields[0]) << _music_stuff.m_serial_number
			<< "|" << OUT_W(' ', width_of_fields[1]) << _music_stuff.m_storage
			<< "|" << OUT_W(' ', width_of_fields[2]) << _music_stuff.m_name
			<< "|" << _music_stuff.m_artist_name
			<< "|" << OUT_W(' ', width_of_fields[5]) << _music_stuff.m_sound_time
			<< "|" << OUT_W(' ', width_of_fields[6]) << _music_stuff.m_number_of_plays
			<< "|" << OUT_W(' ', width_of_fields[7]) << _music_stuff.m_price
			<< "|";

		return _out_stream;
	}
};

// считывание списка из файла
template<class T>
void read_from_file(my_list<T>& _list)
{
	// открытие файла
	ifstream fin(db_file_path);

	// если файл не был открыт
	if (!fin.is_open())
	{
		cout << "файл не был открыт\n";
		return;
	}

	// считывание данных
	while (fin.peek() != EOF)
	{
		// пропуск ненужных переводов строк
		if (fin.peek() == '\n')
		{
			fin.get();
		}
		// если не нашли переход строки
		// (строка не пустая)
		else
		{
			_list.push(fin);
		}
	}
}

// считывание списка из консоли
template<class T>
void read_from_console(my_list<T>& _list)
{
	// количество строк
	int numb_str = input_and_check<int>([](int num)
		{
			return 0 <= num && num <= INT_MAX;
		}, "Введите количество строк: ");
	cout << "Вводите в таком порядке:\n\
<ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>\n";

	cin.get();

	// считывание данных
	for (int i = 0; i < numb_str; i++)
	{
		_list.push(cin);
	}
}

// печат в поток
template<class T>
void print_list_to_stream(ostream& _out_stream, const my_list<T>& list)
{
	//_out_stream << data;
	// печатаем список, если он не пуст
	if (list.get_size() != 0)
	{
		_out_stream << table_cap;
		_out_stream << list;
	}
	else
	{
		INFO("Список пуст");
	}
}

// функция взаимодействия с пользователем
void dialog()
{
	// переменная содержащая коды действий
	input_codes in_code;

	// переменная содержащая коды места печати
	print_codes print_code;

	// список с музыкальными товарами
	my_list<MusicStuff> music_list;

	// файловый поток для печати отчетов программы в файл
	ofstream fout(output_data);

	if (!fout.is_open())
	{
		cout << "Файл " << output_data << " не был открыт\n";
	}

	do
	{
		// запрос у пользователя следующих действий
		in_code = input_codes(input_and_check<int>(
			[](int num)
			{
				return 1 <= num && num <= 10;
			},
			command_str));

		// запуск соответствующих функций
		switch (in_code)
		{
		case input_codes::exit:
			INFO("Выход из программы");
			exit(0);
			break;

		case input_codes::file_read:
			INFO("Чтение из файла " + db_file_path);
			read_from_file(music_list);
			break;

		case input_codes::console_read:
			INFO("Чтение из консоли.");
			// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
			read_from_console(music_list);
			break;

		case input_codes::sort:
			break;

		case input_codes::print:
			// запрос места печати (консоль, файл)
			print_code = print_codes(input_and_check<int>([](int _prt_code)
				{
					return 1 <= _prt_code && _prt_code <= 2;
				}, print_place_str));

			// печать в нужный поток
			switch (print_code)
			{
			case print_codes::console:
				print_list_to_stream(cout, music_list);
				break;
			case print_codes::file:
				print_list_to_stream(fout, music_list);
				break;
			default:
				INFO("PRINT: неверный код потока");
				break;
			}

		default:
			INFO("Неверный код");
			break;
		}

	} while (in_code != input_codes::exit);

	// закрытие файлового потока
	fout.close();
}

int main()
{
	setlocale(LC_ALL, "ru");

	// для считывания кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	dialog();

	return 0;
}
