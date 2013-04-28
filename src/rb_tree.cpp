#include <functional>

#include "rb_tree.h"
#include "rb_vertex.h"

template<typename T>
rb_tree<T>::rb_tree(std::function<bool (T, T)> in_func)
{
    compare = in_func;
    root = 0;
}

template<typename T>
rb_tree<T>::~rb_tree()
{
    //dtor
}

template<typename T>
void rb_tree<T>::insert(T in_value) {

    rb_vertex<T>* new_vertex = new rb_vertex<T>(in_value);

    rb_vertex<T>* current_vertex = 0;
    rb_vertex<T>* parent = root;

    while (parent != 0) {
        current_vertex = parent;

        if (compare(new_vertex->get_value(), parent->get_value())) {
            parent = parent->get_left_child();
        } else {
            parent = parent->get_right_child();
        }
    }

    new_vertex->set_parent(current_vertex);

    if (new_vertex == 0) {
        root = new_vertex;
    } else {
        if (compare(new_vertex->get_value(), current_vertex->get_value())) {
            current_vertex->set_left_child(new_vertex);
            } else {
            current_vertex->set_right_child(new_vertex);
            }
    }

    rb_tree::insert_fixup(new_vertex);
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

// Diagnostic methods
template<typename T>
int rb_tree<T>::max_depth() {
    return root->depth();
}

template<typename T>
bool rb_tree<T>::test(T val1, T val2)
{
    return compare(val1, val2);
}

template<typename T>
bool rb_tree<T>::black_balance() {
    return root->black_balance() != -1;
}
