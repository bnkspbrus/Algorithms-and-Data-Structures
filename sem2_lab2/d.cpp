#include <stdio.h>
#include <string>
#include <cmath>
 
using namespace std;
 
struct Node
{
    int key, h;
    long long sum;
    Node *left;
    Node *right;
 
    Node(int key)
    {
        this->key = key;
        h = 1;
        sum = key;
        left = NULL;
        right = NULL;
    }
};
 
long long node_sum(Node *x);
 
long long upperPrev(Node *x, int k);
 
long long lowerNext(Node *x, int k);
 
Node *balance(Node *x);
 
int h(Node *x);
 
long long node_sum(Node *x);
 
Node *insert(Node *x, int k);
 
int main()
{
    Node *root = NULL;
    int s;
    char sym = 'b';
    scanf("%i", &s);
    long long ans;
    while (s--)
    {
        char prev = sym;
        int x;
        scanf("\n%c %i", &sym, &x);
        if (sym == '+')
        {
            if (prev == '+' || prev == 'b')
            {
                root = insert(root, x);
            }
            else
            {
                int k = (x + ans) % (int) 1e+9;
                root = insert(root, k);
            }
        }
        else
        {
            int y;
            scanf("%i", &y);
            ans = upperPrev(root, y) - lowerNext(root, x);
            printf("%lli\n", ans);
        }
    }
}
 
long long node_sum(Node *x)
{
    return x != NULL ? x->sum : 0;
}
 
long long upperPrev(Node *x, int k) // max value <= x
{
    Node *cur = x;
    long long sum = 0;
    while (cur != NULL)
    {
        if (cur->key <= k)
        {
            sum += node_sum(cur->left) + cur->key;
            cur = cur->right;
        }
        else
        { // cur->key > k
            cur = cur->left;
        }
    }
    return sum;
}
 
long long lowerNext(Node *x, int k) // min >= x
{
    Node *cur = x;
    long long sum = 0;
    while (cur != NULL)
    {
        if (cur->key >= k)
        {
            cur = cur->left;
        }
        else
        {
            sum += node_sum(cur->left) + cur->key;
            cur = cur->right;
        }
    }
    return sum;
}
 
void recalc(Node *x)
{
    x->sum = x->key + node_sum(x->left) + node_sum(x->right);
    x->h = fmax(h(x->left), h(x->right)) + 1;
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
