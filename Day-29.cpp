#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* rotateRight(struct node* head, int k){

    if(head == NULL || head->next == NULL)
        return head;

    int n = 1;
    struct node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
        n++;
    }

    temp->next = head;   // make circular

    k = k % n;
    int steps = n - k;

    struct node* newTail = head;

    for(int i = 1; i < steps; i++)
        newTail = newTail->next;

    struct node* newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}

void printList(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main(){

    int n,k,x;

    scanf("%d",&n);

    struct node* head = NULL;
    struct node* tail = NULL;

    for(int i=0;i<n;i++){
        scanf("%d",&x);

        struct node* newNode = createNode(x);

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d",&k);

    head = rotateRight(head,k);

    printList(head);

    return 0;
}