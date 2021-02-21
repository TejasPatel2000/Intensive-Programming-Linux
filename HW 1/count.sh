#!/usr/bin/env bash

function traverse(){
    local unknown=$1
    [ -d $unknown ] && {
	b=$(basename $unknown)
	echo $b
	lst=`ls $unknown`
	for x in $lst; do
	    traverse $unknown/$x
	done
    }
	
}

function count(){
    IFS = ' '
    local unknown=$1
    lst=`ls $unknown`
    declare -A COUNT_ELEMENTS
    for cmds in $lst; do
	firstletter=${cmds:0:1}
	if [[ $firstletter = [a-zA-Z] ]]; then    
	    if [[ ${COUNT_ELEMENTS[$firstletter]} ]]; then
		((COUNT_ELEMENTS[$firstletter]++))
	    elif [[ $firstletter == [a-zA-Z] ]]; then
		COUNT_ELEMENTS[$firstletter]=1
	    fi
	fi
  
    done
    for letter in {a..z}; do
	echo "$letter ${COUNT_ELEMENTS[$letter]}"
    done
    
    #For Loop to print key and value
   # for KEY in "${!COUNT_ELEMENTS[@]}"; do
#	echo "$KEY ${COUNT_ELEMENTS[$KEY]}"
 #   done	
}


count /bin

