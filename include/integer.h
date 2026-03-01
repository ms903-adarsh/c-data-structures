#ifndef INTEGER_H
#define INTEGER_H
#include "object.h"

typedef struct integer Integer;

Object* create_Integer(int num);
Object* add_Integers(Object* obj1, Object* obj2);
void print_Integer(Object* obj);

#endif