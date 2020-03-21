#include<bits/stdc++.h>
using namespace std;


int max(int a,int b)
{
    return (a>b)?a:b;
}
int max(int a,int b,int c)
{
    return max(max(a,b),c);
}

int maxCrossingSum(vector<int>& a,int l,int m,int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i=m;i>=l;i--)
    {
        sum+=a[i];
        if(sum>left_sum)
            left_sum=sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for(int i=m+1;i<=h;i++)
    {
        sum+=a[i];
        if(sum>right_sum)
            right_sum=sum;
    }
    return left_sum+right_sum;
}

int max_sum_contiguous_array(vector<int>& a,int l,int h)
{
    if(l==h)
    {
        return a[l];
    }
    int m = (l+h)/2;
    return max(
        max_sum_contiguous_array(a,l,m),
        max_sum_contiguous_array(a,m+1,h),
        maxCrossingSum(a,l,m,h)
    );
}
int main()
{
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int max_sum=max_sum_contiguous_array(v,0,n-1);
    cout<<max_sum<<endl;
    return 0;
}