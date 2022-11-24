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
Vector *new_Vector(size_t size) { return NULL; }

///
/// @brief      { Delete an existing vector }
///
/// @param      v     { Pointer to the vector to be deleted. If v is null, no operation is performed }
///
void del_Vector(Vector *v) { return NULL; }

///
/// @brief      { Copies the contents of a vector into a new vector }
///
/// @param      v     { Pointer to the existing vector }
///
/// @return     { Returns a pointer to the newly copied vector on success,
/// 			  or a null pointer on failure. }
///
Vector *copy_Vector(Vector *v) { return NULL; }

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
Data *at_Vector(struct Vector *v, size_t index) { return NULL; }

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
void insert_Vector(struct Vector *v, Data d, size_t index) {}

///
/// @brief      { Resize the vector storage. 
///               This includes both the array and the used storage.
///               If the realloc call fails, call exit(1) }
///
/// @param      v     { The vector whose storage will be resized }
/// @param[in]  size  The new storage size
///
void resize_Vector(struct Vector *v, size_t size) {}

///
/// @brief      { Remove an item from the vector's storage at index 
///               by zeroing that index in the array, and mark it unused.
///               Len may possibly be updated if the index is equal to len. }
///
/// @param      v      { The vector }
/// @param[in]  index  The index to remove
///
void remove_Vector(struct Vector *v, size_t index) {}

///
/// @brief      { Remove all items from vector storage. 
///               The result is equivalent to a zero-initialized array 
///               and all items marked unused in the used array.
///               Storage size does not change, but len is zeroed.}
///
/// @param      v     { The vector to be cleared. }
///
void clear_Vector(struct Vector *v) {}

///
/// @brief      Pretty prints contents of the vector's array and used array.
///
/// @param      v     { parameter_description }
///
void print_Vector(Vector *v) {}