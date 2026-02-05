class Solution {
public:
    
    int binarysearch(int n){
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        int answer = -1;
        while(s<=e){
            long long int square = mid * mid;
            if(square == n){
                return mid;

            }
            if(square < n ){
                answer = mid ; 
                s = mid+1;
            }
            else {
                e = mid - 1;                
            }
            mid = s + (e-s)/2;
        }
        return answer;
    }

    int mySqrt(int x) {
        return binarysearch(x);        
    }
};