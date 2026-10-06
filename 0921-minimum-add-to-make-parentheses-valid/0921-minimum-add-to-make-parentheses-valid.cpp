class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int close = 0;
        int count = 0;
        for(auto i:s){
            if(i=='(')open++;
            else close++;

            if(close > open){
                count += close - open;
                close = 0;
                open = 0;
            }
        }

        count += open - close;
        return count;
    }
};