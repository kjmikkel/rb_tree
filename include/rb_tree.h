#ifndef RB_TREE_H
#define RB_TREE_H

#include <functional>
#include "rb_vertex.h"

template<typename T>
class rb_tree
{
    public:
        rb_tree<T>(std::function<bool (T, T)> in_func);
        virtual ~rb_tree();

        // Insert and delete
        void insert(T in_value);
        void remove(T out_value);

        bool test(T val1, T val2);

        // Diagnostic methods
        int max_depth();
        bool black_balance();
        void print_tree();


    protected:
    private:
        std::function<bool (T, T)> compare;
        rb_vertex<T>* root;

        // Left and right rotate
        void left_rotate(rb_vertex<T>* current_vertex);
        void right_rotate(rb_vertex<T>* current_vertex);

        // Insert and remove fixup
        void insert_fixup(rb_vertex<T>* current_vertex);
        void remove_fixup(rb_vertex<T>* current_vertex);

};

#endif // RB_TREE_H
