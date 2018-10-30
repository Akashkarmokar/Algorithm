#include<stdio.h>
int linear_search(int A[],int n,int x){
  int i;
  for(i=0;i<n;i++){
    if(A[i]==x){
      return i;
    }
  }
  i=-1;
  return i;
}
 int main() {
  int size_of_array,searching_element,i;
  printf("Enter your searching element:\n");
  scanf("%d",&searching_element);
  printf("Enter the size of array\n");
  scanf("%d",&size_of_array);
  int array[size_of_array];
  printf("Enter the element of your array\n");

  for(i=0;i<size_of_array;i++){
    scanf("%d",&array[i]);
  }

  if(linear_search(array,size_of_array,searching_element)==-1){
    printf("Your searching element does not exist there :) !\n");
  }
  else{
    printf("Your searching element hold on %d position and elemnet is %d",linear_search(array,size_of_array,searching_element),array[linear_search(array,size_of_array,searching_element)]);
  }
  return 0;
}
