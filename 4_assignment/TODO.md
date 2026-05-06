# check if it works for time as well. This is super important. 
# then check that it works with contains as well. 
I haven't thought about the order so I will just try with time first. 
# make it actually use contains...

# I am fixing contains, but when I am done with contains, I also need to check the other tests, in tests\testinsert_into_tl.c

# I can just import the julia code "for windows" and use it. 
I have a script in lab1 in Windows that works fine. 


# I will have to insert false on debugging in the main function a lot!


# The reason that insert doesnt work is because it doesnt input a pointer. 
Because it doesnt input a pointer, I can't modify a pointer inside of it. 
There are several ways out of this: 
1. Modify several functions so that it works correctly. 
    What I mean by that, is to make the init return a pointer. 
    After it has returned a pointer, I can use that everywhere and then the stuff will work fine. 
2. modify
