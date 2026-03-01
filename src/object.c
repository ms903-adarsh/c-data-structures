#include "object.h"
#include <stdlib.h>

Object* create(Type* type){
    Object* obj = malloc(type->size);
    obj->type = type;
    obj->ref_count = 1;
};

void incref(Object* obj){
    obj->ref_count++;
};

void decref(Object* obj){
    if(obj){
        obj->ref_count--;
        if(obj->ref_count <= 0){
            free(obj);
        }
    }
};