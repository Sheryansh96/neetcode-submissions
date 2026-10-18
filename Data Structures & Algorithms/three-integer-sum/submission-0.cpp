class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int lo=i+1, hi=n-1;
            if(nums[i]>0) break;
            while(lo<hi){
                int sum = nums[i]+nums[lo]+nums[hi];
                if(sum==0){
                    ans.push_back({nums[i],nums[lo],nums[hi]});
                    lo++;
                    hi--;
                    while(lo<hi && nums[lo-1] == nums[lo]) lo++;
                    while(lo<hi && nums[hi+1] == nums[hi]) hi--;
                }
                else if(sum < 0){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }
        return ans;
    }
};
