class Solution {
public:
    // class trieNode{
    //     trieNode* child[26];
    //     int data;
    //     int childCount;
    //     bool isTerminal;


    // }
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        
        int n = strs.size();

        int i = 0;
        int j = 0;
        int firstSize = strs[0].size();
        int secondSize = strs[n-1].size();

        string first  = strs[0];
        string last = strs[n-1];

        string ans = "";
        while(i < firstSize && j < secondSize){
            if(first[i]!=last[j]){
                break;
            }
            ans+=first[i];
            i++;
            j++;
        }
        return ans;
    }
};