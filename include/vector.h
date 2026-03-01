#ifndef VECTOR_H
#define VECTOR_H

#include "object.h"

typedef struct vector Vector{
    Object base;
    int size;
    int capacity;
    Object** data;
};

Object* create(Type* type, int num){
    Object* obj = malloc(sizeof(type->size)*num);
    obj->type = type;
    obj->ref_count = 1;
}

Object* get(Object* vector, int pos){
    return (Vector*)vector[pos];
}

Object* push(Object* vector, Object* obj){

}

Object* pop(Object* vector){

}

Type VectorType = {
    .name = "Vector",
    .size = 
}