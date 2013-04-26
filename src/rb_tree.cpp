#include <functional>
#include "rb_tree.h"

template<typename T>
rb_tree<T>::rb_tree(std::function<bool (T, T)> in_func)
{
    func = in_func;
}

template<typename T>
bool rb_tree<T>::test(T val1, T val2) {
    return func(val1, val2);
}

template<typename T>
rb_tree<T>::~rb_tree()
{
    //dtor
}
