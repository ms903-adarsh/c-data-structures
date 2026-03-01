#include "object.h"
#include <stdlib.h>

Object* create(Type* type, ...){
    Object* obj = malloc(type->size);
    obj->type = type;
    obj->ref_count = 1;

    if(type->init != NULL){
        va_list args;
        va_start(args, type);
        type->init(obj, args);
        va_end(args);
    }
    return obj;
};

void destroy(Object* obj){
    free(obj);
    return;
}

void incref(Object* obj){
    obj->ref_count++;
    return;
};

void decref(Object* obj){
    if(obj){
        obj->ref_count--;
        if(obj->ref_count == 0){
            free(obj);
        }
    }
    return;
};