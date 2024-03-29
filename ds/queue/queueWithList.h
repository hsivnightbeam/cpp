// generic queue implemented with doubly linked list
// source: http://www.mathcs.duq.edu/drozdek/DSinCpp/genQueue.h
#ifndef DLL_QUEUE
#define DLL_QUEUE

#include <list>


template<class T>
class Queue {
public:
    Queue() {
    }
    void clear() {
        lst.clear();
    }
    bool isEmpty() const {
        return lst.empty();
    }
    T& front() {
        return lst.front();
    }
    T dequeue() {
        T el = lst.front();
        lst.pop_front();
        return el;
    }
    void enqueue(const T& el) {
        lst.push_back(el);
    }
private:
    list<T> lst;
};

#endif