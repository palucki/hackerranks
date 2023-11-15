#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>

struct Node {
    int data;
    Node* left{nullptr};
    Node* right{nullptr};
};

int height(Node* root) 
{
    if(!root)
    {
        return 0;
    }

    if(!root->left && !root->right)
    {
        // base case for a node
        return 0;
    }

    return 1 + std::max(height(root->left), height(root->right));
}

Node *lca(Node *root, int v1, int v2) 
{
    if(!root) return nullptr;

    // std::cout << "LCA at " << root->data << '\n';
    if(root->data == v1 || root->data == v2) return root;

    auto* found_left = lca(root->left, v1, v2);
    auto* found_right = lca(root->right, v1, v2);

    if(found_left && found_right) return root;
    if(found_left && !found_right) return lca(root->left, v1, v2);
    if(!found_left && found_right) return lca(root->right, v1, v2);

    return nullptr;
}

int main()
{
    // Node n2{2};
    // Node n1{2};
    // Node n3{3};
    // Node n4{4};
    // Node n5{5};
    // Node n6{6};

    // n2.left = &n1;
    // n2.right = &n3;
    // n3.left = &n4;
    // n3.right = &n5;
    // n5.left = &n6;

    // std::cout << "LCA for 2, 4, 6 is " << lca(&n2, 4, 6)->data << '\n';

    Node n4{4};
    Node n2{2};
    Node n1{1};
    Node n3{3};
    Node n7{7};
    Node n6{6};

    n4.left = &n2;
    n4.right = &n7;
    n2.left = &n1;
    n2.right = &n3;
    n7.left =  &n6;

    std::cout << "LCA for 4, 1, 7 is " << lca(&n4, 1, 7)->data << '\n';

    return 0;
}