class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0;
        int right = m;
        int total_left_size = (m + n + 1) / 2;
        
        while (left <= right) {
            int mid1 = left + (right - left) / 2;
            int mid2 = total_left_size - mid1;
            
            int maxLeft1, minRight1, maxLeft2, minRight2;
  
            if (mid1 == 0) {
                maxLeft1 = INT_MIN;
            } else {
                maxLeft1 = nums1[mid1 - 1];
            }
            
            if (mid1 == m) {
                minRight1 = INT_MAX;
            } else {
                minRight1 = nums1[mid1];
            }
            
            if (mid2 == 0) {
                maxLeft2 = INT_MIN;
            } else {
                maxLeft2 = nums2[mid2 - 1];
            }
            
            if (mid2 == n) {
                minRight2 = INT_MAX;
            } else {
                minRight2 = nums2[mid2];
            }
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 != 0) {
                    return max(maxLeft1, maxLeft2);
                }
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } 
            else if (maxLeft1 > minRight2) {
                right = mid1 - 1; 
            } 
            else {
                left = mid1 + 1; 
            }
        }
        
        return 0;
    }
    
};