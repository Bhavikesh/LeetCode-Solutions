class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end(),greater<int>());

        int n = nums.size();
        int go = (n/2) + (n%2);
        long long ans = 0;
        
        for(auto i:nums){
            if(go>0){
                ans += i*i;
                go--;
            }else{
                ans -= i*i;

            }

        }
        return ans;
    }
};