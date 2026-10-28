class Solution {
public:
    int dp[1001][1001];

    int solve(string &text1, string &text2, int i, int j){
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int match = 0;

        if(text1[i] == text2[j]){
            match = 1 + solve(text1, text2, i-1, j-1);
        }

        int notMatch = max(solve(text1, text2, i-1, j), solve(text1, text2, i, j-1));

        return dp[i][j] = max(match, notMatch);
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n1 = text1.length()-1;
        int n2 = text2.length()-1;

        memset(dp,-1, sizeof(dp));

        return solve(text1, text2, n1, n2);
    }
};