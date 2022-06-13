//package laba;
 
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;
 
public class A {
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
                    x = del(x, k);
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
 
    static Node del(Node x, int k) {
        if (x == null) {
            return null;
        }
        if (k < x.key) {
            x.left = del(x.left, k);
        } else if (k > x.key) {
            x.right = del(x.right, k);
        } else if (x.left != null && x.right != null) {
            x.key = minimum(x.right).key;
            x.right = del(x.right, x.key);
        } else {
            if (x.left != null) {
                x = x.left;
            } else if (x.right != null) {
                x = x.right;
            } else {
                x = null;
            }
        }
        return x;
    }
 
    static Node insert(Node x, int k) {
        if (x == null) {
            return new Node(k);
        } else if (k < x.key) {
            x.left = insert(x.left, k);
        } else if (k > x.key) x.right = insert(x.right, k);
        return x;
    }
}
 
class Node {
    int key;
    Node left;
    Node right;
 
    Node(int key) {
        this.key = key;
    }
}
