#include <iostream>
#include <locale>
#include "RLE.h"
#include "LZ77.h"
#include "LZ78.h"

using namespace std;

void printMenu();

int main() {
	setlocale(LC_ALL, "Russian");

	string input = "WWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
	string output = "";
	//output = RLE::Encode(input);
	//cout << output << endl;
	//output = RLE::Decode(output);
	//cout << output << endl;
	//cout << input.compare(output);

	input = "кукуркукурекурекун";
	list<Node78> encoded = LZ78::Encode(input);
	cout << input.compare(LZ78::Decode(encoded)) << endl;
	cout << input << endl << LZ78::Decode(encoded) << endl;
	
	//int task = -1;
	//while (true)
	//{
	//	system("cls");
	//	printMenu();
	//	cout << "Enter a task number: ";
	//	cin >> task;
	//	switch (task)
	//	{
	//	default:
	//		cout << "Incorrect task number!" << endl;
	//		break;
	//	}
	//	system("pause");
	//}
}