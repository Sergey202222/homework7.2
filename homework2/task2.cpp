#include "task2.hpp"
#include "Timer.h"
#include <thread>
#include <iostream>
#include <mutex>

using namespace std;
std::mutex mtx;

void drawRowProgress(size_t i, int y)
{
	static int x{ 10 };
	static int t{};
	for (size_t index{}; index < 10; ++index)
	{
		consol_parameter::SetPosition(x, y);
		std::this_thread::sleep_for(500ms);
		mtx.lock();
		++t;
		std::cout << (char)222u;
		if (t % 5 == 0) ++x;
		mtx.unlock();
	}
}

void task2(int N)
{
	std::thread* th{ new std::thread[N] };
	int y{ 2 };
	for (size_t index{}; index < N; ++index)
	{
		th[index] = std::thread(drawRowProgress, index, y);
		y += 2;
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
		t.start("");
		//consol_parameter::SetPosition(10, y2);
		th[index].join();
		consol_parameter::SetPosition(30, y2);
		t.print();
		y2 += 2;
	}
}