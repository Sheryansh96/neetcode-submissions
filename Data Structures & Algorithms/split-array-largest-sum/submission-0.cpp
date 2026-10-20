class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int max_int = 0;
        int n = nums.size();
        int ans = 1;
        for(int i=0; i<n; i++){
            sum += nums[i];
            max_int = max(nums[i], max_int);
        }
        int lo = max_int, hi = sum;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            int k1 = 1;
            int a = 0;
            for(int i = 0; i<n; i++){
                a += nums[i];
                if(a>mid){
                    k1++;
                    a=nums[i];
                }
            }
            if(k1 > k){
                lo = mid+1;
            }
            else{
                hi = mid-1;
                ans = mid;
            }
        }
        return ans;
    }
};