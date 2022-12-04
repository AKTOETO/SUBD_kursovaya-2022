#pragma once
#include "../../support_func/support_func.hpp"
#include "../name_surname/name_surname.h"

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
	MusicStuff();

	// конструктор с параметрами
	MusicStuff(
		string _st, int _sn, string _name,
		NameSurname _an, int _stime, int _nop, int _price);

	// конструктор считывающий данные из потока
	MusicStuff(string& _input_stream);

	// деструктор
	~MusicStuff();

	// оператор вывода в консоль
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff);
};