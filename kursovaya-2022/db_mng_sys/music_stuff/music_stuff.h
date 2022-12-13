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

	// ����������� ����������� ������ �� ������
	MusicStuff(string& _input_string);

	// ����������
	~MusicStuff();

	// �������� ������ � �������
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff);
};