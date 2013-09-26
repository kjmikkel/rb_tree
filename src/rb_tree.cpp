#include <functional>
#include <iostream>
#include <string>

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

    // This is 'y' in Cormen
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
void rb_tree<T>::remove(rb_vertex<T>* out_value) {
    //out_value is y in Corman

    // this is y in Corman
    rb_vertex<T>* successor;

    // this is x in Corman
    rb_vertex<T>* child;

    if (out_value->get_left_child() == 0 or out_value->get_right_child() == 0) {
        successor = out_value;
    } else {
        successor = Tree_Successor(out_value);
    }

    if (successor->get_left_child() != 0) {
        child = successor->get_left_child();
    } else {
        child = successor->get_right_child();
    }

    child->set_parent(successor->get_parent());

    if (successor->get_parent() == 0) {
        root = child;
    } else {
        if (successor == successor->get_parent()->get_left_child()) {
            successor->get_parent()->set_left_child(child);
        } else {
            successor->get_parent()->set_right_child(child);
        }
    }

    if (child != out_value) {
        out_value->set_value(successor->get_value());
    }

    if (successor->get_colour() == BLACK) {
        remove_fixup(child);
    }
}


// Left and right rotate
template<typename T>
void rb_tree<T>:: left_rotate(rb_vertex<T>* current_vertex) {

    // y in Cormen
    rb_vertex<T>* right_subtree = current_vertex->get_right_child();
    rb_vertex<T>* left = right_subtree->get_left_child();

    current_vertex->set_right_child(left);

    if (left != 0) {
        left->set_parent(current_vertex);
    }

    rb_vertex<T>* parent = current_vertex->get_parent();
    right_subtree->set_parent(parent);

    if (parent == 0) {
        root = right_subtree;
    } else {
        if (current_vertex == parent->get_left_child()) {
            parent->set_left_child(right_subtree);
        } else {
            parent->set_right_child(right_subtree);
        }
    }
    right_subtree->set_left_child(current_vertex);
    current_vertex->set_parent(right_subtree);
}

template<typename T>
void rb_tree<T>:: right_rotate(rb_vertex<T>* current_vertex) {

    rb_vertex<T>* left_subtree = current_vertex->get_left_child();
    rb_vertex<T>* right = left_subtree->get_right_child();

    current_vertex->set_left_child(right);

    if (right != 0) {
        right->set_parent(current_vertex);
    }

    rb_vertex<T>* parent = current_vertex->get_parent();
    left_subtree->set_parent(parent);

    if (parent == 0) {
        root = left_subtree;
    } else {
        if (current_vertex == parent->get_right_child()) {
            parent->set_right_child(left_subtree);
        } else {
            parent->set_left_child(left_subtree);
        }
    }
    left_subtree->set_right_child(current_vertex);
    current_vertex->set_parent(left_subtree);

}

 // Insert and remove fixup
template<typename T>
void rb_tree<T>::insert_fixup(rb_vertex<T>* new_vertex) {

    rb_vertex<T>* current_vertex = 0;
    bool current_vertex_exist;

    // If the grandparent does not exist, then we return
    if (new_vertex->get_grandparent() == 0) {
        root->set_colour(BLACK);
        return;
    }

    while(new_vertex->get_parent() != 0 && new_vertex->get_parent()->get_colour() == RED) {

        if (new_vertex->get_parent() == new_vertex->get_grandparent()->get_left_child()) {
            current_vertex = new_vertex->get_grandparent()->get_right_child();
            current_vertex_exist = current_vertex != 0;

            // Case 1
            if (current_vertex_exist && current_vertex->get_colour() == RED) {
                new_vertex->get_parent()->set_colour(BLACK);
                current_vertex->set_colour(BLACK);
                if (new_vertex->get_grandparent() != 0) {
                    new_vertex->get_grandparent()->set_colour(RED);
                    new_vertex = new_vertex->get_grandparent();
                }
            } else {

                if (new_vertex == new_vertex->get_parent()->get_right_child()) {
                    // Case 2
                    new_vertex = new_vertex->get_parent();

                    rb_tree::left_rotate(new_vertex);
                }
                // Case 3
                new_vertex->get_parent()->set_colour(BLACK);
                if (new_vertex->get_grandparent() != 0) {
                    new_vertex->get_grandparent()->set_colour(RED);
                    rb_tree::right_rotate(new_vertex->get_grandparent());
                }
            }
        } else {
            current_vertex = new_vertex->get_grandparent()->get_left_child();
            current_vertex_exist = current_vertex != 0;

            // Case 1
            if (current_vertex_exist && current_vertex->get_colour() == RED) {
                new_vertex->get_parent()->set_colour(BLACK);
                current_vertex->set_colour(BLACK);
                if (new_vertex->get_grandparent() != 0) {
                    new_vertex->get_grandparent()->set_colour(RED);
                    new_vertex = new_vertex->get_grandparent();
                }
            } else {

                if (new_vertex == new_vertex->get_parent()->get_left_child()) {
                    // Case 2
                    new_vertex = new_vertex->get_parent();

                    rb_tree::right_rotate(new_vertex);
                }
                // Case 3
                new_vertex->get_parent()->set_colour(BLACK);
                if (new_vertex->get_grandparent() != 0) {
                    new_vertex->get_grandparent()->set_colour(RED);
                    rb_tree::left_rotate(new_vertex->get_grandparent());
                }
            }
        }
    }

    root->set_colour(BLACK);
}

template<typename T>
void rb_tree<T>::remove_fixup(rb_vertex<T>* current_vertex) {
    // current_vertex is x in Corman

    // this is w in Corman
    rb_vertex<T>* child;

    while (current_vertex != root && current_vertex->get_colour() == BLACK) {
        if (current_vertex == current_vertex->get_parent()->get_left_child()) {
            child = current_vertex->get_parent()->get_right_child();
            if (child->get_colour() == RED) {
                child.set_colour(BLACK);
                current_vertex->get_parent()->set_colour(RED);
                left_rotate(current_vertex->get_parent);
                child = current_vertex->get_parent->get_right_child();
            }
            if (child->get_left_child()->get_colour() == BLACK && child->get_right_child()->get_colour() == BLACK) {
                child->set_colour(RED);
                current_vertex = current_vertex->get_parent();
            } else {
                if (child->get_right_child()->get_colour() == BLACK) {
                    child->get_left_child()->set_colour(BLACK);
                    child->set_colour(RED);
                    right_rotate(child);
                    child = current_vertex->get_parent()->get_right_child();
                }
                child->set_colour(current_vertex->get_parent()->get_colour());
                current_vertex->get_parent()->set_colour(BLACK);
                child->get_right_child()->set_colour(BLACK);
                left_rotate(current_vertex->get_parent());
                current_vertex = root;
            }
        } else {
            child = current_vertex->get_parent()->get_left_child();
            if (child->get_colour() == RED) {
                child.set_colour(BLACK);
                current_vertex->get_parent()->set_colour(RED);
                right_rotate(current_vertex->get_parent);
                child = current_vertex->get_parent->get_left_child();
            }
            if (child->get_left_child()->get_colour() == BLACK && child->get_right_child()->get_colour() == BLACK) {
                child->set_colour(RED);
                current_vertex = current_vertex->get_parent();
            } else {
                if (child->get_left_child()->get_colour() == BLACK) {
                    child->get_right_child()->set_colour(BLACK);
                    child->set_colour(RED);
                    left_rotate(child);
                    child = current_vertex->get_parent()->get_left_child();
                }
                child->set_colour(current_vertex->get_parent()->get_colour());
                current_vertex->get_parent()->set_colour(BLACK);
                child->get_left_child()->set_colour(BLACK);
                right_rotate(current_vertex->get_parent());
                current_vertex = root;
            }
        }
    }

    current_vertex->set_colour(BLACK);
}

// Help functions
template<typename T>
rb_vertex<T>* Tree_Minimum(rb_vertex<T>* min_subj) {
    while(min_subj->get_left_child() != 0) {
        min_subj = min_subj->get_left_child();
    }

    return min_subj;
}

template<typename T>
rb_vertex<T>* Tree_Maximum(rb_vertex<T>* max_subj) {
    while(max_subj->get_right_child() != 0) {
        max_subj = max_subj->get_right_child();
    }

    return max_subj;
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

template<typename T>
void rb_tree<T>::print_tree() {
    root->print_tree("Root","");
}

template<typename T>
bool rb_tree<T>::check_red_black_property() {
    return root->double_red_children();
}

template<typename T>
rb_vertex<T>* Tree_Successor(rb_vertex<T>* subject) {
    if (subject->get_right_child() != 0) {
        return Tree_Minimum(subject);
    }

    rb_vertex<T>* temp = subject->get_parent();

    while(temp != 0 and subject == temp->get_right_child()) {
        subject = temp;
        temp = temp->get_parent();
    }

    return temp;
}

template<typename T>
void rb_tree<T>::print_complete_status() {
    print_tree();
    std::cout << "Depth: " << max_depth() << std::endl;
    std::cout << "Balanced: " << (black_balance() ? "Yes" : "No") << std::endl;
    std::cout << "Red-Black property: " << (check_red_black_property() ? "No Violation found" : "Violation found") << std::endl;
}
