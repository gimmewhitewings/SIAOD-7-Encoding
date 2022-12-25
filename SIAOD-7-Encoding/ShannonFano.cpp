#include "ShannonFano.h"

void ShannonFano::add(Node node) {
    if (root == nullptr) {
        root = new Node;
        root->symbol = node.symbol;
        root->frequency = node.frequency;
        root->code = node.code;
    } else {
        Node *current = root;
        while (true) {
            if (node.symbol < current->symbol) {
                if (current->left == nullptr) {
                    current->left = new Node;
                    current->left->symbol = node.symbol;
                    current->left->frequency = node.frequency;
                    current->left->code = node.code;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == nullptr) {
                    current->right = new Node;
                    current->right->symbol = node.symbol;
                    current->right->frequency = node.frequency;
                    current->right->code = node.code;
                    break;
                } else {
                    current = current->right;
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

void ShannonFano::Encode(string input) {
    vector <Node> nodes;
    for (int i = 0; i < input.length(); i++) {
        bool found = false;
        for (int j = 0; j < nodes.size(); j++) {
            if (nodes[j].symbol == input[i]) {
                nodes[j].frequency++;
                found = true;
                break;
            }
        }
        if (!found) {
            Node node;
            node.symbol = input[i];
            node.frequency = 1;
            nodes.push_back(node);
        }
    }

    // Sort nodes by frequency
    for (int i = 0; i < nodes.size() - 1; i++) {
        for (int j = i + 1; j < nodes.size(); j++) {
            if (nodes[i].frequency < nodes[j].frequency) {
                Node temp = nodes[i];
                nodes[i] = nodes[j];
                nodes[j] = temp;
            }
        }
    }

    shannon(nodes);

    printTree(root);
}
