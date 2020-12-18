# QueueLinkedListADT

This project constructs a linked list from scratch and uses it to create a queue class. An exception class was also created to handle errors.

PROJECT DETAILS

For this project, you are to implement two abstract data types (ADTs). You will write a doubly linked list (Dll) and a queue class. The queue will use the dll internally. The class interfaces are downloadable below. You must follow the interface exactly. While you can define other public and private methods and fields, the class names and methods given must appear as provided, or you will not pass the unit tests. Include the implementation of the classes in their respective header (.h) files. Please note: Dll is not a node class, as in, a Dll does not point to another Dll; it contains nodes internally.

Dll Comments
When inserting into a dll, rank 0 inserts at the front of the list and rank size() inserts at the back of the list. If you have the list 0 -> 10 -> 30, then after insert(2, 20), the list should be 0 -> 10 -> 20 -> 30.

When removing from a dll, rank 0 removes from the front of the list and rank size() - 1 removes from the back of the list. If you have the list 0 -> 10 -> 20 -> 30, then after remove(2), the list should be 0 -> 10 -> 30.

When building a dll from an array, the array [ 0 1 2 ] should create the list 0 -> 1 -> 2.

Displaying
When displaying a Dll, it should appear with the head on the left and the tail on the right. For example, the list created after insert(0, 3), insert(0, 2), insert(0, 1) should represent the list 1 -> 2 -> 3 and should display as follows:

[ 1 2 3 ]
When displaying a queue, it should appear with the front on the left and the back on the right. For example, the queue created after enqueue(1), enqueue(2), enqueue(3) should display as follows:

[ 1 2 3 ]
When displaying an empty ADT, it should be a single space surrounded by brackets:

[ ]
Efficiency
All operations should have an efficient runtime. Besides display(), all queue operations should run in O(1). Because the queue uses a dll internally, this means insert(), remove(), and size() must be O(1) for the appropriate cases (insert back, remove front), which also means size should be stored and not calculated by looping through the list.

Exceptions
Two exception classes can be found in exceptions.h: InvalidOperationException and IndexOutOfRangeException. Your ADTs will throw exceptions according to the instructions below:

List: throw IndexOutOfRangeException for the following operations:
at(): when accessing an index outside the bounds (0 to size-1 inclusive) of the linked list with the message "at(): Index was outside the bounds of the linked list."
insert(): when index is not in the range from 0 to size (inclusive) with the message "insert(): Index was outside the bounds of the linked list."
remove(): when removing an index outside the bounds (0 to size-1 inclusive) of the linked list with the message "remove(): Index was outside the bounds of the linked list."
Queue: throw InvalidOperationException with the message "Queue empty." when dequeuing or peeking an empty queue.
p3.cpp
p3.cpp is a command-line interface that can be used to test your data structures. Review the code before running it and testing your data structures. p3.cpp assumes your dll.h and queue.h are completed. You must comment out the portions of the code that you have not implemented (includes and the loops in main pertaining to the data structure) or create "empty" method definitions to make it compilable.

You can compile your program with g++ p3.cpp.
