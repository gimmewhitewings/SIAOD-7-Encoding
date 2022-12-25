#include "RLE.h"

string RLE::Encode(string input) {
    string output = "";
    char current = input[0];
    unsigned count = 1;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == current) {
            count++;
        } else {
            output += to_string(count);
            output += current;
            current = input[i];
            count = 1;
        }
    }
    output += to_string(count);
    output += current;
    return output;
}

string RLE::Decode(string input) {
    string output = "";
    string count = "";
    for (int i = 0; i < input.size(); i++) {
        if (input[i] >= '1' && input[i] <= '9') {
            count += input[i];
        } else {
            int index = 0;
            int amount = stoi(count);
            while (index < amount) {
                output += input[i];
                index++;
            }
            count = "";
        }
    }
    return output;
}
