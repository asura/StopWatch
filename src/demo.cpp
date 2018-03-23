#include <iostream>
#include "StopWatch.h"

int main()
{
    StopWatch sw;

    sw.Start();
    sleep(1);
    sw.Stop();

    std::cout << "real: " << sw.timespan_real() << " [ms]" << std::endl;
    std::cout << "cpu:  " << sw.timespan_cpu() << " [ms]" << std::endl;
}