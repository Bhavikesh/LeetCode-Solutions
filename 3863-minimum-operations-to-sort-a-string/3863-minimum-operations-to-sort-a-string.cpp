class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int operations = 0;

        string copy = s;
        sort(copy.begin(), copy.end());

        if(s == copy) return 0;
        if(n == 2) return -1;

        if(s[0] == copy[0] || s[n-1] == copy[n-1]){
            return 1;
        }

        string temp = s;

        sort(temp.begin() + 1, temp.end());
        operations++;

        sort(temp.begin(), temp.end() - 1);
        operations++;

        if(temp == copy) return operations;

        temp = s;

        sort(temp.begin(), temp.end() - 1);
        sort(temp.begin() + 1, temp.end());

        if(temp == copy) return 2;

        return 3;
    }
};