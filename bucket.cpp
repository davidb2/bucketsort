#include "bucket.h"

#define NULL 0 

bucket::bucket() {
    _queue = new std::queue<int>();
}

void bucket::push(int number) {
    _queue->push(number);
}

int bucket::pop() {
    int last = _queue->front(); _queue->pop();
    return last;
}

int bucket::size() const {
    return _queue->size();
}

bool bucket::empty() const {
    return _queue->size() == 0;
}

bucket::~bucket() {
    delete _queue;
    _queue = NULL;
}
