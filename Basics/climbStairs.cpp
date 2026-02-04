#include<iostream>
#include<vector>
using namespace std;
void fn(int i, string &path) {
    if(i == 0) {
        cout << path << endl;
        return;
    }

    path.push_back('1');
    fn(i - 1, path);
    path.pop_back();
    if(i >= 2) {
        path.push_back('2');
        fn(i - 2, path);
        path.pop_back();
    }
    
}

int main() {
    string temp = "";
    int n = 1;
    fn(n, temp);
    
}