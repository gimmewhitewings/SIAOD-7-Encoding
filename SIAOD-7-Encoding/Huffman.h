#pragma once
#include <string>

using namespace std;

class Huffman
{
private:
	struct Node
	{
		char symbol = 0;
		int frequency = 0;
		string code = "";
	};
public:
	static void Encode(string input);
};
