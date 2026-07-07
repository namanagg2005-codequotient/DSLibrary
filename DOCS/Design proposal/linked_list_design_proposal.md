# Linked List
A linked list is a dynamic linear data structure consisting of nodes, where each node stores data and a pointer to the next node, allowing efficient insertion and deletion without shifting elements.
## Section 1 : Public Api

  1.```insertFront(T value)``` : It takes the value as input and insert it to the front of linked list as the user knows the location there is no need toreturn anything i.e. void <br>
  2. ```deleteFront()``` : it will delete the node from the start and in my implementation I have decided to return the element that is deleted so i will return integer as return type <br>
  3. ```insertIndex(int index , T value)``` : Here the user will enter the index at which they want to insert the value and the return type is also void here too <br>
  4. ```search(T value)``` : it will return whether the value is present in linked list or not so the return type is bool in here <br>
  5. ```size()``` : it will return the number of elements present in the linked list so the return type here is integer <br>
  6. ```print()``` : it will just traverse the array and print the values so the return type is void here 


## Section 2 : Internal Representation
The LinkedList object itself is created in memory and contains three data members: head, tail, and length. 
The head pointer stores the address of the first node, the tail pointer stores the address of the last node, and length stores the total number 
of nodes in the list. The actual nodes are not stored inside the LinkedList object; instead, they are dynamically allocated on the heap. 
Each node contains a data field (value) and a pointer (next) that stores the address of the next node. Starting from the head, we can traverse 
the entire list by repeatedly following the next pointers until we reach a node whose next is NULL, which is the tail node. 
During insertion and deletion, only these pointers are updated while the nodes themselves remain dynamically allocated or are freed using 
free when no longer needed.

## Section 3 : Complexity Estimates
1.``` insertFront(T value)```<br>
   It only required to just shuffle pointers to nodes in a sequential way and is independent of the size of the array hence it is O(1) for
   best, worst and average case.<br>
2. ```deleteFront()```<br>
   Similarly, delete front is also of constant time complexity as we donot need to traverse the linked list hence it is also of constant time
   complexity i.e. O(1)<br>
3. ```insertIndex(int index, T value)```<br>
__Best Case:__ The insertIndex() operation takes O(1) time when the insertion index is at the beginning of the linked list.<br>
__Average Case:__ The insertIndex() operation takes O(n) time because, on average, about half of the nodes must be traversed to reach the desired index.<br>
__Worst Case:__ The insertIndex() operation takes O(n) time when the insertion index is near the end of the linked list, requiring traversal of almost all nodes.<br>
6. ```search(T value)```<br>
__Best Case:__ The search() operation takes O(1) time when the required value is present in the first node.<br>
__Average Case:__ The search() operation takes O(n) time because the value is expected to be found after traversing approximately half of the linked list.<br>
__Worst Case:__ The search() operation takes O(n) time when the value is in the last node or is not present in the linked list.<br>
7. ```size()```<br>
In our implementation we have kept a variable stored and it will just be returned nothing else is needed hence it is of O(1) time complexity.<br>
8. ```print()```<br>
Here, it is strongly dependent upon the number of inputs hence it is always dependent on size N hence time complexity is O(N) in all the cases
for print<br>

## Section 4 : Design Decision

__Maintaining a `length` Variable__

In our linked list implementation, we maintain a dedicated variable named `length` to store the current number of nodes in the list. This variable is updated after every insertion and deletion operation, allowing the program to determine the size of the linked list in **O(1)** time. Without this variable, every request to find the size of the list would require traversing all the nodes from the head to the end, resulting in **O(n)** time complexity. This becomes inefficient when the size is accessed frequently, especially for large linked lists or within loops. By maintaining the `length` variable, operations such as checking whether the list is empty, validating indices, and reporting the number of elements become significantly faster. The only drawback of this approach is that the `length` variable must always be updated correctly during every insertion and deletion. If an update is missed due to a programming error, the stored size will become inconsistent with the actual number of nodes. However, this drawback is minor compared to the substantial performance improvement gained by constant-time size retrieval.

__Why We Chose a Singly Linked List__

Our implementation uses a **Singly Linked List** because the project only requires forward traversal of nodes. Operations such as insertion, deletion, searching, and displaying elements are all performed by moving from the head toward the end of the list, making backward traversal unnecessary. Since a singly linked list stores only a single `next` pointer in each node, it requires less memory and has a simpler implementation than a doubly linked list. In contrast, a doubly linked list stores both `next` and `previous` pointers, increasing the memory required for every node and making insertion and deletion operations more complex because both pointers must be updated correctly. Although a doubly linked list provides efficient backward traversal in **O(1)** time, this advantage is not useful for our implementation because none of the supported operations require moving backward through the list. Applications such as browser history navigation, undo/redo systems, and LRU cache implementations benefit from a doubly linked list due to frequent backward movement. Since our project has no such requirement, choosing a singly linked list reduces memory usage, simplifies pointer management, and provides a more efficient and maintainable solution.