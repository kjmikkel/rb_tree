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
    // This is 'z' in Cormen
    rb_vertex<T>* new_vertex = new rb_vertex<T>(in_value);

    // This iss 'y' in Cormen
    rb_vertex<T>* current_vertex = 0;
    // This is 'x' in Cormen
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

    if (current_vertex == 0) {
        root = new_vertex;
        root->set_colour(BLACK);
        return;
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

    rb_vertex<T>* y = current_vertex->get_right_child();
    rb_vertex<T>* left = y->get_left_child();
    rb_vertex<T>* parent = current_vertex->get_parent();

    current_vertex->set_right_child(left);

    if (left != 0) {
        left->set_parent(current_vertex);
    }

    y->set_parent(parent);

    if (parent == 0) {
        root = y;
    } else {
        if (current_vertex == parent->get_left_child()) {
            parent->set_left_child(y);
        } else {
            parent->set_right_child(y);
        }
    }
    y->set_left_child(current_vertex);
    current_vertex->set_parent(y);
}

template<typename T>
void rb_tree<T>:: right_rotate(rb_vertex<T>* current_vertex) {

    rb_vertex<T>* y = current_vertex->get_left_child();
    rb_vertex<T>* right = y->get_right_child();
    rb_vertex<T>* parent = current_vertex->get_parent();

    current_vertex->set_left_child(right);

    if (right != 0) {
        right->set_parent(current_vertex);
    }

    y->set_parent(parent);

    if (parent == 0) {
        root = y;
    } else {
        if (current_vertex == parent->get_right_child()) {
            parent->set_right_child(y);
        } else {
            parent->set_left_child(y);
        }
    }
    y->set_right_child(current_vertex);
    current_vertex->set_parent(y);

}

 // Insert and remove fixup
template<typename T>
void rb_tree<T>::insert_fixup(rb_vertex<T>* new_vertex) {

    rb_vertex<T>* parent = new_vertex->get_parent();
    rb_vertex<T>* grandparent = parent->get_parent();
    rb_vertex<T>* current_vertex = 0;
    bool current_vertex_exist;

    // If the grandparent does not exist, then we return
    if (grandparent == 0) {
        root->set_colour(BLACK);
        return;
    }

    while(parent->get_colour() == RED) {
        grandparent = parent->get_parent();

        if (grandparent->get_left_child() == parent) {
            current_vertex = grandparent->get_right_child();
            current_vertex_exist = current_vertex != 0;

            // Case 1
            if (current_vertex_exist && current_vertex->get_colour() == RED) {
                parent->set_colour(BLACK);
                current_vertex->set_colour(BLACK);
                grandparent->set_colour(RED);
                new_vertex = grandparent;
            } else if (new_vertex == parent->get_right_child()) {
                // Case 2
                current_vertex = parent;
                rb_tree::left_rotate(new_vertex);
            }
            // Case 3
            parent->set_colour(BLACK);
            grandparent->set_colour(RED);
            rb_tree::right_rotate(grandparent);
        } else {
            current_vertex = grandparent->get_left_child();
            current_vertex_exist = current_vertex != 0;

            // Case 1
            if (current_vertex_exist && current_vertex->get_colour() == RED) {
                parent->set_colour(BLACK);
                current_vertex->set_colour(BLACK);
                grandparent->set_colour(RED);
                new_vertex = grandparent;
            } else if (new_vertex == parent->get_left_child()) {
                // Case 2
                current_vertex = parent;
                rb_tree::right_rotate(new_vertex);
            }
            // Case 3
            parent->set_colour(BLACK);
            grandparent->set_colour(RED);
            rb_tree::left_rotate(grandparent);
        }
    }

    root->set_colour(BLACK);
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
