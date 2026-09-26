class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> frq(26,0);

        for(auto i:sentence){
            if(i==' ') continue;
            frq[i-'a']++;
        }

        for(auto i:frq){
            if(i==0){
                return false;
            }
        }
        return true;
    }
};