class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        k = k%n;
        if(k == 0) return;
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
        nums = ans;
    }
};