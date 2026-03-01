#include "integer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct integer{
    Object base;
    int value;
} Integer;

Type IntegerType;

void create_Integer(Object* Int, va_list args){
    Integer* self = (Integer*)Int;
    self->value = va_arg(args, int);
}

Object* add_Integers(Object* Int1, Object* Int2){
    return create(&IntegerType, ((Integer*)Int1)->value + ((Integer*)Int2)->value);
};

int length_Integer(Object* Int){
    if(Int != NULL){
        return 1;
    } else {
        return 0;
    }
}

void print_Integer(Object* obj){
    printf("Object: %s\nValue:%d\n",obj->type->name, ((Integer*)obj)->value);
    return;
}

Type IntegerType = {
    .name = "Integer",
    .size = sizeof(Integer),
    .create = create_Integer,
    .destroy = NULL,
    .add = add_Integers,
    .print = print_Integer,
    .length = length_Integer
};


