// Application.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <string>
#include <iostream>
#include "../Library/Shtabs.h"
#include "../Library/Army.h"
#include "../Library/Table.h"

using namespace Shtabs;
using namespace Army;
using namespace Matrix;

const std::string Names[] = { "Unknown", "Field fighter", "Staff officer", "Field commander", "Max commander" };
const std::string Menu[] = { "1. Add a soldier", "2. Find a soldier",
"3. Delete a soldier", "4. Replace a soldier",
"5. Show all", "6. Use an Iterator",
"7. Check the constant object", "7. Get the location of infield", "0. Quit" },

Choice = "Make your choice",
Msg = "You are wrong; repeate please";

int Answer(const std::string alt[], int n);
int Add(Infield&), Find(Infield&), Remove(Infield&), Replace(Infield&), ShowAll(Infield&), Iter(Infield&),
ConstObj(Infield&);
int(*Funcs[])(Infield&) = { nullptr, Add, Find, Remove, Replace, ShowAll, Iter, ConstObj };
const int Num = sizeof(Menu) / sizeof(Menu[0]);
int main()
{
	Infield infield;
	int ind;
	try {
		while (ind = Answer(Menu, Num))
			Funcs[ind](infield);
		std::cout << "That's all. Buy!" << std::endl;
	}
	catch (const std::exception& er)
	{
		std::cout << er.what() << std::endl;
	}
	return 0;
}
int Answer(const std::string alt[], int n)
{
	int answer;
	std::string prompt = Choice;
	std::cout << "\nWhat do you want to do:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << alt[i].c_str() << std::endl;
	do {
		std::cout << prompt.c_str() << ": -> ";
		prompt = Msg;
		std::cin >> answer;
		if (!std::cin.good()) {
			std::cout << "Error when number of choice was entered; \nRepeat, please." << std::endl;
			std::cin.ignore(80, '\n');
			std::cin.clear();
		}
	} while (answer < 0 || answer >= n);
	std::cin.ignore(80, '\n');
	return answer;
}
int Add(Infield& infield)
{
	Soldier* ptr = nullptr;
	Field_fighter f1;
	Staff_officer f2;
	Field_commander f3;
	Max_commander f4;
	int key;
	int status;
	int ans;
	int team;

	std::cout << "Enter the team of a soldier -->" << std::endl;
	std::cin >> team;
	if ((team < 0) || (team > 2)) {
		std::cout << "You entered the wrong team numebr" << std::endl;
		return 0;
	}
	std::cout << "Enter the key of a soldier -->" << std::endl;
	std::cin >> key;
	std::cout << "Enter the status of a soldier -->" << std::endl;
	std::cin >> status;
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << i << '.' << Names[i] << std::endl;
	}
	std::cout << "What do you want to enter? -->";
	std::cin >> ans;

	switch (ans) {
	case 0:
		ptr = &f1;
	case 1:
		ptr = &f2;
	case 2:
		ptr = &f3;
	case 3:
		ptr = &f4;
	default:
		std::cout << "Wtf you entered some random number lol" << std::endl;
	}

	try {
		std::cin >> (*ptr);
	}
	catch (std::exception& ex){
		std::cout << ex.what() << std::endl;
	}

	infield.add_soldier(key, status, team, ptr);
	
	return 0;
}
int Find(Infield& infield)
{
	int key;
	Table::Const_Iterator it;
	const Soldier* ptr = nullptr;
	std::cout << "Enter a soldier number: --> ";
	std::cin >> key;

	try {
		infield.get_soldier(key);
	}
	catch (std::exception &ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
int Remove(Infield& infield)
{
	int key;
	Table::Const_Iterator it;
	const Soldier* ptr = nullptr;
	std::cout << "Enter a soldier number: --> ";
	std::cin >> key;

	try {
		infield.delete_soldier(key);
	}
	catch (std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	return 0;
}
int Replace(Infield& a)
{
	return 0;
}
int ShowAll(Infield& infield)
{
	Table table_1 = infield.get_table(1), table_2 = infield.get_table(2);
	Table::Const_Iterator it;
	std::cout << "In team 1:" << std::endl;
	for (it = table_1.begin(); it != table_1.end(); ++it)
		std::cout << (*it) << std::endl;
	std::cout << "In team 2:" << std::endl;
	for (it = table_2.begin(); it != table_2.end(); ++it)
		std::cout << (*it) << std::endl;
	return 0;
}
int Iter(Infield& infield)
{
	std::cout << "Calculate the number of people in total for all shapes in container" << std::endl;
	
	std::cout << "The number of people in the 1 team:" << infield.get_n(1) << std::endl;
	std::cout << "The number of people in the 2 team:" << infield.get_n(2) << std::endl;
	return 0;
}
int ConstObj(Infield& infield)
{
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
