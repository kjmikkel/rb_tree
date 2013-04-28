#include "rb_vertex.h"
#include "enum.h"

template<class T>
rb_vertex<T>::rb_vertex(T in_value, rb_vertex* in_parent)
{
    value = in_value;
    colour = BLACK;
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
