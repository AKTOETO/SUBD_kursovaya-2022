#include "command.h"

command::command(string _file_name)
	:m_path_to_file_msg_folder("assets/messages/"),
	m_number_of_commands(3),
	m_str_arr(new string* [m_number_of_commands]),
	m_check_func(nullptr)
{
	m_str_arr[0] = &m_name;
	m_str_arr[1] = &m_short_description;
	m_str_arr[2] = &m_full_description;

	FillCommandData(_file_name);
}

command::command()
	:m_path_to_file_msg_folder("assets/messages/"),
	m_number_of_commands(3),
	m_str_arr(new string* [m_number_of_commands]),
	m_check_func(nullptr)
{
	m_str_arr[0] = &m_name;
	m_str_arr[1] = &m_short_description;
	m_str_arr[2] = &m_full_description;
}

command::~command()
{
}

void command::FillCommandData(string _file_name)
{
	string file_path = m_path_to_file_msg_folder + _file_name;

	ifstream fin(file_path);
	if (!fin)
	{
		cout << "\tFillCommandData: файл " << file_path << " не открылся\n";
	}

	string temp;
	int ind = 0; // индекс текущего заполняемого поля

	// считывание данных из файла
	while (fin.peek() != EOF && ind < m_number_of_commands)
	{
		// считывание строки
		getline(fin, temp);

		// если последний символ - ;
		if (temp[temp.size() - 1] == ';')
		{
			// удаляем этот символ
			temp = temp.substr(0, temp.size() - 1);

			// сохраняем полученную строку
			*m_str_arr[ind] += temp;

			// переходим к следующей команде
			ind++;
		}
		// если это не конец всей фразы
		else
		{
			*m_str_arr[ind] += temp + '\n';
		}
	}
}

ostream& operator<<(ostream& _out_stream, const command& _cmd)
{
	_out_stream << _cmd.m_name << endl
		<< _cmd.m_short_description << endl
		<< _cmd.m_full_description << endl;
	return _out_stream;
}
