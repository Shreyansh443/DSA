#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* p1 = head1;
    
    while (p1 != NULL) {
        struct Node* p2 = head2;
        
        while (p2 != NULL) {
            if (p1 == p2)   // same memory address
                return p1;
            p2 = p2->next;
        }
        
        p1 = p1->next;
    }
    
    return NULL;
}

int main() {
    int n, m, x;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    scanf("%d", &n);
    for(int i=0;i<n;i++) {
        scanf("%d", &x);
        head1 = insertEnd(head1, x);
    }

    scanf("%d", &m);
    for(int i=0;i<m;i++) {
        scanf("%d", &x);
        head2 = insertEnd(head2, x);
    }

    struct Node* intersection = findIntersection(head1, head2);

    if(intersection)
        printf("%d", intersection->data);
    else
        printf("No Intersection");

    return 0;
}