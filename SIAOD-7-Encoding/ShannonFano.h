#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class ShannonFano
{
private:
	struct Node
	{
		char symbol = 0;
		int frequency = 0;
		string code = "";
	};
	static void printTree(vector<Node> vector);
	static void shannon(vector<Node> vector);
public:
	static void Encode(string input);
};

