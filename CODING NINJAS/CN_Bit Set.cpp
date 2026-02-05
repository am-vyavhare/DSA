#include <bits/stdc++.h> 
int findFirstRepeatingDigit(string digitPattern){
    //variable to store size of string
    int size = digitPattern.size();
    //vector to collect count of occurences of digit
    vector<int> freq(10,0);
    //traverse through the string
    for(int i = 0; i < size; i++){
        //find digit so that we can increase count in correct index
        int index = digitPattern[i] - '0'; 
        // ASCII Of digits are from 48-57 (0-9) so for original digit - '0' is used
        freq[index]++;
        //if any digit encountered twice then return 
        if(freq[index] == 2){
            return digitPattern[i] - '0';
        }
    }
    //else no repeat found
    return -1;
}