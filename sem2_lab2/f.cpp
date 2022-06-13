#include <cstdio>
#include <cstdlib>
 
struct Node
{
    int /*get_ind, */val, ind, random;
    Node *left;
    Node *right;
 
    Node(int val)
    { // x
        this->val = val; // y
        ind = 1;
        random = rand();
        left = NULL;
        right = NULL;
    }
};
 
struct Nodes
{
    Node *first;
    Node *second;
};
 
void print_array(Node *x);
 
int get_ind(Node *x);
 
int node_ind(Node *x);
 
void recalc(Node *x);
 
Nodes split(Node *root, int x);
 
Node *merge(Node *a, Node *b);
 
Node *add(Node *root, Node *node, int ind);
 
Node *remove(Node *root, int ind);
 
int main()
{
    srand(0);
    Node *root = NULL;
    int n, m;
    scanf("%i %i", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%i", &val);
        Node *node = new Node(val);
        root = add(root, node, i);
    }
    while (m--)
    {
        char act[4];
        scanf("%s", act);
        if (act[0] == 'a')
        {
            int ind, val;
            scanf("%i %i", &ind, &val);
            Node *node = new Node(val);
            root = add(root, node, ind);
        }
        else
        {
            int ind;
            scanf("%i", &ind);
            root = remove(root, ind);
        }
    }
    printf("%i\n", node_ind(root));
    print_array(root);
    return 0;
}
 
void print_array(Node *x)
{
    if (x != NULL)
    {
        print_array(x->left);
        printf("%i ", x->val);
        print_array(x->right);
    }
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
 
int get_ind(Node *x)
{
    return node_ind(x->left) + 1;
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
