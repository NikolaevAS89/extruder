#include "Scheduler.h"

Scheduler::Scheduler() {
   this->jobs = NULL;
   this->startMs = millis();
   this->state = digitalRead(this->pin);
   pinMode(pin, INPUT_PULLUP);
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
  Node* p = this->jobs;
  while(p != NULL) {
    p->job->execute();
    p = p->prev;
  }
}