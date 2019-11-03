#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

vector<string> split_string(string s, const string delimiter) {
    vector<string> list;
    if (s.length() == 0) return list;
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        list.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    list.push_back(s);
    return list;
}

string decode_word(string word, string ant) {
    vector<string> splitted = split_string(word, "_");

    // cout << "size: " << splitted.size() << ": " << splitted[0] << endl;
    if (splitted.size() == 1)
        return splitted[0];
    
    string decoded = "";
    for (int i = 0; i < stoi(splitted[0]); i++)
        decoded += ant[i];
    for (int i = 0; i < splitted[1].size(); i++)
        decoded += splitted[1][i];
    return decoded;
}

string remove_dot(string word) {
    if (word[0] != '.')
        return word;

    string s = "";
    for (int i = 1; i < word.size(); i++)
        s += word[i];
    return s;
}

int main () {
    system("cd src/; tar xf compressed.tar.xz; cd ..;");
    ifstream infile("src/compressed.txt");
    string s, ant;
    while (infile >> s) {
        if (s[0] == '.') {
            ant += "'s";
            cout << ant << endl;
        }
        // cout << "before processing: " << s << endl;
        s = remove_dot(s);
        s = decode_word(s, ant);
        cout << s << endl;
        ant = s;
        // if (s == "canal")
        //     break;

    }
}