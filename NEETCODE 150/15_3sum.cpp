class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        //step 1 - create vector to store triplets
        vector<vector<int>> result;
        int n = nums.size();
        //sort the given array
        sort(nums.begin(), nums.end());
        //traverse and find the compare a pair with i and check triplet by sum
        for(int i = 0; i < n - 2; i++){
            //skip duplicate elements for i 
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            //create two pointer to to find and handle balance to find triplet 
            //or reach pair to sum 0
            int left = i+1;
            int right = n - 1;
            while(left < right){
                //calculate the sum of 3
                int sum = nums[i] + nums[left] + nums[right];
                //check if triplet
                if(sum == 0){
                    //add to result
                    result.push_back({nums[i],nums[left],nums[right]});
                    
                    //skip duplicates from left so move left pointer
                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    
                    //skip duplicates from right so move right pointer
                    while(left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                //update pointer
                left++;
                right--;
                }
                else if(sum < 0){
                // less than 0 means we need to maximize the sum to find 
                //triplet so increase left
                    left++;
                }
                else{
                //greater than 0 means we need to minimize it to 0 so decrement right
                    right--;
                }
            }
        }
        return result;
    }
};