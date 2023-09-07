#include "../include/timer.h"

double get_user_time_seconds()
{
	struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    double user_time = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
    return  user_time;

}
double get_system_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double) tv.tv_sec + (double) tv.tv_usec / 1000000.0;
}

void consumesTime()
{
    int i, j;
    for (i = 0; i < 100000; i++)
    {
        for (long long i = 0; i < 10000000000LL; i++) {
            j = i;

    }
    }
}


