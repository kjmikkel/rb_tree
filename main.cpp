

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
        tree->print_tree();

        tree->insert(2);
        std::cout << "2" << std::endl;
        tree->print_tree();

        tree->insert(3);
        std::cout << "3" << std::endl;
        tree->print_tree();

        tree->insert(4);
        std::cout << "4" << std::endl;
        tree->print_tree();

        tree->insert(5);
        std::cout << "5" << std::endl;
        tree->print_tree();

        tree->insert(6);
        std::cout << "6" << std::endl;
        tree->print_tree();

        tree->insert(7);
        std::cout << "7" << std::endl;
        tree->print_tree();

        tree->insert(8);
        std::cout << "8" << std::endl;
        tree->print_tree();

        tree->insert(9);
        std::cout << "9" << std::endl;
        tree->print_tree();

        tree->insert(10);
        std::cout << "10" << std::endl;
        tree->print_complete_status();

        tree->insert(-1);
        std::cout << "-1" << std::endl;
        tree->print_complete_status();


        std::cin >> test;
     //   return true;

    }
}
