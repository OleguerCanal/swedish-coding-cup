#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
    system("cd src/; tar xf compressed.tar.xz; cd ..;");
    ifstream infile("/src/compressed.txt");
    string s, ant;
    while (infile >> s){
        if (s != ".")
            cout << s << endl;
        else
            cout << ant + "'s" << endl;
        ant = s;
    }
    return 0;
}