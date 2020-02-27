#include<bits/stdc++.h>
using namespace std;

// using recursion
int josephus_recursion(int people,int count_number) // time complexity : O(n)
{
	if(people==1)
		return 1;
	else
		return (josephus_recursion(people-1,count_number)+(count_number-1))%people+1;
}


int main()
{
	int people,count_number;
	cin>>people>>count_number;
	cout<<"Output with recursion function"<<endl;
	cout<<josephus_recursion(people,count_number);
	cout<<"-------"<<endl;

	cout<<"OUtput with loop"<<endl;

	int initial_soward = 1;
	for(int j=2;j<=people;j++) // time complexity : O(n)
	{
		initial_soward = (initial_soward+(count_number-1))%j+1;
	}
	cout<<initial_soward<<endl;
	return 0;
}




// for more details : https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
