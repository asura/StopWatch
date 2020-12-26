#include <chrono>
#include <iostream>
#include <thread>

#include "StopWatch.h"

int main()
{
    StopWatch sw;

    sw.Start();
    std::this_thread::sleep_for(
        std::chrono::seconds(1));
    sw.Stop();

    std::cout << "real: " << sw.timespan_real() << " [ms]" << std::endl;
    std::cout << "cpu:  " << sw.timespan_cpu() << " [ms]" << std::endl;
}