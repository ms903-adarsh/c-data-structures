#include "include/integer.h"
#include<stdio.h>

use_IntegerType;

int main(){
    Object* num1 = create(&IntegerType, 5);
    Object* num2 = create(&IntegerType, 23);
    Object* res = add_Integers(num1, num2);
    print_Integer(res);
}