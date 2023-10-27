#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <unordered_set>

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

struct Node 
{
    int data;
    struct Node* next;
};

bool has_cycle(Node* head) 
{
    std::unordered_set<Node*> visited;
    while(head)
    {
        if(visited.find(head) != visited.end())
        {
            return true;
        }

        visited.insert(head);
        head = head->next;
    }

    return false;
}

int main()
{
    // SinglyLinkedListNode head{0, nullptr};

    // SinglyLinkedListNode *it = &head;

    // it = insertNodeAtPosition(it, 16, 1);
    // it = insertNodeAtPosition(it, 13, 1);
    // it = insertNodeAtPosition(it, 7, 2);

    // printList(it);

    // insertNodeAtPosition(&head, 1, 2);

    // printList(&head);

    Node head{0, nullptr};
    Node n1{1, nullptr};
    Node n2{2, nullptr};
    Node n3{3, nullptr};

    head.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &head;

    std::cout << has_cycle(&head) << '\n';

    return 0;
}