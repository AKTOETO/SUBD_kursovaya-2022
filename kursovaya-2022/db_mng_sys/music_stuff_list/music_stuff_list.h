#pragma once
#include "../music_stuff/music_stuff.h"
#include "../../../list/my_list/my_list.hpp"

struct MusicStuffList
{
	// список с музыкальными вещами
	my_list<MusicStuff> m_list_ms;

	// Конструктор по умолчанию
	MusicStuffList();

	// чтение из консоли
	void ReadFromConsole();

	// чтение из файла
	void ReadFromFile(ifstream& _read_stream);

	// печать в поток
	void ReadablePrintToStream(ostream& _out_stream);
};