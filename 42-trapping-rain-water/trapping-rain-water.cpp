class Solution {

public:
    int trap(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        int ans = a[0];
        leftMax[0] = 0;
        for (int i = 1; i < n; ++i) {
            leftMax[i] = ans;
            ans = max(ans, a[i]);
        }

        ans = a[n - 1];
        rightMax[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = ans;
            ans = max(ans, a[i]);
        }

        int water = 0;
        for (int i = 0; i < n; ++i) {
            int minHeight = min(leftMax[i], rightMax[i]);
            if (minHeight - a[i] > 0) {
                water += (minHeight - a[i]);
            }
        }

        return water;
    }
};
