### **Push_swap Summary – 42 Project**  

**Objective:**  
The **Push_swap** project is a sorting algorithm challenge where you need to sort a stack of numbers with a limited set of operations. The goal is to write an efficient program that sorts the numbers in the least number of moves.  

---

### **Project Breakdown**  
- You will have **two stacks**:  
  - **Stack A** (initial stack with unsorted numbers).  
  - **Stack B** (used as a helper stack for sorting).  

- Your program must take a list of numbers as arguments and sort them using only specific operations.  

---

### **Allowed Operations:**  
1. **Swap (`sa`, `sb`, `ss`)** – Swap the top two elements of stack A, stack B, or both.  
2. **Push (`pa`, `pb`)** – Move the top element from one stack to the other.  
3. **Rotate (`ra`, `rb`, `rr`)** – Move the top element to the bottom of the stack.  
4. **Reverse Rotate (`rra`, `rrb`, `rrr`)** – Move the bottom element to the top of the stack.  

---

### **Main Challenges:**  
- **Efficiency** – The fewer moves, the better.  
- **Algorithm Choice** – You must implement a sorting strategy (e.g., Bubble Sort is too slow).  
- **Handling Edge Cases** – Duplicates, invalid inputs, already sorted lists, etc.  

---

### **My Approach: Best Move Algorithm**  
I implemented a **Best Move Algorithm**, which:  
✅ Assigns a **target position** for every node in Stack A.  
✅ Calculates a **cost (or price)** for moving each node to its correct position.  
✅ Always selects the **cheapest move** to optimize the sorting process.  

This method ensures that sorting is done efficiently with fewer moves, making the algorithm both **optimized and structured**.  

---

### **Performance of My Code**  
🚀 **100 numbers** → **< 700 moves**  
🚀 **500 numbers** → **< 7000 moves**  

This meets the **Push_swap efficiency requirements** and demonstrates a well-optimized sorting strategy.  

---

### **Expected Approach:**  
1. **Small stacks (≤ 5 numbers)**: Use a simple sorting method (like brute-force sorting).  
2. **Larger stacks (> 5 numbers)**: Implement an efficient sorting algorithm (like Quick Sort or Radix Sort, but adapted for two stacks).  

---

### **Evaluation Criteria:**  
✅ Sorting correctness.  
✅ Efficiency (fewer operations).  
✅ Error handling.  
✅ Code quality (Norminette compliance).  

This project is a great way to improve algorithmic thinking and learn about sorting optimizations in a restricted environment. 🚀
