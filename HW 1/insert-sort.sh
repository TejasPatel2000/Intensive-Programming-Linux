#!/usr/bin/env bash

function sortArray(){
    local numArray=()
    for arg in "$@"; do
	numArray+=($arg)
    done
    	
    for((i=1;i<${#numArray[@]};i++)); do
	j=$i-1
	temp=${numArray[$i]}
	while((j>=0 && numArray[j]>temp)); do
	    numArray[$j+1]=${numArray[$j]}
	    j=$j-1
	done
	numArray[j+1]=$temp
    done
    echo "${numArray[@]}"
}


sortArray $@
