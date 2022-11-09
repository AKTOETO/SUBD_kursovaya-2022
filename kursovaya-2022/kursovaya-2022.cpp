#include <iostream>
#include <fstream>
//#include "../LW4-2022/LW4/LW4.hpp"
#include"../LW4/my_list/my_list.hpp"

// Класс перечислений НОСИТЕЛЬ
enum class Storage
{
	gramophone_record = 0,	// грампластинка
	audio_cassettes,		// аудиокассета
	laser_disk				// лазерный диск
};

// Структура ИМЯ ФАМИЛИЯ
struct NameSurname
{
	char* m_name;
	char* m_surname;

	// конструктор по умолчанию
	NameSurname()
		:m_name(nullptr), m_surname(nullptr)
	{}

	// конструктор с параметрами
	NameSurname(char* _name, char* _surname)
		:m_name(_name), m_surname(_surname)
	{}

	// деструктор
	~NameSurname()
	{
		// очистка динамической памяти
		if (m_name != nullptr)
			delete m_name;

		if (m_surname != nullptr)
			delete m_surname;
	}
};

// Структура данных МУЗЫКАЛЬНЫЙ ТОВАР
struct MusicStuff
{
	Storage m_storage;		// носитель
	int m_serial_number;	// порядковый номер
	char* m_name;			// название
	NameSurname m_artist_name;// имя исполнителя
	int m_sound_time;		// время звучания в минутах
	int m_number_of_plays;	// количество воспросизведений
	int m_price;			// цена

	// конструктор без параметров
	MusicStuff()
		:m_storage(Storage(0)), m_serial_number(0), m_name(nullptr),
		m_artist_name(), m_sound_time(0),
		m_number_of_plays(0), m_price(0)
	{}

	// конструктор с параметрами
	MusicStuff(
		Storage _st, int _sn, char* _name,
		NameSurname _an, int _stime, int _nop, int _price)
		:m_storage(_st), m_serial_number(_sn), m_name(_name),
		m_artist_name(_an), m_sound_time(_stime),
		m_number_of_plays(_nop), m_price(_price)
	{}

	// деструктор
	~MusicStuff()
	{
		// очистка динамической памяти 
		if (m_name != nullptr)
			delete m_name;
	}
};

// TODO: функция взаимодействия с пользователем

// получение подстроки отделенной с помощью delim
char* get_token(char* _str, char _delim)
{
	// позиция делителя
	int delim_pos = 0;

	// поиск позиции делителя
	for (; _str[delim_pos] != '\n'; delim_pos++)
	{
		if (_str[delim_pos] == _delim)
			break;
	}

	// строка с нужной подстрокой
	char* new_str = new char[100];

	// копирование нужной строки
	strncpy(new_str, _str, delim_pos);

	//...............
}

// функция создания записи о музыкальном товаре
MusicStuff* AddMusicStaff(istream& _input_stream)
{
	// выделение памяти под объект который вернетсяв конце
	MusicStuff* music_stuff = new MusicStuff;

	// Cтруктура данных при считывании из потока ввода должна выглядеть так
	// Предполагается, что максимальная длина строки с данными не превышает
	// 100 символов
	// 
	// <КОЛИЧЕСТВО СТРОК ДАННЫХ>
	// <НОСИТЕЛЬ>:<ПОР.НОМЕР>:<НАЗВАНИЕ>:<ИСПОЛНИТЕЛЬ>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
	// ....
	// <НОСИТЕЛЬ>:<ПОР.НОМЕР>:<НАЗВАНИЕ>:<ИСПОЛНИТЕЛЬ>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
	//

	// количество строк данных
	int number_of_string;
	_input_stream >> number_of_string;
	_input_stream.get();

	// строка с веденной информацией
	char* input_str = new char[100];

	// считываем строки
	for (int i = 0; i < number_of_string; i++)
	{
		// считывание инфорамции из потока
		_input_stream.getline(input_str, 100, '\n');

		// подстрока
		char* substr;

		//...............
	}




	return new MusicStuff;
}

int main()
{
	my_list<MusicStuff*> music_list;
	return 0;
}
