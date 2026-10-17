class Solution {
public:

    int getDigitSum(int num){
        int sum = 0;

        while(num){
            sum += num%10;
            num/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<int> afterSorted(nums);

        auto lamba = [&](int num1, int num2){
            int num1digitSum = getDigitSum(num1);
            int num2digitSum = getDigitSum(num2);

            if(num1digitSum != num2digitSum) return num1digitSum < num2digitSum;

            return num1 < num2;
        };

        sort(begin(afterSorted), end(afterSorted), lamba);

        unordered_map<int,int> valToIdx;
        for(int i=0; i<n; i++){
            valToIdx[nums[i]] = i;
        }

        int swap = 0;

        for(int i=0; i<n; i++){
            int expectedVal = afterSorted[i];
            int currVal = nums[i];

            if(expectedVal == currVal) continue;

            int idx = valToIdx[expectedVal];

            nums[i] = expectedVal;
            nums[idx] = currVal;

            valToIdx[expectedVal] = i;
            valToIdx[currVal] = idx;

            swap++;
        }

        return swap;
    }
};