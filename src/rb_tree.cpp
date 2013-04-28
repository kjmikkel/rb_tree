#include <functional>

#include "rb_tree.h"
#include "rb_vertex.h"

template<typename T>
rb_tree<T>::rb_tree(std::function<bool (T, T)> in_func)
{
    func = in_func;
    root = 0;
}

template<typename T>
void rb_tree<T>::insert(T in_value) {
    rb_vertex<T>* current_vertex = 0;
    rb_vertex<T>* parent = root;

    while (parent != 0) {
        current_vertex = parent;
        if (func()) {

        }
    }
}

template<typename T>
void rb_tree<T>::remove(T out_value) {

}


// Left and right rotate
template<typename T>
void rb_tree<T>:: left_rotate(rb_vertex<T>* current_vertex) {

}

template<typename T>
void rb_tree<T>:: right_rotate(rb_vertex<T>* current_vertex) {

}

 // Insert and remove fixup
template<typename T>
void rb_tree<T>::insert_fixup(rb_vertex<T>* current_vertex) {

}

template<typename T>
void rb_tree<T>::remove_fixup(rb_vertex<T>* current_vertex) {

}



template<typename T>
bool rb_tree<T>::test(T val1, T val2)
{
    return func(val1, val2);
}

template<typename T>
rb_tree<T>::~rb_tree()
{
    //dtor
}
