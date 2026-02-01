class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create a unordered map to store value and indices
        unordered_map<int , int> mp;
        //traverse through an array and check any index contains value that fulfill target
        for(int i = 0; i < nums.size(); i++){
            //calculate needed
            int needed = target - nums[i];
            //check needed exist in map or not if yes then mp.find return result iteretor that is not equal to empty set that is return by mp.end() or else element not found then condition become false empty set != empty set -> false
            if(mp.find(needed) != mp.end()){
                return {mp[needed], i};
            }
            //add the element in the unordered map
            mp[nums[i]] = i;
        }
        return {};
    }
};