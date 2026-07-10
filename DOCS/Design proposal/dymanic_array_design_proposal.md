# Dynamic Array
A dynamic array is a linear data structure that stores elements in contiguous memory locations, just like a normal array. Unlike a static array, however, its size is not fixed. When the array becomes full, it automatically allocates a larger block of memory, copies the existing elements into it, and releases the old memory. This allows the array to grow during program execution.
## Section 1: Public API

**method 1** : ```append(T value)``` , it will take input as an integer and add it to the end of the array here we are not returning anything as it is already understood by the user that at which index the new element is added so there is no need to return the index hence we return void.

**method 2** : ```remove(int index)```, here we will provide the index of the element that we want to be removed from our dynamic array, according to me we should also return the element value that is deleted so, I choose T as the return type.

**method 3** : ```get(int index)``` it will take an index as the input and return the value associated with that index so the returned value is T in here for my implementation

**method 4** : ```getSize()``` it will not take any parameter and will only return the current size of the dynamic array hence the return type is int 

**method 5** : ```getCapacity()``` it will not take any parameter and will only return the current capacity of the dynamic array hence the return type is int

**method 6** : ```insert(int index, T value)``` it will input the value on the index by shifting elements to next by one and the return type here also is void

**method 7** : ```nextPowerOf2(int n)``` it will take an integer as input and return the next power of 2 that is greater than or equal to the given value. This is used to ensure that the initial capacity and resized capacity always remain powers of two, resulting in efficient memory allocation,because if other it will cause the issue of fragmentation

**method 8** : ```growthFactor(int currentCapacity)``` it will take the current capacity as input and calculate the appropriate growth factor based on the memory consumption 

**Method 10** : ```resize()``` it will not take any parameter and will automatically increase the capacity of the dynamic array whenever the current capacity is full. It first calculates the new capacity using the adaptive growth strategy, allocates a new block of memory, copies all existing elements into the new memory using placement new, destroys the old objects, frees the previously allocated memory, and finally updates the internal pointer and capacity to point to the newly allocated storage.

 ## Constructors:
Here I have deciced to make 3 constuctor that are:
1. __Default Constructor__ : 
   ``` DynamicArray() ```: The default constructor initializes an empty dynamic array by setting the current size to 0, assigning an initial capacity as 4, and dynamically allocating memory on the heap for that capacity. This ensures the object is ready to store elements immediately after creation.

2. __Paramterized Constructor__:
```DynamicArray(int size)```: This constructor allows the user to specify the initial capacity of the dynamic array. Internally, the provided size is rounded up to the nearest power of 2 (e.g., if the user passes 10, the capacity becomes 16). Choosing a capacity that is a power of 2 simplifies the resizing strategy, as the array can efficiently double its capacity whenever it becomes full. The current number of stored elements (`length`) is initialized to **0**, indicating that the array is empty, while memory is allocated on the heap based on the computed capacity. This approach minimizes the frequency of resizing operations and helps maintain an amortized insertion time complexity of **O(1)**.

3. __Copy Constructor__:
```DynamicArray(const DynamicArray& other)```: This constructor is used to create a new Dynamic Array object as an exact copy of an existing object. Instead of copying only the pointer to the underlying array (shallow copy), it performs a **deep copy** by allocating a new block of memory with the same capacity as the source array and copying each element individually. The new object also copies the current size (`length`) and capacity of the original array, ensuring that both objects maintain independent copies of the data. As a result, any modification made to one array does not affect the other, preventing issues such as shared memory, double deletion, and memory corruption during object destruction.

## Operators Overloaded

Here I have decided to overload 2 operators that are:

1. __Assignment Operator (`=`)__:
   ```DynamicArray& operator=(const DynamicArray& other)```: This operator is used when an already-existing Dynamic Array object is assigned the contents of another existing object (e.g. `a = b`), as opposed to the copy constructor which handles creation of a brand-new object. It first checks for **self-assignment** (`this == &other`) to avoid unnecessary work or accidental destruction of the array's own data. It then frees the current object's existing memory, allocates a new block of memory with the same capacity as the source array, and copies each element individually to perform a **deep copy**. The current size (`length`) and capacity of the source object are also copied over. This ensures the assigned-to object holds an entirely independent copy of the data, preventing issues such as shared memory, double deletion, and memory corruption during object destruction. The function returns a reference to `*this` so that assignments can be chained (e.g. `a = b = c`).

2. __Subscript Operator (`[]`)__:
   ```T& operator[](int index)```: This operator allows elements of the Dynamic Array to be accessed and modified using familiar array-style syntax (e.g. `arr[2]`) instead of a named method like `get(index)`. It first validates that the provided `index` lies within the valid range `[0, size)`, throwing an `std::out_of_range` exception if it does not, to prevent silent out-of-bounds access. Because the function returns a reference (`T&`) rather than a copy, it supports both **reading** (`x = arr[2]`) and **writing** (`arr[2] = x`) through the same operator. A `const` overload (`const T& operator[](int index) const`) is also provided so that the subscript operator can be used safely on `const` Dynamic Array objects, restricting access to read-only.

## Section 2 : Internal Representation
![Dynamic Array](../images/Dynamic%20Array%20Memory%20Diagram.jpeg)
# Rule of Three

The **Rule of Three** is a C++ design principle which states that if a class manually manages a resource (such as dynamically allocated memory), then it must explicitly define the following three special member functions:

1. Destructor
2. Copy Constructor
3. Copy Assignment Operator

The `DynamicArray<T>` class allocates memory manually using `malloc()` and constructs objects using placement `new`. Since the class owns this dynamically allocated memory, the compiler-generated versions of these functions are insufficient and can lead to serious issues such as memory leaks, dangling pointers, and double-free errors.

---

## Why is the Rule of Three Needed?

The `DynamicArray` stores its elements in a dynamically allocated memory block.

```cpp
T* ptr;
int size;
int capacity;
```

Here, `ptr` points to memory allocated on the heap. Since the class owns this memory, it is responsible for:

- Allocating memory
- Constructing objects
- Destroying objects
- Releasing memory

If these responsibilities are not handled correctly, multiple objects may end up sharing the same memory, causing undefined behavior.

---

# 1. Destructor

## Purpose

The destructor releases every resource owned by the dynamic array when the object goes out of scope.

### Responsibilities

- Call the destructor of every stored object.
- Release the allocated memory.
- Prevent memory leaks.

### Why is it Required?

Objects are constructed using placement `new`.

```cpp
new (ptr + i) T(value);
```

Since placement `new` does not associate the object with automatic destruction, every object's destructor must be invoked manually.

After destroying every element, the raw memory must also be released.

Without a destructor:

- Memory remains allocated.
- Destructors of stored objects are never executed.
- Resources owned by stored objects (such as strings or other dynamic memory) are leaked.

---

# 2. Copy Constructor

## Purpose

The copy constructor creates a completely independent copy of an existing `DynamicArray`.

Example:

```cpp
DynamicArray<int> arr1;
DynamicArray<int> arr2 = arr1;
```

The newly created array should have its own memory block.

### Responsibilities

- Allocate a new memory block.
- Copy `size`.
- Copy `capacity`.
- Construct copies of every stored element inside the new memory.

### Why is it Required?

The compiler-generated copy constructor performs only a **shallow copy**.

```
Compiler Generated

arr1.ptr --------\
                  \
                   ---> Same Memory
                  /
arr2.ptr --------/
```

Both objects point to the same memory.

When one object is destroyed,

- the memory is freed,

and when the second object is destroyed,

- it attempts to free the same memory again.

This results in:

- Double free
- Dangling pointers
- Program crashes
- Undefined behavior

Instead, the copy constructor performs a **deep copy**.

```
Deep Copy

arr1.ptr -----> Memory Block A

arr2.ptr -----> Memory Block B
```

Each object owns its own memory independently.

Therefore, modifications to one array do not affect the other.

---

# 3. Copy Assignment Operator

## Purpose

The copy assignment operator copies one existing dynamic array into another existing dynamic array.

Example:

```cpp
arr2 = arr1;
```

Unlike the copy constructor, both objects already exist before the assignment.

### Responsibilities

1. Handle self-assignment.
2. Destroy existing elements.
3. Release existing memory.
4. Allocate new memory.
5. Copy all elements.
6. Return the current object.

### Why is it Required?

Again, the compiler-generated assignment operator performs only a shallow copy.

```
Before Assignment

arr1 -----> Memory A

arr2 -----> Memory B

After Compiler Assignment

arr1 -----> Memory A
arr2 -----> Memory A
```

The original memory owned by `arr2` is lost.

Problems include:

- Memory leak
- Double free
- Shared ownership
- Undefined behavior

A proper copy assignment operator first cleans up the old resources owned by the destination object before creating an independent copy.

---

# Deep Copy vs Shallow Copy

## Shallow Copy

Only pointer values are copied.

```
Object A

ptr -----> Data

Object B

ptr -----^
```

Both objects share the same memory.

Problems:

- Double deletion
- Dangling pointers
- Shared modifications
- Undefined behavior

---

## Deep Copy

A completely new memory block is created.

```
Object A

ptr -----> Data A

Object B

ptr -----> Data B
```

Each object manages its own resources independently.

---

# Why Rule of Three Applies to DynamicArray

The `DynamicArray` class performs manual memory management.

It:

- Allocates memory using `malloc()`
- Constructs objects using placement `new`
- Calls destructors manually
- Releases memory using `free()`

Since the compiler cannot understand how these resources should be copied or destroyed, it cannot generate correct copy semantics automatically.

Therefore, implementing:

- Destructor
- Copy Constructor
- Copy Assignment Operator

ensures:

- Proper ownership of memory
- No memory leaks
- No double-free errors
- Safe copying of dynamic arrays
- Independent objects through deep copying

---

## Section 3 : Complexity Estimates

1. ```append(T value)```

- **Best Case:** The append operation takes O(1) time when there is enough capacity in the array, as the new element is simply placed at the end. <br>
- **Average Case:** The append operation takes O(1) amortized time because although resizing occasionally occurs, most insertions do not require it.<br>
- **Worst Case:** The append operation takes O(n) time when the array is full and all existing elements must be copied to a newly allocated larger array.<br>
2. ```remove(int index)```

- __Best Case:__ The remove operation takes O(1) time when the last element is removed, as no shifting of elements is required.<br>
- **Average Case:** The remove operation takes O(n) time because elements after the removed index usually need to be shifted one position to the left.<br>
- **Worst Case:** The remove operation takes O(n) time when the first element is removed, requiring all remaining elements to be shifted.<br>
3. ```get(int index)```

- **Best Case:** **O(1)**  
  The element is accessed directly using its index through pointer arithmetic. No traversal or iteration is required.

- **Average Case:** **O(1)**  
  Regardless of which valid index is requested, the element is accessed directly from memory in constant time.

- **Worst Case:** **O(1)**  
  Even when accessing the last element, the operation still performs a single memory access using the index. The execution time does not depend on the number of elements in the array.

**Reason:**  
A dynamic array stores its elements in contiguous memory. The address of any element can be computed using the formula:

4. `getSize()`

- **Best Case:** **O(1)**  
  The function directly returns the stored `size` member variable without performing any computation or traversal.

- **Average Case:** **O(1)**  
  Regardless of the number of elements in the dynamic array, the function always returns the stored `size` value in constant time.

- **Worst Case:** **O(1)**  
  Even for a very large dynamic array, the operation only accesses a single member variable and returns its value.

**Reason:**  
The current number of elements is maintained in the `size` member variable, so retrieving it requires only a single memory access, resulting in **O(1)** time complexity in all cases.

5. `getCapacity()`

- **Best Case:** **O(1)**  
  The function directly returns the stored `capacity` member variable.

- **Average Case:** **O(1)**  
  The capacity value is always stored as a member variable, so retrieving it takes constant time irrespective of the array size.

- **Worst Case:** **O(1)**  
  Even when the dynamic array contains a large number of elements, the function simply returns the stored `capacity` value without any additional work.

**Reason:**  
The maximum storage capacity of the dynamic array is maintained in the `capacity` member variable. Since the function only returns this stored value, its time complexity remains **O(1)** in the best, average, and worst cases.

6. ```insert(int index, T value)```

- **Best Case:** The insert operation takes O(1) time when the element is inserted at the end of the array and sufficient capacity is available.<br>
- **Average Case:** The insert operation takes O(n) time because elements usually need to be shifted to make space for the new element.<br>
- **Worst Case:** The insert operation takes O(n) time when the element is inserted at the beginning or when resizing and shifting of all elements are required.

7. `nextPowerOf2(int n)`

- **Best Case:** **O(1)**  
  The function performs a fixed sequence of bitwise operations regardless of the input value.

- **Average Case:** **O(1)**  
  Every execution performs the same number of shift and OR operations, so the running time remains constant.

- **Worst Case:** **O(1)**  
  Even for the largest valid integer, the function executes the same fixed number of operations without any loops or recursion.

**Reason:**  
The algorithm consists of a constant number of bitwise shift and OR operations. Since the number of instructions does not depend on the value of `n`, the time complexity is **O(1)** in all cases.


8. `growthFactor(int currentCapacity)`

- **Best Case:** **O(1)**  
  The function performs a few conditional checks and returns the appropriate growth factor.

- **Average Case:** **O(1)**  
  The number of comparisons and arithmetic operations remains constant regardless of the current capacity.

- **Worst Case:** **O(1)**  
  Even when the capacity is very large, the function still executes the same fixed number of operations.

**Reason:**  
The function only performs a few arithmetic calculations and conditional statements. Since there are no loops or recursive calls, its time complexity remains **O(1)** in every case.


9. `resize()`

- **Best Case:** **O(n)**  
  During resizing, all existing elements must be copied from the old memory block to the newly allocated block.

- **Average Case:** **O(n)**  
  Every resize operation requires visiting each stored element exactly once to construct it in the new memory location.

- **Worst Case:** **O(n)**  
  Even in the worst case, the function copies every element exactly once before releasing the old memory block.

**Reason:**  
Although computing the new capacity and allocating memory take constant time, the dominant operation is copying (or moving) all `n` existing elements to the new storage. Therefore, the overall time complexity is **O(n)**.

#### Auxiliary Space Complexity

- **Best Case:** **O(n)**
- **Average Case:** **O(n)**
- **Worst Case:** **O(n)**

**Reason:**  
A new memory block capable of storing all existing elements (and additional capacity) is allocated during resizing. Hence, the extra space required is proportional to the number of stored elements, giving an auxiliary space complexity of **O(n)**.

## Section 4: Design Decisions


__1. Initial Capacity of the Dynamic Array__

Instead of starting with a capacity of **1**, I chose an initial capacity of **4**.

### Reasoning

- If the initial capacity is **1**, every early insertion triggers a resize (1 → 2 → 4 → 8...), resulting in unnecessary memory allocations and element copying.
- Starting with **8** or more reduces the number of reallocations but wastes memory for users who store only a few elements.
- Most applications initially store only a small number of elements, so choosing **4** provides a balance between minimizing reallocations and avoiding excessive memory wastage.
- It also keeps the implementation simple while providing good performance for typical use cases.

Therefore, an initial capacity of **4** offers a practical compromise between performance and memory efficiency.

---

## 2. Capacity Growth Strategy

The next design decision was determining how much the array should grow once it becomes full.

Initially, I considered always doubling the capacity because it is the most common strategy used in dynamic arrays.

### Why Doubling?

When the array becomes full, allocating only one additional element would require reallocation after almost every insertion.

Example:

```
Capacity:
1 → 2 → 3 → 4 → 5 → 6 ...
```

Each resize copies all existing elements, making insertions extremely expensive.

Instead, doubling produces

```
1 → 2 → 4 → 8 → 16 → 32 → ...
```

This significantly reduces the number of resize operations and gives an **amortized insertion complexity of O(1)**.

However, after further analysis I observed another issue.

---

## 3. Adaptive Growth Factor

Always doubling the capacity works well for smaller arrays, but becomes inefficient for very large arrays.

For example,

- Capacity = 1,000,000
- Doubling allocates space for 2,000,000 elements

If the application never uses those additional elements, a large amount of memory remains unused.

To balance performance with memory usage, I implemented an **adaptive growth factor** based on the amount of memory currently occupied by the array.

### Growth Policy

| Current Memory Usage | Growth Factor |
|----------------------|--------------:|
| Less than 1 MB | 2.0× |
| 1 MB – 16 MB | 1.5× |
| Greater than 16 MB | 1.25× |

### Why this approach?

- Small arrays benefit from aggressive growth because memory consumption is negligible and fewer reallocations improve performance.
- Medium-sized arrays require a balance between memory usage and resizing frequency.
- Very large arrays should avoid doubling because it can allocate a large amount of unused memory. A smaller growth factor reduces memory wastage while still limiting the number of reallocations.

This approach provides a better trade-off between execution speed and memory efficiency across different workloads.

---

## 4. Choosing the Next Power of Two

After computing the new capacity using the growth factor, I round it up to the **nearest power of two**.

For example,

```
Current Capacity = 10

Growth Factor = 1.5

New Capacity = 15

Nearest Power of Two = 16
```

### Why choose the next power of two?

#### 1. Better Memory Management

We can also choose the initial size as any value other then power of two but that would lead to fragmentation issues so I have implemented  this function 

---

#### 2. Efficient Bitwise Computation

The next power of two is computed using bitwise operations rather than loops.

Since only a fixed number of bitwise operations are performed, the computation runs in **O(1)** time.

---

