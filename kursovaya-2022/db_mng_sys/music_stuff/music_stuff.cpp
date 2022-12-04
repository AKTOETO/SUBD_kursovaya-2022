#include "music_stuff.h"

MusicStuff::MusicStuff()
	:m_storage(not_correct_data),
	m_serial_number(0),
	m_name(not_correct_data),
	m_artist_name(),
	m_sound_time(0),
	m_number_of_plays(0),
	m_price(0)
{
}

MusicStuff::MusicStuff(string _st, int _sn, string _name, NameSurname _an, int _stime, int _nop, int _price)
	:m_storage(_st), m_serial_number(_sn), m_name(_name),
	m_artist_name(_an), m_sound_time(_stime),
	m_number_of_plays(_nop), m_price(_price)
{
}

MusicStuff::MusicStuff(string& _input_string)
{
	// Cтруктура данных при считывании из потока ввода должна выглядеть так
	// Предполагается, что максимальная длина строки с данными не превышает
	// 
	// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
	// ....
	// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>

	//_input_string += ":";

	// заполнение класса MusicStuff
	m_serial_number = GET_INT_DATA(_input_string);
	m_storage = GET_DATA(_input_string);
	m_name = GET_DATA(_input_string);
	m_artist_name = {
		GET_DATA(_input_string),
		GET_DATA(_input_string)
	};
	m_sound_time = GET_INT_DATA(_input_string);
	m_number_of_plays = GET_INT_DATA(_input_string);
	m_price = GET_INT_DATA(_input_string);
}

MusicStuff::~MusicStuff()
{
}

ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff)
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
