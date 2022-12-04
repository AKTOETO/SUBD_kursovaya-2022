#pragma once
#include "../../support_func/support_func.hpp"
#include "../name_surname/name_surname.h"

struct MusicStuff
{
	string m_storage;			// ��������
	int m_serial_number;		// ���������� �����
	string m_name;				// ��������
	NameSurname m_artist_name;	// ��� �����������
	int m_sound_time;			// ����� �������� � �������
	int m_number_of_plays;		// ���������� ����������������
	int m_price;				// ����

	// ����������� ��� ����������
	MusicStuff();

	// ����������� � �����������
	MusicStuff(
		string _st, int _sn, string _name,
		NameSurname _an, int _stime, int _nop, int _price);

	// ����������� ����������� ������ �� ������
	MusicStuff(string& _input_stream);

	// ����������
	~MusicStuff();

	// �������� ������ � �������
	friend ostream& operator<<(ostream& _out_stream, const MusicStuff& _music_stuff);
};