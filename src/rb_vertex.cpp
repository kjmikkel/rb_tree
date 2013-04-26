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
