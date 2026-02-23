class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        //declare one vector to store the pair of position and speed of car
        vector<pair<int,int>> cars;
        int len = position.size();
        //add position and speed as a pair in vector
        for(int i = 0; i < len; i++){
            cars.push_back({position[i], speed[i]});
        }
        //sort the vector of pairs in descending order to make the cars sequence closest to farthest
        sort(cars.begin(), cars.end(),greater<pair<int,int>>());
        //declare one stack to store the current pair time required to reach target at top and traverse
        //and if new pair time is grester then top time then they cannot make fleet with the previous 
        //so add to stack calculate new fleet
        stack<double> stk;
        for(int i = 0; i < len; i++){
            //calculate the time of current car
            double time =(double)(target - cars[i].first)/cars[i].second;
            //if stack empty then add current time is greater add for new fleet
            if(stk.empty() || stk.top() < time){
                stk.push(time);
            }
        }
        return stk.size();
    }
};