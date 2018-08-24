#include<stdio.h>
int main()
{
    int i=1,j,temp,item_no;
    int array[5]={5,4,2,3,1};
    //temp=array[0];
    for(i=1;i<=5-1;i++){
        for(j=i;j>=0;j--){
            if(array[j]<array[j-1]){
                temp=array[j];
                array[j]=array[j-1];
                array[j-1]=temp;
            }
        }
    }
    for(int i=0;i<5;i++){
        printf("%d",array[i]);
    }
}
