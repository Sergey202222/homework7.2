#include "task2.hpp"
#include "Timer.h"
#include <thread>
#include <iostream>
#include <mutex>

std::mutex mtx;
using namespace std;

void drawRowProgress(size_t i)
{
	static int y{ 2 };
	//std::lock_guard<std::mutex> lk(mtx);
	consol_parameter::SetPosition(10, 2);
	y += 2;
	for (size_t index{}; index < i; ++index)
	{
		std::this_thread::sleep_for(3s);
		std::cout << (char)222u;
	}
	std::cout << '\n';
}

void task2(int N)
{
	std::thread* th{ new std::thread[N] };
	for (size_t index{}; index < N; ++index)
	{
		th[index] = std::thread(drawRowProgress, index);
	}
	int y1{ 2 };
	for (size_t index{}; index < N; ++index)
	{
		consol_parameter::SetPosition(0, y1);
		std::cout << th[index].get_id();
		y1 += 2;
	}
	Timer t;
	int y2{ 2 };
	for (size_t index{}; index < N; ++index)
	{
		t.start("t");
		th[index].join();
		consol_parameter::SetPosition(20, y2);
		t.print();
		y2 += 2;
	}
}