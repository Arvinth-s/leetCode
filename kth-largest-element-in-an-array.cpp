//OM NAMO NARAYANA
//https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/
class Solution {
public:
    
    //used in quicksort
    int partition(vector<int>& nums, int l, int h){
        //i lies in [l, j+1]. elements[l, i) are less than arr[h]; arr[i, j] are greater than arr[h] 
        //of each iteration
        int i = l, j = l;
        for(; j < h; j++){
            if(nums[j] < nums[h]){
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[j]);
        return i;
    }
    
    int findKthLargest(vector<int>& nums, int k){
        int l=0, h=nums.size()-1;
        k = nums.size() - k;
        if(h-l+1 < k)return -1;
        while(l < h){
            int idx = partition(nums, l, h);
            if(idx ==  k)return nums[idx];
            else if(idx < k)l=idx+1;
            else h=idx-1;
        }
        return nums[l];
    }

};