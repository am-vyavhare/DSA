class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //Step 1 - define search space for k - that is speed of eating banana at each hour
        int low = 1;
        //find the maximum bananas present in the each single pile
        int high = *max_element(piles.begin(), piles.end());

        //Step 2 - variable to store answer initially use max banana as speed
        int answer = high;

        //Step 3 - apply binary search on possible speed that is from low to high
        while(low <= high){

            int mid = low + (high - low) / 2;

            //Step 4 - calculate total hours needed at speed mid
            long long hours = 0;

            for(int bananas : piles){
                //we need the ciel value so we have added mid -1 in bananas that will overcome that problem
                hours += (bananas + mid - 1) / mid;
            }

            //Step 5 - check feasibility
            if(hours <= h){
                //mid works, try smaller speed to find the minimum
                answer = mid;
                high = mid - 1;
            }
            else{
                //require more hours than expected so mid too slow, increase speed t
                low = mid + 1;
            }
        }
        //Step 6 - return minimum valid speed
        return answer;
    }
};