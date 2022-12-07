#include "LZ78.h"

list<Node78> LZ78::Encode(string input)
{
	string buffer = "";
	map<string, int> dictionary = {};
	list<Node78> result;
	
	for (size_t i = 0; i < input.size(); i++)
	{
		if (dictionary.find(buffer += input[i]) == dictionary.end())
		{
			Node78 node(dictionary[buffer], input[i]);
			result.push_back(node);
			dictionary[buffer + input[i]] = dictionary.size();
			buffer = "";
		}
		else
		{
			buffer += input[i];
		}
	}

	if (!buffer.empty())
	{
		char last = buffer.at(buffer.size() - 1);
		buffer.erase(buffer.size() - 1);
		Node78 node(dictionary[buffer], last);
		result.push_back(node);
	}
	return result;
}

string LZ78::Decode(list<Node78> input)
{
	string result = "";
	map<int, string> dictionary = {};
	int index = 0;
	for (Node78 node : input)
	{
		if (dictionary.find(node.position) == dictionary.end())
		{
			dictionary[index] = dictionary[node.position] + node.next;
			result += dictionary[index];
		}
		else
		{
			dictionary[index] = dictionary[node.position] + node.next;
			result += dictionary[index];
		}
		index++;
	}
	return result;
}
