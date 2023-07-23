class Solution {
    int[] nums;
    final int MAX_SIZE = 205;
    final int MAX_VALUE = 10005;

    int[][] dp = new int[MAX_SIZE][MAX_VALUE];

    private boolean subsetSum(int idx, int remaining_sum) {
        if (idx >= this.nums.length) {
            return false;
        }

        if (dp[idx][remaining_sum] != -1) {
            return dp[idx][remaining_sum] == 1;
        }

        boolean ans = this.nums[idx] == remaining_sum;

        if (this.nums[idx] > remaining_sum) {
            ans = subsetSum(idx + 1, remaining_sum);
        } else if (this.nums[idx] < remaining_sum) {
            ans = subsetSum(idx + 1, remaining_sum - this.nums[idx]) ||
                    subsetSum(idx + 1, remaining_sum);
        }
        dp[idx][remaining_sum] = ans ? 1 : 0;
        return ans;
    }

    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
        }
        if ((sum & 1) == 1) return false;
        this.nums = new int[nums.length];
        System.arraycopy(nums, 0, this.nums, 0, nums.length);

        for (int i = 0; i < MAX_SIZE; ++i) {
            for (int j = 0; j < MAX_VALUE; ++j) {
                this.dp[i][j] = -1;
            }
        }

        return subsetSum(0, sum >> 1);

    }
}
