#include<iostream>
#include<cstring>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


int lps[50];

int build_lps(char *pat,int sizee){   //It's the failure table to analyze the pattern
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
/*
Here we pass string  and pattern .
*/

int kmp (char *str ,char *ptr){    // It's  this algorithm's principal  method

    int p_size = strlen(ptr);
    int s_size = strlen(str);

    build_lps(ptr,p_size);

    int str_index=0,ptr_index=0;


    while (str_index<s_size ){  // Here we call a loop through my Text from start to end ;
        if(str[str_index]==ptr[ptr_index]){
            while(str[str_index]==ptr[ptr_index] && str_index < s_size){
                str_index++;
                ptr_index++;

            }
            if(ptr[ptr_index]=='\0'){
                cout << "Index found at " << str_index-ptr_index << " position "  << endl;
            }
            int lps_value = lps[ptr_index-1];

            if(lps_value == 0){
                //str_index++;
                ptr_index = 0;
            }
            else{
                ptr_index = lps_value;
            }
        }
        else{
            str_index++;

        }
    }
}
int main(int argc,char const *argv[])
{
    lps[0]=0;

    char* str="CBC ABABAB";
    char* ptr = "ABAB";

    kmp(str,ptr);

    return 0;
}

