#include <stdio.h>
#include "include/string.h"

use_StringType;

int main(){
    Object* obj = create(&StringType, "adarsh s kamatagi");
    print(obj);
    printf("\n%d\n", length(obj));
    destroy(1, obj);
}