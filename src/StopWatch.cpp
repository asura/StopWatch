#include "StopWatch.h"

void StopWatch::Start()
{
    m_start_cpu = clock();
    clock_gettime(CLOCK_REALTIME, &m_start_real);
}

void StopWatch::Stop()
{
    m_end_cpu = clock();
    clock_gettime(CLOCK_REALTIME, &m_end_real);
}

double StopWatch::timespan_cpu() const
{
    return (m_end_cpu - m_start_cpu) / (CLOCKS_PER_SEC / double(1000));
}

double StopWatch::timespan_real() const
{
    return (m_end_real.tv_sec * 1000 + m_end_real.tv_nsec / double(1000000)) -
           (m_start_real.tv_sec * 1000 + m_start_real.tv_nsec / double(1000000));
}
