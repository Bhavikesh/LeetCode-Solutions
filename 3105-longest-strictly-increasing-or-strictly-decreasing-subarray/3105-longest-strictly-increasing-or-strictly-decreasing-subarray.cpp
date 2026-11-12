class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
        int maxi = 1;
        int mini = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] < nums[i]) {
                maxi++;
                mini = 1;
            }
            else if(nums[i-1] > nums[i]) {
                mini++;
                maxi = 1;
            }
            else {
                maxi = 1;
                mini = 1;
            }

            ans = max(ans, max(maxi, mini));
        }

        return ans;
    }
};