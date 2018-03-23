#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <ctime>

class StopWatch
{
    clock_t m_start_cpu;
    clock_t m_end_cpu;

    struct timespec m_start_real;
    struct timespec m_end_real;

public:
    /// 時間計測を開始
    void Start();

    /// 時間計測を終了
    void Stop();

    /// CPU時間を返す(単位:ミリ秒)
    double timespan_cpu() const;

    /// 実所要時間を返す(単位:ミリ秒)
    double timespan_real() const;
};
#endif /* !STOPWATCH_H_ */
