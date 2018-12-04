#include <stdio.h>
#include <time.h>

class Perf
{
public:
    Perf()
    {
        startTime = clock();
    }
    ~Perf()
    {
        double nProcessExcuteTime = ((double)(clock()-startTime))/ CLOCKS_PER_SEC;
        printf("%f sec\n", nProcessExcuteTime);
    }

private:
    clock_t startTime;
    double nProcessExcuteTime;
};

#define PERF(func)  \
        do {        \
            Perf p; \
            func;   \
            printf("excute %s : ", #func); \
        } while(0);
