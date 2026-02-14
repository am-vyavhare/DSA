class Solution {
public:
    int maxProfit(vector<int>& prices){

        //Step 1 - initialize max profit as 0
        int maxprofit = 0;

        //Step 2 - assume first day is minimum buying price
        int lastmin = prices[0];

        //Step 3 - traverse from day 1
        for(int i = 1 ; i < prices.size(); i++){

            //calculate profit if sold today
            int profit = prices[i] - lastmin;

            //update maximum profit
            maxprofit = max(maxprofit, profit);

            //update minimum buying price
            if(prices[i] < lastmin){
                lastmin = prices[i];
            }
        }

        return maxprofit;
    }
};
