class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int ascCnt = 0;
        int dscCnt = 0;

        for(int i=1; i<n; i++){
            ascCnt += (nums[i] == (nums[i-1]+1)%n);
            dscCnt += (nums[i-1] == (nums[i]+1)%n);
        }

        if(ascCnt == n-1 && nums[0]==0) return 0; 

        if(ascCnt == n-1){
            int leftMoves = n-nums[0];
            int rightMoves = 1 + (nums[n-1]+1) + 1;

            return min(leftMoves, rightMoves);
        }

        if(dscCnt == n-1){
            int leftMoves = n - nums[n-1] + 1;
            int rightMoves = (nums[0]+1)%n + 1;   
            return min(leftMoves, rightMoves);
        }

        return -1;
    }
};