# Counting Runs

Runs, similar to any other card game, **can give you a great deal of points in the game of Cribbage.** Runs consist of having at least 3 cards that are in **ascending numerical order**, for example ```8, 9, 10```, ```10, J, Q```, ```3, 4, 5``` or even longer ones like ```1, 2, 3, 4, 5, 6```.

## Breakdown of how the program finds runs in a hand

This was one of the harder things for me to figure out, but by all means way easier than trying to figure out 15s for some reason.

For our demonstration, we are going to use the cards (of any suit) **Ace, 3, 3 and 2**, meaning our values to work with are **1, 3, 3, 2.** The reason we are using these 4 cards is because there are two runs, **1 2 3<sub>1</sub>** and **1 2 3<sub>2</sub>**. There is also a pair in here, but we are going to ignore that for this example because we are finding runs, not pairs. (Double runs of 3, like this one, are always 8 points because of the 2 runs and the single pair). Each card in a run is worth 1 point.

Let's take our numbers and lay them out like this:

 ```1   3   3   2```
 
This method is somewhat different from the methods that we use to find 15s and pairs. Instead of looping through the list by each element individually, we are going to do this:


Start with **sorting the list** from **lowest to highest** value. This helps because the way the program works is by starting with the lowest possible option for a run. So by sorting our list, we go from **1, 3, 3, 2** to **1, 2, 3, 3**. Now our first value to work with is our lowest.
 
Take the ```i```th element of the list, or ```1``` in this case, and set a *checker* variable to the value of this element. This will be used to find the next value which makes it a valid run. Now, in a nested for loop, assign the flag of that for loop (```a```) equal to ```i```. Now, we count how many times we see the value of *checker* in our list:

**<ins>1</ins>   2   3   3** (We have found it once as of now)

**1   <ins>2</ins>   3   3**

**1   2   <ins>3</ins>   3**

**1   2   3   <ins>3</ins>**

We found the value of *checker* (which is currently ```1```) **1** times.

Now, if this value from running this process is greater than 0, it means that the next value that makes our run valid is in our list! So we can add 1 to *run_length*, a variable to store the length of our current run, and then multiply *multiplier* by what that process returned (**1**). The reason we have this multiplier variable is to give necessary points to double, tripple, quadruple, etc. runs. This way, we don't have to loop through the list multiple times to find every single possible double or tripple run.

If this value from running this process is 0 or less, that means that the next valid number in our run to keep it going is not in our list, meaining it is the end of the run. We will break out of this for loop to the next process.

If we haven't broken out of this process, it means that we can check the next possible value in our run! So we are going to increment *checker* because the run works in ascending numerical order:

```checker++      //checker is now equal to 2 because it was 1 before```

Now, we are going to search our list for how many times the value of *checker* appears, just like before:

**<ins>1</ins>   2   3   3** 

**1   <ins>2</ins>   3   3** (We have found it once as of now)

**1   2   <ins>3</ins>   3**

**1   2   3   <ins>3</ins>**

We found the value of *checker* (which is currently ```2```) **1** times.

This process gave us a value greater than 0, so we can increase *run_length* by 1 and multiply *multiplier* by the value it returned.

Increment *checker* again, so that it is now **3**, and check how many times it appears in our list:

**<ins>1</ins>   2   3   3** 

**1   <ins>2</ins>   3   3**

**1   2   <ins>3</ins>   3** (We have found it once as of now)

**1   2  3   <ins>3</ins>** (We have found it twice as of now)

This process returned a value greater than 0, it returned **2**, meaning there is a **double run** as of now. So we can increase *run_length* by 1 and multiply *multiplier* by **2** to account for the double run.

We have looped through the whole entire list, now it is time to check the validity of our run. If the run has the length of 3 or greater (excluding double runs, etc.), then it is valid! This means that we can apply *multiplier* to *run_length* by multiplying them together:

```
//The value of run_length is 3, the value of multiplier is 2

run_length *= multiplier

//Now run_length is 6, which is true for a double run
```

Now, to avoid sub-runs, we want to set ```i``` to ```a``` because we have now used all of the values we needed to from our list that make a full run. Then, we add run_length to our total points and loop this process again for the rest of the list.


### Summary
---
Counting runs is a process of counting cards in **ascending numerical order,** and each **card in a run is worth 1 point.** You can not have sub-runs and a run has to be a **length of at least 3.** You can also have double runs, where you have a card with the same value as one in your run, in which you get double the amount of points the normal run would give you. This value can tripple, quadruple, and higher if you get a tripple or quadruple run. The program works by sorting the list from lowest values to highest values, and then looping through each element to see if they are the start of a run. If they continue a run up until it has a length of 3, then 3 points will be awarded. Multi-runs (double, tripple, quad, etc.) are implemented with a multiplier to the original score an initial run gives you. To avoid sub-runs, once an official run breaks, the values that were part of that run are skipped when starting new runs.