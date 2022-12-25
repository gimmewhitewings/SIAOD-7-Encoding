#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class ShannonFano {
private:
    struct Node {
        char symbol = 0;
        int frequency = 0;
        string code = "";
        Node *left = nullptr;
        Node *right = nullptr;
    };
    Node *root = nullptr;

    void add(Node node);

    void printNode(Node *node, int level);

    void printTree(Node *node);

    void shannon(vector <Node> vector);

	string getCode(char symbol);
public:
    void Encode(string input);
    string getEncodedString(string input);
};
