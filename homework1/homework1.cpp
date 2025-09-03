#include "operator.hpp"
#include <iostream>
#include <thread>

int main()
{
    int client{};
    int clients{};
    std::cin >> clients;
    std::thread th1(operator1, std::ref(client), clients);
    std::thread th2(operator2, std::ref(client), clients);
    th1.join();
    th2.join();
    return EXIT_SUCCESS;
}