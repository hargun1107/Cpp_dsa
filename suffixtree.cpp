#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cout<<"Name: Hargun Kaur Kohli"<<endl<<"Registeration Number: 24BCE2198"<<endl;
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;
    int n = text.length();
    if (n == 0) {
        cout << "Invalid case: empty text\n";
        return 0;
    }
    if (n == 1) {
        if (text == pattern)
            cout << "Pattern found\n";
        else
            cout << "Pattern not found\n";
        return 0;
    }
    vector<string> suffixes;
    for (int i = 0; i < n; i++) {
        suffixes.push_back(text.substr(i));
    }
    sort(suffixes.begin(), suffixes.end());
    bool found = false;
    for (auto s : suffixes) {
        if (s.find(pattern) == 0) {
            found = true;
            break;
        }
    }
    if (found)
        cout << "Pattern found\n";
    else
        cout << "Pattern not found\n";

    return 0;
}