#echo $1
#make run ARG1=Instances/$1 ARG2=sols/$1 ARG3=10
make program
for f in Instances/*.sop; do
    name=$(basename "$f")
    echo "$name"
    make run ARG1="Instances/$name" ARG2="sols/$name" ARG3=15
done

