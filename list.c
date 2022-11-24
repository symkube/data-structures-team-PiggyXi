#include "datastructs/list.h"
#include <stddef.h>
#include <stdlib.h>

///
/// @brief      { Create a new node, containing specified data }
///
/// @param      d     { The data to be stored in the node }
///
/// @return     { Return a pointer to the newly created node on success, 
///               or a null pointer on failure. }
///
Node *new_Node(Data *d) { 
    Node * P_nd;
    P_nd = (Node *)malloc(sizeof(Node));
    if(P_nd == NULL){
        return NULL;
    }
    P_nd -> data = *d;
    P_nd -> next = P_nd ->prev = P_nd;
    return P_nd; 
}

/// 
/// @brief      { Delete an existing node }
///
/// @param      n     { The node to be deleted. If n is null, no operation is performed. }
///
void del_Node(Node *n) { 
    if(n==NULL){
        return;
    }else{
        free(n);
    }
    return NULL; 
}

///
/// @brief      { Copy an existing node }
///
/// @param      n     { A pointer to the node to be copied }
///
/// @return     { Return a pointer to the new, copied node on success,
///               or a null pointer on failure. }
///
Node *copy_Node(Node *n) { 
    Node * P_newnd;
    P_newnd = (Node *)malloc(sizeof(Node));
    if(P_newnd == NULL){
        return NULL;
    }
    P_newnd -> data = n->data;
    P_newnd -> next = n->next;
    P_newnd -> prev = n->prev;
    return P_newnd; 
} 

///
/// @brief      { Create a new list }
///
/// @return     { Return a pointer to the list on success, or a null pointer on failure. }
///
List *new_List() { 
    List * P_lst;
    P_lst = (List *)malloc(sizeof(List));
    if( P_lst == NULL ){
        return NULL;
    }
    P_lst -> head = P_lst -> tail = NULL;
    return P_lst; 
}

///
/// @brief      { Delete an existing list }
///
/// @param      l     { The list to be deleted. If l is null, no operation is performed. }
///
void *del_List(List *l) { 
    if(l==NULL){
        return NULL;
    }
    Node *now = l -> head;
    if(now==NULL){
        free(l);
    }else{
        do{
            const Node * nxt = now -> next;
            free(now);
            now = nxt;
        }while(now!= l -> tail);
    }
    return NULL; 
}

///
/// @brief      { Copy a list into a new list }
///
/// @param      l     { A pointer to the list to be copied }
///
/// @return     { A pointer to the new, copied list }
///
List *copy_List(List *l) { 
    List * P_lst = new_List();
    if(l->head==NULL && l->tail==NULL){
        P_lst -> head = NULL;
        P_lst -> tail = NULL;
    }else{
        Node * P_orind = l->head;
        Node * P_newnd = P_lst -> head = new_Node(P_orind->data);
        do{
            const Node * P_ori_nxt = P_orind -> next;
            Node * P_new_nxt = P_newnd -> next = new_Node(P_ori_nxt->data);
            P_new_nxt -> prev = P_newnd ;
            P_orind = P_ori_nxt;
            P_newnd = P_new_nxt;

        }while(P_orind != l->tail);
        P_lst->tail = P_newnd;
    }
    return P_lst; 
}

///
/// @brief      { Return the length of a list }
///
/// @param      l     { The list to be measured }
///
/// @return     { The length of the list, which is the number of nodes. }
///
size_t len_List(List *l) { 
    int cnt = 0;
    Node * now = l->head;
    if(now==NULL){
        return 0;
    }else{
        cnt ++;
        while(now != l->tail){
            now=now->next;
            cnt++;
        }
    }
    return 0; 
}

///
/// @brief      { Gets a pointer to the first node in the list 
///               with that data value. }
///
/// @param      l     { The list potentially containing a node }
/// @param[in]  d     { The data value to be searched for }
///
/// @return     A pointer to the found node
///
Node *getNode_List(List *l, Data d) { 
    Node * now = l->head;
    if(now == NULL){
        return NULL;
    }else{
        do{
            if(now->data==d){
                return now;
            }
            now = now->next;
        }while(now!=l->tail);
    }
    return NULL; 
}

///
/// @brief      { Inserts a node into the list before the node pointed to by pos.
///               If pos is also the head node, the head pointer is updated. }
///
/// @param      l     { The list to be inserted into }
/// @param      n     { The node to be inserted }
/// @param      pos   { A pointer to the node which will become the successor }
///
/// @return     { A pointer to the modified list }
///
List *insert_Node(List *l, Node *n, Node *pos) { 
    if(l->head==pos){
        n->next = l->head;
        l->head = n;
        return l;
    }else{
        n->next = pos;
        n->prev = pos->prev;
        pos->prev->next = n;
        pos->prev = n;
    }
}

///
/// @brief      { Appends a node at of the list, and updates the tail pointer }
///
/// @param      l     { The list to be appended to }
/// @param      n     { The node to be appended }
///
/// @return     { A pointer to the modified list }
///
List *append_Node(List *l, Node *n); { 
    if( l->head == NULL ){
        l->head = n;
        l->tail = n;
    }else{
        n->prev = l->tail;
        l->tail->next = n;
        l->tail = n;
    }
    return l; 
}

///
/// @brief      Removes a node from the list.
///
/// @param      l     { The list containing the node to be removed }
/// @param      pos   { A pointer to the node to be removed }
///
/// @return     { A pointer to the modified list }
///
List *remove_Node(List *l, Node *pos) { 
    if(l->head == pos){
        l->head = pos->next;
    }
    if(l->tail == pos){
        l->tail = pos->prev;
    }
    if(pos->prev!=NULL){
        pos->prev = pos->next;
    }
    if(pos->next!=NULL){
        pos->next = pos->prev;
    }
    del_Node(pos);
    return l; 
}

///
/// @brief     { Pretty prints a node's data, and the addresses in the 
///              prev and next pointers. }
///
/// @param      n     { The node to be printed }
///
void print_Node(Node* n) {
    printf("ADDRESS:%p, data:%ulld, PREV_ADDRESS:%p, NEXT_ADDRESS:%p\n",n,n->data,n->prev,n->next);
    return ;
}

///
/// @brief      { Pretty prints a list. First, it prints the head/tail pointers,
///               then it traverses the list, calling print_Node on each node. }
///
/// @param      l     { The list to be printed }
///
void print_List(List* l) {
    printf("LIST: HEAD:%p, TAIL:%p \n",l->head,l->tail);
    Node * now = l->head;
    if(now==NULL){
        printf("====EMPTY LIST====\n");
        return ;
    }else{
        do{
            print_Node(now);
            now=now->next;
        }while(now!=l->tail);
    }
}
