class Solution {
public:

    void merge(vector<int>& arr, int start, int mid, int end){
        int n1 = mid - start +1;
        int n2 = end - mid;
        vector<int> L(n1), R(n2);
        for(int i = 0; i<n1; i++){
            L[i] = arr[start+i];
        }
        for(int i = 0; i<n2; i++){
            R[i] = arr[mid+i+1];
        }
        int k = start;
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2){
            if(L[i] < R[j]){
                arr[k] = L[i];
                i++;
            }
            else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while(i<n1){
            arr[k] = L[i];
            i++;
            k++;
        }
        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<int>& nums, int start, int end){
        if(start >= end) {
            return;
        }
        int mid = (start + end)/2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid+1, end);
        merge(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};