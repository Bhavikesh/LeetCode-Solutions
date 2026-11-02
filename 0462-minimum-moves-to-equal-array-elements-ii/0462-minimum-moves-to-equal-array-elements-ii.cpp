class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return 0;
        sort(nums.begin(), nums.end());
        int medianIdx = n/2;

        int sum = 0;
        for(auto i:nums){
            sum += i>nums[medianIdx]?(i-nums[medianIdx]):(nums[medianIdx]-i);
        }

        return sum;
    }
};