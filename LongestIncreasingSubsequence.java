// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
    int[] nums;
    int[] dp;

    public int LIS(int idx) {
        if (idx >= nums.length) {
            return 0;
        }

        if (dp[idx] != -1) return dp[idx];

        int ans = 0;
        for (int i = idx + 1; i < nums.length; ++i) {
            if (nums[i] > nums[idx]) {
                ans = Math.max(ans, LIS(i));
            }
        }
        ans++;
        return dp[idx] = ans;
    }

    public int lengthOfLIS(int[] nums) {
        this.nums = new int[nums.length];
        this.dp = new int[nums.length];
        System.arraycopy(nums, 0, this.nums, 0, nums.length);
        for (int i = 0; i < nums.length; ++i) dp[i] = -1;

        int res = 0;
        for (int i = 0; i < nums.length; ++i) {
            res = Math.max(res, LIS(i));
        }
        return res;
    }
}