class Solution {
public:
    bool checkValidString(string s) {
        bool ans = false;
        int n = s.length();

        int open = 0;
        int close = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            else if(s[i] == '*') open++;
            else close++;

            if(open == close){
                ans = ans | true;

            }
            else if(close > open){
                ans = ans | false;
                break;
            }
        }
        

        open = 0;
        close = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '(') open++;
            else if(s[i] == '*') close++;
            else close++;
            if(open == close){
                ans = ans | true;
            }
            else if(open > close){
                ans = ans | false;
                break;
            }
        }


        open = 0;
        close = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            else if(s[i] == ')') close++;

            if(open == close ){
                ans = ans | true;
            }
            else if(close > open){
                ans = ans | false;
                break;
            }
        }

        return ans;
    }
};