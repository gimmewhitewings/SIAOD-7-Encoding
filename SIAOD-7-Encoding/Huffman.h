#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Huffman
{
private:
	struct Letter
	{
		char symbol;
		int frequency;
		string code;

		Letter()
		{
			symbol = '\0';
			frequency = 0;
			code = "";
		}

		Letter(char symbol, int frequency)
		{
			this->symbol = symbol;
			this->frequency = frequency;
		}
	};

	struct Node
	{
		string symbols;
		int frequency;
		Node* left;
		Node* right;
		
		Node()
		{
			symbols = "";
			left = nullptr;
			right = nullptr;
			frequency = 0;
		}
		
		Node(string symbols, int frequency)
		{
			this->symbols = symbols;
			this->frequency = frequency;
			left = nullptr;
			right = nullptr;
		}

		Node(char symbol, int frequency)
		{
			this->symbols = symbol;
			this->frequency = frequency;
			left = nullptr;
			right = nullptr;
		}

		Node(Node* left, Node* right)
		{
			this->symbols = left->symbols + right->symbols;
			this->frequency = left->frequency + right->frequency;
			this->left = left;
			this->right = right;
		}
	};
	
	Node* root;
	vector<Letter> letters;
	vector<Node> nodes;
	void printNode(Node* node, int level);
	string getSymbolCode(char symbol);
	void assignCode(Node* node, string code);
public:
	void print();
	void encode(string input);
	void encodeFile(string txtFileName, string binFileName);
	string getEncodedString(string input);
};
