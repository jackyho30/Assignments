#include <iostream>
#include <math.h>
#include "Task.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////
//
// Public operators and methods
/*	bool        enqueue(const Task& t);               // Add a new task
	Task*       dequeue();                            // Remove current task
	const Task* peek() const;                         // What is current task?
	const Task* next(const Task::TaskType& t) const;  // Return next task of type t
	bool        isFull() const;                       // Queue is full
	bool        isEmpty() const;                      // Queue is empty
	bool        quarterFull() const;                  // Queue is < quarter full    
	bool        doubleQueueSize();                    // Double queue size
	bool        halveQueueSize();                     // Halve queue size
	
	
	struct Task {
	enum TaskType { LAUNDRY, DISHES, MAKE_BED, VACUUM, MOP_FLOOR, ECE150 };

	TaskType type;         // LAUNDRY, DISHES, etc.
	int      taskID;       // Unique ID per task
	char*    description;  // Task description
	};

*/
bool TaskQueue::enqueue(const Task& t){
	//add the task
	/*Task* toDo = new (std::nothrow) Task[_queueSize]();
	
	
	
	char* taskDescription = new (std::nothrow) char[500];
	int i = 0;
	while (t.description[i] != 0){
		taskDescription[i] = t.description[i];
		i++
	}*/
}
Task* TaskQueue::dequeue(){
	return NULL;
}
const Task* TaskQueue::peek() const{
	//return address of first item in front
	return &_tasks[_front];
}
const Task* TaskQueue::next(const Task::TaskType& t) const{
	return NULL;
}
bool TaskQueue::isFull() const{
	if (_numItems == _queueSize){
		return true;
	}
	else{
		return false;
	}
}
bool TaskQueue::isEmpty() const{
	if (_numItems == 0){
		return true;
	}
	else {
		return false;
	}
}
bool TaskQueue::quarterFull() const{
	//see if number of items is with a quarter full
	if (_numItems <= (_queueSize/4)){
		return true;
	}
	else {
		return false;
	}
}
bool TaskQueue::doubleQueueSize(){
	//double the queue size
	_queueSize = _queueSize*2;
	Task* toDo = new (std::nothrow) Task[_queueSize]();
	//re-enter the old tasks into the array
	for (int i = _front; i <= _back; i++){
		toDo[i] = _tasks[i];
	}
	//Check if unable to allocate memory
	if (toDo == 0){
		return false;
	}
	delete[] _tasks;
	_tasks = toDo;
	return true;
}
bool TaskQueue::halveQueueSize(){
	/*
	//halve the queue size
	_queueSize = _queueSize/2;
	//check if the halved queue size will fit the tasks and error if not
	if (_queueSize < _numItems){
		return false;
	}
	Task* toDo = new (std::nothrow) Task[_queueSize]();

	//re-enter the old tasks into the array
	for (int i = _front; i <= _back; i++){
		toDo[i] = _tasks[i];
	}
	delete[] _tasks;
	_tasks = toDo;
	return true;*/
	return false;
}
///////////////////////////////////////////////////////////////////////////
//
// Constructors and Destructor
TaskQueue::TaskQueue() {
	//both front and back will be -1 if the queue is empty
	_front = 0;
	_back = -1;
	_numItems = 0;
	_queueSize = INITIAL_TASKQUEUE_SIZE;
	Task* toDo = new (std::nothrow) Task[_queueSize]();
	//delete[] _tasks;
	_tasks = toDo;
	
}
TaskQueue::~TaskQueue() {
	delete[] _tasks;
}

	
