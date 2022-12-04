#include "menu.h"

Menu::Menu()
{
	// выделение памяти под массив с описанием функций
	m_command = new command[NUMBERS_OF_COMMANDS];

	// чтение команд из файлов
	for (int i = 0; i < NUMBERS_OF_COMMANDS; i++)
	{
		m_command[i].FillCommandData(COMMAND_DESCRIPTION_FILES[i]);
	}

	// заполнение массива функций обработки команд
	m_command[0].m_check_func = &Menu::CheckExit;
	m_command[1].m_check_func = &Menu::CheckHelp;
	m_command[2].m_check_func = &Menu::CheckReadData;
	m_command[3].m_check_func = &Menu::CheckPrintData;
}

Menu::~Menu()
{
	delete[] m_command;
}

void Menu::ProgramMenu()
{
	// нужно ли показывать логотип
#ifdef SHOW_LOGO
	// вывод логотипа
	ShowLogo();
#endif

	// вывод справки о программе
	cout << DBMS_DESCRIPTION;

	// строка с введенными командами
	string input_all_command;
	// строка с введенными командами
	string input_first_command;
	// строка с введенными аттрибутами команды
	string input_attributes;

	// цикл выполнения программы
	do
	{
		// вывод сообщения запроса команды
		cout << DBMS_CONSOLE_REQUEST_COMMAND;

		// считывание команды
		getline(cin, input_all_command);

		// если строка не пустая,
		// тогда можно проверять ее на корректность
		if (input_all_command.length() != 0)
		{
			// подготовка строки для получения слов из нее
			RemoveUnnecessarySpaces(input_all_command);

			// перевод строки в нижний регистр
			input_all_command = ToLowerCase(input_all_command);

			// получение только команды (без атрибутов)
			input_first_command = GetToken(input_all_command, ' ');

			// если введенное слово является командой
			// и не был введен выход 
			if (
				IsCommandCorrect(input_first_command) &&
				input_first_command != CMD_NAME(0)
				)
			{
				//вызов необходимой функции для команды
				CMD_CHK_FUNC(input_first_command, input_all_command);
			}
			// если была введена не команда
			else if (input_first_command != CMD_NAME(0))
			{
				INFO("\""+input_first_command+"\"" + NOT_CORRECT_COMMAND);
			}
		}
	} while (input_first_command != CMD_NAME(0));
}

bool Menu::IsCommandCorrect(const string& _command)
{
	// проходимся по массиву команд
	for (int i = 0; i < NUMBERS_OF_COMMANDS; i++)
	{
		// если нашли совпадающую команду
		// выводим 1
		if (CMD_NAME(i) == _command)
		{
			return true;
		}
	}

	// иначе выводим 0
	return false;
}

int Menu::GetNumberOfCommand(const string& _command)
{
	// проходимся по массиву команд
	for (int i = 0; i < NUMBERS_OF_COMMANDS; i++)
	{
		// если нашли совпадающую команду
		// выводим i
		if (CMD_NAME(i) == _command)
		{
			return i;
		}
	}

	// иначе -1
	return -1;
}

// отображение логотипа
void Menu::ShowLogo()
{
	ifstream fin;
	int numb_of_frame = 1;
	do
	{
		system("cls");
		fin.close();
		string path = PATH_TO_LOGO_FOLDER + to_string(numb_of_frame) + "_slide.txt";
		fin.open(path);
		string frame_text;

		while (fin.peek() != EOF && fin.is_open())
		{
			getline(fin, frame_text);
			cout << frame_text << endl;
		}
		numb_of_frame++;

		Sleep(TIME_TO_SHOW_FRAME);
	} while (fin.is_open());
}

// проверка команды выход
void Menu::CheckExit(string _str)
{
	// параметров у нее нат, так что их 
	// не надо проверять 
}

// проверка команды ПОМОЩЬ
void Menu::CheckHelp(string _str)
{
	// если аргументы не были переданы
	// тогда выводим все команды и информацию по ним
	if (_str.size() == 0)
	{
		for (int i = 0; i < NUMBERS_OF_COMMANDS; i++)
		{
			cout << ToUpperCase(CMD_NAME(i))
				<< "\t\t" << CMD_SH_DECR(i)
				<< endl;
		}
	}
	// если есть какие-то аргументы
	else
	{
		// если этот аргумент - команда
		// выводим подробную инфу по ней
		if (IsCommandCorrect(_str))
		{
			cout << CMD_FL_DECR(GetNumberOfCommand(_str)) << endl;
		}
		// если такого аргумента не существует
		else
		{
			cout << "\t" << _str << NOT_CORRECT_COMMAND;
		}
	}
}

// проверка команды	ЧТЕНИЕДАННЫХ
void Menu::CheckReadData(string _str)
{
	// место считывания информации
	string temp = GetToken(_str);

	// проверка места считывания информации
	// из файла
	if (temp == "-ф")
	{
		// проверка на наличие файлового пути
		temp = GetToken(_str);

		// если путь до файла не указан
		// используем стандартный путь
		if (temp.length() == 0)
		{
			INFO("Использование стандартного файла " + db_file_path);
			temp = db_file_path;
		}

		// создаем файловый поток и
		// читаем информацию оттуда
		ifstream fin(temp);

		// если не удалось открыть файл
		if (!fin.is_open())
		{
			// вывод сообщение об ошибке
			INFO("Файл \"" + temp + "\" не был открыт");
		}
		// иначе записываем информацию из файлв в консоль
		else
		{
			m_music_list.ReadFromFile(fin);
		}

		// закрытие файла
		fin.close();
	}
	// из консоли
	else if (temp == "-к")
	{
		//TODO
	}
	else
	{
		INFO("CHECKREADDATA: неизвестный ключ: \"" + temp+"\"");
	}
}

// проверка команды	ПЕЧАТЬДАННЫХ
void Menu::CheckPrintData(string _str)
{
}