class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for(auto i:s){
            map1[i]++;
        }
        for(auto i:t){
            map2[i]++;
        }
        return map1 == map2;       
    }
};