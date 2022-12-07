#pragma once
#include <string>
#include <list>

using namespace std;

struct Node77
{
	int offset;
	int length;
	char next;
};

class LZ77
{
public:
	static list<Node77> Encode(string input);
	static string Decode(list<Node77> input);
};

