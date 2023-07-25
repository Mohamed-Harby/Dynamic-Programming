class Solution {
    private ArrayList<ArrayList<Integer>> cuboidList;
    private int n;
    int[] dp;

    private int dp(int idx) {
        if (idx >= n) {
            return 0;
        }

        if (dp[idx] != -1) {
            return dp[idx];
        }

        int ans = 0;
        for (int j = idx + 1; j < n; ++j) {
            if (cuboidList.get(idx).get(0) >= cuboidList.get(j).get(0) &&
                cuboidList.get(idx).get(1) >= cuboidList.get(j).get(1) &&
                cuboidList.get(idx).get(2) >= cuboidList.get(j).get(2)
            ) {
                ans = Math.max(ans, dp(j));
            }
        }
        ans += cuboidList.get(idx).get(0);
        return dp[idx] = ans;
    }

    public int maxHeight(int[][] cuboids) {
        this.n = cuboids.length;
        this.cuboidList = new ArrayList<>();
        for (int[] cuboid : cuboids) {
            ArrayList<Integer> innerList = new ArrayList<>();
            for (int value : cuboid) {
                innerList.add(value);
            }
            Collections.sort(innerList, Collections.reverseOrder());
            this.cuboidList.add(innerList);
        }

        cuboidList.sort((list1, list2) -> {
            for (int i = 0; i < list1.size(); i++) {
                int compareResult = Integer.compare(list2.get(i), list1.get(i));
                if (compareResult != 0) {
                    return compareResult;
                }
            }
            return 0;
        });


        this.dp = new int[this.n];
        for (int i = 0; i < n; ++i) {
            dp[i] = -1;
        }
        int ans = 0;
        for (int i = 0; i < this.n; ++i) {
            ans = Math.max(ans, dp(i));
        }
        return ans;
    }
}
