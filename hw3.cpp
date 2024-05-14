#include <iostream>
#include <vector>

using namespace std;

void output(const vector<int>& arr) {
    for (int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[i]);
    return i;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int a = partition(arr, low, high);

        cout << "pivot: " << arr[a] << endl;
        cout << "current array: ";
        output(arr);

        quickSort(arr, low, a - 1);
        quickSort(arr, a + 1, high);
    }
}

int main() {
    vector<int> arr = {33, 67, 8, 13, 54, 119, 3, 84, 25, 41};
    int n = arr.size();

    cout<<"initial array: ";
    output(arr);

    quickSort(arr, 0, n - 1);

    cout<<"Sorted array: ";
    output(arr);

    return 0;
}
