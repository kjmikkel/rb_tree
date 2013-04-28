#include <algorithm>
#include "rb_vertex.h"
#include "enum.h"

template<class T>
rb_vertex<T>::rb_vertex(T in_value, rb_vertex* in_parent)
{
    value = in_value;
    colour = RED;
    left_child = 0;
    right_child = 0;
    parent = in_parent;
}

template<class T>
rb_vertex<T>::~rb_vertex()
{
    //dtor
}

template<class T>
enum_colour rb_vertex<T>::get_colour() {
    return colour;
}

template<class T>
void rb_vertex<T>::set_colour(enum_colour in_colour) {
    colour = in_colour;
}

        // Parents getters and setters
template<class T>
rb_vertex<T>* rb_vertex<T>::get_parent() {
    return parent;
}


template<class T>
void rb_vertex<T>::set_parent(rb_vertex<T>* vertex) {
    parent = vertex;
}

        // Value getter
template<class T>
T rb_vertex<T>::get_value() {
    return value;
}

// Child getters and setters
template<class T>
rb_vertex<T>* rb_vertex<T>::get_left_child() {
    return left_child;
}

template<class T>
void rb_vertex<T>::set_left_child(rb_vertex<T>* child){
    left_child = child;
}

template<class T>
rb_vertex<T>* rb_vertex<T>::get_right_child(){
    return right_child;
}

template<class T>
void rb_vertex<T>::set_right_child(rb_vertex<T>* child){
    right_child = child;
}

// Diagnostic methods
template<class T>
int rb_vertex<T>::depth() {
    int left = 0;
    int right = 0;

    if (left_child != 0) {
        left = left_child->depth();
    }

    if (right_child != 0) {
        right = right_child->depth();
    }

    return 1 + std::max(left, right);
}

template<class T>
int rb_vertex<T>::black_balance() {
    int left_balance = 0;
    int right_balance = 0;

    int personal_black = 0;

    if (colour = BLACK) {
        personal_black = 1;
    }

    if (left_child != 0) {
        left_balance = left_child->black_balance();
    }

    if (right_child != 0) {
        right_balance = right_child->black_balance();
    }

    // If we get an error message, then propergate the error
    if ((left_balance == -1) or (right_balance == -1)) {
        return -1;
    // If the numbers are equal, then we return the current number of black vertecies + the current colour
    } else if (left_balance == right_balance) {
        return left_balance + personal_black;
    }
    // If we reach this point, then we can be sure that there is an imbalance, and we return the error number
    else {
        return -1;
    }
}
