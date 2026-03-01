#ifndef OBJECT_H
#define OBJECT_H

//Type struct acts like a template for all the objects which have a particular type;
typedef struct type{
    char* name;
    int size;
} Type;

typedef struct object{
    Type* type;
    int ref_count;
} Object;

Object* create(Type* type);
void incref(Object* obj);
void decref(Object* obj);

#endif