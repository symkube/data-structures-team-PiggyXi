#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#ifndef DATASTRUCTS_DATA_T
#define DATASTRUCTS_DATA_T 
typedef uint64_t Data;
#endif // DATASTRUCTS_DATA_T

#ifndef DATASTRUCTS_TREE_H
#define DATASTRUCTS_TREE_H

typedef struct TreeNode {
	Data data;
	struct TreeNode *parent;
	struct TreeNode *left;
	struct TreeNode *right;
} TreeNode;

typedef struct Tree {
	TreeNode *root;
} Tree;

// TreeNode constructor/destructors
TreeNode *new_TreeNode(Data d);
TreeNode *copy_TreeNode(TreeNode *tn);
void del_TreeNode(TreeNode *tn);

// Tree constructor/destructors
Tree *new_Tree();
Tree *copy_Tree(Tree *t);
void del_Tree(Tree *t);

// Tree properties
size_t height(Tree *t);
size_t size(Tree *t);
size_t depth(TreeNode *tn);
bool isLeaf(TreeNode *tn);
TreeNode *max(TreeNode *tn);
TreeNode *min(TreeNode *tn);

// Tree mutators/accessors
void insertData(Tree *t, Data d);
TreeNode *findData(Tree *t, Data d);
TreeNode *removeData(Tree *t, Data d);

// Traversal Routines
void preorder(Tree *t);
void inorder(Tree *t);
void postorder(Tree *t);

#endif // DATASTRUCTS_TREE_H 