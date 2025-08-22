#include <bits/stdc++.h> 

int partition(vector<int>& arr, int start, int end){
    
    int pivot_element = arr[start];
    int count = 0;
    
    for(int i = start+1; i <= end ; i++){
        if(arr[i] <= pivot_element){
            count++;
        }
    }

    int pivot_index = start + count;
    swap(arr[start],arr[pivot_index]);


    int i = start;
    int j = end;
    
    while(i < pivot_index && j > pivot_index){
        
        while(arr[i] <= pivot_element){
            i++;
        }

        while(arr[j] > pivot_element){
            j--;
        }

        if( i < pivot_index && j > pivot_index){
            swap(arr[i++],arr[j--]);
        }
    }

    return pivot_index;
}

void quickSort_Solution(vector<int>& arr, int start, int end){
    
    if(start>=end){
       return; 
    }

    int pivot_position = partition(arr, start, end);

    //Left partition    
    quickSort_Solution(arr, start, pivot_position-1);

    //right partition
    quickSort_Solution(arr, pivot_position+1 , end);

}

vector<int> quickSort(vector<int> arr)
{
    quickSort_Solution(arr, 0, arr.size()-1);
    
    return arr;
    // Write your code here.
}
