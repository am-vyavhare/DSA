class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //create one vector to store the result 
        vector<int> result;
        //create deque to store the indices of elements in array
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++){
            //Remove elements index outside the window limit
            if(!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            //remove smaller value index from back since they cant be maximum
            //if current is greater so keep the elements in decreasing order
            while(!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();

            //add the current element index in deque
            dq.push_back(i);

            //window start producing result after first k elements index reach
            if(i >= k-1){
                //front contain the maximum element index add the value in result
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};