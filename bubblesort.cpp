#include<iostream>
using namespace std;

void bubblesort (int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        for (int j = 0; j<n-i; j++) {
            if (arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
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
    bubblesort(arr,n);
    return 0;
}
