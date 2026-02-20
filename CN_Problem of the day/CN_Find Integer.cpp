#include <bits/stdc++.h> 
int findInteger(int n, int k) 
{
    //find the total odd number in sequence
    int totalodds = (n+1)/2;
    //if odd number then calculate and return 
    if(k <= totalodds){
        return (k*2)-1;
    }
    else{
    //if even then calculate the even and return
        return 2*(k - totalodds);
    }
}
