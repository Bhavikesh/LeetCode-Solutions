class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int open = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='(' && open++>0){
                ans+=s[i];
            }
            if(s[i] == ')' && open-->1){
                ans+=s[i];
            }
        }
        return ans;
    }
};