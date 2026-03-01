#include "object.h"
#include <stdlib.h>
#include <stdio.h>

Object* create(Type* type, ...){
    Object* obj = malloc(type->size);
    obj->type = type;
    obj->ref_count = 1;

    if(type->create != NULL){
        va_list args;
        va_start(args, type);
        type->create(obj, args);
        va_end(args);
    }
    return obj;
};

void destroy(int count, Object* obj, ...){
    va_list args;
    va_start(args, obj);
    for (int i = 1; i < count; i++){
        free(va_arg(args, Object*));
    }
    free(obj);
    va_end(args);
    return;
}

Object* add(Object* self, Object* other){
    return self->type->add(self, other);
};

void print(Object* obj){
    return obj->type->print(obj);
};

void incref(Object* obj){
    obj->ref_count++;
    return;
};

int length(Object* obj){
    return obj->type->length(obj);
}

void decref(Object* obj){
    if(obj){
        obj->ref_count--;
        if(obj->ref_count == 0){
            free(obj);
        }
    }
    return;
};