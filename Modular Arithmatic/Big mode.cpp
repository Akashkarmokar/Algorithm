/*	
	Problem solved by Akash Karmokar Aditto
	Metropolitan University,Bangladesh.
	Department of Computer Science and Engineering
*/
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int scan_int(){
	int x;
	scanf("%d",&x);
	return x;
}
int main()
{
	#ifndef Akash_Karmokar
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int fact = 1;
	for(int i = 1;i<=100;i++){
		fact = ((fact%97)*(i%97))%97;
	}
	printf("%d",fact);
	return 0;
}
/*
If where we do that fact = (100!)%97 ,then overflow must be occured int the code ,so we have to use Big mode methodology.

Formula of big mod is :
						(a+b)%m = ((a%m)+(b%m))%m
						(a*b)%m = ((a%m)*(b%m))%m
*/