#include <bits/stdc++.h>
using namespace std;
// Kadane's algorithm : if there exist at least one positive number 
int maxS(int *arr,int n)
{
    int max_so_far = INT_MIN;
    int max_end_here = 0 ;
    for(int i = 0 ;i<n ;i++)
    {
        max_end_here = max_end_here + arr[i];
        if(max_end_here < 0)
            max_end_here = 0 ;
        if(max_end_here>max_so_far)
            max_so_far = max_end_here;
    }
    return max_so_far ;
}
// kadane's algorithm :if ther exist only negetive number ,
// no positve then it work to find out contiguous subarry 
//of mazimum sum ....method(dynamic)
int kadanes(int *arr,int n)
{
    int max_so_far = arr[0];
    int curr_max = arr[0];
    for(int i = 1 ;i<n ;i++)
    {
        curr_max = max(arr[i],curr_max+arr[i]);
        max_so_far = max(max_so_far,curr_max);
    }
    return max_so_far ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int tc ; //test case
    cin>>tc;
    while(tc--)
    {
        int n ;//array element no
        cin>>n;
        int arr[n];
        int positive = 0 ; //count positive number have or not
        for(int i = 0 ;i<n;i++)
        {
            cin>>arr[i];
            if(arr[i]>=0)
                positive++;
        }
        if(positive)//if arry contain any positive number then execute this section
        {
            int m = maxS(arr,n);
            cout<<m<<endl;
        }
        else
        {
            int m = kadanes(arr,n);
            cout<<m<<endl;
        }
    }
    return 0;
}
// problem link : https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// UVA : 10684,507

// 2
// 5
// 1 2 3 -2 5
// 4
// -1 -2 -3 -4
