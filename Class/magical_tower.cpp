#include<iostream>
#include<vector>

using namespace std;

int main() {
    vector<bool> ans(1e5 + 1, false);
    ans[0] = false;
    ans[1] = true;
    for(int i = 2; i <= 100000; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(ans[i - j * j] == false) {
                ans[i] = true;
                break;
            }
        }
    }

    int n;
    while(cin >> n) {
        cout << ans[n] << endl;
    }
}