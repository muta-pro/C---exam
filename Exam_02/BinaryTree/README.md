# binary-tree
Binary tree exercise for the 42 exam.

Implement a function that calculates size of binary tree - total numebers of nodes it contains.
Binary tree is a tree where all nodes have at most two chidren, left and right one. 
Prototype should be as follows;

int size_binary_tree(t_btree *root);

You have to use ft_btree.h file, which will only contain:
typedef struct s_btree
{
  int value;
  struct s_btree *left;
  struct s_btree *right;
} t_btree;
If the root node is NULL, your function must return 0.
//
Approach to use is recursion; if the first node is not NULL then we sum 1 with left and right subtrees.

Complexity: TIME is O(n) ; because each node is visited once until NULL node.
            SPACE is O(h) ; use of memory by the algo - call stack: each recursive call uses one stack frame.
            Worst case(complitely unbalanced tree) recurse is n times O(n) stack depth.
            Best/avarage case (balanced tree h = log2n) recurse log2n levels O(log n) space.
            
Check if tree is balanced; for every node h of L subtrees and R subtrees differ by at most 1.
O(n^2) Worst case.
O(h)



