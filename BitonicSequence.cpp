/*
You are given array, find the Longest Bitonic Subsequence
Bitonic Sequence is a Sequence which will
Increase and Decrease : /\
Increase : /
Decrease : \
I/P : 10 22 9 33 21 50 41 60 80 3
O/P : 7
TC : O(n * n)
SC : O(n * n)
*/
#include<bits/stdc++.h>
using namespace std;

int Bitonic_Sequence(int arr[], int n){
	int lis[n];		//Longest Increasing Subsequence
	int lds[n];		//Longest Decreasing Subsequence

	memset(lis,0,sizeof lis);
	memset(lds,0,sizeof lds);

	for(int i=0;i<n;i++){
		int max=0;
		for(int j=0;j<i;j++){
			if(arr[j]<=arr[i]){
				if(lis[j]>max){
					max=lis[j];
				}
			}
		}
		lis[i]=max+1;
	}

	for(int i=n-1;i>=0;i--){
		int max=0;
		for(int j=n-1;j>i;j--){
			if(arr[j]<=arr[i]){
				if(lds[j]>max){
					max=lds[j];
				}
			}
		}
		lds[i]=max+1;
	}
	int maxval=0;
	for(int i=0;i<n;i++){
		if(lis[i]+lds[i]-1>maxval){
			maxval=lis[i]+lds[i]-1;
		}
	}
	return maxval;

}

int main(){

	int arr[] = {10,22,9,33,21,50,41,60,80,3};
	int n = 10;
	cout << Bitonic_Sequence(arr, n) << "\n" ;

	return 0;
}
