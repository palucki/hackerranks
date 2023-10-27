#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) 
{
    auto* new_node = new SinglyLinkedListNode{data};
    new_node->next = nullptr;
    
    if(position == 0)
    {
        new_node->next = llist;
        return new_node;
    }

    auto* head = llist;
    SinglyLinkedListNode* prev = llist;
    while(position-- > 0 && llist)
    {
        prev = llist;
        llist = llist->next;
    }

    prev->next = new_node;
    new_node->next = llist;

    return head;
}

void printList(SinglyLinkedListNode* head)
{
    while(head)
    {
        std::cout << head->data << '\n';
        head = head->next;
    }
}

int main()
{
    SinglyLinkedListNode head{0, nullptr};

    SinglyLinkedListNode *it = &head;

    it = insertNodeAtPosition(it, 16, 1);
    it = insertNodeAtPosition(it, 13, 1);
    it = insertNodeAtPosition(it, 7, 2);

    printList(it);

    // insertNodeAtPosition(&head, 1, 2);

    // printList(&head);

    return 0;
}