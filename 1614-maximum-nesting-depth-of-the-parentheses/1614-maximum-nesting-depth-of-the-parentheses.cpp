class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;

        for(auto i : s){
            if(i=='(') depth++;
            if(i==')'){
                ans = max(ans, depth);
                depth--;
            }
        }

        return ans;
    }
};