import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;
 
public class B {
    public static void main(String[] args) throws IOException {
        final BufferedWriter output = new BufferedWriter(new OutputStreamWriter(System.out));
        Node x = null;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String act = sc.next();
            int k = sc.nextInt();
            switch (act) {
                case "insert":
                    x = insert(x, k);
                    break;
                case "delete":
                    x = delete(x, k);
                    break;
                case "exists":
                    if (search(x, k) != null) {
                        output.write("true\n");
                    } else {
                        output.write("false\n");
                    }
                    break;
                case "next":
                    Node node = lowerNext(x, k);
                    if (node == null) {
                        output.write("none\n");
                    } else {
                        output.write(node.key + "\n");
                    }
                    break;
                default:
                    node = upperPrev(x, k);
                    if (node == null) {
                        output.write("none\n");
                    } else {
                        output.write(node.key + "\n");
                    }
                    break;
            }
        }
        output.flush();
    }
 
    static int h(Node x) {
        return x != null ? x.h : 0;
    }
 
    static void recalc(Node x) {
        if (x != null) {
            x.h = Math.max(h(x.left), h(x.right)) + 1;
        }
    }
 
    static Node rotateLeft(Node x) {
        Node y = x.right;
        x.right = y.left;
        y.left = x;
        recalc(x);
        recalc(y);
        return y;
    }
 
    static Node rotateRight(Node x) {
        Node y = x.left;
        x.left = y.right;
        y.right = x;
        recalc(x);
        recalc(y);
        return y;
    }
 
    static Node upperPrev(Node x, int k) {
        Node cur = x;
        Node suc = null;
        while (cur != null) {
            if (cur.key < k) {
                suc = cur;
                cur = cur.right;
            } else { // cur.key >= k
                cur = cur.left;
            }
        }
        return suc;
    }
 
    static Node lowerNext(Node x, int k) {
        Node cur = x;
        Node suc = null;
        while (cur != null) {
            if (cur.key > k) {
                suc = cur;
                cur = cur.left;
            } else {
                cur = cur.right;
            }
        }
        return suc;
    }
 
    static Node search(Node x, int k) {
        if (x == null || k == x.key) {
            return x;
        }
        if (k < x.key) {
            return search(x.left, k);
        } else {
            return search(x.right, k);
        }
    }
 
    static Node minimum(Node x) {
        if (x.left == null) {
            return x;
        }
        return minimum(x.left);
    }
 
    static Node insert(Node x, int k) {
        if (x == null) {
            return new Node(k);
        } else if (k < x.key) {
            x.left = insert(x.left, k);
        } else if (k > x.key) {
            x.right = insert(x.right, k);
        }
        return balance(x);
    }
 
    static Node delete(Node x, int k) // удаление ключа k из дерева p
    {
        if (x == null) {
            return null;
        }
        if (k < x.key) {
            x.left = delete(x.left, k);
        } else if (k > x.key) {
            x.right = delete(x.right, k);
        } else if (x.left != null && x.right != null) {
            x.key = minimum(x.right).key;
            x.right = delete(x.right, x.key);
        } else {
            if (x.left != null) {
                x = x.left;
            } else if (x.right != null) {
                x = x.right;
            } else {
                x = null;
            }
        }
        return balance(x);
    }
 
    static Node balance(Node x) {
        if (x == null) {
            return null;
        }
        recalc(x);
        if (h(x.left) + 2 == h(x.right)) {
            if (x.right == null) {
                return x;
            }
            if (h(x.right.left) > h(x.left)) {
                x.right = rotateRight(x.right);
            }
            return rotateLeft(x);
        }
        if (h(x.left) == h(x.right) + 2) {
            if (x.left == null) {
                return x;
            }
            if (h(x.left.right) > h(x.right)) {
                x.left = rotateLeft(x.left);
            }
            return rotateRight(x);
        }
        return x;
    }
}
 
class Node {
    int key, h;
    Node left;
    Node right;
 
    Node(int key) {
        this.key = key;
    }
}
