// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the shared library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

#include <functional>
#include <iostream>
#include "rb_tree.h"
#include "rb_vertex.h"
#include "src/rb_tree.cpp"
#include "src/rb_vertex.cpp"

extern "C"
{
    int main(int argc, char** argv) {
        std::function<bool (int, int)> test_func = [] (int val1, int val2) { return val1 < val2; };
     //   rb_vertex<int>(3, NULL);


        rb_tree<int>* tree = new rb_tree<int>(test_func);

/*
        rb_tree<int, std::function<bool (int, int)>>* tree;
        tree = new rb_tree<int, std::function<bool (int, int)>>(test_func);
  */
       // rb_tree<int> tree(test_func);
/*
        if (tree->test(1, 2)) {
            std::cout << "Hello";
            char test;
            std::cin >> test;
        }
  */
     //   return true;

    }


    // A function adding two integers and returning the result
    int SampleAddInt(int i1, int i2)
    {
        return i1 + i2;
    }

    // A function doing nothing ;)
    void SampleFunction1()
    {
        // insert code here
    }

    // A function always returning zero
    int SampleFunction2()
    {
        // insert code here

        return 0;
    }
}
