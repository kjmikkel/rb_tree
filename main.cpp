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

        // Ignore me!
        argc = 0;


        std::function<bool (int, int)> test_func = [] (int val1, int val2) { return val1 < val2; };

        rb_tree<int>* tree = new rb_tree<int>(test_func);

        char test;

        tree->insert(1);
        std::cout << "1" << std::endl;

        tree->insert(2);
        std::cout << "2" << std::endl;

        tree->insert(3);
        std::cout << "3" << std::endl;

        tree->insert(4);
        std::cout << "4" << std::endl;

        tree->insert(5);
        std::cout << "5" << std::endl;

        tree->insert(6);
        std::cout << "6" << std::endl;

        tree->insert(7);
        std::cout << "7" << std::endl;

        tree->insert(8);
        std::cout << "8" << std::endl;

        tree->insert(9);
        std::cout << "9" << std::endl;

        tree->insert(10);
        std::cout << "10" << std::endl;
        tree->print_tree();
        std::cin >> test;


     //   return true;

    }
}
