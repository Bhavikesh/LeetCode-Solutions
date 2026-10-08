class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int mini = INT_MAX;
        unordered_map<int,bool> map;
        for(auto i: nums){
            map[i] = true;
            if(i >= 0){
                mini = i<mini?i:mini;
            }
        }

        if(mini > 1) return 1;

        while(true){
            if(!map[mini]){
                return mini;
            }
            mini++;
        }

        return 0;
    }
};