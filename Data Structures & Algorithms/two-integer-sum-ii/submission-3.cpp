class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for(int i = 0; i<n; i++){
            int num = target-numbers[i];
            int lo = i+1;
            int hi = n-1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(numbers[mid] == num){
                    return {i+1, mid+1};
                }
                else if(numbers[mid] < num){
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return {};
    }
};
