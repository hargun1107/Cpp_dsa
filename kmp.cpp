#include <iostream>
#include <vector>
#include <string>
using namespace std;

void computeLPS(string pat, vector<int> &lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while(i < pat.length()){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        } 
        else{
            if(len != 0)
                len = lps[len-1];
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

int main(){
    cout<<"Name: Hargun Kaur Kohli"<<endl<<"Registration Number: 24BCE2198"<<endl;
    string text, pat;

    cout<<"Enter text: ";
    getline(cin, text);

    cout<<"Enter pattern: ";
    getline(cin, pat);

    if(text.length()==0 || pat.length()==0){
        cout<<"Invalid input";
        return 0;
    }

    int n = text.length();
    int m = pat.length();

    vector<int> lps(m);
    computeLPS(pat, lps);

    int i=0, j=0;
    bool found=false;

    while(i<n){
        if(text[i]==pat[j]){
            i++; j++;
        }

        if(j==m){
            cout<<"Pattern found at "<<i-j<<endl;
            found=true;
            j=lps[j-1];
        }
        else if(i<n && text[i]!=pat[j]){
            if(j!=0)
                j=lps[j-1];
            else
                i++;
        }
    }

    if(!found)
        cout<<"No match";

    return 0;
}