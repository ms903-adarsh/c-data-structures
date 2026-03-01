#include "include/integer.h"
#include<stdio.h>

struct name{
    char* name;
    int marks;
};

int main(){
    Object* num1 = create_Integer(5);
    Object* num2 = create_Integer(23);
    Object* res = add_Integers(num1, num2);
    print_Integer(res);
}