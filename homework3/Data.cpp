#include "Data.hpp"

Data::Data()
{
	a = 0;
	b = 0;
}

Data::Data(int a1, int b1) : a(a1), b(b1) {};

std::mutex& Data::get_mutex()
{
	return mtx;
}

int& Data::get_a()
{
	return a;
}

int& Data::get_b()
{
	return b;
}

void swapData1(Data& d1, Data& d2)
{
	std::lock(d1.get_mutex(), d2.get_mutex());
	std::lock_guard(d1.get_mutex(), std::adopt_lock);
	std::lock_guard(d2.get_mutex(), std::adopt_lock);
	std::swap(d1.get_a(), d2.get_b());
}

void swapData2(Data& d1, Data& d2)
{
	std::scoped_lock ul1(d1.get_mutex());
	std::scoped_lock<std::mutex> ul2(d2.get_mutex());
	std::swap(d1.get_a(), d2.get_b());
}

void swapData3(Data& d1, Data& d2)
{
	std::lock(d1.get_mutex(), d2.get_mutex());
	std::unique_lock<std::mutex> ul1(d1.get_mutex(), std::defer_lock);
	std::unique_lock<std::mutex> ul2(d2.get_mutex(), std::defer_lock);
	std::swap(d1.get_a(), d2.get_b());
}