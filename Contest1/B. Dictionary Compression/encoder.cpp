#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    ifstream infile("src/original.txt");
    string s, ant = "";
    ofstream encoded_file;
    encoded_file.open ("src/pre_compressed.txt");
    while (infile >> s) {
        if (s != ant + "'s") {
            encoded_file << s << endl;
        } else {
            encoded_file << "." << endl;
        }
	    ant = s;
    }
    encoded_file.close();
}
