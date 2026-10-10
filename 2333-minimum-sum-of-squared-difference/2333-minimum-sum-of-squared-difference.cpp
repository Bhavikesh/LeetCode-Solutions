class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();
        vector<int> diff(100001,0);

        for(int i=0; i<n; i++){
            diff[abs(nums1[i] - nums2[i])]++;
        }

        int k = k1+k2;

        for(int i = 100000; i>0 && k>0; i--){
            int currOperation = min(diff[i], k);
            diff[i] = diff[i]-currOperation;
            diff[i-1] = diff[i-1] + currOperation;
            k -= currOperation;
        }
        
        long long ans = 0;

        for(long long i=0; i<100001 ; i++){
            ans += (diff[i]*(i*i));
        }
        
        return ans;
    }
};