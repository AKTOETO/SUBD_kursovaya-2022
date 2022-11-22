#include "menu.h"

void ProgramMenu()
{
	// строка с введенными командами
	string input_all_command;
	// строка с введенными командами
	string input_first_command;
	// строка с введенными аттрибутами команды
	string input_attributes;

	// цикл выполнения программы
	do
	{
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
							<< "\t\t" << ALL_COMM_DESCRIPTION[i]
							<< endl;
					}
				}
				else
				{
					//TODO
				}
			}

		}

	} while (input_all_command != "exit");
}