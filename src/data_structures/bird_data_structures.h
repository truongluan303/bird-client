#ifndef BIRD_CLIENT__DATA_STRUCTURES_H
#define BIRD_CLIENT__DATA_STRUCTURES_H

// https://docs.rs/birdc/latest/birdc/


typedef struct protocol_t {
    char* name;
    char* proto;
    char* table;
    char* state;
    char* since;
    char* info;
} protocol;


#endif // BIRD_CLIENT__DATA_STRUCTURES_H
