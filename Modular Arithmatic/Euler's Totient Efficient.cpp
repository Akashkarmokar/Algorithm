#include<iostream>
using namespace std; 

#define Max 10000005
int phi[Max];

void totient()
{
    phi[1]=1;
    int factor_ase = 0 ;
    for(int i = 2 ; i<Max ; i++)
    {
        if(phi[i]==0)
        {
            phi[i] = i - 1 ;
            for(int j = i*2 ; j<Max ;j+=i)
            {
                if(phi[j]==0)
                {
                    phi[j]=j;
                }
                factor_ase = phi[j]/i;
                phi[j] = phi[j] - factor_ase ;
                
            }
        }

    }
}

int main()
{

    totient();
    int number ;
    cout<<"Enter A number:";
    cin>>number ;
    cout<<"Phi of your Entered Number is:";
    cout<<phi[number]<<endl;
    for(int i = 1 ;i<= 10 ;i++)
    {
        cout<<phi[i]<<" ";
    }
    return 0;
}