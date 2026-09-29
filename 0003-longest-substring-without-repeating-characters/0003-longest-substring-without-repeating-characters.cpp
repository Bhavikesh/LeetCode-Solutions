class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int length = 0;
        int ans = 0;
        int i = 0;
        for(int j=0; j<s.length(); j++){
            char ch = s[j];
            map[ch]++;
            length++;

            if(map[ch] > 1){
                while(map[ch] > 1){
                    char c = s[i];
                    map[c]--;
                    i++;
                    length--;
                }
            }

            ans = max(length,ans);
        }

        return ans;
    }
};