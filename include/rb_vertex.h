#ifndef RB_VERTEX_H
#define RB_VERTEX_H

#include "enum.h"

template<typename T>
class rb_vertex
{
    public:
        rb_vertex<T>(T in_value, rb_vertex* in_parent);
        virtual ~rb_vertex();

        void set_colour(enum_colour in_colour);
        enum_colour get_colour();

        rb_vertex* get_parent();
        void set_parent(rb_vertex* vertex);

    protected:
    private:

        rb_vertex<T>* left_child;
        rb_vertex<T>* right_child;
        rb_vertex<T>* parent;
        T value;
        enum_colour colour;
};

#endif // RB_VERTEX_H
