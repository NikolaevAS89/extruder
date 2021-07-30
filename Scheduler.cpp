#include "Scheduler.h"

Scheduler::Scheduler() {
   this->jobs = NULL;
}

Scheduler::~Scheduler() {
  while(this->jobs != NULL) {
    JobNode* p = this->jobs;
    this->jobs = this->jobs->prev;
    delete p->job;
    delete p;
  }
}

void Scheduler::addJob(Job *job) {
  JobNode* p = new JobNode();
  p->prev = this->jobs;
  p->job = job;
  this->jobs = p;
}

void Scheduler::loop() {
  JobNode* p = this->jobs;
  while(p != NULL) {
    p->job->execute();
    p = p->prev;
  }
}
