class Solution {
public:
    
    void reverseString(string &s, int l, int r) {
        while(l < r) {
            swap(s[l++], s[r--]);
        }
    }
    
    string reverseWords(string s) {
        
        int n = s.length();
        int i = 0, j = 0;
        while(j < n) {
            while(j < n && s[j] == ' ') j++;
            while(j < n && s[j] != ' ') s[i++] = s[j++];
            while(j < n && s[j] == ' ') j++; 
            if(j < n) s[i++] = ' '; 
        }
        s.resize(i);
        
        reverseString(s, 0, s.length() - 1);
        
        int start = 0;
        for(int end = 0; end <= s.length(); end++) {
            if(end == s.length() || s[end] == ' ') {
                reverseString(s, start, end - 1);
                start = end + 1;
            }
        }
        
        return s;
    }
};