#pragma once
#include "../../support_func/support_func.hpp"
#include "../../../list/my_list/my_list.hpp"

// поле базы данных
struct FieldsType
{
	int* m_number;
	string* m_string;

	FieldsType();
	~FieldsType();

	FieldsType(const FieldsType&);

	string GetValue();
};

class MusicStuff
{
private:
	// носитель
	// порядковый номер
	// название
	// имя исполнителя
	// время звучания в минутах
	// количество воспросизведений
	// цена

	// поля базы данных
	FieldsType* m_fields;

	// для упрощенного доступа к полям
#define STORAGE				m_fields[0].m_string
#define SERIAL_NUMBER		m_fields[1].m_number
#define NAME				m_fields[2].m_string
#define ARTIST_NAME			m_fields[3].m_string
#define ARTIST_SURNAME		m_fields[4].m_string
#define SOUND_TIME			m_fields[5].m_number
#define NUMBER_OF_PLAYS		m_fields[6].m_number
#define PRICE				m_fields[7].m_number

public:

	// конструктор без параметров
	MusicStuff();

	// конструктор копирования
	MusicStuff(const MusicStuff&);

	// конструктор считывающий данные из строки
	MusicStuff(string& _input_string);

	// деструктор
	~MusicStuff();

	// оператор вывода в консоль
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff);

	// оператор присваивания
	MusicStuff& operator= (const MusicStuff& _obj);

	// Set методы
	void SetStorage(string);
	void SetSerialNumber(int);
	void SetName(string);
	void SetArtistsName(string);
	void SetArtistsSurname(string);
	void SetSoundTime(int);
	void SetNumberOfPlays(int);
	void SetPrice(int);

	// Get методы
	string GetStorage() const;
	int GetSerialNumber() const;
	string GetName() const;
	string GetArtistsName() const;
	string GetArtistsSurname() const;
	int GetSoundTime() const;
	int GetNumberOfPlays() const;
	int GetPrice() const;

	FieldsType GetField(int index) const;

	string GetFormattedFormToSaveToFile() const;
};

