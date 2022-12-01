#include "datastructs/stack.h"
#include <stddef.h>
#include <stdlib.h>

///
/// @brief      { Create a new StackNode containing specified data }
///
/// @param[in]  d     { The data to be stored in the node}
///
/// @return     { Return a pointer to the newly created node on success, 
///               or a null pointer on failure. }
///
StackNode *new_StackNode(Data d) { 
    StackNode* P_sn = (StackNode *)malloc(sizeof(StackNode));
    if(P_sn==NULL){
        return NULL;
    }
    P_sn->value = d;
    P_sn->next = NULL;
    return P_qn; 
}

///
/// @brief      { Delete an existing StackNode. Its heap memory is freed. }
///
/// @param      sn    A pointer to the node to be deleted
///
void del_StackNode(StackNode *sn) { 
    free(sn);
    return; 
}

///
/// @brief      Copy an existing StackNode
///
/// @param      sn    A pointer to the node to be copied
///
/// @return     { Return a pointer to the new, copied node on success,
///               or a null pointer on failure. }
///
StackNode *copy_StackNode(StackNode *sn) { 
    return new_StackNode(sn->value);
}

///
/// @brief      { Create a new stack }
///
/// @return     { Return a pointer to the newly created stack on success, 
///               or a null pointer on failure }
///
Stack *new_Stack() {
    Stack *P_stk = (Stack*) malloc(sizeof(Stack));
    if(P_stk==NULL){
        return NULL;
    }    
    P_stk->length = 0;
    P_stk->top = NULL;
    return P_stk; 
}

///
/// @brief      { Delete an existing stack. Its heap memory is freed.
///               If the stack is not empty, then clear the stack first. }
///
/// @param      s     { A pointer to the stack to be deleted }
///
void del_Stack(Stack *s) {
    clear(s);
    free(s);
    return; 
}

///
/// @brief      { Copy an existing stack }
///
/// @param      s     { A pointer to the existing stack }
///
/// @return     { Return a pointer to the new stack on success,
///               return a null pointer on failure. }
///
Stack *copy_Stack(Stack *s) { 
    Stack *P_1 =copy_Stack_half(s);
    Stack *P_2 =copy_Stack_half(P_1);
    del_Stack(P_1);
    return P_2; 
}

Stack *copy_Stack_half(Stack *s) { 
    Stack *P_stk = (Stack*) malloc(sizeof(Stack));
    if(P_stk==NULL){
        return NULL;
    } 
    StackNode * now = s->top;
    if(now==NULL){
        return P_stk;
    }else{
        do{
            push(P_que,now->next);
        }while(now==q->tail);
    }
    return P_stk; 
}


///
/// @brief      { Clears the contents of the stack without deleting 
///               the stack itself. Reset the length of the stack to 0.
///               Free the memory of all nodes on the stack if the stack was non-empty. 
///
/// @param      s     { A pointer to the stack to be cleared. }
///
void clear(Stack *s) {
    if(s->length>0){
        pop(s);
    }
    return; 
}


///
/// @brief      { Create a node with the given value, 
///               then push it onto the stack. 
///               Increment the length of the stack. }
///
/// @param      s     { A pointer to the stack }
/// @param[in]  d     { The value to be placed in the node }
///
void push(Stack *s, Data d) { 
    s->length++;
    StackNode * now = new_StackNode(d);
    now->next = s->top;
    s->top = now;
    return; 
}

///
/// @brief      { Pop a node from the stack, and return the Data inside.
///               Decrement the length of the stack. The popped node is freed.}
///
/// @param      s     { A pointer to the stack }
///
/// @return     { The data value in the popped node. }
///
Data pop(Stack *s) { 
    s->length--;
    StackNode * now = s->top;
    Data ans = now->value;
    s->top = now->next;
    del_StackNode(now);
    return ans; 
}

///
/// @brief      { Get the value of the top of the stack without popping the node. }
///
/// @param      s     { A pointer to the stack }
///
/// @return     { The data value in the node at the top of the stack. }
///
Data peek(Stack *s) { 
    return s->top->value; 
}