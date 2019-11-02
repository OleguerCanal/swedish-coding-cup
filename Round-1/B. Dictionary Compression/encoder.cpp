#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Returns number of same chars in strings 
int equal_chars(string word, string ant) {
    int i = 0;
    while (ant[i] == word[i] and i < (int) min(ant.size(), word.size()))
        i++;
    return i;
}

// Returns (numsamechars)_differentchars
string encode_word(string word, string ant) {
    int pos = equal_chars(word, ant);
    if (pos < 3) // Not worth to compress
        return word;
    string encoded = to_string(pos) + "_";
    for (size_t i = pos; i < word.size(); i++)
        encoded += word[i];
    return encoded;
}

int main () {
    ifstream infile("src/original.txt");
    string s;
    string ant = "";
    ofstream encoded_file;
    encoded_file.open("src/compressed.txt");
    int max_elems = 75e3;
    while (infile >> s and max_elems > 0) {
        if (s != ant + "'s") {
            string encoded = encode_word(s, ant);
            encoded_file << encoded << endl;
        } else {
            encoded_file << ".";
        }
	    ant = s;
        max_elems--;
    }
    encoded_file.close();
}
