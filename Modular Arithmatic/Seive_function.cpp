#include<iostream>
#include<math.h>
using namespace std;
#define Max 10000007
int prime[Max];

void seive()
{
    prime[0] = 1 ;
    prime[1] = 1 ;
    for(int i = 4 ; i<Max  ; i+=2)
    {
        prime[i] = 1 ;  // one means not prime ..prime array is decleard in global scope .so initially all value are 0
                       // that means initially all value of prime array are in prime .
    }
    int root = sqrt(Max);
    for(int i = 3 ;i<root ;i+=2)
    {
        if(prime[i]==0)
        {
            for(int j = i*i ;j<Max ;j+=i)
            {
                prime[j] = 1 ;
            }
        }
    }
    
}

int main()
{
    seive();
    int number ;
    cin>>number ;
    cout<<prime[number];
    return 0 ;
}