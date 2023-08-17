

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
- define data and operations, but no Implementation details
- DataStructure is referenced as a simple mathematic or logical model

**We are going to study**:
- logical view
- operations
- cost of operations
- Implementation
---
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
---
# Arrays

- Create a varible end to mark the end of the list, with end=-1 in the beginning
- Insert if not said the index always occurs at the end of the list
- If insert is maid in the middle of the list, it is required to shift all those that have a bigger index
- Remove has a silimar effect
- But what is the max size? **The array can always be totally occupied**!
- We have to create a new array with a copy of the values of the old one and with a bigger size!
- But this costs a lot of memory! So create the new array 
with double the size

## Analysis of the time cost of operations

- **Access** -> constant time O(1)
- **Insert** -> linear time O(n) 
- **Remove** -> linear time  O(n)
- **Add** -> O(n), **worst case** -- because is necessary to copy all elements to a new array

## Conclusion
- If the size of the array changes a lot is required a lot of operations
- A lot of the times the majority of the array will be empty, not memory efficient

---
# Linked-Lists

### Recap/Concepts

- Memory manager - keeps track of memory that is free or allocated. Every task needs to communicate with it
- Comunication - can be made using a programming language like C++ ex. int x;
- **Again**: The problem with arrays is that sometimes is necessary to add values but there is no available space in the stores space for the array
- It is necessary to create a new space which is costy, and sometimes the space is not totally used

## The solution is LINKEDLIST!!!!
- The memory is not a large contiguos block
- The request is made one item at a time. Every item is in a different place in memory, not necessarly contiguous
#### Blocks
- In order for this to work is necessary to link somehow those blocks. We need to store extra data in each block.
- First part of block we save the actually data and in the second part we store the adress of the following block.
- The final block of the list has a 0 value in the second part.

- **C representation** -> In C this is possible by creating a `struct Node {int data; node* next} 4bytes`

- The first node is called the **Head** and gives us access to the complete list
- To access the elements we always need to start from the head
- To add a new node we need to add a new space in memory for that node and connect the last node of the list to the one created

## Analysis of the time cost of the various operations
- **Access** -> linear time O(n)
- **Insert** -> linear time O(n) 
- **Remove** -> liner time O(n)

---
## Comparation 

### Array

- **Accesing**: O(1) -> because the data is stored in a contiguous block of memory is possible to calculate the location of a given value based on its index

- **Memory requirements**
  - Fixed size so a lot of memory may be unused
  - Memory may not be available as one large block

- **Inserting**
  - **At the beginning** O(n) -> it is necessary to shift all the values one space to the right
  - **At the end** 
    - O(1) -> if array is not full
    - O(n) -> if is full
  -  **At ith position**: O(n) -> necessity to shift the values after the added 

- **Deleting**: The same

#### Pros
- Ease of use


### Linked list:

- **Acessing**: O(n) -> because the data is not stored in a contiguos block of memory its necessar to start in the head node in the worst case is necessary to travers all the elements of the list

- **Memory requirements**:
  - No unused memory
  - Extra memory for pointer variables
  - Memory may be available as multiple small blocks

- **Inserting**:
    - At the beginning: O(1) -> Only necessary to create a new node that points to the previously first node
    - At the end: O(n) -> necessisty to traverse the list
    - At ith position: O(n) -> necessity to traverse the list 


- **Deleting**: The same

#### Pros
- Best when the data type is really large, the space for the pointer variables is not relevant

---
## Reverse Linked List

There are two aproaches to solve this problem. 

- Iterative solution
- Recursive solution
  
### Iterative

Go to each node and reverse its **next** value. At the end ajust the **head** node to point to the last one.

Its necessary to, while doing the iteration, store the value of the current, previous and next node Since once the connection is broken between Nodes its not possible to go back. 
After the iteration, the previous variable would be equal to the last Node of the List. Then it just necessary to connect the head to that Node.

### Recursion

#### Print elements of list

``` C++
void Print(struct Node* n){

  if (n == NULL) return;
  std::cout << n->data;
  Print(value->next)
}
```
#### Print elements of list in reverse

``` C++
void Reverse_Print(struct Node* n){

  if (m == NULL) return;
  Reverse_Print(n->next);
  std::cout << n->data;
}
```

#### Reverse the linked list


``` C++
void Reverse(struct Node* n){

  if (n->next == NULL){
    head = n;
    return;
  }
  Reverse(n->next);
  struct Node * p = n->next;
  p->next = n;  
  // or
  // n->next->next = n;
  n->next = NULL;
}
```

---
# Doubly linked lists

- Really similar to the Linked lists already studied, actually called **Singly Linked List**. In this new variant, each **Node**, instead of being connected to only the **next Node** is also connected directly to the **previous Node**.

The declaration of a Node of a Doubly Linked List would be:

``` C++
struct Node{
  int data;
  struct Node* next;
  struct Node* prev;
}
```

## Advantages

- With only a pointer we can access all items of the list. 
- The implementation of some actions, like deleting an element, becomes easier

## Disavantages

- Extra memory for pointer to previous node
- More prone to errors

## Implementations

Considering **head** as a global variable that points to the first Node of the List


Considering the following function a tool to create new Nodes with a specific value:
``` C++
struct Node* GetNewNode(int x){
  struct Node* newNode = new struct Node;
  newNode->data = 0;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
  }
```

- **Inserting at the beggining**
``` C++
void InsertAtHead(int x){
  struct Node* newNode = GetNewNode(x);

  if (head != NULL){
    head->prev = newNode;
    newNode->next = head;
  }
  head = newNode;
}
```

---
# Stack

> ## ADT

- Stacks in programming languages as a Data Structure is really similar to the concept of Stack in Real Life
- Also has the name LIFO Last-In-First-Out
- Any insertion or removal as to occur from the top of the Stack

- A list with the restriction that insertion and deletion can be performed only from one end, called the top

### Operations
All Constant Time - O(1)
- Push
- Pop
- Top
- IsEmpty

### Aplications

- Function Calls/Recursion
- Undo in an editor
- Balanced Parentheses


 ## Implementation

- The implementation of stack can be done using an **Array** or **List**

- But the implementation of stack can also be done by using  **linked lists**
  - The top of the stacks needs to be the beggining/head of the linked list, because changing the last element would take O(n) time.
  - The good thing of using linked lists over arrays is that there is no cap size for the number of elements

## Use cases for stack

#### Reverse a string or a linked list

- Create a stack to store the 
- Because what comes in first, comes out last, we can then take the characters and putting them in the string again
- Time complexity: O(n) 
- Space complexity: O(n)
- There is a way of doing it without using stacks and no extra memory

- The recursive solution to solve reverse a linked list is called **implicit stack**

#### Check for balanced parentheses

- Use a stack to save the last opened parentheses.
- Every time a parenthesis is closed, the stack cannot be empty and the top element of the stack should correspond to the parentheses type of the closed. 
- In the end the stack should be empty

#### Evaluation of expressions

- There are different type of notations. **infix**, **postfix** and **prefix**.
- 
