//Method 1 - Iterative approach
int search(vector<int>& nums, int target) {
    //declare start and end pointer
    int start = 0;
    int end = nums.size() - 1;
    //traverse until both pointer cross each other
    while(start <= end){
        //calculate the current mid
        int mid = start + (end - start) / 2;
        //if found at mid then return target
        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
            start = mid + 1; //search in right part
        else
            end = mid - 1;  //search in left part 
    }
    //if not fount return -1
    return -1;
}

//Method 2 - using recursion 
class Solution {
public:
    int BinarySearch(vector<int>& nums, int start, int end, int target){
        //if pointers cross each other means element not found
        if(start > end){
            return -1;
        }
        //calculate mid for the current part 
        int mid = start + (end - start)/2;
        //check if the element is at the mid position 
        //recursively traverse the left and right part of the array to find target
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){ //left part target is smaller
            return BinarySearch(nums, start, mid-1, target);
        }
        else{   //right part target is bigger
            return BinarySearch(nums, mid+1, end, target);
        }
    }
    int search(vector<int>& nums, int target) {
        //Declare the start and the end pointer for the binary search 
        int start = 0;
        int end = nums.size() - 1;
        //Call the Binary Search Function with respective parameters
        return BinarySearch(nums, start, end, target);
    }
};