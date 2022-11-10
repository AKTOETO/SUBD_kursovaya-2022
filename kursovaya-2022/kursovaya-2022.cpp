#include <iostream>
#include <fstream>
#include <string>
//#include "../LW4-2022/LW4/LW4.hpp"
#include"../LW4/my_list/my_list.hpp"

// Структура ИМЯ ФАМИЛИЯ
struct NameSurname
{
	string m_name;
	string m_surname;

	// конструктор по умолчанию
	NameSurname()
		:m_name(""), m_surname("")
	{
	}

	// конструктор с параметрами
	NameSurname(string _name, string _surname)
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
		_out_stream << _name.m_name << " "
			<< _name.m_surname;
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
		:m_storage(""), m_serial_number(0), m_name(""),
		m_artist_name(), m_sound_time(0),
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

	// деструктор
	~MusicStuff()
	{
	}

	// оператор вывода в консоль
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff)
	{
		_out_stream << _music_stuff.m_storage << " "
			<< _music_stuff.m_serial_number << " "
			<< _music_stuff.m_name << " "
			<< _music_stuff.m_artist_name << " "
			<< _music_stuff.m_sound_time << " "
			<< _music_stuff.m_number_of_plays << " "
			<< _music_stuff.m_price << endl;

		return _out_stream;
	}
};

// TODO: функция взаимодействия с пользователем

// получение подстроки отделенной с помощью delim
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

// функция создания записи о музыкальном товаре
MusicStuff AddMusicStaff(istream& _input_stream)
{
	// выделение памяти под объект который вернетсяв конце
	MusicStuff music_stuff;

	// Cтруктура данных при считывании из потока ввода должна выглядеть так
	// Предполагается, что максимальная длина строки с данными не превышает
	// 100 символов
	// 
	// <КОЛИЧЕСТВО СТРОК ДАННЫХ>
	// <НОСИТЕЛЬ>:<ПОР.НОМЕР>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛНЮ>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
	// ....
	// <НОСИТЕЛЬ>:<ПОР.НОМЕР>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛНЮ>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
	//

	// количество строк данных
	int number_of_string;
	_input_stream >> number_of_string;
	_input_stream.get();

	// строка с веденной информацией
	string input_str;

	// считываем строки
	for (int i = 0; i < number_of_string; i++)
	{
		// считывание инфорамции из потока
		getline(_input_stream, input_str);
		input_str += ':';

		// заполнение структуры MusicStuff
		//music_stuff->m_storage = get_token(input_str);
		//music_stuff->m_serial_number = atoi(get_token(input_str).c_str());
		/*music_stuff = {
			GetToken(input_str),
			atoi(GetToken(input_str).c_str()),
			GetToken(input_str),
			NameSurname(GetToken(input_str),GetToken(input_str)),
			atoi(GetToken(input_str).c_str()),
			atoi(GetToken(input_str).c_str()),
			atoi(GetToken(input_str).c_str())
		};*/
		music_stuff.m_storage = GetToken(input_str);
		music_stuff.m_serial_number = atoi( GetToken(input_str).c_str());
		music_stuff.m_name = GetToken(input_str);
		music_stuff.m_artist_name = { GetToken(input_str), GetToken(input_str) };
		music_stuff.m_sound_time = atoi(GetToken(input_str).c_str());
		music_stuff.m_number_of_plays = atoi(GetToken(input_str).c_str());
		music_stuff.m_price = atoi(GetToken(input_str).c_str());
	}
	return music_stuff;
}

int main()
{
	setlocale(LC_ALL, "ru");

	my_list<MusicStuff> music_list;

	ifstream fin("../database/db.txt");

	if (!fin.is_open())
	{
		cout << "file not found\n";
		return -1;
	}

	music_list.push(AddMusicStaff(fin));

	cout << music_list;

	return 0;
}
