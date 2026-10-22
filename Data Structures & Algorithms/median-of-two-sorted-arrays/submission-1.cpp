class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n) return findMedianSortedArrays(nums2, nums1);

        int total = m+n;
        int leftsize = (m+n+1)/2;
        int lo = 0, hi = m;
        while(lo<=hi){
            int i = (lo+hi)/2;
            int j = leftsize - i;
            int lmin, lmax, rmin, rmax;
            lmin = i==0?INT_MIN:nums1[i-1];
            lmax = i==m?INT_MAX:nums1[i];
            rmin = j==0?INT_MIN:nums2[j-1];
            rmax = j==n?INT_MAX:nums2[j];
            if(lmin > rmax){
                hi = i-1;
            }
            else if(rmin > lmax){
                lo = i+1;
            }
            else{
                if(total%2 != 0){
                    return max(lmin,rmin);
                }
                else{
                    return (max(lmin,rmin) + min(lmax,rmax))/2.0;
                }
            }
        }
        return -1;

    }
};

/*
    the left array will always have m+n+1 elements

    odd -> leftarray always has the median -> 
    (1,2,3,4,5)
    5 = (5+1)/2 = 3  -> last number of the leftarray (leftNums1[i], leftNums2[j])

    i = 0-m
    j = (m+n+1)/2 - i; 
    nums1 = leftNums1, rightnums1;
    nums2 = leftNums2, rightnums2;

    leftNums1[i] < rightnums2[0] && leftNums2[j] < rightnums1[0] -> good
    
    if (leftNums1[i] > rightnums2[0]) lo = mid-1;
    else if(leftNums2[j] > rightnums1[0]) hi = mid+1;
*/
