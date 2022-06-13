#include <cstdio>
#include <cmath>
 
struct Node
{
    int key, h, count;
    Node *left;
    Node *right;
 
    Node(int key)
    {
        this->key = key;
        count = 1;
        h = 1;
        left = NULL;
        right = NULL;
    }
};
 
int node_count(Node *x);
 
int get_value(Node *x, int k);
 
Node *del(Node *x, int k);
 
Node *insert(Node *x, int k);
 
Node *balance(Node *x);
 
int h(Node *x);
 
int main()
{
    Node *root = NULL;
    int n;
    scanf("%i", &n);
    while (n--)
    {
        int act, k;
        scanf("%i %i", &act, &k);
        switch (act)
        {
            case 1:
                root = insert(root, k);
                break;
            case 0:
                printf("%i\n", get_value(root, k));
                break;
            default:
                root = del(root, k);
        }
    }
}
 
int get_value(Node *x, int k)
{
    Node *cur = x;
    while (true)
    {
        if (1 + node_count(cur->right) == k)
        {
            return cur->key;
        }
        else if (1 + node_count(cur->right) < k)
        {
            k -= 1 + node_count(cur->right);
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
}
 
Node *minimum(Node *x)
{
    if (x->left == NULL)
    {
        return x;
    }
    return minimum(x->left);
}
 
Node *del(Node *x, int k) // удаление ключа k из дерева p
{
    if (x == NULL)
    {
        return NULL;
    }
    if (k < x->key)
    {
        x->left = del(x->left, k);
    }
    else if (k > x->key)
    {
        x->right = del(x->right, k);
    }
    else if (x->left != NULL && x->right != NULL)
    {
        x->key = minimum(x->right)->key;
        x->right = del(x->right, x->key);
    }
    else
    {
        if (x->left != NULL)
        {
            x = x->left;
        }
        else if (x->right != NULL)
        {
            x = x->right;
        }
        else
        {
            x = NULL;
        }
    }
    return balance(x);
}
 
int node_count(Node *x)
{
    return x != NULL ? x->count : 0;
}
 
void recalc(Node *x)
{
    x->h = fmax(h(x->left), h(x->right)) + 1;
    x->count = node_count(x->left) + node_count(x->right) + 1;
}
 
Node *insert(Node *x, int k)
{
    if (x == NULL)
    {
        return new Node(k);
    }
    else if (k < x->key)
    {
        x->left = insert(x->left, k);
    }
    else if (k > x->key)
    {
        x->right = insert(x->right, k);
    }
    return balance(x);
}
 
Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    recalc(x);
    recalc(y);
    return y;
}
 
Node *rotateRight(Node *x)
{
    Node *y = x->left;
    x->left = y->right;
    y->right = x;
    recalc(x);
    recalc(y);
    return y;
}
 
 
Node *balance(Node *x)
{
    if (x == NULL)
    {
        return NULL;
    }
    recalc(x);
    if (h(x->left) + 2 == h(x->right))
    {
        if (x->right == NULL)
        {
            return x;
        }
        if (h(x->right->left) > h(x->left))
        {
            x->right = rotateRight(x->right);
        }
        return rotateLeft(x);
    }
    if (h(x->left) == h(x->right) + 2)
    {
        if (x->left == NULL)
        {
            return x;
        }
        if (h(x->left->right) > h(x->right))
        {
            x->left = rotateLeft(x->left);
        }
        return rotateRight(x);
    }
    return x;
}
 
int h(Node *x)
{
    return x != NULL ? x->h : 0;
}
