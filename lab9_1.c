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
void del_at_pos(struct node **head, int pos){
    struct node *temp=*head;
    if(pos==0){
        *head=temp->next;
        free(temp);
        return;
    }
    for(int i=0; i<pos-1; i++){
        temp=temp->next;
    }
    struct node *del_node=temp->next;
    temp->next=del_node->next;
    free(del_node);
}
void display(struct node *head){
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void duplicate(struct node **head){
    struct node *temp=*head,*temp2=*head;
    while(temp!=NULL){
        temp2=temp->next;
        while(temp2!=NULL){
            if(temp->data==temp2->data){
                struct node *del_node=temp2;
                temp->next=temp2->next;
                free(del_node);
                break;
            }
            temp2=temp2->next;
        }
        temp=temp->next;
    }
}
int main(){

    return 0;
}
