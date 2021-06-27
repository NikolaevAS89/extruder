#include "Job.h"

Job::Job(uint32_t periodMs, void (*task)()) {
   this->nextExecMs = millis();
   this->task = task;
   this->periodMs = periodMs;
}

Job::~Job() {
}

void Job::execute() {
  uint32_t ms = millis();
  if(this->nextExecMs<=ms) {
    this->task();
    this->nextExecMs += this->periodMs;
  }
}
