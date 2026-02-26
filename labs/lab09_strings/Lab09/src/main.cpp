#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;


int main() {

    char str1[20] = "Hello ";
    char str2[20] = "World";
    char str3[30];

    cout << strlen(str1) << endl;

    strcpy_s(str3, str1);
    cout << str3 << endl;

    strcat_s(str3, str2);
    cout << str3 << endl;

    string s1 = "Hello";
    string s2 = "World";

    cout << s1.length() << endl;

    s1.append(s2);
    cout << s1 << endl;

    string sub = s2.substr(1, 3);
    cout << sub << endl;

    cout << endl;

    bool check = false;
    int word_count = 0;

    while (true) {
        std::cin >> word_count;
        if (word_count >= 1 && word_count <= 20) break;
        cout << "Enter a number between 1 and 20" << endl;
    }

    vector<string> words;
    words.reserve(word_count);
    for (int i = 0; i < word_count; ++i) {
        string word;
        std::cin >> word;
        if (word.length() > 10) word = word.substr(0, 10);
        words.push_back(word);
    }
    for (int i = 1; i < word_count; i += 2) {
        cout << words[i] << " ";
    }
    cout << endl << "Variant 2" << endl;

    const int MAX_WORDS = 20;
    const int WORD_LEN = 11;  
    char _words[MAX_WORDS][WORD_LEN]; 
    int word_count2 = 0;
    
    if (!(std::cin >> word_count2) || word_count2 > MAX_WORDS || word_count2 <= 0) {
        return 0;
    }
    
    
    for (int i = 0; i <= word_count2; ++i) {

        std::cin.getline(_words[i], WORD_LEN);
    }

    for (int i = 2; i <= word_count2; i += 2) {
        cout << _words[i] << " ";
    }


    return 0;
}
