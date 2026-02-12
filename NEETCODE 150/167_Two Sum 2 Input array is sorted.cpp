class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //declare two pointers start and end
        int start = 0;
        int end = numbers.size() - 1;
        //traverse and check if curr sum is less than target then increase start
        //and if greater than target then decrease end since we will move closer to the target
        while(start < end){
            int current_sum = numbers[start] + numbers[end];
            if(current_sum == target){
                return {start+1, end+1};
            }
            if(current_sum < target){
                start++;
            }
            else{
                end--;
            }
        }
        return {};
    }
};