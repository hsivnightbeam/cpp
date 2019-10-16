//
// source: https://www.cprogramming.com/tutorial/computersciencetheory/queuecode.html
#ifndef __QueueClassH__
#define __QueueClassH__

#include <assert.h>    // For error-checking purposes

template <class Elem>
class Queue
{
  public:
    Queue(int MaxSize=500);
    Queue(const Queue<Elem> &OtherQueue);
    ~Queue(void);

    void       Enqueue(const Elem &Item);    // Adds Item to Queue end
    Elem       Dequeue(void);                // Returns Item from Queue
    inline int ElemNum(void);                // Returns Number of Elements

  protected:
    Elem     *Data;      // The actual Data array
    const int MAX_NUM;   // The actual spaces will be one more than this
    int       Beginning, // Numbered location of the start and end
              End;

    // Instead of calculating the number of elements, using this variable
    // is much more convenient.
    int       ElemCount;
};


#endif /*__QueueClassH__*/

/*
 * This source file is an implementation of the Queue class. The class is implemented with templates, and the size is determined dynamically at initialization (although the default is 500 elements).
   For the templated class, the elements must have the operators <, =, and > defined.
   The actual amount of space allocated for the Queue will be one more element than the defined maximum size. This is useful for implementing the Queue in a circular method.
    To understand the circular implementation, think of the array as a circle. When an element is dequeued, the Queue doesn't shift all of the elements forward to the start of the queue. Instead, the class shifts the start of the queue back (Instead, you updated an indicator of the start of the queue) Eventually, the start of the queue will have shifted so far that the queue will extend beyond the end of the array. This is where the circle comes in. When the queue reaches the end of the array, it wraps around to the beginning of the array.
 */