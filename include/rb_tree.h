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

        bool test(T val1, T val2);
    protected:
    private:

    std::function<bool (T, T)> func;

};

#endif // RB_TREE_H
