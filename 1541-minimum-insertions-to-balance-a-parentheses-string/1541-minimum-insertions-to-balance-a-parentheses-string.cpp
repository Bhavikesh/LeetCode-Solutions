
class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;
        int i = 0;
        int n = s.length();

        while (i < n) {
            if (s[i] == '(') {
                open++;
                i++;
            } 
            else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i += 2;
                } 
                else {
                    insertions++;
                    i++;
                }

                if (open == 0) {
                    insertions++;
                } 
                else {
                    open--;
                }
            }
        }

        insertions += open * 2;

        return insertions;
    }
};
