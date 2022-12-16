#include "music_stuff.h"

MusicStuff::MusicStuff()
{
	/*m_storage.m_string = new string;
	m_serial_number.m_string = new string;
	m_name.m_string = new string;
	m_artist_name.m_namesurname = new NameSurname;
	m_sound_time.m_number = new int;
	m_number_of_plays.m_number = new int;
	m_price.m_number = new int;*/

	m_fields = new FieldsType[NUMBER_OF_FIELDS];

	m_fields[0].m_string = new string;		// носитель
	m_fields[1].m_number = new int;			// порядковый номер
	m_fields[2].m_string = new string;		// название
	m_fields[3].m_string = new string;		// имя исполнителя
	m_fields[4].m_string = new string;		// фамилия исполнителя
	m_fields[5].m_number = new int;			// время звучания в минутах
	m_fields[6].m_number = new int;			// количество воспросизведений
	m_fields[7].m_number = new int;			// цена
}

MusicStuff::MusicStuff(const MusicStuff& _obj)
	:MusicStuff()
{
	*this = _obj;
	/**STORAGE		 = *_obj.STORAGE;
	*SERIAL_NUMBER	 = *_obj.SERIAL_NUMBER;
	*NAME			 = *_obj.NAME;
	*ARTIST_NAME	 = *_obj.ARTIST_NAME;
	*ARTIST_SURNAME	 = *_obj.ARTIST_SURNAME;
	*SOUND_TIME		 = *_obj.SOUND_TIME;
	*NUMBER_OF_PLAYS = *_obj.NUMBER_OF_PLAYS;
	*PRICE			 = *_obj.PRICE;*/
}

MusicStuff::MusicStuff(string& _input_string)
	:MusicStuff()
{	
	// Cтруктура данных при считывании из потока ввода должна выглядеть так
	// Предполагается, что максимальная длина строки с данными не превышает
	// 
	// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>
	// ....
	// <ПОР.НОМЕР>:<НОСИТЕЛЬ>:<НАЗВАНИЕ>:<ИМЯ ИСПОЛН.>:<ФАМИЛ. ИСПОЛН.>:<ВРЕМЯ>:<ВОСПРОИЗВ.>:<ЦЕНА>

	// заполнение класса MusicStuff
	*SERIAL_NUMBER = GET_INT_DATA(_input_string);
	*STORAGE = GET_DATA(_input_string);
	*NAME = GET_DATA(_input_string);
	*ARTIST_NAME = GET_DATA(_input_string);
	*ARTIST_SURNAME = GET_DATA(_input_string);
	*SOUND_TIME = GET_INT_DATA(_input_string);
	*NUMBER_OF_PLAYS = GET_INT_DATA(_input_string);
	*PRICE = GET_INT_DATA(_input_string);
}

MusicStuff::~MusicStuff()
{
	delete[] m_fields;
}

ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff)
{
	_out_stream
		<< "|" << OUT_W(' ', width_of_fields[0]) << *_music_stuff.SERIAL_NUMBER
		<< "|" << OUT_W(' ', width_of_fields[1]) << *_music_stuff.STORAGE
		<< "|" << OUT_W(' ', width_of_fields[2]) << *_music_stuff.NAME
		<< "|" << OUT_W(' ', width_of_fields[3]) << *_music_stuff.ARTIST_NAME
		<< "|" << OUT_W(' ', width_of_fields[4]) << *_music_stuff.ARTIST_SURNAME
		<< "|" << OUT_W(' ', width_of_fields[5]) << *_music_stuff.SOUND_TIME
		<< "|" << OUT_W(' ', width_of_fields[6]) << *_music_stuff.NUMBER_OF_PLAYS
		<< "|" << OUT_W(' ', width_of_fields[7]) << *_music_stuff.PRICE
		<< "|";

	return _out_stream;
}

MusicStuff& MusicStuff::operator=(const MusicStuff& _obj)
{

	*STORAGE			= *_obj.STORAGE;
	*SERIAL_NUMBER		= *_obj.SERIAL_NUMBER;
	*NAME				= *_obj.NAME;
	*ARTIST_NAME		= *_obj.ARTIST_NAME;
	*ARTIST_SURNAME		= *_obj.ARTIST_SURNAME;
	*SOUND_TIME			= *_obj.SOUND_TIME;
	*NUMBER_OF_PLAYS	= *_obj.NUMBER_OF_PLAYS;
	*PRICE				= *_obj.PRICE;

	return *this;
}

void MusicStuff::SetStorage(string _str)
{
	*STORAGE = _str;
}

void MusicStuff::SetSerialNumber(int _num)
{
	*SERIAL_NUMBER = _num;
}

void MusicStuff::SetName(string _str)
{
	*NAME = _str;
}

void MusicStuff::SetArtistsName(string _str)
{
	*ARTIST_NAME = _str;
}

void MusicStuff::SetArtistsSurname(string _str)
{
	*ARTIST_SURNAME = _str;
}

void MusicStuff::SetSoundTime(int _num)
{
	*SOUND_TIME = _num;
}

void MusicStuff::SetNumberOfPlays(int _num)
{
	*NUMBER_OF_PLAYS = _num;
}

void MusicStuff::SetPrice(int _num)
{
	*PRICE = _num;
}

string MusicStuff::GetStorage() const
{
	return *STORAGE;
}

int MusicStuff::GetSerialNumber() const
{
	return *SERIAL_NUMBER;
}

string MusicStuff::GetName() const
{
	return *NAME;
}

string MusicStuff::GetArtistsName() const
{
	return *ARTIST_NAME;
}

string MusicStuff::GetArtistsSurname() const
{
	return *ARTIST_SURNAME;
}

int MusicStuff::GetSoundTime() const
{
	return *SOUND_TIME;
}

int MusicStuff::GetNumberOfPlays() const
{
	return *NUMBER_OF_PLAYS;
}

int MusicStuff::GetPrice() const
{
	return *PRICE;
}

FieldsType MusicStuff::GetField(int index) const
{
	if (0 <= index && index <= NUMBER_OF_FIELDS)
	{
		return m_fields[index];
	}
	return FieldsType();
}

string MusicStuff::GetFormattedFormToSaveToFile() const
{
	return string(
		to_string(*SERIAL_NUMBER) + ':' +
		*STORAGE + ':' +
		*NAME + ':' +
		*ARTIST_NAME + ':' +
		*ARTIST_SURNAME + ':' +
		to_string(*SOUND_TIME) + ':' +
		to_string(*NUMBER_OF_PLAYS) + ':' +
		to_string(*PRICE)
	);
}

FieldsType::FieldsType()
	:m_number(NULL), m_string(NULL)
{
}

FieldsType::~FieldsType()
{
	if(m_number != NULL)
		delete m_number;
	if(m_string != NULL)
		delete m_string;
}

FieldsType::FieldsType(const FieldsType& _obj)
	:FieldsType()
{
	if (_obj.m_number)
	{
		if (m_number) delete m_number;
		m_number = new int;
		*m_number = *_obj.m_number;
	}
	if (_obj.m_string)
	{
		if (m_string) delete m_string;
		m_string = new string;
		*m_string = *_obj.m_string;
	}
}

string FieldsType::GetValue()
{
	if (m_number)
		return to_string(*m_number);
	if (m_string)
		return *m_string;
	return "";
}
