#include<iostream>
#include<vector>
using namespace std;
#include <bits/stdc++.h> 

bool isPossible(vector<int> arr,int n, int m, int mid){
	
	int StudentCount = 1;
	int pagesum = 0;

	for(int i = 0; i<n ; i++){
		
	if(pagesum + arr[i] <= mid){
		pagesum = pagesum + arr[i];
	}
	else{
		StudentCount++;
		
		if(StudentCount > m || arr[i] > mid){
			return false;
		}
		pagesum = arr[i];
	}
	}
	return true;
}


long long ayushGivesNinjatest(int n, int m, vector<int> arr) 
{	
	// Write your code here.
	int s = 0;
	int sum = 0;

	for(int i = 0; i < n ; i ++){
		sum = sum + arr[i];
	}

	int e = sum;
	int ans = -1;
	int mid = s + (e-s)/2;
	
	while(s<=e){
		
		if(isPossible(arr,n,m,mid)){
			ans = mid;
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
		
		mid = s + (e-s)/2;
	}
	return ans;
}