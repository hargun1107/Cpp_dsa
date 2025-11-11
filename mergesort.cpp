#include<iostream>
#include<vector>
using namespace std;

void merge (int arr[], int low, int mid, int high) {
    vector<int> temp;
    int right = mid + 1;
    int left = low;
    while (left<=mid && right<=high) {
        if (arr[left]<=arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left<=mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right<=high) {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i=low; i<=high; i++) {
        arr[i] = temp [i-low];
    }
}

void ms (int arr[], int low, int high) {
    if (low==high) {
        return;
    }
    int mid = (low+high)/2;
    ms (arr,low,mid);
    ms (arr, mid+1, high);
    merge (arr, low, mid, high);
}

void mergesort (int arr[], int n) {
    ms (arr,0,n-1);
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
    mergesort(arr,n);
    cout<<"The sorted array is"<<endl;
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}