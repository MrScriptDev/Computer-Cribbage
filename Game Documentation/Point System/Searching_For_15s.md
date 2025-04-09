# Counting 15s

The number **15 is essential to the game of Cribbage.** You can use the cards in your hand and also the cut card to try to **make groups that have a sum of 15.**

## Breakdown of how the program finds 15s in a hand

This was very difficult for me to figure out for some reason, and took me a couple of days, but here is the plan I came up with that ended up working great!

For our demonstration, we are going to use the cards (of any suit) **Ace, 3, 9 and 2**, meaning our values to work with are **1, 3, 9, 2.** The reason we chose these numbers to work with is because they are good universal numbers to work with in cribbage, the sum of all the cards' values add to 15 and there is also a run in there as well to work with later.

Let's take our numbers and lay them out like this:

 ```1   3   9   2```
 
 Start with the  ``` i ```th number (or element of list, which is our hand), which would be  ``` 1 ```  in this case.
 
**<ins>1</ins><sup>```i```th</sup>   3   9   2**

Check if the first possible group with the ```a```th number:

**<ins>1</ins><sup>```i```th</sup>   <ins>3</ins><sup>```a```th</sup>   9   2**

Check if their sum is 15. Now, unlike finding pairs, we need to check the next possible group, not pair, meaning we need to check the first possible group with the ```b```th number:

**<ins>1</ins><sup>```i```th</sup>   <ins>3</ins><sup>```a```th</sup>   <ins>9</ins><sup>```b```th</sup>   2**

Check if their sum is 15. Then, check the first possible group with the ```c```th number:

**<ins>1</ins><sup>```i```th</sup>   <ins>3</ins><sup>```a```th</sup>   <ins>9</ins><sup>```b```th</sup>   <ins>2</ins><sup>```c```th</sup>**

Check if their sum is 15. Now, all possible groups have been checked for ```i```&```a```&```b```&```c```.
Now, shift backwards by one in this process, from checking all possible combinations for ```i```&```a```&```b```&```c``` to instead ```i```&```a```&```b``` again, but with ```b``` incremented. So this time, check if the next possible group for the ```b```th number:

**<ins>1</ins><sup>```i```th</sup>   <ins>3</ins><sup>```a```th</sup>   9   <ins>2</ins><sup>```b```th</sup>**

Check if their sum is 15. Now, all possible groups havebeen checked for ```i```&```a```&```b++```. Now, shift backwards by one in this process, from checking all possible combinations for ```i```&```a```&```b++``` to instead ```i```&```a``` again, but with ```a``` incremented. So this time, check the next possible group for the ```a```th number:

**<ins>1</ins><sup>```i```th</sup>   3   <ins>9</ins><sup>```a```th</sup>   2**

Check if their sum is 15. Then, check the next possible combination for ```b```, with ```b``` being reset from the previous countings and checks because the ```b``` value was modified during those processes:

**<ins>1</ins><sup>```i```th</sup>   3   <ins>9</ins><sup>```a```th</sup>   <ins>2</ins><sup>```b```th</sup>**

Check if their sum is 15. Now, all possible groups have been checked for ```i```&```a++```&```b```. Now, shift backwards by one in this process, from checking all possible combinations for ```i```&```a++```&```b``` to instead ```i```&```a++``` again but incrementing ```a``` again to make ```i```&```a+=2```. Check the next possible group for ```a+=2```th number:

**<ins>1</ins><sup>```i```th</sup>   3   9   <ins>2</ins><sup>```a```th</sup>**

Check if their sum is 15. Now, all possible groups have been checked for ```i```&```a+=2```. Now, shift backwards by one in this process, from checking all possible combinations for ```i```&```a+=2``` to instead ```i```. ```i``` does not need to be checked because the ```i```th number can never be 15 alone. ```i``` can now be incremented and this whole process can repeat:

**1   <ins>3</ins><sup>```i```th</sup>   9   2**

**1   <ins>3</ins><sup>```i```th</sup>   <ins>9</ins><sup>```a```th</sup>   2** (Check for sum of 15)

**1   <ins>3</ins><sup>```i```th</sup>   <ins>9</ins><sup>```a```th</sup>   <ins>2</ins><sup>```b```th</sup>** (Check for sum of 15)

**1   <ins>3</ins><sup>```i```th</sup>   9  <ins>2</ins><sup>```a```th</sup>** (Check for sum of 15)

**1   3   <ins>9</ins><sup>```i```th</sup>   2**

**1   3   <ins>9</ins><sup>```i```th</sup>   <ins>2</ins><sup>```a```th</sup>** (Check for sum of 15)

**1   3   9   <ins>2</ins><sup>```i```th</sup>**


### Summary
---
What this whole process is doing is **checking every single possible combination that the cards could go together in to return a sum of 15.** The function (```find_15s()```) in the ```PointCounter.cpp``` file uses recursion to dig deep into the list and get the elements such as ```i```th, ```a```th and so on. In theory, this method allows you to expand the size of your hand (or the amount of cards you input) to count all possible points for hands larger than 4 cards (excluding the cut card).