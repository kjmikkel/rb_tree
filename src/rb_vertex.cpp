#include <algorithm>
#include <iostream>
#include <functional>
#include "rb_vertex.h"
#include "enum.h"


template<class T>
rb_vertex<T>::rb_vertex(T in_value)
{
    value = in_value;
    colour = RED;
    left_child = 0;
    right_child = 0;
    parent = 0;
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

// Get the grandparent, mostly for convinicence
template<class T>
rb_vertex<T>* rb_vertex<T>::get_grandparent() {
    if (parent != 0) {
        return parent->get_parent();
    } else {
        return 0;
    }
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

template<class T>
void rb_vertex<T>::print_tree(std::string side, std::string tabulator) {

    std::cout << tabulator << side << ": Value: " << value << ", Color: " << (colour == BLACK ? "Black" : "Red") << std::endl;

    if (left_child != 0) {
        left_child->print_tree("Left", tabulator + "\t");
    }

    if (right_child != 0) {
        right_child->print_tree("Right", tabulator + "\t");
    }
}

template<class T>
bool rb_vertex<T>::double_red_children() {
    // If the current colour is black, then there is nothing to test for this node

    bool left_child_result = true;
    bool right_child_result = true;

    // Functors! Becuase why write the same exact code 4 times when you only need to do it once!
    std::function<bool (rb_vertex<T>*)> check_children = [] (rb_vertex<T>* child) {
        if (child != 0) {
            return (bool)child->double_red_children();
        } else {
            // The child isn't there, so we can be sure that there isn't any problem
            return true;
        }
    };

    if (colour == BLACK) {

        left_child_result = check_children(left_child);
        right_child_result = check_children(right_child);

        return right_child_result && left_child_result;
    } else {
        // The current vertex is RED, so we have to check its children
        bool children_black = (left_child == 0 or left_child->get_colour() == BLACK) &&
        (right_child == 0 or right_child->get_colour() == BLACK);

        if (!children_black) {
            return false;
        }

        // Since both of its children aren't RED, we can continue checking
        left_child_result = check_children(left_child);
        right_child_result = check_children(right_child);
        return right_child_result && left_child_result;
    }
}
