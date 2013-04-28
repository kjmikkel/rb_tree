#ifndef RB_VERTEX_H
#define RB_VERTEX_H

#include "enum.h"

template<typename T>
class rb_vertex
{
    public:
        rb_vertex<T>(T in_value, rb_vertex* in_parent);
        virtual ~rb_vertex();

        // Colour gettters and setters
        enum_colour get_colour();
        void set_colour(enum_colour in_colour);

        // Parents getters and setters
        rb_vertex<T>* get_parent();
        void set_parent(rb_vertex<T>* vertex);

        // Value getter
        T get_value();

        // Child getters and setters
        rb_vertex<T>* get_left_child();
        void set_left_child(rb_vertex<T>* child);

        rb_vertex<T>* get_right_child();
        void set_right_child(rb_vertex<T>* child);

    protected:
    private:

        rb_vertex<T>* left_child;
        rb_vertex<T>* right_child;
        rb_vertex<T>* parent;
        T value;
        enum_colour colour;
};

#endif // RB_VERTEX_H
