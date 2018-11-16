#include <stdio.h>
//binary search function
int binary_search(int a[],int array_size,int search_element){
  int left,right,mid;
  left=0;
  right = array_size-1;
  while (left<=right) {
    mid=(left+right)/2;
    if(a[mid]==search_element){
      return mid;
    }
    if(a[mid]<search_element){
      left=mid+1;
    }
    else{
      right=mid-1;
    }
  }
  return -1;
}


int main()
{
  int array_size,i,search_element;
  //scan for array  size
  scanf("%d",&array_size);
  //scanf for searching element
  scanf("%d",&search_element);
  int array[array_size];
  for(i=0;i<array_size;i++){
    scanf("%d",&array[i]);
    //printf("%d",array[i]);
  }
  if(binary_search(array,array_size,search_element) == -1){
    printf("Your searching element is not here\n");
  }
  else{
    printf("your searching element %d is in %dth index",search_element,binary_search(array,array_size,search_element));
  }
  return 0;
}
