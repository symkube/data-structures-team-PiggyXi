#include "datastructs/tree.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int maxi(int x, int y){
    if(x>y)
        return x;
    return y;
}
// TreeNode constructor/destructors

//
// @brief      { Allocate a new TreeNode and initialize its fields }
//
// @param[in]  d     { data value to be contained in the new node }
//
// @return     { pointer to a new TreeNode, whose data value is set, and whose
//             pointers are all initially set to NULL }
//
TreeNode *new_TreeNode(Data d) { 
    TreeNode * TN = (TreeNode * )malloc(sizeof(TreeNode));
    if(TN==NULL){
        return NULL;
    }
    TN->data = d;
    TN->parent = NULL;
    TN->left = NULL;
    TN->right = NULL;
    return TN; 
}

///
/// @brief      { Allocate a new TreeNode, and perform a deep copy of an
///               existing TreeNode. If tn is NULL, return a NULL pointer. }
///
/// @param      tn    { Pointer to the TreeNode to be copied }
///
/// @return     { A pointer to the newly copied TreeNode }
///
TreeNode *copy_TreeNode(TreeNode *tn) { 
    TreeNode * tn_new = (TreeNode * )malloc(sizeof(TreeNode));
    if(tn_new==NULL){
        return NULL;
    }
    tn_new -> data  = tn -> data;
    tn_new -> parent= tn -> parent;
    tn_new -> left  = tn -> left;
    tn_new -> right = tn -> right;
    return tn_new; 
}

///
/// @brief      { Delete an existing TreeNode and free its memory. It is the
///               caller's responsibility to remove the node from the Tree
///               if applicable. }
///
/// @param      tn    { Pointer to the TreeNode to be deleted }
///
void del_TreeNode(TreeNode *tn) { 
    free(tn);
    return; 
}

// Tree constructor/destructors
//
// @return     { A pointer to a new Tree, whose root pointer is NULL because
//               the tree is empty}
//
Tree *new_Tree() { 
    Tree *T = (Tree * )malloc(sizeof(Tree));
    if(T==NULL){
        return NULL;
    }
    T->root = NULL;
    return T; 
}

///
/// @brief      { Allocate a new Tree, and perform a deep copy of an
///               existing Tree. If t is NULL, return a NULL pointer. }
///
/// @param      t     { Pointer to the Tree to be copied }
///
/// @return     { A pointer to the newly copied Tree }
///
Tree *copy_Tree(Tree *t) { 
    if(t==NULL){
        return NULL;
    }
    Tree *t_new = new_Tree();
    TreeNode * tn_old = t -> root;
    TreeNode * tn_new = t_new -> root;
    while( ! ( tn_old == NULL && t_new == NULL ) ){// teminate when both arrived root->parent

        // self(root) --> left --> right --> back(filled)
        if( tn_new == NULL ){
            tn_new = new_TreeNode( tn_old -> data );
            t_new -> root = tn_new;

        }else if( (tn_new -> left == NULL) && (tn_old -> left != NULL) ){
            tn_new -> left = new_TreeNode( tn_old -> left -> data );
            tn_new -> left -> parent = tn_new;
            tn_new = tn_new -> left;
            tn_old = tn_old -> left;
        }else if( (tn_new -> right == NULL) && (tn_old -> right != NULL) ){
            tn_new -> right = new_TreeNode( tn_old -> right -> data );
            tn_new -> right -> parent = tn_new;
            tn_new = tn_new -> right;
            tn_old = tn_old -> right;
        }else{// both child fullfilled 
            tn_new = tn_new -> parent;
            tn_old = tn_old -> parent;
        }
    }
    return t_new; 
}

///
/// @brief      { Delete an existing Tree and free its memory.
///               If the tree is not empty, then properly delete each TreeNode
///               in the tree. }
///
/// @param      t     { Pointer to the Tree to be deleted }
///
void del_Tree(Tree *t) { 
    if(t==NULL){
        return ;
    }
    TreeNode * tn = t->root;
    while(tn!=NULL){
        if(tn->left!=NULL){
            tn = tn->left;
        }else if(tn->right!=NULL){
            tn = tn->right;
        }else{ // both null
            TreeNode * tmp = tn;
            tn = tn->parent;
            del_TreeNode(tmp);
        }
    }
    free(t);
    return; 
}

// Tree properties

///
/// @brief      { Return the length of the longest path to any leaf node from
///               the root of the tree. The length is the number of edges,
///               not the number of nodes in that path. }
///
/// @param      t     { Pointer to the tree }
///
/// @return     { The height of the tree }
///

int aux_height(TreeNode *now,int h){
    int maxmh = h;
    if(now->left!=NULL){
        maxmh=maxi(maxmh,aux_height(now->left,h+1));
    }
    if(now->right!=NULL){
        maxmh=maxi(maxmh,aux_height(now->right,h+1));
    }
    return maxmh;
}
size_t height(Tree *t) { 
    if( t==NULL || t->root==NULL ){
        return 0;
    }
    return aux_height(t->root,0); 
}

///
/// @brief      { The number of nodes in the tree, which is also its degree
///               plus one. The size of an empty tree is zero by definition. }
///
/// @param      t     { Pointer to the tree }
///
/// @return     { The size of the tree }
///
int aux_size(TreeNode * now){
    int sz = 1;
    if(now->left!=NULL){
        sz+=aux_size(now->left);
    }
    if(now->right!=NULL){
        sz+=aux_size(now->right);
    }    
    return sz;
}
size_t size(Tree *t) { 
    if( t==NULL || t->root==NULL ){
        return 0;
    }
    return aux_size(t->root); 
}

///
/// @brief      { The depth of the a node within the tree, which is the number
///               of edges between a node and the root of the tree.
///               The depth of the root node is zero by definition. }
///
/// @param      tn    { parameter_description }
///
/// @return     { description_of_the_return_value }
///
size_t depth(TreeNode *tn) { 
    int dpt = 0;
    while(tn->parent!=NULL){
        tn=tn->parent;
        dpt++;
    }
    return dpt; 
}

///
/// @brief      { Return whether a node is a leaf node. A node is a leaf node
///               if it has no children. }
///
/// @param      tn    { parameter_description }
///
/// @return     True if the specified tn is leaf, False otherwise.
///
bool isLeaf(TreeNode *tn) { 
    if(tn->left == NULL && tn->right == NULL)
        return true;
    else
        return false; 
}

///
/// @brief      { Find the tree node with the maximum data value in the
///               subtree of a TreeNode. Note that the return is *not* the data
///               value itself! }
///
/// @param      tn    { Pointer to a TreeNode at the root of a subtree. }
///
/// @return     { Pointer to the TreeNode containing the maximum value. }
///

TreeNode *aux_max(TreeNode *now){
    TreeNode *tn_max = now;
    if(now->left!=NULL){
        TreeNode *tmp = aux_max(now->left);
        if(tn_max->data < tmp->data){
            tn_max = tmp;
        }
    }
    if(now->right!=NULL){
        TreeNode *tmp = aux_max(now->right);
        if(tn_max->data < tmp->data){
            tn_max = tmp;
        }
    }
    return tn_max;
}

TreeNode *max(TreeNode *tn) {      // changed name
    return aux_max(tn); 
}

///
/// @brief      { Find the tree node with the minimum data value in the
///               subtree of a TreeNode. Note that the return is *not* the data
///               value itself! }
///
/// @param      tn    { Pointer to a TreeNode at the root of a subtree. }
///
/// @return     { Pointer to the TreeNode containing the minimum value. }
///
TreeNode *aux_min(TreeNode *now){
    TreeNode *tn_min = now;
    if(now->left!=NULL){
        TreeNode *tmp = aux_min(now->left);
        if(tn_min->data > tmp->data){
            tn_min = tmp;
        }
    }
    if(now->right!=NULL){
        TreeNode *tmp = aux_min(now->right);
        if(tn_min->data > tmp->data){
            tn_min = tmp;
        }
    }
    return tn_min;
}
TreeNode *min(TreeNode *tn) {          // changed name
    return aux_min(tn); 
}

// Tree mutators/accessors

//
// @brief      { Insert a data value into the tree. If the value does not
//               exist, then a TreeNode will be created. If the value does
//               exist, then a TreeNode is not created, and a duplicate value
//               is not inserted. }
//
// @param      t     { The tree into which the data value will be inserted. }
// @param[in]  d     { The data value to be inserted. }
//
void insertData(Tree *t, Data d) { 
    if(t->root==NULL){
        t->root=new_TreeNode(d);
        return;
    }
    TreeNode *tmp = t->root;
    TreeNode *todo = t->root;
    while(todo!=NULL){
        if(tmp->data<d){
            todo=tmp->left;
        }else if(tmp->data>d){
            todo=tmp->right;
        }else{
            return ;
        }
        if(todo != NULL){
            tmp=todo;
        }
    }
    if(tmp->data<d){
        tmp->left = new_TreeNode(d);
        tmp->left->parent = tmp;
    }
    if(tmp->data>d){
        tmp->right = new_TreeNode(d);
        tmp->right->parent = tmp;
    }
    return; 
}

///
/// @brief      { Return a pointer to the TreeNode containing a given value. If
///               the value is not in the tree, return a NULL pointer. }
///
/// @param      t     { The tree to be searched }
/// @param[in]  d     { The data value to be searched. }
///
/// @return     { A pointer to the TreeNode containing the data value if it
///               exists, a NULL pointer if it does not exist. }
///

TreeNode * aux_findData(TreeNode *now, Data d){
    if(now->data==d){
        return now;
    }
    TreeNode * findIdx = NULL;
    if(now->left!=NULL){
        findIdx = aux_findData(now->left,d);
    }
    if(findIdx!=NULL){
        return findIdx;
    }
    if(now->right!=NULL){
        findIdx = aux_findData(now->right,d);
    }
    return findIdx;
}
TreeNode *findData(Tree *t, Data d) { 
    if(t==NULL){
        return NULL;
    }
    return aux_findData(t->root,d); 
}

///
/// @brief      { Remove a data value from the tree. The TreeNode containing
///               the data value is removed but not freed. It is the caller's
///               responsibility to delete the TreeNode. If the value does not
///               exist in the tree, the tree remains unchanged, and a null 
///               pointer is returned. }
///
/// @param      t     { The tree in which the data value may be contained }
/// @param[in]  d     { The data value to be removed }
///
/// @return     { A pointer to the TreeNode containing that data, now unlinked
///               from the tree. }
///

TreeNode *getnext(TreeNode * now){
    TreeNode *tmp = now;
    while(tmp && tmp->left!=NULL){
        tmp=tmp->left;
    }
    return tmp;
}

TreeNode *aux_remove(TreeNode *now,Data d){
    if(now->data>d){
        now->left = aux_remove(now->left,d);
    }else if(now->data<d){
        now->right = aux_remove(now->right,d);
    }else{
        if(now->left==NULL){
            TreeNode * tmp = now->right;
            return tmp;
        }else if(now->right==NULL){
            TreeNode * tmp = now->left;
            return tmp;
        }
        TreeNode * tmp = getnext(now->right);
        now->data = tmp->data;
        now->right = aux_remove(now->right,tmp->data);
    }
    return now;
}
TreeNode *removeData(Tree *t, Data d) { 
    TreeNode * tmp = findData(t,d);
    if(tmp==NULL){
        return NULL;
    }
    t->root=aux_remove(t->root,d);
    tmp = findData(t,d);
    // if(t->root==tmp){

    // }
    // if(isLeaf(tmp)){
    //     if(tmp->parent->left==tmp){
    //         tmp->parent->left = NULL;
    //     }
    //     if(tmp->parent->right==tmp){
    //         tmp->parent->right = NULL;
    //     }       
    //     return tmp;
    // }
    // if(tmp->left==NULL){
        
    // }

    // TreeNode * rightbound = tmp->right;
    // while(rightbound->left!=NULL){
    //     rightbound=rightbound->left;
    // }
    // if(t->root==tmp){
    //     t->root = tmp->right;
    // }
    // tmp->right->parent=NULL;
    // tmp->left->parent=rightbound;
    // rightbound->left=tmp->left;
    return tmp; 
}

// Traversal Routines
// Implement these routines for 10 points bonus credit each!

///
/// @brief      { Walk the tree in preorder, printing the data value of each
///               node as it is walked with a space between each value:
///               1. Visit the current node
///               2. Recursively traverse the current node's left subtree.
///    			  3. Recursively traverse the current node's right subtree. }
///
/// @param      t     { The tree to be walked. }
///

void aux_preorder(TreeNode *now){
    printf("%ld ",now->data);
    if(now->left!=NULL){
        aux_preorder(now->left);
    }
    if(now->right!=NULL){
        aux_preorder(now->right);
    }
    return ;
}

void preorder(Tree *t) {
    aux_preorder(t->root);
    return; 
}

///
/// @brief      { Walk the tree in inorder, printing the data value of each
///               node as it is walked with a space between each value:
///               1. Recursively traverse the current node's left subtree.
///               2. Visit the current node (in the figure: position green).
///               3. Recursively traverse the current node's right subtree. }
///
/// @param      t     { The tree to be walked. }
///
void aux_inorder(TreeNode *now){
    if(now->left!=NULL){
        aux_inorder(now->left);
    }
    printf("%ld ",now->data);
    if(now->right!=NULL){
        aux_inorder(now->right);
    }
    return ;
}

void inorder(Tree *t) { 
    aux_inorder(t->root);
    return; 
}

///
/// @brief      { Walk the tree in postorder, printing the data value of each
///               node as it is walked with a space between each value:
///               1. Recursively traverse the current node's left subtree.
///               2. Recursively traverse the current node's right subtree.
///               3. Visit the current node. }
///
/// @param      t     { The tree to be walked. }
///

void aux_postorder(TreeNode *now){
    if(now->left!=NULL){
        aux_postorder(now->left);
    }
    if(now->right!=NULL){
        aux_postorder(now->right);
    }
    printf("%ld ",now->data);
    return ;
}
void postorder(Tree *t) { 
    aux_postorder(t->root);
    return; 
}