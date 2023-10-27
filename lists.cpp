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

template<typename T>
void printList(T* head)
{
    while(head)
    {
        std::cout << head->data << " at " << head << '\n';
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
 
struct DoublyLinkedListNode 
{
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};

DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) 
{
    auto* new_head = llist;
    while(llist)
    {
        new_head = llist;
        std::swap(llist->prev, llist->next);
        llist = llist->prev;
    }
    
    return new_head;
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

    DoublyLinkedListNode head{0, nullptr, nullptr};
    DoublyLinkedListNode n1{1, nullptr, nullptr};
    DoublyLinkedListNode n2{2, nullptr, nullptr};
    DoublyLinkedListNode n3{3, nullptr, nullptr};

    head.next = &n1;
    n1.next = &n2;
    n1.prev = &head;
    n2.next = &n3;
    n2.prev = &n1;
    n3.prev = &n2;
    // n3.next = &head;

    auto* it = &head;

    printList(it);
    it = reverse(it);
    std::cout << "after\n";
    printList(it);

    return 0;
}