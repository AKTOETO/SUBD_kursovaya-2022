#pragma once
#include "../../support_func/support_func.hpp"
#include "../name_surname/name_surname.h"

class MusicStuff
{
private:
	string m_storage;			// ��������
	int m_serial_number;		// ���������� �����
	string m_name;				// ��������
	NameSurname m_artist_name;	// ��� �����������
	int m_sound_time;			// ����� �������� � �������
	int m_number_of_plays;		// ���������� ����������������
	int m_price;				// ����

public:

	// ����������� ��� ����������
	MusicStuff();

	// ����������� �����������
	MusicStuff(const MusicStuff&);

	// ����������� ����������� ������ �� ������
	MusicStuff(string& _input_string);

	// ����������
	~MusicStuff();

	// �������� ������ � �������
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff);

	// Set ������
	void SetStorage(string);
	void SetSerialNumber(int);
	void SetName(string);
	void SetArtistsName(NameSurname);
	void SetSoundTime(int);
	void SetNumberOfPlays(int);
	void SetPrice(int);
	// Get ������
	string GetStorage() const;
	int GetSerialNumber() const;
	string GetName() const;
	NameSurname GetArtistsName() const;
	int GetSoundTime() const;
	int GetNumberOfPlays() const;
	int GetPrice() const;

};