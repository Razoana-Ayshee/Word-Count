#include <bits/stdc++.h>
#include <fstream>
using namespace std;

string removePunctuations(const string& word) {
    string cleanedWord;
    for (char ch : word) {
        if (isalpha(ch) || isspace(ch))
            cleanedWord += ch;
    }
    return cleanedWord;
}

int main() {
    ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    string content;
    string line;

    while (std::getline(file, line)) {
        content += line;
    }
    file.close();

    istringstream iss(content);
    map<std::string, int> wordCount;

    string word;
    while (iss >> word) {
        string cleanedWord = removePunctuations(word)
;
        if (!cleanedWord.empty()) 
            wordCount[cleanedWord]++;
    }

    for (const auto& pair : wordCount) {
        cout << pair.first << " = " << pair.second << endl;
    }

    return 0;
}