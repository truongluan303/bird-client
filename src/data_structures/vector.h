#ifndef BIRD_CLIENT__VECTOR_H
#define BIRD_CLIENT__VECTOR_H

#include <stdbool.h>
#include <stdlib.h>


/******************************************************************************
 * @brief       Represents the vector/list data structure.
 *****************************************************************************/
typedef struct _vector vector;


/******************************************************************************
 * @brief       Construct a new vector.
 *
 * @return      The newly constructed vector.
 *****************************************************************************/
vector* vector_construct();


/******************************************************************************
 * @brief       Get the number of elements in a vector.
 *
 * @return      Number of elements in the given vector.
 *****************************************************************************/
size_t vector_size(vector* v);


/******************************************************************************
 * @brief       Get the element at a given index in the vector.
 *
 * @param v             The vector to get data from.
 * @param index         The index to get data from.
 *
 * @return      The data at the given index.
 *****************************************************************************/
void* vector_get(vector* v, size_t index);


/******************************************************************************
 * @brief       Set the data at a given index in the vector.
 *
 * @param v             The vector to set data.
 * @param index         The index where data will be set.
 * @param data          The data to be assigned.
 *
 * @return      True if successful, false otherwise.
 *****************************************************************************/
bool vector_set(vector* v, size_t index, void* data);


/******************************************************************************
 * @brief       Add a new element to the end of the vector.
 *
 * @param v             The vector to be added to.
 * @param data          The data to be added.
 *
 * @return      True if successful, false otherwise.
 *****************************************************************************/
bool vector_pushback(vector* v, void* data);


/******************************************************************************
 * @brief       Add a new element to the front of the vector.
 *
 * @param v             The vector to be added to.
 * @param data          The data to be added.
 *
 * @return      True if successful, false otherwise.
 *****************************************************************************/
bool vector_pushfront(vector* v, void* data);


/******************************************************************************
 * @brief       Remote the element at the given index. Note that you need to
 *              manually free the element after it is returned from this
 *              function (if the element was dynamically allocated).
 *
 * @param v             The vector to remove the element from.
 * @param index         The index of the element to be removed.
 *
 * @return      The value of the deleted element.
 *****************************************************************************/
void* vector_delete(vector* v, size_t index);


/******************************************************************************
 * @brief       Remove the element at the end of the vector. Note that you need
 *              to manually free the element after it is returned from this
 *              function (if the element was dynamically allocated).
 *
 * @param v             The vector to remove element from.
 *
 * @return      The data removed.
 *****************************************************************************/
inline void* vector_popback(vector* v) {
    return vector_delete(v, vector_size(v) - 1);
}


/******************************************************************************
 * @brief       Remove the element at the front of the vector. Note that you
 *              need to manually free the element after it is returned from
 *              this function (if the element was dynamically allocated).
 *
 * @param v             The vector to remove element from.
 *
 * @return      The data removed.
 *****************************************************************************/
inline void* vector_popfront(vector* v) {
    return vector_delete(v, 0);
}


/******************************************************************************
 * @brief       Find the index of an element in a vector.
 *
 * @param v             The vector to be initialized
 * @param data_size     The size of each data element
 *
 * @return      The index of the first occurence of the given data, -1 if the
 *              given data does not exist.
 *****************************************************************************/
long vector_find(vector* v, void* data);


/******************************************************************************
 * @brief       Check if the vector contains a specific data value.
 *
 * @param v             The vector to be searched.
 * @param data          The data to be searched.
 *
 * @return      `TRUE` if the vector contains the given data, `FALSE`
 *              otherwise.
 *****************************************************************************/
inline bool vector_contains(vector* v, void* data) {
    return vector_find(v, data) == -1 ? false : true;
}


/******************************************************************************
 * @brief       Deallocates the memory allocated for the vector.
 *
 * @param v                 The vector to be destroyed.
 * @param free_elements     Whether to the call `free` on the elements.
 *
 * @return      True if successful, false otherwise
******************************************************************************/
bool vector_destroy(vector** v, bool free_elements);


#endif // BIRD_CLIENT__VECTOR_H
