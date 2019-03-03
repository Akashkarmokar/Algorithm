/*
	Problem solved by Akash Karmokar Aditto
	Metropolitan University,Bangladesh.
	Department of Computer Science and Engineering
*/
#include<bits/stdc++.h>
#include<stdio.h>
#define i64 long long 
using namespace std;
i64 M;
i64 F(i64 N,i64 P){
	if(P==0) return 1;
	if(P%2==0){
		return ((F(N,P/2))%M*(F(N,P/2))%M)%M;
	}
	else return ((N%M)*(F(N,P-1))%M)%M;
}

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

	printf("Enter the no of Divider:");
	M=scan_int();
	printf("\n");
	int base,power;
	printf("Enter The no of Base and power:");
	base= scan_int();
	power = scan_int();
	printf("\n");
	printf("Mod of this number is :%d",F(base,power));

	return 0;
}
/*
If where we do that fact = (100!)%97 ,then overflow must be occured int the code ,so we have to use Big mode methodology.

Formula of big mod is :
						(a+b)%m = ((a%m)+(b%m))%m
						(a*b)%m = ((a%m)*(b%m))%m
*/