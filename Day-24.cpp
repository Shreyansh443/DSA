#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

/* Insert at end */
struct node* insertAtEnd(struct node *head, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    
    if (temp == NULL) {
        printf("Memory not allocated\n");
        return head;
    }

    temp->info = data;
    temp->link = NULL;

    if (head == NULL)
        return temp;

    struct node *p = head;
    while (p->link != NULL)
        p = p->link;

    p->link = temp;
    return head;
}

/* Delete first occurrence of key */
struct node* deleteFirst(struct node *head, int key) {

    if (head == NULL)
        return head;

    /* Case 1: key in first node */
    if (head->info == key) {
        struct node *temp = head;
        head = head->link;
        free(temp);
        return head;
    }

    /* Case 2: key in middle or end */
    struct node *p = head;
    while (p->link != NULL && p->link->info != key) {
        p = p->link;
    }

    if (p->link != NULL) {
        struct node *temp = p->link;
        p->link = temp->link;
        free(temp);
    }

    return head;
}

/* Display list */
void display(struct node *head) {
    struct node *p = head;
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->link;
    }
}

int main() {
    int n, x, key;
    struct node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head = insertAtEnd(head, x);
    }

    scanf("%d", &key);

    head = deleteFirst(head, key);

    display(head);

    return 0;
}