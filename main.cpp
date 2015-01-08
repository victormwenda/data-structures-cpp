#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<int> integers{10};

    if(integers.isEmpty()){
        printf("is  empty \n");
    }

    for (int i = 0; i < 11; i++) {
        integers.add(i);
        printf("The item at %i is %i\n", i, integers.peek());
    }

    int *items = integers.list();

    for(int i =0; i < integers.getItemCount();i++){
        printf("Found item %i\n", items[i]);
    }
    integers.popAll();

    if(integers.isEmpty()){
        printf("is  empty\n");
    }
    return 0;
}