class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            vector<int> rotated(nums);
            bool possible = true;

            for (int i = 0; i < n; i += k) {
                int best = -1;

                for (int r = 0; r < k; r++) {
                    bool sorted = true;

                    for (int j = 0; j < k - 1; j++) {
                        if (nums[i + (j + r) % k] >
                            nums[i + (j + 1 + r) % k]) {
                            sorted = false;
                            break;
                        }
                    }

                    if (sorted) {
                        best = r;
                        break;
                    }
                }

                if (best == -1) {
                    possible = false;
                    break;
                }

                for (int j = 0; j < k; j++) {
                    rotated[i + j] = nums[i + (j + best) % k];
                }
            }

            if (possible) {
                for (int i = 0; i < n - 1; i++) {
                    if (rotated[i] > rotated[i + 1]) {
                        possible = false;
                        break;
                    }
                }
            }

            if (possible) {
                ans += k;
            }
        }

        return ans;
    }
};