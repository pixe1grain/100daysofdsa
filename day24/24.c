//Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Insert node at end
struct ListNode* insertEnd(struct ListNode* head, int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Delete first occurrence of key
struct ListNode* deleteFirstOccurrence(struct ListNode* head, int key) {
    if (head == NULL)
        return NULL;

    // If head needs to be deleted
    if (head->val == key) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct ListNode* current = head;

    while (current->next != NULL && current->next->val != key) {
        current = current->next;
    }

    // If key found
    if (current->next != NULL) {
        struct ListNode* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

    return head;
}

// Print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, value, key;
    struct ListNode* head = NULL;

    // Input list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insertEnd(head, value);
    }

    // Input key
    scanf("%d", &key);

    // Delete first occurrence
    head = deleteFirstOccurrence(head, key);

    // Output result
    printList(head);

    return 0;
}