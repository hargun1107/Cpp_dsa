#include<iostream>
using namespace std;

int linearsearch (int arr[], int n, int key) {
    for (int i=0; i<n; i++) {
        if (arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    int f = linearsearch(arr,n,key);
    if (f==-1) {
        cout<<"Element not found";
    }
    else {
        cout<<"element found at position "<<f<<endl;
    }
    return 0;
}