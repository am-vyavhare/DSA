class Solution {
public:
    int search(vector<int>& nums, int target) {
    //initialise the boundaries of the binary search
    int size = nums.size();
    int start = 0;
    int end = size - 1;
    //traverse the arrray to check the mid contains the target
    while(start <= end){
        //calculate the mid
        int mid = start + (end - start)/2;
        //check the target
        if(nums[mid] == target){
            return mid;
        }
        //check if left part is sorted
        if(nums[start] <= nums[mid]){
            //check whether the element lies within this boundaries
            if(nums[start] <= target && target < nums[mid]){
                end = mid -1;
            }
            else{
                start = mid + 1;
            }
        }
        else{   //right part is sorted
            if(nums[mid] < target && target <= nums[end]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return -1;
    }
};