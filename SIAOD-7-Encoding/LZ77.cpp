#include "LZ77.h"

list<Node77> LZ77::Encode(string input)
{
	list<Node77> output;
	for (int i = 0; i < input.size(); i++)
	{
		int offset = 0; 
		int length = 0;
		for (int j = i - 1; j >= 0; j--) // walk back
		{
			if (input[j] == input[i]) // 
			{
				int k = 0;
				while (input[j + k] == input[i + k]) // walk forward
				{
					k++;
					if (j + k >= i || i + k >= input.size()) // if we reached the end of the string
					{
						break;
					}
				}
				if (k > length)
				{
					offset = i - j;
					length = k;
				}
			}
		}
		Node77 node;
		node.offset = offset;
		node.length = length;
		node.next = input[i + length];
		output.push_back(node);
		i += length;
	}
	return output;
}

string LZ77::Decode(list<Node77> input)
{
	string output;
	for (auto node : input)
	{
		for (int i = 0; i < node.length; i++)
		{
			output += output[output.size() - node.offset];
		}
		output += node.next;
	}
	return output;
}
