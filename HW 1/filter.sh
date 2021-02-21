#!/usr/bin/env bash

arr=()
avg=0
function average(){
    local unknown=$1
    local total=0
    len=0
    [ -d $unknown ] && {
	lst=`ls $unknown`
    }
    for file in $lst; do
	arr+=( $unknown/$file )
        #len=${#arr[@]}
    done
    
    for file in ${arr[@]}; do
	file_info=`ls -l $file`
	set -- $file_info
	file_size=$5
	total=$((file_size + total))
    done
    len="${#arr[@]}"
    avg=$((total / len))
   	  
}

function filter(){
    local unknown=$1
    [ -d $unknown ] && {
    lst=`ls $unknown`
    for file in ${arr[@]}; do
	file_info=`ls -l $file`
	set -- $file_info
	file_size=$5
	if (( $file_size > $avg )); then
	    echo $(basename $file)
	fi
    done
    }
    
}

function main(){
    average $1
    filter $1
}

main $1
