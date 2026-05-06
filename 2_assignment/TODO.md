# Many things need to get done. 

## iterations in loc search back away from 1. 


## check that len in main actually does what it is supposed to.
Why doesnt it give different values?
SOmething is wrong, as can be seen by one value being -1 for no clear reason in the print. 


## a lot of the stuff has been implemented but it doesn't have tests, so there may be a bunch of errors in there!
For now my plan is to try to run it and after having run it, I will 

## The array howmuchtimeifgone doesnt set a value if wheretheyare =-1. 


## then I need to implement local iterations
I need to try to do local improvements. I guess what I will do is that I will try to see if I can find somewhere else that I can put things. 
Maybe this is as easy as just picking random elements seeing if they are good. 
One "difficult" way of doing it is to keep track of which bucket which thing is in, and how much time is remaining in each bucket. 
Then, we can do a double for loop where we can find out what the best swap is. 
For this: 
    Write down when we place, where we place it. 
    Have a counter which is the remaining time for each bucket. 
    Pick 5 random indexes. Find out if a swap would be profitable and then how much so. 
        In addition to if it is profitable, if it fits timewise. 
    I need an objective function for all of this. 
    If localspace is 5, this could be fine. Can't do it on my troll matrix though...


## ideally each bucket_t would know how many buckets, not just how long each bucket is. 
This, I haven't fixed just yet. 

## tests for putoneinbucket
I havent written tests but everything seems to work well.
There were bugs, and I found them. 



