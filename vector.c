#include "datastructs/vector.h"
#include <stddef.h>
#include <stdlib.h>

///
/// @brief      { Creates a new vector}
///
/// @param[in]  size  The initial size of the vector's array storage
///
/// @return     { Return a pointer to the vector }
///
Vector *new_Vector(size_t size) { 
    Vector * P_vec;
    P_vec = (Vector *)malloc(sizeof(Vector));
    P_vec -> len = 0;
    P_vec -> size = size;
    P_vec -> array = (Data *)malloc( sizeof(Data) * size );
    memset(P_vec -> array, 0, sizeof(Data) * size );
    P_vec -> used = malloc( sizeof(bool) * size );
    memset(P_vec -> used, 0, sizeof(bool) * size );
    return P_vec; 
}

///
/// @brief      { Delete an existing vector }
///
/// @param      v     { Pointer to the vector to be deleted. If v is null, no operation is performed }
///
void del_Vector(Vector *v) { 
    free(v->array);
    free(v->used);
    free(v);
    return; 
}

///
/// @brief      { Copies the contents of a vector into a new vector }
///
/// @param      v     { Pointer to the existing vector }
///
/// @return     { Returns a pointer to the newly copied vector on success,
/// 			  or a null pointer on failure. }
///
Vector *copy_Vector(Vector *v) { 
    Vector * P_newvec;
    P_newvec = (Vector *)malloc(sizeof(Vector));
    P_newvec -> len = v -> len;
    P_newvec -> size = v -> size;
    P_newvec -> array = (Data *)malloc( sizeof(Data) * P_newvec -> size );
    memcpy( P_newvec -> array , v -> array , sizeof(Data) * P_newvec -> size );
    P_newvec -> used = malloc( sizeof(bool) * P_newvec -> size  );
    memcpy( P_newvec -> used , v -> used , sizeof(bool) * P_newvec -> size );
    return P_newvec; 
}

///
/// @brief      Get the element from the vector at an index
///
/// @param      v      { The vector containing the element }
/// @param[in]  index  The index of the element to be retrieved
///
/// @return     { Returns a pointer to the element on success,
///               or a null pointer on failure (e.g. the index is out of bounds 
///               or the element is not marked used.) }
///
Data *at_Vector(struct Vector *v, size_t index) { 
    if( index >= (v->len) || (v->used)[index] == false ){
        return NULL;
    }
    return (v->array)[index]; 
}

///
/// @brief      { Insert an element into the vector at an index. 
///               If index is larger than the current bounds of the array, 
///               this will also cause a resizing operation to the nearest 
///               power of two larger than the desired index. 
///               The index will be marked used, and len is updated 
///               if index is larger than len. }
///
/// @param      v      { The vector in which to store the element }
/// @param[in]  d      { The data to be stored in the vector }
/// @param[in]  index  The index of the element to contain the data item.
///
void insert_Vector(struct Vector *v, Data d, size_t index) {
    while( index > (v->size) ){
        resize_Vector( v, 2*(v->size) );
    }
    (v->array)[index] = d;
    (v->used)[index] = true;
    if((v->len)< index ){
        v->len = index;
    }
    return ;
}

///
/// @brief      { Resize the vector storage. 
///               This includes both the array and the used storage.
///               If the realloc call fails, call exit(1) }
///
/// @param      v     { The vector whose storage will be resized }
/// @param[in]  size  The new storage size
///
void resize_Vector(struct Vector *v, size_t size) {
    Vector * P_newarr = malloc( sizeof(Data) * size );
    if( P_newarr == NULL ) {
        exit(1);
    }else{
        memset(P_newarr , 0, sizeof(Data) * size );
        memcpy( v->array , P_newarr , sizeof(Data) * (v->size) );
        free(v->array);
        v -> array = P_newarr;
        v -> size = size;
    }
    return;
}

///
/// @brief      { Remove an item from the vector's storage at index 
///               by zeroing that index in the array, and mark it unused.
///               Len may possibly be updated if the index is equal to len. }
///
/// @param      v      { The vector }
/// @param[in]  index  The index to remove
///
void remove_Vector(struct Vector *v, size_t index) {
    (v->array)[index] = 0;
    (v->used)[index] = false;
    if(v->len == index){
        size_t ans = 0;
        for(int i=index-1 ; i>=0 ; i--){
            if((v->used)[i]){
                ans = i;
                break;
            }
        }
        v->len = ans;
    }
    return ;
}

///
/// @brief      { Remove all items from vector storage. 
///               The result is equivalent to a zero-initialized array 
///               and all items marked unused in the used array.
///               Storage size does not change, but len is zeroed.}
///
/// @param      v     { The vector to be cleared. }
///
void clear_Vector(struct Vector *v) {
    memset(v->array,0,v->size);
    memset(v->used,false,v->size);
    v->len = 0;
    return ;
}

///
/// @brief      Pretty prints contents of the vector's array and used array.
///
/// @param      v     { parameter_description }
///
void print_Vector(Vector *v) {
    const int sz = v->size;
    printf("vector's array:\n");
    for(int i=0;i<sz;i++){
        if(i!=0){
            printf(",");
        }
        printf("%d",(v->array)[i]);
    }
    printf("\nvector's used:\n");
    for(int i=0;i<sz;i++){
        if(i!=0){
            printf(",");
        }
        printf("%d",(v->used)[i]);
    }
    return ;
}