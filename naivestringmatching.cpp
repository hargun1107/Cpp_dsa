#include <iostream>
#include <string>
using namespace std;

int main() {
    cout<<"Name: Hargun Kaur Kohli"<<endl<<"Registration Number: 24BCE2198"<<endl;
    string text, pattern;
    
    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter pattern: ";
    getline(cin, pattern);

    int n = text.length();
    int m = pattern.length();
    bool found = false;

    if(m > n){
        cout << "Invalid input - no match";
        return 0;
    }

    for(int i = 0; i <= n - m; i++){
        int j;
        for(j = 0; j < m; j++){
            if(text[i + j] != pattern[j])
                break;
        }

        if(j == m){
            cout << "Pattern found at index " << i << endl;
            found = true;
        }
    }

    if(!found)
        cout << "Invalid input - no match";

    return 0;
}