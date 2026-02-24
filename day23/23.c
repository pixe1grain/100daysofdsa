//Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to insert node at end
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

// Function to merge two sorted lists
struct ListNode* mergeLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // Attach remaining nodes
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy.next;
}

// Function to print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n, m, value;
    struct ListNode *list1 = NULL, *list2 = NULL;

    // Input first list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        list1 = insertEnd(list1, value);
    }

    // Input second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        list2 = insertEnd(list2, value);
    }

    // Merge lists
    struct ListNode* merged = mergeLists(list1, list2);

    // Output result
    printList(merged);

    return 0;
}