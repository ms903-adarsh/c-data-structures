#ifndef INTEGER_H
#define INTEGER_H
#define use_IntegerType extern Type IntegerType

#include "object.h"

typedef struct integer Integer;

Object* add_Integers(Object* obj1, Object* obj2);
void print_Integer(Object* obj);

#endif