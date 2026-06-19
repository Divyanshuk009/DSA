Welcome to what the programming community calls "Tutorial Hell". Literally every single programmer on earth has been exactly where you are right now.

When you watch a video, your brain is doing passive learning. You are following someone else's logic, and it makes perfect sense in the moment. But when you face a blank screen, you are forced to do active recall, which is a completely different muscle. It's the difference between riding in the passenger seat vs. driving the car yourself.

Here is a proven, 4-step framework to break out of this cycle, specifically for Data Structures and Algorithms (DSA):

1. The "No Typing" Rule
When watching a tutorial, take your hands off the keyboard. Do not code along with them. Watch the video strictly to understand the concept and the logic. Take notes on paper if you need to, but do not type a single line of code.

2. The Pen and Paper Phase (Crucial for Trees)
Once the video is over, close it. Do not look at their code. Take a piece of paper and draw a small binary tree. Try to trace the logic the video just explained by hand.

"Okay, I start at the root (1)."
"I need to go left. Now I'm at (2). Length is 1, Sum is 3."
"Now I'm at a leaf. What do I do?" If you can't solve it on paper, you cannot solve it in code.
3. Write "Plain English" Code First
### Open your code editor. Before writing any C++, write out your logic using comments.

cpp
## int sumOfLongestPath(TreeNode *root) {
    // 1. I need a helper function to travel the tree
    // 2. I need to keep track of max length and max sum
    // 3. I need to start at the root with 0 length and 0 sum}
    
// Helper function
// 1. If the node is null, go back
// 2. Add current node's value to current sum
// 3. If I hit a leaf node, check if my current path is the longest
// 4. If it is, update my max variables.
// 5. Go left, then go right.
This forces your brain to structure the logic without worrying about missing a semicolon or getting pointers wrong.

4. Translate and the "15-Minute Rule"
Now, translate those English comments into C++ line by line.

You will get stuck here. That is part of the process. When you get stuck, apply the 15-Minute Rule:

Struggle with it for exactly 15 minutes. Google specific syntax (e.g., "how to pass by reference C++"), but do not look at the solution.
If 15 minutes pass and you are still completely frozen, open the video/solution.
Look ONLY at the specific line you are stuck on.
As soon as you have your "Aha!" moment, close the solution immediately and go back to typing yourself.
Why this works:
Right now, you are trying to learn the logic of trees and the syntax of C++ at the exact same time. It's overloading your brain. By using paper and plain English first, you separate the logic from the syntax.

Try this exact method on your next tree problem. It will take longer initially, but it is the only way to build the "active recall" muscle! You've got this.