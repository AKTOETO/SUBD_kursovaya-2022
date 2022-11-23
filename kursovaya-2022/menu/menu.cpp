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

	// функции проверки атрибутов для введенных команд
	void(*CHECK_ATTRIBUTES_FUNCTIONS[NUMBERS_OF_COMMANDS])(string) =
	{
		CheckExit,
		CheckHelp,
		CheckReadData,
		CheckPrintData,
	};

	// цикл выполнения программы
	do
	{
		// вывод сообщения запроса команды
		cout << DBMS_CONSOLE_REQUEST_COMMAND;

		// считывание команды
		getline(cin, input_all_command);

		// подготовка строки для получения слов из нее
		RemoveUnnecessarySpaces(input_all_command);

		// перевод строки в нижний регистр
		input_all_command = ToLowerCase(input_all_command);

		// получение только команды (без атрибутов)
		input_first_command = GetToken(input_all_command, ' ');

		// если введенное слово является командой и не был введен выход 
		if (
			IsCommandCorrect(input_first_command) &&
			input_first_command != ALL_COMMANDS[0]
			)
		{
			//вызов необходимой функции для команды
			CHECK_ATTRIBUTES_FUNCTIONS[GetNumberOfCommand(input_first_command)](input_all_command);
		}
		// если была введена не команда
		else if (input_first_command != ALL_COMMANDS[0])
		{
			cout << "\t" << input_first_command << NOT_CORRECT_COMMAND;
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

// проверка команды выход
void CheckExit(string _str)
{
	// параметров у нее нат, так что их 
	// не надо проверять 
}

// проверка команды ПОМОЩЬ
void CheckHelp(string _str)
{
	// если аргументы не были переданы
	// тогда выводим все команды и информацию по ним
	if (_str.size() == 0)
	{
		for (int i = 0; i < NUMBERS_OF_COMMANDS; i++)
		{
			cout << ToUpperCase(ALL_COMMANDS[i])
				<< "\t\t" << SHORT_COMM_DESCRIPTION[i]
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
			cout << DETAILED_COMMAND_DESCRIPTION[
				GetNumberOfCommand(_str)
			] << endl;
		}
		// если такого аргумента не существует
		else
		{
			cout << "\t" << _str << NOT_CORRECT_ARGUMENT;
		}
	}
}

// проверка команды	ЧТЕНИЕДАННЫХ
void CheckReadData(string _str)
{
}

// проверка команды	ПЕЧАТЬДАННЫХ
void CheckPrintData(string _str)
{
}
