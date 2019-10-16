// queue implemented as an array
// source: http://www.mathcs.duq.edu/drozdek/DSinCpp/genArrayQueue.h

#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE

template<class T, int size = 100>
class ArrayQueue {
public:
    ArrayQueue() {
        first = last = -1;
    }
    void enqueue(T);
    T dequeue();
    bool isFull()  {
        return first == 0 && last == size-1 ||      //it's full in a linear way
               first == last + 1;                   //it's full as we did a circular run on the array
    }
    bool isEmpty() {
        return first == -1;
    }
private:
    int first, last;
    T storage[size];
};

template<class T, int size>
void ArrayQueue<T,size>::enqueue(T el) {
    if (!isFull())
        if (last == size-1  ||      // it's not full, but we have allocated until the end, we need to start inserting in the beginning...
            last == -1) {           // it's the first time we are inserting ?
            storage[0] = el;
            last = 0;
            if (first == -1)        // just if it's the first time we inserted we increase it
                first = 0;
        }
        else storage[++last] = el;  //normal case we just push linearly
    else cout << "Full queue.\n";
}

template<class T, int size>
T ArrayQueue<T,size>::dequeue() {
    T tmp;
    tmp = storage[first];
    if (first == last)              //if we dequeued all elements
        last = first = -1;
    else if (first == size-1)       //if we dequeued linearly and now we need to go back circulary to the beginning
        first = 0;
    else first++;                   //normal case we just dequeue items..
    return tmp;
}

#endif