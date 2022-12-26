#include "menu/menu.h"
#include <Windows.h> // для считывания кириллицы

int main()
{
	setlocale(LC_ALL, "ru");

	// для считывания кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu mn;
	mn.ProgramMenu();
	
	return 0;
}
