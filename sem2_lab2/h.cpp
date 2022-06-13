#include <cstdio>
#include <cstdlib>
#include <ctime>
 
struct Node
{
    int val, ind, random;
    bool rev;
    Node *left;
    Node *right;
 
    Node(int val, int random)
    {
        rev = false;
        this->val = val; // y
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
 
void rev(Node *node);
 
void propagate(Node *node);
 
void print_array(Node *x);
 
int get_ind(Node *x);
 
int node_ind(Node *x);
 
void recalc(Node *x);
 
Nodes split(Node *root, int x);
 
Node *merge(Node *a, Node *b);
 
Node *add(Node *root, Node *node, int ind);
 
Node *do_reverse(Node *root, int l, int r);
 
Node *reverse(Node *node);
 
int main()
{
//    srand(time(NULL));
    Node *root = NULL;
    int n, m;
    scanf("%i %i", &n, &m);
    for (int i = 0; i < n; i++)
    {
        Node *node = new Node(i + 1, rand());
        root = add(root, node, i);
    }
    while (m--)
    {
        int l, r;
        scanf("%i %i", &l, &r);
        root = do_reverse(root, l - 1, r);
    }
    print_array(root);
    return 0;
}
 
Node *do_reverse(Node *root, int l, int r)
{
    Nodes p1 = split(root, l);
    Nodes p2 = split(p1.second, r - l);
    p2.first->rev = !p2.first->rev;
    root = merge(p1.first, p2.first);
    root = merge(root, p2.second);
    return root;
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
    propagate(a);
    propagate(b);
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
 
void print_array(Node *x)
{
    if (x != NULL)
    {
        propagate(x);
        print_array(x->left);
        printf("%i ", x->val);
        print_array(x->right);
    }
}
 
void propagate(Node *node)
{
    if (node->rev)
    {
        Node *temp = node->left;
        node->left = node->right;
        node->right = temp;
        node->rev = !node->rev;
        rev(node->left);
        rev(node->right);
    }
}
 
void rev(Node *node)
{
    if (node != NULL)
    {
        node->rev = !node->rev;
    }
}
 
int get_ind(Node *x)
{
    return node_ind(x->left) + 1;
}
 
int node_ind(Node *x)
{
    return x != NULL ? x->ind : 0;
}
 
void recalc(Node *x)
{
    x->ind = node_ind(x->left) + node_ind(x->right) + 1;
}
 
Nodes split(Node *root, int x)
{
    if (root == NULL)
    {
        return {NULL, NULL};
    }
    propagate(root);
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
