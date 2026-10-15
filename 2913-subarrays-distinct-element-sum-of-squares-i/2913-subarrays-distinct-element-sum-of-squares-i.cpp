
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int windowSize = 1;
        int n = nums.size();
        int uttar = 0;

        while (windowSize <= n) {
            unordered_map<int, int> freq;
            int i = 0;
            int j = 0;

            for (; j < windowSize; j++) {
                freq[nums[j]]++;
            }

            int motu = freq.size();
            uttar += motu * motu;

            while (j < n) {
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                }
                i++;

                freq[nums[j]]++;
                j++;

                motu = freq.size();
                uttar += motu * motu;
            }

            windowSize++;
        }

        return uttar;
    }
};
