#ifndef _SCHEDULER_H_
#define _SCHEDULER_H_

#include <arduino.h>
#include "Job.h"

extern bool isDebug;

struct JobNode {
  JobNode* prev;
  Job *job;
};

class Scheduler {
  private :
    JobNode    *jobs;
  public :
     Scheduler();
     ~Scheduler();
     void addJob(Job *job);
     void loop();
};

#endif
