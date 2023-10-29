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

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) 
{
    // std::cout << "inserting " << data << '\n';
    auto new_node = new DoublyLinkedListNode{data};
    new_node->next = nullptr;
    new_node->prev = nullptr;
    auto* head = llist;

    if(llist == nullptr)
    {
        new_node->next = llist;
        head = new_node;
        return head;
    }

    DoublyLinkedListNode* prev = llist;
    while(llist && llist->data < data)
    {
        // std::cout << "at " << llist->data << '\n';
        prev = llist;
        llist = llist->next;
    }

    //llist points to location where to insert
    if(!llist)
    {
        // std::cout << "Insert at the end\n";
        prev->next = new_node;
        new_node->prev = prev;
    }
    else if(!llist->prev)
    {
        // std::cout << "Insert at the begining\n";
        new_node->next = llist;
        llist->prev = new_node;
        head = new_node;
    }
    else
    {
        // std::cout << "Insert in the middle\n";
        prev->next = new_node;
        llist->prev = new_node;
        new_node->next = llist;
        new_node->prev = prev;
    }

    return head;
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    std::set<SinglyLinkedListNode*> list1;

    while(head1)
    {
        list1.insert(head1);
        head1 = head1->next;
    }

    while(head2)
    {
        if(list1.find(head2) != list1.end())
        {
            return head2->data;
        }
        head2 = head2->next;
    }

    return -1;
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

    // DoublyLinkedListNode head{1, nullptr, nullptr};
    // DoublyLinkedListNode n1{2, nullptr, nullptr};
    // DoublyLinkedListNode n2{5, nullptr, nullptr};

    // head.next = &n1;
    // n1.next = &n2;
    // n1.prev = &head;
    // n2.prev = &n1;

    // auto* it = &head;

    // printList(it);

    // it = sortedInsert(it, 0);
    // it = sortedInsert(it, 3);
    // it = sortedInsert(it, 6);

    // std::cout << "after\n";
    // printList(it);

    SinglyLinkedListNode head{1, nullptr};
    SinglyLinkedListNode n2{2, nullptr};
    SinglyLinkedListNode n3{3, nullptr};
    SinglyLinkedListNode n4{4, nullptr};

    SinglyLinkedListNode n11{1, nullptr};
    SinglyLinkedListNode n12{2, nullptr};

    head.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    n11.next = &n12;
    n12.next = &n3;

    std::cout << "Merge point " << findMergeNode(&head, &n11) << '\n';

    return 0;
}