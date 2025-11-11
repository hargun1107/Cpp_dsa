#include <iostream>
using namespace std;

void countsort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    int count[max + 1];
    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++){
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    cout << "Number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter unsorted array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    countsort(arr,n);

    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
