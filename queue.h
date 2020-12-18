#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "exceptions.h"
#include "dll.h"

class Queue {
private:
    Dll store;
public:
    Queue() // create an empty queue
    {
        store;
    }
    void enqueue(int value) // add an item to the back of the queue
    {
        store.insert(store.size(), value);
    }
    int dequeue() // remove the value at the front of the queue and return its value
    {
        if (size() == 0)
        {
            throw InvalidOperationException("Queue empty.");
        }
        else {
            return store.remove(0);
        }
    }
    int peek() // return the value at the front of the queue, keeping it in the queue
    {
        if (size() == 0)
        {
            throw InvalidOperationException("Queue empty.");
        }
        else {
            return store.at(0);
        }
    }
    int size() const // return how many items are in the queue
    {
        return store.size();
    }
    bool empty() const // return if the queue is empty
    {
        return store.empty();
    }
    void display(ostream& os) const // write the contents of the queue to the ostream
    {
        store.display(cout);
    }
    friend ostream& operator<<(ostream& os, const Queue& queue);
};

ostream& operator<<(ostream& os, const Queue& queue) // write the contents of the queue to the ostream
{
    DllNode * q = queue.store.getHead();
    os << "[ ";
    while ( q != nullptr) {
        os << q->value << " ";
        q = q->next;
    }
    os << "]";
    
    return os;
}

#endif
