#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to insert node at end
struct node* insertAtEnd(struct node *head, int data) {
    struct node *temp, *p;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL) {
        return temp;
    }

    p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = temp;
    return head;
}

// Function to count occurrences of key
int countOccurrences(struct node *head, int key) {
    int count = 0;
    struct node *p = head;

    while (p != NULL) {
        if (p->data == key) {
            count++;
        }
        p = p->next;
    }

    return count;
}

int main() {
    int n, i, value, key;
    struct node *head = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertAtEnd(head, value);
    }

    scanf("%d", &key);

    printf("%d", countOccurrences(head, key));

    return 0;
}