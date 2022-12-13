#pragma once
#include "../../support_func/support_func.hpp"
#include "../name_surname/name_surname.h"

class MusicStuff
{
private:
	string m_storage;			// носитель
	int m_serial_number;		// порядковый номер
	string m_name;				// название
	NameSurname m_artist_name;	// имя исполнителя
	int m_sound_time;			// время звучания в минутах
	int m_number_of_plays;		// количество воспросизведений
	int m_price;				// цена

public:

	// конструктор без параметров
	MusicStuff();

	// конструктор считывающий данные из строки
	MusicStuff(string& _input_string);

	// деструктор
	~MusicStuff();

	// оператор вывода в консоль
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff);
};