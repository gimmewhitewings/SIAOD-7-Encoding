#include <iostream>
#include <locale>
#include "RLE.h"
#include "LZ77.h"
#include "LZ78.h"
#include "ShannonFano.h"
#include "Huffman.h"

using namespace std;

void printMenu();

void RLETest();

void LZ77Test();

void LZ78Test();

void ShannonFanoTest();

void HuffmanTest();

int main() {
	setlocale(LC_ALL, "Russian");

    int task = -1;
    while (true)
    {
    	system("cls");
    	printMenu();
    	cout << "Enter a task number: ";
    	cin >> task;
    	switch (task)
    	{
		case 1:
			RLETest();
			break;
		case 2:
			LZ77Test();
			break;
		case 3:
			LZ78Test();
			break;
		case 4:
			ShannonFanoTest();
			break;
		case 5:
			HuffmanTest();
			break;
		case 0:
			cout << "Goodbye!" << endl;
			return 0;
    	default:
    		cout << "Incorrect task number!" << endl;
    		break;
    	}
    	system("pause");
    }
}

void printMenu()
{
	cout << "1. RLE" << endl;
	cout << "2. LZ77" << endl;
	cout << "3. LZ78" << endl;
	cout << "4. Shannon-Fano" << endl;
	cout << "5. Huffman" << endl;
	cout << "0. Exit" << endl;
}

void RLETest()
{
    cout << "RLE" << endl;
    string input = "WWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
    string output = "";
    cout << "input string: " << input << endl;
    output = RLE::Encode(input);
    cout << "encoded: " << output << endl;
    output = RLE::Decode(output);
    cout << "decoded: " << output << endl << endl;
}

void LZ77Test()
{
	cout << "LZ77" << endl;
	string input = "0001010010101001101";
	list<Node77> encoded77 = LZ77::Encode(input);
	cout << "input string: " << endl << input << endl;
	cout << "decoded: " << endl << LZ77::Decode(encoded77) << endl << endl;
}

void LZ78Test()
{
	cout << "LZ78" << endl;
	string input = "sionsinossionsinos";
	list<Node78> encoded78 = LZ78::Encode(input);
	cout << "input string: " << endl << input << endl;
	cout << "decoded: " << endl << LZ78::Decode(encoded78) << endl << endl;
}

void ShannonFanoTest() {
	setlocale(LC_ALL, "Russian");
	string input = "Привет";
	cout << "Input: " << endl << input << endl;
	cout << "Shannon-Fano: " << endl;
	ShannonFano shannonFano;
	shannonFano.Encode(input);
	cout << shannonFano.getEncodedString(input) << endl;
}

void HuffmanTest()
{
	Huffman huffman;
	int task = -1;
	string input;
	while (true)
	{
		system("cls");
		cout << "1. FIO" << endl;
		cout << "2. Text (Hamlet)" << endl;
		cout << "0. Back" << endl;
		cout << "Enter a task number: ";
		cin >> task;
		switch (task)
		{
		case 1:
			cout << "FIO" << endl;
			input = "Поведенок Станислав Сергеевич";
			cout << "input string: " << input << endl;
			huffman.encode("Поведенок Станислав Сергеевич");
			cout << "Huffman: " << endl;
			cout << "encoded: " << huffman.getEncodedString(input) << endl;
			huffman.printTable();
			huffman.print();
			break;
		case 2:
			cout << "Text (Hamlet)" << endl;
			huffman.encodeFile("hamlet.txt", "hamlet_encoded.bin");
			huffman.printTable();
			huffman.print();
			break;
		case 0:
			return;
		default:
			cout << "Incorrect task number!" << endl;
			break;
		}
		system("pause");
	}
}
