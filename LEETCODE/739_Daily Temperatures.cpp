class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    //create one stack to store the index of the temperature
    stack<int> stk;
    vector<int> answer(temperatures.size(), 0);
    //traverse through the temperature
    for(int i = 0; i < temperatures.size(); i++){
        //check if stk empty if yes then push current index and go to next iteration
        //until we get the smaller elements than current element in stack assign the current day 
        //as their next warm day
        while(!stk.empty() && temperatures[stk.top()] < temperatures[i]){
                answer[stk.top()] = i - stk.top(); //calculate no of days
                stk.pop(); //remove the top whose count is found
            }
            stk.push(i);    //push the current element on top
        }
        return answer;
    }
};