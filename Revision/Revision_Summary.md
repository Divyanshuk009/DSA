# 📂 Revision Folder Recap

Welcome back! You have systematically progressed through 14 "Days" of core data structures and algorithms. 

> [!NOTE]
> This is a quick overview of your `d:\DSA\Revision` directory to help you pick up exactly where you left off.

| Day(s) | Topic | Key Concepts |
| :--- | :--- | :--- |
| **01** | **Binary Search** | First/last occurrences, pivot elements, square roots. |
| **02** | **Sorting** | Fundamental sorting algorithms. |
| **03** | **Char Array & String** | String manipulation and operations. |
| **04** | **2D Arrays** | Matrices and multi-dimensional traversals. |
| **05** | **Pointers & Memory** | Reference variables (`reference_var.cpp`), dynamic allocation (`dynamicArray.cpp`). |
| **06-07** | **Recursion** | Base cases, recursive relations, problem-solving. |
| **08** | **OOPs** | Object-Oriented Programming principles. |
| **09-10** | **Linked Lists** | Singly, Doubly, and Circular Linked Lists; reversing logic. |
| **11** | **Stacks** | Bracket matching, next smaller element, largest rectangle area. |
| **12** | **Queues** | Implementations and queue-based problems. |
| **13-14** | **Binary Trees** | Traversal, finding heights, calculating total leaves. |

---

## 🧠 Cheat Sheet: Frequently Used Elements & Definitions

> [!TIP]
> Keep this cheat sheet handy to quickly recall C++ syntax and core logic.

### 1. Core Language Features (C++)

| Concept | Definition |
| :--- | :--- |
| **Pointers (`*`)** | Stores the exact memory address of another variable. |
| **References (`&`)** | An alias or an alternative name for an existing variable. |
| **Dynamic Allocation** | Using `new` / `delete` to allocate memory on the *heap* during runtime. |
| **STL** | Standard Template Library. E.g., `std::vector` (dynamic arrays) and `std::string`. |

### 2. Algorithmic Approaches

> [!IMPORTANT]
> **Recursion Rule of Thumb:** Every recursive function *must* have a **Base Case** (stopping condition) and a **Recursive Relation**.

*   **Binary Search:** An `O(log n)` algorithm used on **sorted** data. Constantly halves the search space using `start`, `end`, and `mid` pointers.
*   **Recursion:** A function that calls itself to solve smaller instances of the same problem utilizing the *Call Stack*.

### 3. Data Structures

| Structure | Type | Description |
| :--- | :--- | :--- |
| **Linked List** | Linear | A sequence of nodes (data + next pointer). Fast insertion/deletion, slow O(n) access. |
| **Stack (LIFO)** | Linear | Last In, First Out. Use `push`, `pop`, `top`. Great for bracket matching and state tracking. |
| **Queue (FIFO)** | Linear | First In, First Out. Use `push`, `pop`, `front`. Like a line at a ticket counter. |
| **Binary Tree** | Non-Linear | Hierarchical structure starting at a `root`. At most 2 children (`left`, `right`). |

**Tree Traversals to Remember:**
1.  **Inorder:** Left, Root, Right
2.  **Preorder:** Root, Left, Right
3.  **Postorder:** Left, Right, Root
