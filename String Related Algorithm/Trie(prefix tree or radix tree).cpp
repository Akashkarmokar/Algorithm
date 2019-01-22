//
// Created by akash_karmokar on 1/23/19.
// Source : Shafayet Asraf
//          Link: http://www.shafaetsplanet.com/planetcoding/?p=1679
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <malloc.h>
using  namespace std;
struct node{
    bool endmark;
    struct node* next[27]; //[26+1]
    node(){
        endmark = false;
        for(int i =0;i<26 ;i++){
            next[i]=NULL;
        }
    }
} *root;
void insert (char *str,int length){
    struct node* curr = root;
    int i ;
    for(i =0;i<length;i++){
        int id = str[i]-'a';
        if(curr->next[id]==NULL){
            curr->next[id] = (struct node *)malloc(sizeof(struct node));
            curr= curr->next[id];
        }
    }
    curr->endmark=true;
}
bool search(char* str,int length){
    struct node* curr = root;
    int i;
    for(i=0;i<length;i++){
        int id = str[i] -'a';
        if(curr->next[id]==NULL){
            return false;
        }
        else{
            curr = curr->next[id];
        }
    }
    return  curr->endmark;
}
// To free memory we need a delete function .It is necessary when we have many test case;otherwise it show us garbage value
void del(struct node* curr){
    int i =0;
    for(i=0;i<26;i++){
        if(curr->next[i]){
            del(curr->next[i]);
        }
    }
    delete(curr);
}
int main(){
    printf("Enter the number of your word:");
    root = (struct node*)malloc(sizeof(struct node));  //Here root is just pointer .Here it is called simply a instance
    // or, root = new node();
    int no_of_word,i;
    cin>>no_of_word;
    // These loop foor inserting word in the dictionary
    for(i=0;i<no_of_word;i++){
        char string[50];
        scanf("%s",string);
        insert(string,strlen(string));
    }
    printf("Enter the no of query:");
    int query_no;
    cin>>query_no;
    for(i=0;i<query_no;i++){
        char string[50];
        scanf("%s",string);
        if(search(string,strlen(string))){
            printf("Found the word\n");
        }
        else{
            printf("NOT FOUND the word\n");
        }
    }
    del(root);
    return 0;
}
