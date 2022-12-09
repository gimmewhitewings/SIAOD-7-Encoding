#include "ShannonFano.h"

void ShannonFano::printTree(vector<Node> vector)
{
}

void ShannonFano::shannon(vector<Node> vector)
{
	if (vector.size() == 1)
	{
		cout << vector[0].symbol << " - " << vector[0].code << endl;
		return;
	}
	int sum = 0;
	for (int i = 0; i < vector.size(); i++)
	{
		sum += vector[i].frequency;
	}
	int half = sum / 2;
	int leftSum = 0;
	int rightSum = 0;
	int i = 0;
	while (leftSum + vector[i].frequency <= half)
	{
		leftSum += vector[i].frequency;
		i++;
	}

	if (leftSum == 0)
	{
		leftSum += vector.front().frequency;
		i++;
	}

	for (int j = 0; j < i; j++)
	{
		vector[j].code += "0";
	}
	for (int j = i; j < vector.size(); j++)
	{
		vector[j].code += "1";
	}

	std::vector<Node> vector1(vector.begin(), vector.begin() + i);
	std::vector<Node> vector2(vector.begin() + i, vector.end());
	shannon(vector1);
	shannon(vector2);
}

void ShannonFano::Encode(string input)
{
	vector<Node> nodes;
	for (int i = 0; i < input.length(); i++)
	{
		bool found = false;
		for (int j = 0; j < nodes.size(); j++)
		{
			if (nodes[j].symbol == input[i])
			{
				nodes[j].frequency++;
				found = true;
				break;
			}
		}
		if (!found)
		{
			Node node;
			node.symbol = input[i];
			node.frequency = 1;
			nodes.push_back(node);
		}
	}
	
	// Sort nodes by frequency
	for (int i = 0; i < nodes.size() - 1; i++)
	{
		for (int j = i + 1; j < nodes.size(); j++)
		{
			if (nodes[i].frequency < nodes[j].frequency)
			{
				Node temp = nodes[i];
				nodes[i] = nodes[j];
				nodes[j] = temp;
			}
		}
	}
	
	shannon(nodes);
}
