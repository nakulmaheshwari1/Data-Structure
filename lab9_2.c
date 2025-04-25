#include <stdio.h>
struct node{
    int data;
    struct node *next;
};
void create(struct node **head, int data){
    struct node *temp=*head;
    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    if((*head)==NULL){
        (*head)=new_node;
    }else{
        struct node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
void rotate(struct node **head, int k){
    struct node *temp=*head;
    struct node *kth_node=NULL;
    struct node *last_node=NULL;
    int count=1;
    if(*head==NULL){
        return;
    }
    while(temp->next!=NULL){
        if(count==k){
            kth_node=temp;
        }
        temp=temp->next;
        count++;
    }
    last_node=temp;
    last_node->next=*head;
    *head=kth_node->next;
    kth_node->next=NULL;
}
int main(){
    return 0;
}
