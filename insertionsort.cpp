#include<iostream>
using namespace std;

void insertionsort (int arr[], int n) {
    for (int i=1; i<n; i++) {
        int temp = arr[i];
        int j=i-1;
        while (arr[j]>temp && j>=00) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    cout<<"The sorted array is"<<endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"Number of elements"<<endl;
    cin>>n;
    cout<<"Enter unsorted array"<<endl;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
    insertionsort(arr,n);
    return 0;
}