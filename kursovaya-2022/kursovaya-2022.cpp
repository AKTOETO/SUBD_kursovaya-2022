#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// подключение файла со списком
#include"../LW4/my_list/my_list.hpp"

// заполнение len элементов элементом symb
#define OUT_W(symb, len) fixed << setfill(symb) << setw(len)

// путь до файла с базой данных
const string db_file_path = "../database/db.txt";

// шапка таблицы
const string table_cap = "| НОМЕР | НОСИТЕЛЬ | НАЗВАНИЕ |\
 ИМЯ/ФАМИЛИЯ ИСПОЛНИТЕЛЯ | ВРЕМЯ | КОЛ-ВО ВОСПР. | ЦЕНА |\n";

// ширина полей таблицы при выводе
const int width_of_fields[8] =
{
	7,10,10,12,13,7,15,6
};

// строка с коммандами
const char* command_str =
"\nВведите номер комманды:\n\
\t1. Выход.\n\
\t2. Считать базу данных из файла.\n\
\t3. Считать музыкальный товар из консоли.\n\
\t4. Сортировать....\n\
\t5. \n\
\t6. \n\
\t7. \n\
\t8. \n\
\t9. \n\
\t10.";

// коды для взаимодействия пользователья с программой
enum class input_codes
{
	exit = 1,
	file_read,
	console_read,
	sort
};

// ввод и проверка значений
template<typename T>
T input_and_check(T _min, T _max,
	const char* welcome_str,
	const char* err_str = "Было введено некорректное значение")
{
	// размер массива
	T num;

	// вывод сообщения
	cout << welcome_str << "\n";
	cin >> num;

	// если было введено некорректное значение
	if (num > _max || num < _min) {
		// если была введена не цифра
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n');
		}

		// отчистка консоли
		//system("cls");
		cout << err_str << "\n";

		// рекурсивное обращение
		num = input_and_check(_min, _max, welcome_str, err_str);
	}
	return num;
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

// Структура ИМЯ ФАМИЛИЯ
struct NameSurname
{
	string m_name;
	string m_surname;

	// конструктор по умолчанию
	NameSurname()
		:m_name("0"), m_surname("0")
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
		:m_storage("0"), m_serial_number(0), m_name("0"),
		m_artist_name(NameSurname()), m_sound_time(0),
		m_number_of_plays(0), m_price(0)
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
		// 100 символов
		// 
		// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
		// ....
		// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
		//

		// строка с веденной информацией
		string input_str;

		// считывание инфорамции из потока
		getline(_input_stream, input_str);

		// заполнение структуры MusicStuff
		m_storage = GetToken(input_str += ':');
		m_serial_number = atoi(GetToken(input_str).c_str());
		m_name = GetToken(input_str);
		m_artist_name = { GetToken(input_str), GetToken(input_str) };
		m_sound_time = atoi(GetToken(input_str).c_str());
		m_number_of_plays = atoi(GetToken(input_str).c_str());
		m_price = atoi(GetToken(input_str).c_str());
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
		_list.push(fin);
	}
}

// функция взаимодействия с пользователем
void dialog()
{
	// переменная содержащая коды действий
	input_codes in_code;

	// список с музыкальными товарами
	my_list<MusicStuff> music_list;

	do
	{
		// запрос у пользователя следующих действий
		in_code = input_codes(input_and_check(1, 10, command_str));

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
			INFO("Чтение из консоли");
			// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>

			break;

		case input_codes::sort:
			break;

		default:
			cout << "Неверный код\n";
			break;
		}

	} while (in_code != input_codes::exit);
}

int main()
{
	setlocale(LC_ALL, "ru");

	my_list<MusicStuff> music_list;

	// открытие файла
	ifstream fin("../database/db.txt");

	if (!fin.is_open())
	{
		cout << "file not found\n";
		return -1;
	}

	// считывание данных
	while (fin.peek() != EOF)
	{
		music_list.push(fin);
	}

	// печать списка
	// <НОСИТЕЛЬ>:<ПОР.НОМЕР>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛНЮ>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
	cout << table_cap;

	cout << music_list;

	return 0;
}
