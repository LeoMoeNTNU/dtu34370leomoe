# better test bench
A better test bench would have random generation of numbers and then run it on that. 
It shouldn't actually be fully random generation of numbers. 
The reason why is that each job has one process for each process and vice versa. 
Generate with the indexes and go from there. 
## I have written the random-function get_random in get.c but I havent tested it just yet...


# I am going to implement a new algorithm in here. 
This will be an evolutionary algorithm. 
What this one needs: 
    1. A population. 
        I think I can make a population by simply making a bunch of random arrays. 
        Then I need to make some crossover on it. 
        To make the crossover, I can simply breed two random instances in the population. Then I just pick the best one of them. 

# path relinking: 
There are many different versions of path relinking. 
This all merits some testing. 

# Idea: use path relinking as crossover. 


# One thing I could do, which would be crazy: 
I could do research on how many steps on average on needs to make to get to a new local optima. 
To do this, I would have to make local search deterministic. 

To do this, I could simply do some statistics. 
From a given local optima, I would simply have to do a "shuffle" of some width. 
This could lead to 

# not re-visiting things we have seen before. 
I imagine that this could be implemented with a hash or something if it is productive. 
It could be because the objective function is fairly big. 

# swap all the functions from getting a function pointer to getting an info_t and int time. 
First test the change and then go from there. 

# make a validation function just in case because who knows if this is even correct...
It should be run outside, by the testing harness. 

# expanding local search. 
Now I have a function that produces all different orders of x length. 
From this, I would like to make the full function. 
The first it does is that it has a random array. 
Then it runs expanding local search of size 2. 
If it improves something, then it will go to that one and from there do the thing. 

## maybe we attempt 2 things at the same time. 

## we only have to produce orders where everything has been changed. 
0,1,2 is not a valid sequence. 
0,2,1 is not a valid sequence because 0 is on its initial position. 
    As such, that would've been seen in localsearch(2)
1,2,0 is valid
2,0,1
These are frankly the only valid ones. 


## psuedo code:
wholefunc(info_t info, int time)//maybe not an int. 
generate random int array of length n. 
get score and maintain max score. 

# for now I am working on expanding local search. 
Currently an error in inner_swap which I dont understand quite yet sadly. 







