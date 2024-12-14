#include "vector.h"

#define MIN_CAPACITY        32
#define NOT_EXIST           -1


typedef struct _vector {
    void**  buf;            // The array.
    size_t  count;          // Number of elements currently in the array.
    size_t  capacity;       // Max number of elements that the array can store.
} vector;


/******************************************************************************
 * @brief Helper function to resize a vector.
 *****************************************************************************/
static bool
vector_resize(vector* v, size_t new_capacity) {
    if (v == NULL) {
        return false;
    }
    bool    status  = false;
    void**  buf     = realloc(v->buf, sizeof(void*) * new_capacity);

    if (buf) {
        v->buf      = buf;
        v->capacity = new_capacity;
        status      = true;
    }
    return status;
}


vector*
vector_construct() {
    vector* v           = malloc(sizeof(v));
    v->capacity         = MIN_CAPACITY;
    v->count            = 0;
    v->buf              = malloc(sizeof(void*) * v->capacity);
    return v;
}


size_t
vector_size(vector* v) {
    return v->count;
}


bool
vector_destroy(vector** v, bool free_elements) {
    if (v == NULL) {
        return false;
    }
    if (free_elements) {
        for (size_t i = 0; i < (*v)->count; i++) {
            free((*v)->buf[i]);
        }
    }
    free((*v)->buf);
    (*v)->buf = NULL;
    free(*v);
    *v = NULL;
    return true;
}


void*
vector_get(vector* v, size_t index) {
    if (v == NULL) {
        return NULL;
    }
    if (index < v->count) {
        return v->buf[index];
    }
    return NULL;
}


bool
vector_set(vector* v, size_t index, void* data) {
    if (v == NULL) {
        return false;
    }
    if (index < v->count) {
        v->buf[index] = data;
        return true;
    }
    return false;
}


bool
vector_pushback(vector* v, void* data) {
    if (v->count == v->capacity) {
        if (!vector_resize(v, v->capacity * 2)) {
            return false;
        }
    }
    return vector_set(v, v->count++, data);
}


bool
vector_pushfront(vector* v, void* data) {
    if (v == NULL) {
        return false;
    }
    if (v->count == v->capacity) {
        if (!vector_resize(v, v->capacity * 2)) {
            return false;
        }
    }

    // shift the elements to make room at the front
    for (size_t i = v->count; i > 0; i--) {
        v->buf[i] = v->buf[i - 1];
    }
    if (!vector_set(v, 0, data)) {
        return false;
    }
    v->count++;
    return true;
}


void*
vector_delete(vector* v, size_t index) {
    if (v == NULL || index >= v->count) {
        return NULL;
    }
    void* deleted_value = v->buf[index];
    v->buf[index] = NULL;

    // shift the elements to fill the gap
    for (size_t i = index; i < v->count - 1; i++) {
        v->buf[i]       = v->buf[i + 1];
        v->buf[i + 1]   = NULL;
    }
    v->count--;

    if (v->count > 0 && v->count == v->capacity / 4) {
        size_t new_capacity = v->count / 2;
        if (new_capacity >= MIN_CAPACITY) {
            if (!vector_resize(v, new_capacity)) {
                return NULL;
            }
        }
    }
    return deleted_value;
}


long
vector_find(vector* v, void* data) {
    for (size_t i = 0; i < v->count; i++) {
        if (vector_get(v, i) == data) return i;
    }
    return NOT_EXIST;
}
