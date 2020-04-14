

/*
    Tower of Hanoi 
    Commented line also right . Just it that it show result like 1 2 3 blocks etc etc ....
    Link : https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/

    For n disks, total 2n – 1 moves are required.
    For n disks, total 2n-1 function calls are made.
*/



// #include<bits/stdc++.h>
// using namespace std;

// long long count_step = 0;
// void tower_of_hanoi(int no_of_blocks,char source,char destination,char auxilary)
// {
//     if(no_of_blocks==1)
//     {
//         count_step++;
//         printf("%dth block moved from %c to %c by the help of %c\n\n",1,source,destination,auxilary);
//         return ;
//     }
//     tower_of_hanoi(no_of_blocks-1,source,auxilary,destination);
//     count_step++;
//     printf("%dth block moved from %c to %c by the help of %c\n\n",no_of_blocks,source,destination,auxilary);
//     tower_of_hanoi(no_of_blocks-1,auxilary,destination,source);
// }
// int main()
// {
//     cout<<"Enter the no of blocks :"<<endl;
//     int n;cin>>n;
//     cout<<"Enter the name of source colom (with in one character)"<<endl;
//     char source;cin>>source;
//     cout<<"Enter the name of destination colom (with in one character)"<<endl;
//     char destination;cin>>destination;
//     cout<<"Enter the name of auxilary colom (with in one character)"<<endl;
//     char auxilary;cin>>auxilary;

//     tower_of_hanoi(n,source,destination,auxilary);
//     cout<<"Total steps :  "<<count_step<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

long long count_step = 0;
vector<string>v;
void tower_of_hanoi(int no_of_blocks,char source,char destination,char auxilary)
{
    if(no_of_blocks==1)
    {
        count_step++;
        cout<<v[0]<<" ";
        printf("color block moved from %c to %c by the help of %c\n\n",source,destination,auxilary);
        return ;
    }
    tower_of_hanoi(no_of_blocks-1,source,auxilary,destination);
    count_step++;
    cout<<v[no_of_blocks-1]<<" ";
    printf("color block moved from %c to %c by the help of %c\n\n",source,destination,auxilary);
    tower_of_hanoi(no_of_blocks-1,auxilary,destination,source);
}
int main()
{
    cout<<"Enter the no of blocks :"<<endl;
    int n;cin>>n;
    cout<<"Enter the disk color: "<<endl;
    for(int i=0;i<n;i++)
    {
        string tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    cout<<"Enter the name of source colom (with in one character)"<<endl;
    char source;cin>>source;
    cout<<"Enter the name of destination colom (with in one character)"<<endl;
    char destination;cin>>destination;
    cout<<"Enter the name of auxilary colom (with in one character)"<<endl;
    char auxilary;cin>>auxilary;

    tower_of_hanoi(n,source,destination,auxilary);
    cout<<"Total steps :  "<<count_step<<endl;

    return 0;
}
