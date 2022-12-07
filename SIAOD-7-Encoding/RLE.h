#pragma once
#include <string>

using namespace std;

class RLE
{
public:
	static string Encode(string input);
	static string Decode(string input);
};
