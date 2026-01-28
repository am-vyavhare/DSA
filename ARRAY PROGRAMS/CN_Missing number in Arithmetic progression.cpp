//first approach by finding the difference by dividing total by n
#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &arr, int n) 
{
    // Calculate the correct common difference of the AP
    // Total difference divided by number of elements
    int diff = (arr[n - 1] - arr[0]) / n;

    // Traverse the array to find where the progression breaks
    for (int i = 0; i < n - 1; i++) {

        // If next element is not following the AP rule
        if (arr[i + 1] - arr[i] != diff) {

            // Missing number is current element + common difference
            return arr[i] + diff;
        }
    }

    // If no missing number is found (safe fallback)
    return -1;
}


//second approach by finding the correct progression from starting element
#include <bits/stdc++.h> 
int missingNumber(vector<int> &arr, int n) 
{
    //variable to store first progression
    int firstprogression = arr[1]-arr[0];
    //variable to store second progression
    int secondprogression = arr[2] - arr[1];

    int finalprogression= 0;
    //if they are equal then we found the final progression
    if(firstprogression == secondprogression){
        finalprogression = firstprogression;
    }
    //else check which is correct progression , since the smaller progression is correct progression 
    //because big difference shows missing element
    else{
        //if first is small then it is final
        if(firstprogression <= secondprogression){
            finalprogression = firstprogression;
        }
        else{
        //otherwise final propression is greater / 2
            finalprogression = firstprogression/2;
        }
    }
 
    //traverse through the array and if missing found return by adding correct progression
    for(int i = 0; i < n-1; i++){
        int progression = arr[i+1] - arr[i];
        //if found calculate missing and return 
        if(finalprogression != progression){
            return arr[i]+finalprogression;
        }  
    } 
}