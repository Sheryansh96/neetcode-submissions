class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> mul(n,1);
        mul[0] = 1;
        for(int i =1; i<n; i++){
            mul[i] = mul[i-1] * nums[i-1];
        }
        int right = 1;
        vector<int> ans(n,0);
        for(int i = n-1; i>=1; i--){
            int prod = right*mul[i];
            ans[i] = prod;
            right*=nums[i];
        }
        ans[0] = right;
        return ans;
        
    }
};
