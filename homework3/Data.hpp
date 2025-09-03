#pragma once
#include <mutex>

class Data
{
public:
	Data();
	Data(int, int);
	std::mutex& get_mutex();
	int& get_a();
	int& get_b();
private:
	std::mutex mtx;
	int a;
	int b;
};

void swapData1(Data&, Data&);
void swapData2(Data&, Data&);
void swapData3(Data&, Data&);