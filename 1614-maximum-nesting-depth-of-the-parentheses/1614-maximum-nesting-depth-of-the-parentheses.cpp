class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;

        for(auto i:s){
            if(i=='('){
                st.push('(');
            }
            else if(i==')'){
                ans = max(ans, (int)st.size());
                st.pop();
            }
        }
        return ans;
    }
};