Advanced C programming descriptive questions:

Question 1:    Chocolates

Rob likes chocolates . He finds N chocolates in his refrigerator to which he gives a special value.

He is also a mathematics lover, so he decides to do something peculiar with the chocolates.

He performs some other operations on the chocolates.

In each operation, he takes one or more chocolates which are lying in a continuous manner.

He then finds and notes down the minimum special value of a chocolates in that group of chocolates.

He performs this operation for all the groups of chocolates he could find.

But unfortunately his pet dog ate the paper. On which he had written the results.

Your task is to find the sum of all the numbers he had written.

 

Input Specifications:

input1 : The number of chocolates N.

input2 : The array representing the special values of chocolates.

 

Output Specifications:

The desired sum

example 1:

input1 : 2

input2 : {3,4}

output : 10

Explanation:

Here, the groups he can form by using one or more continuous chocolates are {3}, {4}, {3,4}

and the minimum of each group is 3,4,5 and sum of these is 10.

example 2:

input1 : 4

input2 : {1,2,3,4}

 

output : 20

Explanation :

Here,the groups he can form by using one or more continuous chocolates are {1},{2},{3},{4},{1,2},{2,3},{3,4},{1,2,3},{2,3,4} and {1,2,3,4}

and the minimum of each group is 1,2,3,4,1,2,3,1,2,1 and sum of these is 20.

#include<stdio.h>

#include<string.h>

// Read only region starts

int chocolates(int input1, int intput2[])

{

//Read only region end

//write code here.

}



Question 2: Saving Marvel

In a parallel Universe called Marvel, an infectious viral disease has been spreading at very fast rate.  Dr.Strange is trying to create a potion that could prevent people from catching the disease and would also cures the once diseased already.

He knows that the cure is a potion which is mixture of N chemicals and is K liters in volume.

He does not know the amount of each chemical that must be added and hence is experimenting on the same.

As Dr.Strange's assistant, you help him in his task and ask him on how to prepare the potion, to which he replies :

1. Chemicals must be added in the increasing order of the labels.

2. The amount of chemicals being added must be between 1 and L, where L is the amount of mixture obtained till that step.

3. Exactly one liter of the first chemical must be taken.

 

You along with being a biologist, are a good programmer & mathematician and hence, decide to fixed the number of potions possible in accordance with

Dr.Stranger's instruction using a computer program.

 

Input Specifications:

input1: An integer value N denoting the number of chemicals.

input2: An integer value K denoting the total amount of chemicals to be added.

 

Output Specifications :

Return the number of potions possible in accordance with Dr.Strange's instructions.

Example 1:

input1: 2

input2: 2

output: 1

Explanation :

The only possible way for the above scenerio is :

1.Chemical 1 -1L, Chemical 2 -1L

Since here is only 1 possible way, hence 1 will be returned as the answer.

 

Example 2:

input1: 5

input2: 10

output: 6

Explanation :

The only possible way for the above scenerio are :

1.Chemical 1-1L,Chemical 2-1L,Chemical 3-2L,Chemical 4-4L,Chemical 5-2L

2.Chemical 1-1L,Chemical 2-1L,Chemical 3-2L,Chemical 4-3L,Chemical 5-3L

3.Chemical 1-1L,Chemical 2-1L,Chemical 3-2L,Chemical 4-2L,Chemical 5-4L

4.Chemical 1-1L,Chemical 2-1L,Chemical 3-1L,Chemical 4-3L,Chemical 5-4L

5.Chemical 1-1L,Chemical 2-1L,Chemical 3-1L,Chemical 4-2L,Chemical 5-5L

6.Chemical 1-1L,Chemical 2-1L,Chemical 3-2L,Chemical 4-1L,Chemical 5-5L

 

#include<stdio.h>

#include<string.h>

// Read only reagion starts

int totalconfiguration(int input1, int intput2)

{

//Read only region end

//write code here.

}
