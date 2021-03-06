#include <iostream>
#include <fstream>
#include <random>
#include "vector.h"

void my_test();
void gankevich_test();

int main() {
//    my_test();
    gankevich_test();
}


void my_test() {
    Vector<int> test_vec(5);
    for (size_t i = 0; i != 5; ++i)
        test_vec[i] = i + 1;

    std::cout << "test_vec: ";
    for (size_t i = 0; i != test_vec.size(); ++i)
        std::cout << test_vec[i] << " ";
    std::cout << std::endl;

    for (size_t i = 0; i != 5; ++i)
        std::cout << "Pushed element: " << test_vec.push_back(i + 6) << std::endl;

    std::cout << "test_vec: ";
    for (size_t i = 0; i != test_vec.size(); ++i)
        std::cout << test_vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Popped element: " << test_vec.pop_back() << std::endl;
    std::cout << "test_vec: ";
    for (size_t i = 0; i != test_vec.size(); ++i)
        std::cout << test_vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Erased value:  " << *test_vec.erase(test_vec.begin()) << std::endl;
    std::cout << "test_vec: ";
    for (size_t i = 0; i != test_vec.size(); ++i)
        std::cout << test_vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Erased values:" << std::endl;
    int * first = test_vec.begin();
    int * last = test_vec.end() - 1;
    int * erased_values = test_vec.erase(first, last);
    for (unsigned i = 0; i != last - first; ++i)
        std::cout << erased_values[i] << " ";
    std::cout << std::endl;

    std::cout << "test_vec: ";
    for (size_t i = 0; i != test_vec.size(); ++i)
        std::cout << test_vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Popped element: " << test_vec.pop_back() << std::endl;
    std::cout << "test_vec: ";
    for (size_t i = 0; i != test_vec.size(); ++i)
        std::cout << test_vec[i] << " ";
    std::cout << std::endl;
}


void gankevich_test() {
    Vector<std::ofstream> streams_vec;
    size_t streams_amount = 7;
    for (size_t i = 0; i != streams_amount; ++i) {
        std::ofstream stream_file("file_" + std::to_string(i) + ".txt");
        streams_vec.push_back(std::move(stream_file));
    }
    std::shuffle(streams_vec.begin(), streams_vec.end(), std::random_device());
    for (size_t i = 0; i != streams_amount; ++i) {
        streams_vec[i] << i << std::endl;
    }
}