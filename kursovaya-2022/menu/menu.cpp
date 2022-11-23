#include "menu.h"

void ProgramMenu()
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

		// подготовка строки для получения слов из нее
		RemoveUnnecessarySpaces(input_all_command);

		// получение только команды (без атрибутов)
		input_first_command = GetToken(input_all_command, ' ');

		// если не был введен выход
		if (input_first_command != ALL_COMMANDS[0])
		{
			// если введена команда ПОМОЩЬ
			if (input_first_command == ALL_COMMANDS[1])
			{
				// если аргументы не были переданы
				// тогда выводим все команды и информацию по ним
				if (!input_all_command.size())
				{
					for (int i = 0; i < NUMBERS_OF_COMMANDS; i++)
					{
						cout << ToUpperCase(ALL_COMMANDS[i])
							<< "\t\t" << SHORT_COMM_DESCRIPTION[i]
							<< endl;
					}
				}
				else
				{
					//TODO
				}
			}

		}

	} while (input_first_command != ALL_COMMANDS[0]);
}

// отображение логотипа
void ShowLogo()
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
