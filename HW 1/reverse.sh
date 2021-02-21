#!/usr/bin/env bash

function reverse(){
    local unknown=$1
    dirArray=()
    [ -d $unknown ] && {
	lst=`ls $unknown`
	for dir in $lst; do
	    dirArray+=( $dir )
	done
	
    }
    
    for (( idx=${#dirArray[@]}-1; idx>=0; idx-- )); do
	    echo "${dirArray[$idx]}"
	done
}

function main(){
    reverse $1
}

main $1
