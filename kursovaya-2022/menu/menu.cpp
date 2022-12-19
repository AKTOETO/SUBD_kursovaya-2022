#include "menu.h"

Menu::Menu()
{
	// выделение памяти под массив с описанием функций
	m_command = new Command[NUMBER_OF_COMMANDS];

	// чтение команд из файлов
	for (int i = 0; i < NUMBER_OF_COMMANDS; i++)
	{
		m_command[i].FillCommandData(COMMAND_DESCRIPTION_FILES[i]);
	}

	// заполнение массива функций обработки команд
	m_command[0].SetCheckFunction(&Menu::CheckCMDExit);
	m_command[1].SetCheckFunction(&Menu::CheckCMDHelp);
	m_command[2].SetCheckFunction(&Menu::CheckCMDReadDB);
	m_command[3].SetCheckFunction(&Menu::CheckCMDPrintDBToConsole);
	m_command[4].SetCheckFunction(&Menu::CheckCMDSaveDBToFile);
	m_command[5].SetCheckFunction(&Menu::CheckCMDDeleteDBNode);
	m_command[6].SetCheckFunction(&Menu::CheckCMDClearDB);
	m_command[7].SetCheckFunction(&Menu::CheckCMDSelectFromDB);
	m_command[8].SetCheckFunction(&Menu::CheckCMDReplaceDefaultDB);
	m_command[9].SetCheckFunction(&Menu::CheckCMDSortDB);
}

Menu::~Menu()
{
	delete[] m_command;
}

void Menu::ProgramMenu()
{

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
				INFO("\"" + input_first_command + "\"" + NOT_CORRECT_COMMAND);
			}
		}

	} while (input_first_command != CMD_NAME(0));
}

bool Menu::IsCommandCorrect(const string& _command)
{
	// проходимся по массиву команд
	for (int i = 0; i < NUMBER_OF_COMMANDS; i++)
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
	for (int i = 0; i < NUMBER_OF_COMMANDS; i++)
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

void Menu::PrintNumberedArray(const string _arr[], int _size)
{
	for (int i = 0; i < _size; i++)
	{
		cout << "\t" << i + 1 << ") " << _arr[i] << "\n";
	}
}

int Menu::ReadIndexInNumberedArray(const string _str, int _min, int _max)
{
	return atoi(
		CheckableRead(
			"\t[" + _str + "]> ",
			[_min, _max](string num)
			{
				return	IsThereANumber(num) &&
				_min <= atoi(num.c_str()) &&
			atoi(num.c_str()) <= _max;
			}
	).c_str()) - 1;
}

// проверка команды выход
void Menu::CheckCMDExit(string _str)
{
	// параметров у нее нет, так что их 
	// не надо проверять 
}

// проверка команды ПОМОЩЬ
void Menu::CheckCMDHelp(string _str)
{
	// если аргументы не были переданы
	// тогда выводим все команды и информацию по ним
	if (!_str.length())
	{
		for (int i = 0; i < NUMBER_OF_COMMANDS; i++)
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
		if (IsCommandCorrect(GetToken(_str)))
		{
			cout << CMD_FL_DESCR(GetNumberOfCommand(_str)) << endl;
		}
		// если такого аргумента не существует
		else
		{
			cout << "\t\"" << _str << "\"" << NOT_CORRECT_COMMAND;
		}
	}
}

// проверка команды	ЧТЕНИЕДАННЫХ
void Menu::CheckCMDReadDB(string _str)
{
	// место считывания информации
	string temp = GetToken(_str);

	// проверка места считывания информации
	// из файла
	if (!temp.length())
	{
		// запуск режима диалога
		cout << "\n\tВыберете способ ввода информации:\n";

		// Вывод названий полей в базе данных
		PrintNumberedArray(INFO_ENTER, INFO_ENTER_SIZE);

		// номер типа считывания
		int read_type = ReadIndexInNumberedArray(
			"Откуда считывать информацию",
			1, INFO_ENTER_SIZE
		);

		// если считывание с консоли
		if (read_type == 0)
		{
			ReadDBFromConsole("");
		}
		// если считывание из файла
		else if (read_type == 1)
		{
			ReadDBFromFile("");
		}
	}
	// из стандартного файла
	else if (temp == "-ф")
	{
		// получение файлового пути
		temp = GetToken(_str);

		// Считывание из файла
		ReadDBFromFile(temp);
	}
	// если введенная информация - не ключ
	else
	{
		FUNC_INFO("неизвестный ключ: \"" + temp + "\"");
	}
}

// сохранение базы данных в файл
void Menu::CheckCMDSaveDBToFile(string _str)
{
	RETURN_IF_LIST_IS_EMPTY;

	// считывание ключа
	string temp = GetToken(_str);

	// если ключей нет
	// запуск диалога
	if (!temp.length())
	{
		INFO("\n\tВыберете место вывода информации:");

		// печать типов 
		PrintNumberedArray(FILE_PATH, FILE_PATH_SIZE);

		// ввод номера варианта
		int read_type = ReadIndexInNumberedArray(
			"Как считывать файл",
			1, FILE_PATH_SIZE
		);

		// использование файла по умолчанию
		if (read_type == 0)
		{
			WriteDBToFile("");
		}
		// если надо ввести путь из консоли
		else if (read_type == 1)
		{
			INFO("\n\tФайл должен быть в папке " + DB_FOLDER_PATH);
			WriteDBToFile(CheckableRead("\t[Введите имя файла]> "));
		}
	}
	// если введен ключ -ф
	else if (temp == "-ф")
	{
		WriteDBToFile(GetToken(_str));
	}
	else
	{
		FUNC_INFO("неизвестный ключ: \"" + temp + "\"");
	}
}

// удаление элеемнта из базы данных
void Menu::CheckCMDDeleteDBNode(string _str)
{
	RETURN_IF_LIST_IS_EMPTY;

	// как удалять: с помощью индекса
	// или с помощью поля
	string temp = GetToken(_str);

	// если ключей нет
	if (!temp.length())
	{
		// запус диалога
		INFO("\n\tВыберете тип удаления информации:");

		// печать типов
		PrintNumberedArray(DELETE_NODE, DELETE_NODE_SIZE);

		// ввод номера варианта
		int type = ReadIndexInNumberedArray(
			"Как удалять",
			1, DELETE_NODE_SIZE
		);

		// удаление по индексу
		if (type == 0)
		{
			DeleteNodeFromDBUseIndex("");
		}
		// удаление по значению поля
		else if (type == 1)
		{
			DeleteNodeFromDBUseFieldValue("");
		}
	}
	// если было введено удаление по индексу
	else if (temp == "-и")
	{
		DeleteNodeFromDBUseIndex(_str);
	}
	// если было введено удаление по полю
	else if (temp == "-п")
	{
		DeleteNodeFromDBUseFieldValue(_str);
	}
	else
	{
		FUNC_INFO("неизвестный ключ: \"" + temp + "\"");
	}

}

// проверка команды	ПЕЧАТЬДАННЫХ
void Menu::CheckCMDPrintDBToConsole(string _str)
{
	RETURN_IF_LIST_IS_EMPTY;

	m_db_manager.PrintDBToConsole();
}

// очистка базы данных
void Menu::CheckCMDClearDB(string _str)
{
	m_db_manager.ClearDB();
	INFO("База данных очищена");
}

// выбрать из базы данных определенны элементы
void Menu::CheckCMDSelectFromDB(string _str)
{
	RETURN_IF_LIST_IS_EMPTY;

	// взятие ключа
	string key = GetToken(_str);

	// диалоговое сообщение
	cout << "\n\tВозможные поля для выборки:\n";

	// Вывод названий полей в базе данных
	PrintFieldsOfDataBase();

	// индекс поля
	int number_of_field =
		atoi(
			CheckableRead(
				"\t[По какому полю осуществлять выбор]> ",
				[](string num)
				{
					return
					IsThereANumber(num) &&
				1 <= atoi(num.c_str()) &&
				atoi(num.c_str()) <= NUMBER_OF_FIELDS;
				}
	).c_str()) - 1;

	// получение списка значений поля
	my_list<string> out = *m_db_manager.GetDataInField(number_of_field);

	// печать списка
	cout << "\n\tУникальные значения этого поля:\n";
	int ind = 1;
	out.for_each([&ind](node<string>* el)
		{
			cout << "\t" << ind++ << ") " << el->get_data() << "\n";
		}
	);

	// какое значение искать в поле
	int number_of_value =
		atoi(
			CheckableRead(
				"\t[Какое значение использовать в поле]> ",
				[&out](string num)
				{
					return
					IsThereANumber(num) &&
				1 <= atoi(num.c_str()) &&
				atoi(num.c_str()) <= out.get_size();
				}
	).c_str()) - 1;

	// значение поля под индексом number_of_value 
	// с которым будем сравнивать
	string field_value = out.get_element_by_index(number_of_value)->get_data();

	cout << "\n\tЕсли неравенство верно, происходит выбор. Типы сравнений:\n";
	// вывод типов сравнений
	for (int i = 0; i < NUMBER_OF_COMPARISONS; i++)
	{
		cout << "\t" << i + 1 << ") " << "элементы " <<
			NAMES_OF_COMPARISONS[i] << ' ' << field_value << "\n";
	}

	// выбор типа сравнения элементов
	int comp_type =
		atoi(
			CheckableRead(
				"\t[Какой тип сравнения использовать]> ",
				[](string num)
				{
					return
					IsThereANumber(num) &&
				1 <= atoi(num.c_str()) &&
				atoi(num.c_str()) <= NUMBER_OF_COMPARISONS;
				}
	).c_str()) - 1;

	// выборка элементов списка с определенным
	// значением определенного поля
	m_db_manager.SelectDB
	(
		number_of_field,
		field_value,
		COMPARE::COMPARISONS[comp_type]
	);

	cout << "\n[Выбраны следующие элементы]> \n";

	// Вывод шапки таблицы
	cout << TABLE_CAP;

	// печать базы данных
	if (!m_db_manager.GetSelectedList().is_empty())
	{
		m_db_manager.GetSelectedList().for_each([](auto _el)
			{
				cout << _el->get_data()->get_data() << endl;
			}
		);
	}
	else
	{
		INFO("\t Такие элементы не найдены");
	}
}

// заменить исходную бд полученной из выборки
void Menu::CheckCMDReplaceDefaultDB(string _str)
{
	RETURN_IF_LIST_IS_EMPTY

		// вызов функции выборки
		if (m_db_manager.GetSelectedList().is_empty())
		{
			CheckCMDSelectFromDB("");
		}
	// иначе печать базы данных
		else
		{
			m_db_manager.PrintSelectedDBToConsole();
		}

	// получение ответа
	string answ = CheckableRead(
		"\t[Готовы ли вы оставить только эти элементы? (да/нет)]> ",
		[](string str)
		{
			return ToLowerCase(str) == "да" || ToLowerCase(str) == "нет";
		}
	);

	if (answ == "да")
	{
		INFO("Замена текущей базы");
		m_db_manager.ReplaceDefaultDataBase();
	}
	else
	{
		INFO("Элемнеты не заменены")
	}

}

void Menu::CheckCMDSortDB(string _str)
{
	RETURN_IF_LIST_IS_EMPTY

		// Вывод названий полей в базе данных
		PrintFieldsOfDataBase();

	// индекс поля
	int number_of_field =
		atoi(
			CheckableRead(
				"\t[По какому полю осуществлять сортировку]> ",
				[](string num)
				{
					return
					IsThereANumber(num) &&
				1 <= atoi(num.c_str()) &&
				atoi(num.c_str()) <= NUMBER_OF_FIELDS;
				}
	).c_str()) - 1;

	// вывод типов сортировок
	for (int i = 0; i < NUMBER_OF_SORTS; i++)
	{
		cout << "\t" << i + 1 << ") " << NAMES_OF_SORTS[i] << endl;
	}

	// взятие типа сортировки
	int sort_type =
		atoi(
			CheckableRead(
				"\t[По как сортировать]> ",
				[](string num)
				{
					return
					IsThereANumber(num) &&
				1 <= atoi(num.c_str()) &&
				atoi(num.c_str()) <= NUMBER_OF_SORTS;
				}
	).c_str()) - 1;


	// сортировка
	m_db_manager.SortDB(number_of_field, COMPARE::COMPARISONS[sort_type]);
}

void Menu::ReadDBFromConsole(string _str)
{
	INFO("\n\tВвод с консоли:");
	MusicStuff ms;

	// считывание места хранения
	ms.SetStorage(
		CheckableRead(
			"\t[Введите НОСИТЕЛЬ]> "
		)
	);

	// запись порядкового номера
	ms.SetSerialNumber(
		m_db_manager.GetLastIndexOfNode() + 1
	);

	// считывание названия трека
	ms.SetName(
		CheckableRead(
			"\t[Введите НАЗВАНИЕ ТРЕКА]> "
		)
	);

	// считывание имени исполнителя
	ms.SetArtistsName(
		CheckableRead(
			"\t[Введите ИМЯ исполнителя]> "
		)
	);

	// считывание фамилии исполнителя
	ms.SetArtistsSurname(
		CheckableRead(
			"\t[Введите ФАМИЛИЮ исполнителя]> "
		)
	);

	// считывание времени проигрывания трека
	ms.SetSoundTime(
		atoi(
			CheckableRead(
				"\t[Введите ВРЕМЯ ЗВУЧАНИЯ (минуты)]> ",
				IsThereANotNegativeNumber
			).c_str()
		)
	);

	// считывание количества воспроизведений
	ms.SetNumberOfPlays(
		atoi(
			CheckableRead(
				"\t[Введите КОЛИЧЕСТВО ВОСПРОИЗВЕДЕНИЙ]> ",
				IsThereANotNegativeNumber
			).c_str()
		)
	);

	// считывание цены
	ms.SetPrice(
		atoi(
			CheckableRead(
				"\t[Введите ЦЕНУ (рубли)]> ",
				IsThereANotNegativeNumber
			).c_str()
		)
	);

	// запись считанного элемента в список
	m_db_manager.ReadDBNodeFromNode(ms);
}

void Menu::ReadDBFromFile(string _str)
{
	INFO("\n\tЧтение из файла");

	// проверка на наличие файлового пути
	string temp = GetToken(_str);

	// если путь до файла не указан
	// запуск диалога
	if (!temp.length())
	{
		// печать типов 
		PrintNumberedArray(FILE_PATH, FILE_PATH_SIZE);

		// ввод номера варианта
		int read_type = ReadIndexInNumberedArray(
			"Как считывать файл",
			1, FILE_PATH_SIZE
		);

		// использование файла по умолчанию
		if (read_type == 0)
		{
			INFO("\n\tИспользование стандартного файла " + DB_FILE_PATH);
			OpenFileAndReadDataToDB(DB_FILE_PATH);
		}
		// если надо ввести путь из консоли
		else if (read_type == 1)
		{
			INFO("\n\tФайл должен быть в папке " + DB_FOLDER_PATH);
			OpenFileAndReadDataToDB(
				DB_FOLDER_PATH + CheckableRead("\t[Введите имя файла]> ")
			);
		}
	}
	// если указан путь до файла
	else
	{
		temp = GetToken(temp);
		temp = DB_FOLDER_PATH + temp;
		INFO("Использование файла " + temp);
		OpenFileAndReadDataToDB(temp);
	}
}

void Menu::OpenFileAndReadDataToDB(string _str)
{
	// создаем файловый поток и
	// читаем информацию оттуда
	ifstream fin(_str);

	// если не удалось открыть файл
	if (!fin.is_open())
	{
		// вывод сообщение об ошибке
		INFO("Файл \"" + _str + "\" не был открыт");
	}
	// иначе записываем информацию из файлв в консоль
	else
	{
		m_db_manager.ReadDBFromFile(fin);
		INFO("Чтение выполнено");
	}

	// закрытие файла
	fin.close();
}

void Menu::WriteDBToFile(string _str)
{
	INFO("\n\tПечать в файл");

	// получение файлового пути
	string temp = GetToken(_str);

	// если путь до файла не указан
	// запуск диалога
	if (!temp.length())
	{

		INFO("Использование стандартного файла " + OUT_DB_FILE_PATH);
		OpenFileAndWriteDBToFile(OUT_DB_FILE_PATH);

	}
	// если указан путь до файла
	else
	{
		temp = GetToken(temp);
		temp = DB_FOLDER_PATH + temp;
		INFO("Использование файла " + temp);
		OpenFileAndWriteDBToFile(temp);
	}
}

void Menu::OpenFileAndWriteDBToFile(string _str)
{
	// создаем файловый поток
	ofstream fout(_str);

	// если не удалось открыть файл
	if (!fout.is_open())
	{
		// вывод сообщение об ошибке
		INFO("Файл \"" + _str + "\" не был открыт");
	}
	// иначе записываем информацию из файлв в консоль
	else
	{
		m_db_manager.SaveDBToFile(fout);
		INFO("Запись выполнена");
	}

	// закрытие файла
	fout.close();
}

void Menu::DeleteNodeFromDBUseIndex(string _str)
{
	// получение индекса
	string temp = GetToken(_str);

	// если нет индекса
	if (!temp.length())
	{
		// запуск диалога
		INFO("\n\tВыберете индекс элемента:");

		// печать списка
		CheckCMDPrintDBToConsole("");

		// ввод номера варианта
		int index = ReadIndexInNumberedArray(
			"Индекс удаляемого элемента",
			1, m_db_manager.GetDefaultList().get_size()
		);

		// поиск элемента для удаления
		node<MusicStuff>* nd = m_db_manager.FindNodeToDelete(index);

		// если такого индекса нет
		if (!nd)
		{
			FUNC_INFO("элемент не найден");
			return;
		}

		// уточнение у пользователя
		// готов ли он удалить эти элементы			
		INFO("\n\tЭлемент для удаления:");
		cout << TABLE_CAP << endl;
		cout << nd->get_data() << endl;

		// получение ответа
		string answ = CheckableRead(
			"\t[Готовы ли вы удалить его? (да/нет)]> ",
			[](string str)
			{
				return ToLowerCase(str) == "да" || ToLowerCase(str) == "нет";
			}
		);

		// если ответ да
		if (answ == "да")
		{
			m_db_manager.DeleteDBNode(nd);
		}
		else
		{
			INFO("Элементы не удалены")
		}

	}
	// если был введен индекс и он - число
	else if (IsThereANotNegativeNumber(temp))
	{
		// поиск элемента для удаления
		node<MusicStuff>* nd =
			m_db_manager.FindNodeToDelete(atoi(temp.c_str()) - 1);

		// если такого индекса нет
		if (!nd)
		{
			FUNC_INFO("Элемент не найден");
			return;
		}

		m_db_manager.DeleteDBNode(nd);
	}
	else
	{
		FUNC_INFO("неизвестный ключ: \"" + temp + "\"");
	}
}

void Menu::DeleteNodeFromDBUseFieldValue(string _str)
{
	// процедура выборки
	CheckCMDSelectFromDB("");

	// получение ответа
	string answ = CheckableRead(
		"\t[Готовы ли вы удалить их? (да/нет)]> ",
		[](string str)
		{
			return ToLowerCase(str) == "да" || ToLowerCase(str) == "нет";
		}
	);

	if (answ == "да")
	{
		// удаление выбранных элементов из списка
		m_db_manager.DeleteDBSelectedList();
	}
	else
	{
		INFO("Элементы не удалены")
	}
}
