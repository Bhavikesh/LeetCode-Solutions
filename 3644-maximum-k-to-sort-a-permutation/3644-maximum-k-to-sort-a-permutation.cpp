class Solution {
public:
    int sortPermutation(vector<int>& nums) {

        if(is_sorted(nums.begin(), nums.end())) return 0;
        int ans = -1;

        for(int i=0; i<nums.size(); i++){
            if(ans==-1 && nums[i]!=i){
                ans = nums[i];
            }
            else if(nums[i] != i){
                ans = ans&nums[i];
            }
        }
        return ans;

    }
};