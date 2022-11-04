#pragma once
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void ConfigTask(string inData, string& outputData) {

    stringstream str(inData);
    char temp;
    vector <char> text;
    while (str.get(temp)) {
        text.push_back(temp);
    }

    int lines = 0;
    int word = 0;
    int spaces = 0;
    bool comment = 0;
    bool firstspace = 0;

    vector<int> invalidLines;
    vector<char> templine;
    string out = "Configuration\n";

    char next_char;
    char prev_char;

    for (int i = 0; i < text.size(); i++) {
        if (text[i] == '\n' || i == text.size() - 1) {
            lines++;
        }
        if (text[i] == '#') {
            comment = 1;
        }

        if (comment == 0 && text[i] != '\n' && text[i] != ' ') {
            templine.push_back(text[i]);
        }

        if (i != text.size() - 1) {
            next_char = text[i + 1];
        }

        if (text[i] == ' ' && next_char != ' ' && templine.size() != 0 && next_char != '\n' && next_char != '#') {
            templine.push_back(text[i]);
        }

        if (i != 0) {
            if (comment == 0 && prev_char != ' ') {
                if (text[i] == ' ' || text[i] == '\n' || i == text.size() - 1) {
                    word++;
                }
            }
        }
        prev_char = text[i];

        if (word == 1 && text[i] == ' ') {
            spaces++;
        }

        if (i == text.size() - 1 || text[i] == '\n') {
            comment = 0;
            if (word == 2) {
                for (auto j : templine) {
                    if (j != ' ') {
                        out = out + j;
                    }
                    else {
                        out = out + " - ";
                    }
                }
                out = out + "\n";
            }
            else if (word == 1 && spaces > 0) {
                for (auto j : templine) {
                    out = out + j;
                }
                out = out + " - '";
                for (int s = 0; s < spaces; s++) {
                    out = out + " ";
                }
                out = out + "'\n";
            }
            else {
                invalidLines.push_back(lines);
            }

            templine.clear();
            word = 0;
            spaces = 0;
        }
    }

    out = out + "\n" + "Mistakes\n";
    string Prep = "<string with invalid syntax ";

    for (int j = 0; j < invalidLines.size(); j++) {
        out = out + Prep + to_string(invalidLines[j]) + ">\n";
    }
    outputData = out;
}