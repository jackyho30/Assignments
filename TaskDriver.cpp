#ifndef MARMOSET_TESTING

ostream& operator<<(ostream& os, const Task& t) {
  os << t.taskID << "(";
  switch (t.type) {
  case Task::LAUNDRY:
    os << "Laundry;";
    break;
  case Task::DISHES:
    os << "Dishes;";
    break;
  case Task::MAKE_BED:
    os << "Make Bed;";
    break;
  case Task::VACUUM:
    os << "Vacuum;";
    break;
  case Task::MOP_FLOOR:
    os << "Mop Floor;";
    break;
  case Task::ECE150:
    os << "ECE 150;";
    break;
  default:
    os << "Unknown Task Type;";
    break;
  }
  if (t.description)
    os << t.description;
  else
    os << "0x0";
  os << ")";
  return os;
}

ostream& operator<<(ostream& os, const TaskQueue& tq) {
  os << "[";
  int curTask = tq._front;
  for (int i = 0; i < tq._numItems; ++i) {
    os << "{" << tq._tasks[curTask] << "}";
    if (i != tq._numItems - 1)
      os << "-->";
    ++curTask;
  }
  os << "]";
  return os;
}

void displayQueueStatus(const TaskQueue* tq) {
  if (tq->isFull())
    cout << "Queue is full; ";
  else
    cout << "Queue is not full; ";
  
  if (tq->quarterFull())
    cout << "Queue is less than a quarter full; ";
  else
    cout << "Queue is not less than a quarter full; ";
  
  if (tq->isEmpty())
    cout << "Queue is empty" << endl;
  else
    cout << "Queue is not empty" << endl;
}

///////////////////////////////////////////////////////////////////////////
//
// Test driver
//


int main() {
  srandom((getpid() % 101));
  Task t;
  const char* descriptions[] = { "Meh", "Whatever", "", "Blah", "$^@&" };
  TaskQueue* tq = new new (std::nothrow) TaskQueue;

  displayQueueStatus(tq);
  for (int i = 0; i < 11; ++i) {
    t.taskID = i;
    t.type = (Task::TaskType)(random() % 6);
    t.description = (char*)descriptions[(random() % 5)];
    cout << "\nAttempting to enqueue() task: " << t << endl;
    if (tq->enqueue(t)) 
      cout << "Enqueued item " << i << endl;
    else
      cout << "Failed to enqueue item " << i << endl;
    displayQueueStatus(tq);
  }
  
  const Task* nextTask = tq->peek();
  if (nextTask)
    cout << "The next task is: " << *nextTask << endl;
  else
    cout << "The queue is empty" << endl;
  
  nextTask = tq->next(Task::LAUNDRY);
  if (nextTask)
    cout << "The next laundry task is: " << *nextTask << endl;
  else
    cout << "There are no laundry tasks in the queue" << endl;

  cout << "TQ: " << *tq << endl;

  if (tq->doubleQueueSize())
    cout << "Doubled to: " << *tq << endl;
  
  for (int i = 0; i < 1000; ++i) {
    t.taskID = i;
    t.type = (Task::TaskType)(random() % 6);
    t.description = (char*)descriptions[(random() % 5)];
    
    if (random()%2) {
      if (tq->enqueue(t)) 
        int x = 3; // cout << "Enqueued item " << i << endl;
      else
        int y = 3; //cout << "Failed to enqueue item " << i << endl;
    }
    else {
      Task* next;
      if ((next = tq->dequeue()))
        int z = 2; // cout << "Dequeued item " << *next << endl;
      else
        int w = 1; //cout << "Failed to dequeue item " << endl;
    }
    // displayQueueStatus(tq);
  }
  cout << "TQ: " << *tq << endl;
  delete tq;
  
  return 0;
}

#endif
