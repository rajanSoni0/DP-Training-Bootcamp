#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
vector<string> ans;
void fn(string input, string output) {
    if(input.size() == 0) {
        ans.push_back(output);
        return;
    }
    unordered_set<char> s;
    for(int i = 0; i < input.size(); i++) {
        string ip = input.substr(0, i) + input.substr(i + 1); 
        if(s.find(input[i]) == s.end()) {
            s.insert(input[i]);
            output.push_back(input[i]);
            fn(ip, output);
            output.pop_back();
        }
        
    }
    
}

int main() {
    string str = "aac";
    unordered_set<char> s;
    fn(str, "");
    for(string s : ans) {
        cout << s << " ";
    }

}