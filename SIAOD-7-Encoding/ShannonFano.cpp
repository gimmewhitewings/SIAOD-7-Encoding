#include "ShannonFano.h"

void ShannonFano::add(Node node) {
	if (root == nullptr) {
		root = new Node;
		root->symbol = node.symbol;
		root->frequency = node.frequency;
		root->code = node.code;
		root->left = node.left;
		root->right = node.right;
	}
	else {
		Node* current = root;
		while (true) {
			if (node.frequency < current->frequency) {
				if (current->left != nullptr) {
					current = current->left;
				}
				else {
					current->left = new Node;
					current->left->symbol = node.symbol;
					current->left->frequency = node.frequency;
					current->left->code = node.code;
					current->left->left = node.left;
					current->left->right = node.right;
					break;
				}
			}
			else {
				if (current->right != nullptr) {
					current = current->right;
				}
				else {
					current->right = new Node;
					current->right->symbol = node.symbol;
					current->right->frequency = node.frequency;
					current->right->code = node.code;
					current->right->left = node.left;
					current->right->right = node.right;
					break;
				}
			}
		}
	}
}

void ShannonFano::printNode(Node *node, int level) {
    if (node != nullptr) {
        printNode(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            cout << "\t";
        }
        cout << node->symbol << " " << node->code << endl;
        printNode(node->left, level + 1);
    }
}

void ShannonFano::printTree(Node *vector) {
    printNode(root, 0);
}

void ShannonFano::shannon(vector <Node> vector) {
    if (vector.size() == 1) {
        add(vector[0]);
        return;
    }
    int sum = 0;
    for (int i = 0; i < vector.size(); i++) {
        sum += vector[i].frequency;
    }
    int half = sum / 2;
    int leftSum = 0;
    int rightSum = 0;
    int i = 0;
    while (leftSum + vector[i].frequency <= half) {
        leftSum += vector[i].frequency;
        i++;
    }

    if (leftSum == 0) {
        leftSum += vector.front().frequency;
        i++;
    }

    for (int j = 0; j < i; j++) {
        vector[j].code += "0";
    }
    for (int j = i; j < vector.size(); j++) {
        vector[j].code += "1";
    }

    std::vector <Node> vector1(vector.begin(), vector.begin() + i);
    std::vector <Node> vector2(vector.begin() + i, vector.end());
    shannon(vector1);
    shannon(vector2);
}

string ShannonFano::getCode(char symbol)
{
	Node* current = root;
	while (current->symbol != symbol)
	{
		if (symbol < current->symbol)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return current->code;
}

void ShannonFano::Encode(string input) {
	vector <Node> vector;
	for (int i = 0; i < input.length(); i++) {
		bool found = false;
		for (int j = 0; j < vector.size(); j++) {
			if (vector[j].symbol == input[i]) {
				vector[j].frequency++;
				found = true;
				break;
			}
		}
		if (!found) {
			Node node;
			node.symbol = input[i];
			node.frequency = 1;
			vector.push_back(node);
		}
	}
	shannon(vector);
}

string ShannonFano::getEncodedString(string input)
{
	string encodedString = "";
	for (int i = 0; i < input.length(); i++) {
		encodedString += getCode(input[i]);
	}
	return encodedString;
}
