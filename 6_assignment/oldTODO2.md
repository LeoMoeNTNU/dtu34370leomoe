# We should delete some code. 

# second thing is that I am setting up the testing suite so that I can easily check it from Windows. 

# the next thing to do is to figure out the neighborhood stuff. 
If I can put a nice interface around it, then it'll be easier to fix it. 
Then I need to figure out the different neighborhoods. 
They suggest one version where take set of things out of the array and then input the cheapest things first. 
I don't know if this makes sense for me just yet. 
The reason that I am a bit skeptical is that I'll have to do the objective function for each and figure out where to put it. 
I'll have to do the whole function for each.

# karma system will be important to implement correctly. 
I need to figure out the right way of doing this as well, as it isn't obvious. 
I saw somewhere that they had a system where they have 3 different tiers, maybe 4 different tiers. 
Based on the tier, I guess they'll get a likelihood for being used. 
Then my suggestion is that for each 10 times they have been used, if they have been right 3 times or less, give them to the lowest tier. 
If they have been right between 3 and 7 times, put them in middle. 
If they have improved the current solution 7 or more times, we put them in the highest tier. 

# I will need to modify it so that it doesn't do it in the wholefunc. 
The wholefunc is actually going to be something a little bit different:
It will switch between different metaheuristics, is what it will do. As such, I need an interface that gives me the thing. 

So it will just reserve that thing. 

This will have to get done inside of objective_function. 


# interface for heuristic: 
You should give it a heuristic. 
wholefunc should choose between 2 things based on which is doing better recently. 
to know this: 
I keep which of them has been doing better. 
I guess I can just give the better one 7/10 and the worst one 3/10 and then it is a lot easier. 
Each search iteration should return whether or not it made it better. 
What is the elo system. 
The easiest idea is to just hardcode the thing. 
We give them 8 and 4 and then if 8<2 not bigger than 

# Implement the -1 stuff. 
I foresee several issues here and I am not certain about how to navigate them effectively. 
There are several functions. 
## Total length will need a modification. 
totallength now only check the last thing, which is pretty slow. 

## value, I assume will be more of a problem. 
The reason I think value will be a problem is that we will now deal with holes in the thing.
It isn't made for this. 
### I dont know what order things are placed in 
I can potentially check one thing to find out how it works right now. 
The thing I can do, is that I check the print. 


So what happens is that I have a set of procs and then these do funky stuff. 
My question is what happens if I just put index -1 in there. Will it do things correctly?

Does it assume that the length is full all of the time. 
If not, that will not be great. 
get_first_valid_index is the one that goes through a proc_list for a valid one. 
This function gets in an argument from somewhere: 
It gets set in the iteration function. 
I dont know what happens if I change it. 
Next question: How does it even get initiated. 

I have an init-function. 
What the init-function does is that it sets up all of the proc_lists and it sets the index in them to -1. 
This is good news.
I need get_first_valid_index to check for -1 and not just stop there. 
#### 1. Change the argument in the iteration ap.p[processor].len in the get_first_valid_index to info.len. 
This is so that it checks all of them. 


# I need an interface for copying the ap_and_val_t as I will in my heuristics.
This is a bit of a thingy that is important to fix. 
The thing I need to know is whether or not the actual op_in_job is something that I should copy. 
In reality, none of this is what I should copy. 
op_in_job is just a thing that exists but isn't something to go around copying.
The reason that I shouldn't go around copying it is because it isn't an int*, as it should be. 

What neighbourhood_search1 should implement: 
    {int *, bool} neighbourhoodsearch(int* ip){
        int * newp=
    }

I realized that in the end, I need the thing. 
Maybe the easiest thing to do is to calculate it once. 
Then we need the proc_list because we are printing it!typ

# the iterations have to free and killallprocs!
Both of these are important and shouldn't be forgotten!


# somewhere in the iteration_swap, I need to call killallprocs.
I just dont know yet... 

# additionally, it doesn't return the actual int array, which is pretty important. 
Several options for this. 
1: I want the value() for printing it at the end. Hypothetically, if I have the int *, I will not need the thing. 

My current plan: 
input int *
output int *
output bool improved. 
just re-get it at the end when I need it. 


# Maybe actually write some tests for the thingy...