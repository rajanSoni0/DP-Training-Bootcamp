#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (j >= low && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}

void qSort(int low, int high, vector<int> &arr) {
    if (low < high) {
        int p = partition(arr, low, high);
        qSort(low, p - 1, arr);
        qSort(p + 1, high, arr);
    }
}
int main() {
    vector<int> arr = {1, 8, 6, 4, 8, 9};
    qSort(0, arr.size() - 1, arr);
    for(int n : arr) {
        cout << n << " ";
    }
}