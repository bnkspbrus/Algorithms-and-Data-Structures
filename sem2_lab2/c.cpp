#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stack>
#include <queue>
 
using namespace std;
 
struct Node
{
    int val, ind, random;
    Node *left;
    Node *right;
    bool has_zero;
 
    Node(int val, int random)
    {
        this->val = val;
        has_zero = val == 0;
        ind = 1;
        this->random = random;
        left = NULL;
        right = NULL;
    }
};
 
struct Nodes
{
    Node *first;
    Node *second;
};
 
Node *add(Node *root, Node *node, int ind);
 
Node *merge(Node *a, Node *b);
 
bool node_has_zero(Node *x);
 
void fill_queue(Node *root, deque<int> *que);
 
int get_ind(Node *root);
 
int node_ind(Node *x);
 
void recalc(Node *x);
 
Nodes split(Node *root, int x);
 
int low_next_zero(Node *root);
 
Node *insert(Node *root, Node *node, int ind);
 
Node *remove(Node *root, int ind);
 
int main()
{
    srand(time(NULL));
    Node *root = NULL;
    int n, m;
    scanf("%i %i", &n, &m);
    for (int i = 0; i < m; i++)
    {
        Node *node = new Node(0, rand());
        root = add(root, node, i);
    }
    for (int i = 1; i <= n; i++)
    {
        int ind;
        scanf("%i", &ind);
        Node *node = new Node(i, rand());
        root = insert(root, node, ind - 1);
    }
    deque<int> que;
    fill_queue(root, &que);
    while (!que.back())
    {
        que.pop_back();
    }
    printf("%lu\n", que.size());
    while (!que.empty())
    {
        printf("%i ", que.front());
        que.pop_front();
    }
    return 0;
}
 
Node *add(Node *root, Node *node, int ind)
{
    if (root == NULL)
    {
        return node;
    }
    if (node->random > root->random)
    {
        Nodes p = split(root, ind);
        node->left = p.first;
        node->right = p.second;
        recalc(node);
        return node;
    }
    if (ind < get_ind(root))
    {
        root->left = add(root->left, node, ind);
    }
    else
    {
        root->right = add(root->right, node, ind - get_ind(root));
    }
    recalc(root);
    return root;
}
 
Node *insert(Node *root, Node *node, int ind)
{
    Nodes p = split(root, ind);
    if (node_has_zero(p.second))
    {
        int rem_ind = low_next_zero(p.second);
        p.second = remove(p.second, rem_ind);
    }
    root = merge(p.first, p.second);
    root = add(root, node, ind);
    return root;
}
 
Node *remove(Node *root, int ind)
{
    if (get_ind(root) == ind)
    {
        return merge(root->left, root->right);
    }
    if (ind < get_ind(root))
    {
        root->left = remove(root->left, ind);
    }
    else
    {
        root->right = remove(root->right, ind - get_ind(root));
    }
    recalc(root);
    return root;
}
 
int low_next_zero(Node *root)
{
    Node *cur = root;
    int ind = 0;
    while (node_has_zero(root))
    {
        if (node_has_zero(cur->left))
        {
            cur = cur->left;
        }
        else if (!cur->val)
        {
            ind += get_ind(cur);
            break;
        }
        else
        {
            ind += get_ind(cur);
            cur = cur->right;
        }
    }
    return ind;
}
 
bool node_has_zero(Node *x)
{
    return x != NULL && x->has_zero;
}
 
void fill_queue(Node *root, deque<int> *que)
{
    if (root != NULL)
    {
        fill_queue(root->left, que);
        (*que).push_back(root->val);
        fill_queue(root->right, que);
    }
}
 
void recalc(Node *x)
{
    if (x == NULL) return;
    x->has_zero = x->val == 0 || node_has_zero(x->left) || node_has_zero(x->right);
    x->ind = node_ind(x->left) + node_ind(x->right) + 1;
}
 
int get_ind(Node *x)
{
    return node_ind(x->left) + 1;
}
 
Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    if (a->random > b->random)
    {
        a->right = merge(a->right, b);
        recalc(a);
        return a;
    }
    else
    {
        b->left = merge(a, b->left);
        recalc(b);
        return b;
    }
}
 
int node_ind(Node *x)
{
    return x != NULL ? x->ind : 0;
}
 
Nodes split(Node *root, int x)
{
    if (root == NULL)
    {
        return {NULL, NULL};
    }
    if (x >= get_ind(root))
    {
        Nodes p = split(root->right, x - get_ind(root));
        root->right = p.first;
        recalc(root);
        return {root, p.second};
    }
    else
    {
        Nodes p = split(root->left, x);
        root->left = p.second;
        recalc(root);
        return {p.first, root};
    }
}
