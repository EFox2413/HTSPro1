#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "read.h"
#include "unscramble.h"

using std::cout;                    using std::vector;
using std::cin;                     using std::string;
using std::ifstream;                 using std::getline;
using std::domain_error;               using std::endl;
using std::ofstream;

int main()
{    
    ifstream in("C:\\Users\\Fox\\Documents\\Qt projects\\HTSPro1\\wordlist.txt");

    // container for unscrambled wordlist
    vector<string> wordlist;

    // stores all words from wordlist.txt to vector wordlist
    string x;
    while(getline(in, x)) {
        wordlist.push_back(x);
    }

    // container for scrambled words
    vector<string> scrmList;

    // reads and stores scrambled word list
    cout << "Input scrambled words: ";
    read(cin, scrmList);

    ofstream out("C:\\Users\\Fox\\Documents\\Qt projects\\HTSPro1\\unscrambled.txt");
    out.clear();

    // unscrambles the words from scrmList
    for (vector<string>::size_type i = 0; i != scrmList.size() - 1; ++i) {
        out << unscramble(wordlist, scrmList[i]) << ",";
    }
    out << unscramble(wordlist, scrmList[scrmList.size() - 1]);

    out.close();

    return 0;
}

