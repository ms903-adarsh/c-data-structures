#include "integer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct integer{
    Object base;
    int value;
} Integer;

void init_Integer(Object* Int, va_list args){
    Integer* self = (Integer*)Int;
    self->value = va_arg(args, int);
}

Type IntegerType = {
    .name = "Integer",
    .size = sizeof(Integer),
    .init = init_Integer,
    .destroy = NULL
};

Object* add_Integers(Object* Int1, Object* Int2){
    return create(&IntegerType, ((Integer*)Int1)->value + ((Integer*)Int2)->value);
};

void print_Integer(Object* obj){
    printf("%d",((Integer*)obj)->value);
    return;
}
