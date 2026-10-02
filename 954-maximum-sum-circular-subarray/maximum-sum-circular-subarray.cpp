class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        int mx = INT_MIN;
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
        }
        
        if (mx < 0) {
            return mx;
        }
        
        int ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum < 0) {
                sum = 0;
            } 
            ans = max(ans, sum);
        }
        
        int total_sum = 0;
        for (int i = 0; i < n; i++) {
            total_sum += nums[i];
        }
        
        int min_sub = 0, min_sum = 0;
        for (int i = 0; i < n; i++) {
            min_sum += nums[i];
            if (min_sum > 0) {
                min_sum = 0;
            }
            min_sub = min(min_sub, min_sum);
        }
        
        int circular_max = total_sum - min_sub;
        
        return max(ans, circular_max);
    }
};
