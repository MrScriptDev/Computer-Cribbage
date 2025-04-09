# Counting Pairs

Pairs, like in most standard card games, can get you a lot of points. But in order to get all the points for your pairs, you have to **Look through every possible card option** that could form a pair. This is easier than looking for groups of 15s because you can use multiple cards to form the number 15, but you can only use 2 cards at a time to form a pair.

## Breakdown of how the program finds pairs in a hand

This was a very simple process to get working for me. It works every time and the program finds every pair you give it, even if you put in more cards than the standard Cribbage hand.

For our demonstration, we are going to use the cards (of any suit) **2, 2, 2, 3 and 3**. The reason we chose these numbers to work with is because even though there are more cards here than the standard Cribbage hand, there are 3 possible pairs we could make with the 2s and 1 possible pair we can make with the 3s, allowing for multiple different options for pairing.

Let's take our numbers and lay them out like this:

 ```2   2   2   3   3```
 
 Start with the  ``` i ```th number (or element of list, which is our hand), which would be  ``` 2 ```  in this case.
 
**<ins>2</ins><sup>```i```th</sup>   2   2   3   3**

Check if the first possible pair with the ```a```th number:

**<ins>2</ins><sup>```i```th</sup>   <ins>2</ins><sup>```a```th</sup>   2   3   3**

Check if their values match each other. Now, unlike 15s, we can just increment ```a```'s value and see if they are pairs. This is because you don't need to pair more than 2 cards together at a time:

**<ins>2</ins><sup>```i```th</sup>   2   <ins>2</ins><sup>```a```th</sup>   3   3**

Check if their values match each other. Then, increment ```a``` again:

**<ins>2</ins><sup>```i```th</sup>   2   2   <ins>3</ins><sup>```a```th</sup>   3**

Check if their values match each other. Then, increment ```a``` again:

**<ins>2</ins><sup>```i```th</sup>   2   2   3   <ins>3</ins><sup>```a```th</sup>**

Check if their values match each other. Now, all possible pairs have been checked for the ```i```th number in the hand. We can now increment ```i``` and repeat this process again and again until we reach the end of the hand.


**2   <ins>2</ins><sup>```i```th</sup>   2   3   3**

**2   <ins>2</ins><sup>```i```th</sup>   <ins>2</ins><sup>```a```th</sup>   3   3** (Check for value matching)

**2   <ins>2</ins><sup>```i```th</sup>   2   <ins>3</ins><sup>```a```th</sup>   3** (Check for value matching)

**2   <ins>2</ins><sup>```i```th</sup>   2   3   <ins>3</ins><sup>```a```th</sup>** (Check for value matching)

**2   2   <ins>2</ins><sup>```i```th</sup>   3   3**

**2   2   <ins>2</ins><sup>```i```th</sup>   <ins>3</ins><sup>```a```th</sup>   3** (Check for value matching)

**2   2   <ins>2</ins><sup>```i```th</sup>   3   <ins>3</ins><sup>```a```th</sup>** (Check for value matching)

**2   2   2   <ins>3</ins><sup>```i```th</sup>   3**

**2   2   2   <ins>3</ins><sup>```i```th</sup>   <ins>3</ins><sup>```a```th</sup>** (Check for value matching)

**2   2   2   3   <ins>3</ins><sup>```i```th</sup>**

### Summary
---
The process of checking for all possible pairs is **a simple task** compared to other points that have to be counted in cribbage. Checking for pairs is the easier to do than counting 15s or runs in cribbage because you only need to check all possible *pairs,* meaning **only possible groups of 2.** We start from the begining of the hand (or list) and individually check if any of the other cards match the initial one. Then, we repeat until we reach the end of the list. The way this method works allows you to expand the size of your hand (or the amount of cards you input) to count all possible points for hands larger than 4 cards (excluding the cut card).