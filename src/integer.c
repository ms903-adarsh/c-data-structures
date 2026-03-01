#include "integer.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct integer{
    Object base;
    int value;
} Integer;

Type IntegerType = {
    .name = "Integer",
    .size = sizeof(Integer)
};

Object* create_Integer(int num){
    Object* obj = malloc(IntegerType.size);
    obj->type = &IntegerType;
    obj->ref_count = 1;
    ((Integer*)obj)->value = num;
    return obj;
};

Object* add_Integers(Object* obj1, Object* obj2){
    return create_Integer(((Integer*)obj1)->value + ((Integer*)obj2)->value);
};

void print_Integer(Object* obj){
    printf("%d",((Integer*)obj)->value);
    return;
}
