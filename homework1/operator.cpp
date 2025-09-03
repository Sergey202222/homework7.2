#include "operator.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

using namespace std::chrono_literals;
std::mutex mtx;

void operator1(int& client, int clients)
{
	for (int iclient{}; iclient < clients; ++iclient)
	{
		std::this_thread::sleep_for(1s);
		std::lock_guard<std::mutex> lk(mtx);
		++client;
		std::cout << client << ' ';
	}
}

void operator2(int& client, int clients)
{
	for (int iclient{}; iclient < clients; ++iclient)
	{
		std::this_thread::sleep_for(2s);
		std::lock_guard<std::mutex> lk(mtx);
		--client;
		std::cout << client << ' ';
	}
}