class Solution {
public:
//When duplicates make it impossible to determine which half is sorted, shrink the search range conservatively. The single-step approach may be slower when there are many duplicates, but it avoids accidentally skipping the target.
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(nums[mid] == target) return true;
            if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                lo++;
                hi--;
            }
            else if(nums[mid] >= nums[lo]){
                if(target >= nums[lo] && target < nums[mid]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(target > nums[mid] && target<= nums[hi]){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return false;
    }
};