#include "music_stuff.h"

MusicStuff::MusicStuff()
	:m_storage(NOT_CORRECT_DATA),
	m_serial_number(0),
	m_name(NOT_CORRECT_DATA),
	m_artist_name(),
	m_sound_time(0),
	m_number_of_plays(0),
	m_price(0)
{
}

MusicStuff::MusicStuff(const MusicStuff& _obj)
{
	m_storage = _obj.m_storage;
	m_serial_number = _obj.m_serial_number;
	m_name = _obj.m_name;
	m_artist_name = _obj.m_artist_name;
	m_sound_time = _obj.m_sound_time;
	m_number_of_plays = _obj.m_number_of_plays;
	m_price = _obj.m_price;
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

void MusicStuff::SetStorage(string _str)
{
	m_storage = _str;
}

void MusicStuff::SetSerialNumber(int _num)
{
	m_serial_number = _num;
}

void MusicStuff::SetName(string _str)
{
	m_name = _str;
}

void MusicStuff::SetArtistsName(string _str)
{
	m_artist_name.SetName(_str);
}

void MusicStuff::SetArtistsSurname(string _str)
{
	m_artist_name.SetSurname(_str);
}

void MusicStuff::SetSoundTime(int _num)
{
	m_sound_time = _num;
}

void MusicStuff::SetNumberOfPlays(int _num)
{
	m_number_of_plays = _num;
}

void MusicStuff::SetPrice(int _num)
{
	m_price = _num;
}

string MusicStuff::GetStorage() const
{
	return m_storage;
}

int MusicStuff::GetSerialNumber() const
{
	return m_serial_number;
}

string MusicStuff::GetName() const
{
	return m_name;
}

NameSurname MusicStuff::GetArtistsName() const
{
	return m_artist_name;
}

int MusicStuff::GetSoundTime() const
{
	return m_sound_time;
}

int MusicStuff::GetNumberOfPlays() const
{
	return m_number_of_plays;
}

int MusicStuff::GetPrice() const
{
	return m_price;
}

string MusicStuff::GetFormattedFormToSaveToFile() const
{
	return string(
		to_string(m_serial_number) + ':' +
		m_storage + ':' +
		m_name + ':' +
		m_artist_name.GetName() + ':' +
		m_artist_name.GetSurname() + ':' +
		to_string(m_sound_time) + ':' +
		to_string(m_number_of_plays) + ':' +
		to_string(m_price)
	);
}
