#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<string> ans;
void fn(string & str, int i) {
    if(i >= str.size()) {
        ans.push_back(str);
        return;
    }
    unordered_set<char> s;
    for(int j = i; j < str.size(); j++) {
        if(s.find(str[j]) == s.end()) {
            s.insert(str[j]);
            swap(str[i], str[j]);
            fn(str, i + 1);
            swap(str[i], str[j]);
        }
        
    }
}

int main() {
    string str = "aac";
    fn(str, 0);
    for(string s : ans) {
        cout << s << " ";
    }

}