#ifndef OBJECT_H
#define OBJECT_H
#include <stdarg.h>

typedef struct object Object;
//Type struct acts like a template for all the objects which have a particular type;
typedef struct type{
    char* name;
    int size;
    void (*create)(Object* obj, va_list args);
    void (*destroy)(Object* obj, va_list args);
    Object* (*add)(Object* self, Object* other);
    void (*print)(Object* obj);
    int (*length)(Object* obj);
} Type;

//Object is an instance of a type
typedef struct object{
    Type* type;
    int ref_count;
} Object;

Object* create(Type* type, ...);
Object* add(Object* obj1, Object* obj2);
void print(Object* obj);
void destroy(int count, Object* obj, ...);
int length(Object* obj);
void incref(Object* obj);
void decref(Object* obj);

#endif