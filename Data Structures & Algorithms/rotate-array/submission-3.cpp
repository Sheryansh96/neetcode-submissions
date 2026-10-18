class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        
        k = k%n;
        int t = k;
        int i = n-k;
        while(k-- && i<n){
            ans.push_back(nums[i]);
            i++;
        }
        int j = 0;
        while(j<n-t){
            ans.push_back(nums[j]);
            j++;
        }
        if(ans.size() ==0){
            ans = nums;
        }
        nums = ans;
    }
};