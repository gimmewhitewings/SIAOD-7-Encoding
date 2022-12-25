#include "Huffman.h"

void Huffman::printNode(Node* node, int level)
{
	// If the node is empty, return
	if (node == nullptr)
		return;
	

	

	// Print the left subtree
	printNode(node->left, level + 1);
	
	// Print the level
	for (int i = 0; i < level; i++)
		cout << "\t";
	
	// If the node is a leaf, print the symbol and its code
	if (node->left == nullptr && node->right == nullptr)
	{
		cout << node->symbols << " " << getSymbolCode(node->symbols[0]) << endl;
		return;
	}
	else
	{
		cout << node->symbols << endl;
	}

	// Print the right subtree
	printNode(node->right, level + 1);
}

string Huffman::getSymbolCode(char symbol)
{
	for (int i = 0; i < letters.size(); i++)
	{
		if (letters[i].symbol == symbol)
		{
			return letters[i].code;
		}
	}
	return "";
}

void Huffman::assignCode(Node* node, string code)
{
	if (node != nullptr)
	{
		if (node->symbols.size() == 1)
		{
			for (int i = 0; i < letters.size(); i++)
			{
				if (letters[i].symbol == node->symbols[0])
				{
					letters[i].code = code;
					break;
				}
			}
		}
		else
		{
			assignCode(node->left, code + "0");
			assignCode(node->right, code + "1");
		}
	}
}

void Huffman::print()
{
	printNode(root, 0);
}

void Huffman::encode(string input)
{
	for (int i = 0; i < input.length(); i++)
	{
		bool isFound = false;
		for (int j = 0; j < letters.size(); j++)
		{
			if (letters[j].symbol == input[i])
			{
				letters[j].frequency++;
				isFound = true;
				break;
			}
		}
		if (!isFound)
		{
			letters.push_back(Letter(input[i], 1));
		}
	}
	// Sort letters by frequency
	for (int i = 0; i < letters.size() - 1; i++)
	{
		for (int j = i + 1; j < letters.size(); j++)
		{
			if (letters[i].frequency > letters[j].frequency)
			{
				Letter temp = letters[i];
				letters[i] = letters[j];
				letters[j] = temp;
			}
		}
	}
	// Create nodes
	for (int i = 0; i < letters.size(); i++)
	{
		nodes.push_back(Node(letters[i].symbol, letters[i].frequency));
	}
	while (nodes.size() > 1)
	{
		Node* left = new Node();
		Node* right = new Node();
		*left = nodes[0];
		*right = nodes[1];
		Node* parent = new Node(left, right);
		nodes.erase(nodes.begin());
		nodes.erase(nodes.begin());
		nodes.insert(nodes.begin(), *parent);
		// Sort nodes by frequency
		for (int i = 0; i < nodes.size() - 1; i++)
		{
			for (int j = i + 1; j < nodes.size(); j++)
			{
				if (nodes[i].frequency > nodes[j].frequency)
				{
					Node temp = nodes[i];
					nodes[i] = nodes[j];
					nodes[j] = temp;
				}
			}
		}
	}
	root = &nodes[0];

	// Assign codes
	assignCode(root, "");
}

void Huffman::encodeFile(string txtFileName, string binFileName)
{
	ifstream txtFile(txtFileName);
	ofstream binFile(binFileName, ios::binary);
	string text;
	// Read text from file
	if (txtFile.is_open())
	{
		while (!txtFile.eof())
		{
			string line;
			getline(txtFile, line);
			text += line;
		}
		txtFile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
	// Encode text
	encode(text);
	// Write encoded text to file by bytes
	unsigned char byte = 0;
	int bit = 0;
	for (int i = 0; i < text.length(); i++)
	{
		string code = getSymbolCode(text[i]);
		for (int j = 0; j < code.length(); j++)
		{
			
			if (code[j] == '1')
			{
				byte |= 1 << (7 - bit);
			}
			bit++;
			if (bit == 8)
			{
				binFile.write((char*)&byte, sizeof(byte));
				bit = 0;
				byte = 0;
			}
		}
	}
	txtFile.close();
	binFile.close();
}

string Huffman::getEncodedString(string input)
{
	string encodedString;
	for (int i = 0; i < input.length(); i++)
	{
		encodedString += getSymbolCode(input[i]);
	}
	return encodedString;
}