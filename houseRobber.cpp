class Solution {
public:
    int solveRec(vector<int>& nums, int i) {
        if (i >= nums.size())
            return 0;

        int include = nums[i] + solveRec(nums, i + 2);
        int exclude = solveRec(nums, i + 1);
        return max(include, exclude);
    }

    int solveMemo(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int include = nums[i] + solveRec(nums, i + 2);
        int exclude = solveRec(nums, i + 1);
        dp[i] = max(include, exclude);
        return dp[i];
    }

    int solveTab(vector<int>& nums, int i,int n) {
        vector<int> dp(n + 2, 0); // we have done 2 steps in just one line
         //step1:create dp array and step 2 analyze base case and update dp array.

        for (int i = n - 1; i >= 0; i--) {
            int include = nums[i] + dp[i + 2];
            int exclude = dp[i + 1];
            dp[i] = max(include, exclude);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        return solveTab(nums,i,n);
        // vector<int> dp(n + 1, -1);
        // return solveMemo(nums, i, dp);

        // return solveRec(nums,i);
    }
};
