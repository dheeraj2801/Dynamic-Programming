/* Palindromic Substring
You are given a String str (of length n) and You have to find the no of Palindromic Substrings
I/P : abcbc
O/P : 9
TC : O(n * n)
SC : O(n * n)
*/
#include<bits/stdc++.h>
using namespace std;

int count(string str){
	int n=str.length();
	bool dp[n][n];
	int c=0;
	for(int g=0;g<n;g++){
		for(int i=0,j=g;j<n;i++,j++){
			if(g==0){
				dp[i][j]=true;
			}else if(g==1){
				if(str[i] == str[j]){
					dp[i][j]=true;
				}
				else{
					dp[i][j]=false;
				}
			}else{
				if(str[i]==str[j] && dp[i+1][j-1]){
					dp[i][j]=true;
				}else{
					dp[i][j]=false;
				}
			}
			if(dp[i][j]){
				c++;
			}
		}
	}
	return c;
}

int main(){

	string s="abccbc";
	cout << count(s) << "\n" ;

	return 0;
}