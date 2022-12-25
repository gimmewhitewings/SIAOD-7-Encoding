#pragma once

#include <list>
#include <string>
#include <map>

using namespace std;

struct Node78 {
    int position;
    char next;

    Node78(int position, char next) {
        this->position = position;
        this->next = next;
    }
};

class LZ78 {
public:
    static list <Node78> Encode(string input);

    static string Decode(list <Node78> input);
};

