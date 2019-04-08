#include<bits/stdc++.h>
#include<math.h>
#define Max 9999999
#define not_prime true
#define prime flase

using namespace std;
bool one_to_n[Max]; // eveery one_to_n[i] is 0


int main()
{
    int sqr  = sqrt(Max);
    one_to_n[0]=not_prime; //1 means not prime this number 
    one_to_n[1]=not_prime;
    //one_to_n[2]=0; that has no need .We globally decleare first every number is prime ;
    for(int i = 4 ;i<Max;i+=2) one_to_n[i]=not_prime;
    for(int i = 3;i<=sqr;i+=2){
        if(one_to_n[i]=0){
            for(int j = i*i ;j<Max;j+=i){
                one_to_n[j]=not_prime;
            }
        }
    }
    cout<<"Enter a number(Range Is 0 to "<<Max<<"):"<<endl;
    int input;
    cin>>input;
    if(one_to_n[input]==0){
        cout<<"Your Number is Prime"<<endl;
    }
    else
    {
        cout<<"Entered Number is not Prime"<<endl;
    }    
    return 0;
}

//Problem Link : Uva = 543,686,10394,10533.
