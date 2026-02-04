#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr.begin(), arr.end());
    vector<int> temp(n);
    int left, right, k;
    if(n % 2 != 1) {
        temp[n / 2] = arr[n - 1];
        left = (n / 2) - 1;
        right = (n / 2) + 1;
        k = n - 2;
    }
    else {
        left = (n / 2) - 1, right = n / 2;
        k = n - 1;
    }

    while(k >= 0) {
        if(k >= 0 && left >= 0) {
            temp[left--] = arr[k--];
        }
        if(k >= 0 && right < n) {
            temp[right++] = arr[k--];
        }
    }

    for(int n : temp) {
        cout << n << " ";
    }
    cout << endl;
}