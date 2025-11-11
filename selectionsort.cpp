#include<iostream>
using namespace std;

void selectionsort (int arr[], int n) {
    for (int i=0; i<n; i++) {
        int min = i;
        for (int j = i+1; j<n; j++) {
            if (arr[min]>arr[j]){
                min = j;
            }
        }
        swap (arr[i],arr[min]);
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
    selectionsort(arr,n);
    return 0;
}
