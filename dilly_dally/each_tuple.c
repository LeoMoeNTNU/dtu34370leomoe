int each_tuple(
    int* array,
    int index,
    int max_index,
    int lowest_value,
    int max_value,
    void (*f)(int*,int)
){
    if(lowest_value>max_value)return 0;
    if(index==max_index){
        f(array,max_index);
        return 0;
    }
    for(int i=lowest_value;i<max_value;i++){
        array[index]=i;
        each_tuple(array,index+1,max_index,i+1,max_value,f);
    }
}

//This doesnt yet deal with the array being full. 

//I think I could do this with a goto. 