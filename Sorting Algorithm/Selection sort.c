#include<stdio.h>
int main()
{
    int selection[]={5,2,6,3,4};
    int n=5,i,j,temp,min_index;
    for(i=0;i<n-1;i++){
        min_index = i;
        for(j=i+1;j<n;j++){
            if(selection[j]<selection[min_index]){
                min_index = j;
            }
        }
        if(i!=min_index){
            temp = selection[i];
            selection[i]=selection[min_index];
            selection[min_index]=temp;
        }
    }
    for(i =0;i<n;i++){
        printf("%d\n",selection[i]);
    }

    return 0;
}
