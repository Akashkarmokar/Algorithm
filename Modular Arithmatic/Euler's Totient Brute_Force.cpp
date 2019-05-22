#include<iostream>
using namespace std ;

int gcd(int a , int b )
{
    if(a%b == 0 ) return b ;
    else gcd(b,a%b);
}
int main()
{
    int counter = 0 ;
    int number ;
    cout<<"Enter A number : ";
    cin>>number ;
    for(int i = 1 ;i<= number; i++)
    {
        if(gcd(i,number)==1)
        {
            counter++;
        }
    }
    cout<<"Phi of "<<number<<" is : "<<counter<<endl;
    return 0 ;
}