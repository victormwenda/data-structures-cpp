//
// @author Victor Mwenda
// @author vmwenda.vm@gmail.com
//
// Created by victor on 1/26/15.
// C/C++ Laptop
//



#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <iostream>
#include <glob.h>
#include <malloc.h>
#include <algorithm>

//
// Stack
// //
template<class T>
class Stack {

private:
    T *data;
    size_t size;
    int top;
public:
    /**
     * Initialize a stack of the give size
     * @param size
     */
    Stack<T>(size_t size) : size(size) {
        top = -1;
        data = (T *) calloc(size, sizeof(T));
    }

    /**
     * Add an item to the stack
     * @param t
     */
    void add(T t) {
        data[++top] = t;
    }

    /**
     * Get the item at the specified position
     * @param position
     * @return
     */
    T get(size_t position) {
        return data[position];
    }

    /**
     * Remove the top most item of the stack
     */
    void pop() {
        --top;
    }

    /**
     * Remove all items in the stack
     * @return
     */
    bool popAll() {
        if (!isEmpty()) {
            pop();
            return popAll();
        }
        return isEmpty();
    }

    /**
     * Get the top most item in the stack
     * @return
     */
    T peek() {
        return get((size_t) top);
    }

    /**
     * Checks if the stack is empty
     * @return
     */
    bool isEmpty() {
        return top == -1;
    }

    T *list() {
        return data;
    }

    /**
     * Get the number of items in the stack
     * @return
     */
    size_t getItemCount() { return (size_t) (top + 1); }
};


#endif //DATA_STRUCTURES_STACK_H
