class Solution {
public:
    vector<int>topKFrequent(vector<int>& nums, int k){
        //Step 1 - create a unordered map to store the frequency of the elements
        int n = nums.size();
        unordered_map<int,int> count;
        //Traverse through the array and count the frequency of each number
        for(int i = 0; i < n; i++){
            count[nums[i]]++;
        }   
        //create 1 vector of size nums.size() to store the frequency as index and value
        //as vector of elements that have same frequency
        vector<vector<int>> bucket(n+1);
        for(auto& it:count){
            int number = it.first;
            int freq = it.second;
            bucket[freq].push_back(number);
        }
        //Result vector
        vector<int> result;
        for(int i = n; i >= 0 && result.size() < k ; i--){
            for(int num : bucket[i]){
                result.push_back(num);
                if(result.size() == k)
                    break;
                }
        }      
    return result;       
    }
};