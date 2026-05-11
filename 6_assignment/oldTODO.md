# bunch of checking for the inputs for different things? 
ThePrimeAgen talked about this at some point. 
A bunch of asserts that I include all of the time, so that we can check if the state is reasonable, and a lot fewer tests run. 
This would probably be a lot better.
I guess this is something I can start testing if I have reasonable estimates for what state will be. 


# I ran into a little bit of a question. 
In the init, I return a list of how many things will be in each. 
This is work that I would rather not do every time. 
In my objective-value function, as of now, it didn't get that as an input. 
It is valuable to get that as an input specifically because it 

## I think there is a little bit of restructuring that is about to happen. 
I don't want the init to do exactly that. I only want it to have the vector that represents the length in each of them. 
The reason is that it will not be changed at all, whereas the contents of the other one may. 
I am not yet quite sure about this decision lol. 

# I made the printallprocs and now I need to check what is happening in the code...


# I left a bug in get_first_valid_index in the end case that didn't make real sense hehe...


# further validate that my solutions are valid... 
 
# The thing to do now is to adjust the probability so that it starts at 50%

# I should implement a better function for probability, this one worsens it a lot from simple local search. 