#ifndef OBJECT_H
#define OBJECT_H
#include <stdarg.h>

typedef struct object Object;
//Type struct acts like a template for all the objects which have a particular type;
typedef struct type{
    char* name;
    int size;
    void (*init)(Object* obj, va_list args);
    void (*destroy)(Object* obj);
} Type;

//Object is an instance of a type
typedef struct object{
    Type* type;
    int ref_count;
} Object;

Object* create(Type* type, ...);
void destroy(Object* obj);
void incref(Object* obj);
void decref(Object* obj);

#endif