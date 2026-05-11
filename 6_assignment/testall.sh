for f in ./Instances/CloudComp_instances/*.txt; do [ -f "$f" ] || continue; name=$(basename "$f"); echo "$name"; make run ARG1="$f" ARG2="sols/$name" ARG3=10; done

