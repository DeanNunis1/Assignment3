# Assignment 03: Syntax Checker

- a. Dean Nunis
- b. 2324351
- c. nunis@chapman.edu
- d. CPSC 350-02
- e. Syntax Checker

## Source Files

- assign3.cpp
- GenStack.h

## References

- Tutor: Riley O'Connor
- Class Notes

Description:
Stack is a linear data structure which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out). The stack is implemented as generic by using templated class.

Mainly the following three basic operations are performed in the stack:

Push: Adds an item in the stack and increment the size.

Pop: Removes an item from the stack and returns the item. The items are popped in the reversed order in which they are pushed. The size is decremented by 1.

isEmpty: Returns true if stack is empty by checking the size is zero, else false.
