#include <iostream>
#include <locale>
#include "RLE.h"
#include "LZ77.h"
#include "LZ78.h"
#include "ShannonFano.h"
#include "Huffman.h"

using namespace std;
//void printMenu();

int main() {
    setlocale(LC_ALL, "Russian");

    //cout << "RLE" << endl;
    string input = "WWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWBWWWWWWWWWWWWWW";
    //string output = "";
    //cout << "input string: " << input << endl;
    //output = RLE::Encode(input);
    //cout << "encoded: " << output << endl;
    //output = RLE::Decode(output);
    //cout << "decoded: " << output << endl << endl;

    //cout << "LZ77" << endl;
    //input = "0001010010101001101";
    //list<Node77> encoded77 = LZ77::Encode(input);
    //cout << "input string: " << input << endl;
    //cout << "decoded: " << LZ77::Decode(encoded77) << endl << endl;

    //cout << "LZ78" << endl;
    //input = "������������������";
    //list<Node78> encoded78 = LZ78::Encode(input);
    //cout << input << endl << LZ78::Decode(encoded78) << endl << endl;
    //
    //input = "������-�����������-��, ���-����������������, ���� - ���� - ���� - ���, ���� - �� - ������ - ���!";
    //cout << "input string: " << input << endl;
    //cout << "Shannon Fano: " << endl;
    //ShannonFano shannonFano;
    //shannonFano.Encode(input);

    //input = "��������� ��������� ���������";
    //cout << "input string: " << input << endl;
    Huffman huffman;
    //huffman.encode(input);
    //cout << "Huffman: " << huffman.getEncodedString(input) << endl;
    //huffman.print();
    huffman.encodeFile("hamlet.txt", "output.bin");

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