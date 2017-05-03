#ifndef BUCKET_H
#define BUCKET_H

#include <queue>

class bucket {
    public:
        bucket();
        void push(int number);
        int pop();
        int size() const;
        bool empty() const;
        ~bucket();
    private:
        std::queue<int> * _queue;
};
#endif
