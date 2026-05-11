# pesudo: 

objective function: 
    for each index in the list: 
        
    find out how long the thing ended up being. 
    I need to be able to find out if it is allowed to place it. 
    To do this, I need a little bit of code. What I need spec

random solution:
    give each process a random index. 

random shuffle. 
This is quite easy. I just do a shuffle.
A bunch of random is all I need for this. 

I'll use an index between 0 and len*len. 
Then from this I need to figure out: 
    which processor (look up in table),
    find out which job. (This is important for not having several at the same time). 
    I need to make a bucket thingy here. 
    I guess it will have start, end, index and then it will work finely. 

After I have built the objective function, I will make it so that it always picks an improvement but doesn't always pick the random and it needs to vary on time. 
    The delta stuff, I am not totally clear on just yet...


