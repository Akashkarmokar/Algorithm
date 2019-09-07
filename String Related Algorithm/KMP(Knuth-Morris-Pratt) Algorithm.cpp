
// Complexity : O(textSize + PatternSize)


#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

char str[1100000];
char ptr[1100000];
int lps[1100000];

int build_lps(char *pat,int sizee){
    int i =0,j=1;
    while(j<sizee){
        if(pat[i]==pat[j]){
            lps[j]=i+1;
            j++;
            i++;
        }
        else{
            if(i!=0){
                i--;
            }
            else{
                lps[j]=0;
                j++;
            }
        }
    }
}

int kmp (char *str,char *ptr,int i ){

    int p_size = strlen(ptr);
    int s_size = strlen(str);
    int counter = 0;

    build_lps(ptr,p_size);

    int str_index=0,ptr_index=0;


    while (str_index<s_size ){
        if(str_index==s_size)
                break ;
        if(str[str_index]==ptr[ptr_index]){

            str_index++;
            ptr_index++;
            if(ptr[ptr_index]=='\0'){
                printf("Index found at %d position\n",str_index-ptr_index);
                ptr_index=lps[ptr_index-1];
                counter++;
            }
        }
        else{
            if(ptr_index==0){
                str_index++;
            }else{
                ptr_index = lps[ptr_index-1];
            }


        }

    }
    printf("Case %d: %d\n",i+1,counter);
}
int main()
{
    lps[0]=0;
    int i =0;
    int case_number,number;
    scanf("%d",&case_number);
    for(i=0;i<case_number;i++){
        scanf("%s",str);
        scanf("%s",ptr);
        kmp(str,ptr,i);
    }
    return 0;
}
