#include<bits/stdc++.h>
using namespace std;

#define ll long long 
const int limit = 32000; // sqrt(m or n) 
const int Max = 1e6+5;
vector<int>primes;
int segPrimes[Max];

void sieve()
{
    bool isPrime[limit];
    for(int i =0;i<limit;i++)
        isPrime[i]=true;
    isPrime[0]=false;
    isPrime[1]=false;
    for(int i=4;i<=limit;i+=2)
        isPrime[i]=false;
    for(int i=3;i*i<=limit;i+=2)
    {
        if(isPrime[i]==true)
        {
            for(int j=i*i;j<=limit;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    primes.push_back(2);
    for(int i=3;i<limit;i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

void segmentedSieve(ll left,ll right)
{
    bool isPrime[right-left+1];
    for(int i=0;i<right-left+1;i++)
        isPrime[i]=true;
    
    if(left==1)
        isPrime[0]=false;
    for(int i=0;primes[i]*primes[i]<=right;i++)
    {
        int cp= primes[i];     //current prime
        int base = (left/cp)*cp;
        if(base<left)
            base+=cp;
        for(int j=base;j<=right;j+=cp)
        {
            isPrime[j-left]=false;
        }
        if(base==cp)
            isPrime[base-left]=true;
    }
    for(int i=0;i<right-left+1;i++)
    {
        if(isPrime[i])
        {
            cout<<(i+left)<<endl;
        }
    }
}

int main()
{
    sieve();
    int tc;
    cin>>tc;
    while(tc--)
    {
        int m,n;
        cin>>m>>n;
        segmentedSieve(m,n);
    }
    return 0;
}


// Problem link : https://www.spoj.com/problems/PRIME1/