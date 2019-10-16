// stack with template and array
// source: http://www.cs.utsa.edu/~wagner/CS2213/stack/stack_template.html
template< class T, int MaxStack >
class Stack {
   T items[MaxStack];
   int top;
public:
   Stack() : top{-1} {

   }
   ~Stack() {
       delete[] items;  //typo is not allocated with new...
   }
   void push(T c) {
       items[ ++top ] = c;
   }
   T pop() {
       return items[ top-- ];
   };
   int empty() {
       return top == -1
   };
   int full() {
       return top+1 == MaxStack;
   };
};


