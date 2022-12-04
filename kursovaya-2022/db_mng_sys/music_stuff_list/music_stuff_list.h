#pragma once
#include "../music_stuff/music_stuff.h"
#include "../../../list/my_list/my_list.hpp"

struct MusicStuffList
{
	// ������ � ������������ ������
	my_list<MusicStuff> m_list_ms;

	// ����������� �� ���������
	MusicStuffList();

	// ������ �� �������
	void ReadFromConsole();

	// ������ �� �����
	void ReadFromFile(ifstream& _read_stream);

	// ������ � �����
	void ReadablePrintToStream(ostream& _out_stream);
};