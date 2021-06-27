#ifndef _JOB_H_
#define _JOB_H_

extern bool isDebug;
#include <arduino.h>


class Job {
  private :
    void    (*task)();
    uint32_t nextExecMs;
    uint32_t periodMs;
  public :
     Job(uint32_t periodMs, void (*task)());
     ~Job();
     void execute();
};

#endif
