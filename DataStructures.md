

# Introduction
- Data structures are the building blocks of programming.
- There are a lot of examples in real life where data structures are present and help us a lot 
(dictionary, map, table)
- Computer work with a lot of different types of data. The way we store the data is important to make the progam or something more efficiently
- Definition : a way to store and organize data in a computer, so that it can be used eddiciently

We can talk baout **data structures** as:

- Mathematical/logical models or Abstract data types(**ADT**) (ex. list)
- Implementation ex. Arrays

#### ADTs
- define data and operations, but no Implementation

**We are going to study**:
- logical view
- operations
- cost of operations
- Implementation

# Lists
- Store a given number of elements of a given data-type
- Write/modify element at a position                         ->> ARRAYS
- Read element at a position 
- empty list has size 0
- insert 
- remove
- count ->> Arrays
- read/modify
- specify data type

    --
            .Define a really large Arrays
            .Create a varible end to mark the end of the list, with end = -1 in the beginning
            .Insert if not said the index always occurs at the end of the list
            .If insert is maid in the middle of the list, it is required to shift all those that have a bigger index
            .Remove has a silimar effect
            .But what is the best max size?? The array can always be totally occupied! We have to create a new array with a 
        copy of the values of the old one and with a bigger size! But this costs a lot of memory! So create the new array 
        with double the size
    
    -- Analysis of the time cost of the various operations
        . Access -> constant time O(1)
        . Insert -> linear time O(n) 
        . Remove -> linear time  O(n)
        . Add -> O(n) . worst case.  because is necessary to copy all elements to a new array

Conclusion:
    If the size of the array changes a lot are required a lot of operations
    A lot of the times the majority of the array will be empty, not memory efficient

-----------------------------------------------------------
                            Linked-Lists
-----------------------------------------------------------

Memory manager - keeps track of memory that is free or allocated. Every task needs to communicate with it
Comunication - can be made using a programming language like C++ ex. int x;

Again:: The problem with arrays is that sometimes is necessary to add values but there is no available space in the stores space for the array
    It is necessary to create a new space which is costy, and sometimes the space is not totally used

The solution is LINKEDLIST!!!!
- The memory is not a large contiguos block
- The request is made one item at a time. Every item is in a different place in memory, not necessarly contiguous
- In order for this to work is necessary to link somehow those blocks. We need to store extra data in each block.
- First part of block we save the actually data and in the second part we store the adress of the following block.
- The final block of the list has a 0 value in the second part.

-- C representation:
    - In C this is possible by creating a struct None  {int data; node* next} 4bytes 4 bytes

- The first node is called the heads and gives us access to the complete list
- To access the elements we always need to start form the head
- To add a new node we need to add a new space in memory for that node and connect the last node of the list to the one created

-- Analysis of the time cost of the various operations
        . Access -> linear time O(n)
        . Insert -> linear time O(n) 
        . Remove -> liner time O(n)


        Comparation between Array and linked list

    Array:

Accesing: O(1) -> because the data is stored in a contiguous block of memory is possible to calculate the location of a 
                given value based on its index
Memory requiremetns: -> Fixed size so a lot of memory is may be unused
                    -> Memory may not be available as one large block
Cost of inserting:
            . At the beginning: O(n) -> it is necessary to shift all the values one space to the right
            . At the end: O(1) -> if array is not full
                            O(n) -> if is full
            . at ith position: O(n) -> necessity to shift the values after the added 
Cost of deleting: is the same

Pros:
    -> Ease of use


    Linked list:

acessing: O(n) -> because the data is not stored in a contiguos block of memory its necessar to start in the head node
                in the worst case is necessary to travers all the elements of the list
Memory requirements -> No unused memory
                    -> extra memory for pointer variables
                    -> memory may be available as multiple small blocks

Cost of inserting:
            . At the beginning: O(1) -> Only necessary to create a new node that points to the previously first node
            . At the end: O(n) -> necessisty to traverse the list
            . at ith position: O(n) -> necessity to traverse the list 
Cost of deleting: is the same

Pros:
    -> Best when the data type is really large, the space for the pointer variables is not relevant
