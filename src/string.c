#include "string.h"
#include <stdio.h>
#include <stdlib.h>

//definition of a string
typedef struct string{
    Object base;
    char* line;
} String;

Type StringType;

void create_String(Object* obj, va_list args){
    String* self = (String*)obj;
    self->line = va_arg(args, char*);
}

void print_String(Object* obj){
    printf("Object: %s\nValue: %s", obj->type->name, ((String*)obj)->line);
}

int length_String(Object* obj){
    if(obj != NULL){
        int i;
        for(i = 0; ((String*)obj)->line[i] != '\0'; i++);
        return i; 
    } else {
        return 0;
    }
}

Type StringType = {
    .name = "String",
    .size = sizeof(String),
    .create = create_String,
    .destroy = NULL, 
    .add = NULL,
    .print = print_String,
    .length = length_String
};