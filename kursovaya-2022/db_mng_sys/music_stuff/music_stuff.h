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

	// конструктор копирования
	MusicStuff(const MusicStuff&);

	// конструктор считывающий данные из строки
	MusicStuff(string& _input_string);

	// деструктор
	~MusicStuff();

	// оператор вывода в консоль
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff);

	// Set методы
	void SetStorage(string);
	void SetSerialNumber(int);
	void SetName(string);
	void SetArtistsName(NameSurname);
	void SetSoundTime(int);
	void SetNumberOfPlays(int);
	void SetPrice(int);
	// Get методы
	string GetStorage() const;
	int GetSerialNumber() const;
	string GetName() const;
	NameSurname GetArtistsName() const;
	int GetSoundTime() const;
	int GetNumberOfPlays() const;
	int GetPrice() const;

};