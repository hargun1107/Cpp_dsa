#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int p = partition(arr, low, high);
    quicksort(arr, low, p - 1);
    quicksort(arr, p + 1, high);
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

    quicksort(arr, 0, n - 1);

    cout << "The sorted array is:" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
