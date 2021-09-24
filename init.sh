#!/bin/bash
# Create the problem Code using template
#
# Usage: ./init.sh code name
# ----------------------------------------

################################################################
# Help
################################################################
Help(){
    # Display the help menu
    echo "Create the problem Code using template"
    echo 
    echo "Syntax: ./init.sh [ -h | -c code -n name]"
    echo "Options:"
    echo "-h    display this help menu"
    echo "-c    problem code"
    echo "-n    problem name"
}

################################################################
# Main Program
################################################################

#-----------------------------------------
# Read options from stdin
#-----------------------------------------
while getopts c:n:h: option;
do
    case $option in
        h) # display Help
            Help
            exit;;
        c) # init problem code
            problemCode=$OPTARG;;
        n) # init problem name
            problemName=$OPTARG;;
        \?) # display error message
            echo "Error: Invalid option"
            exit 1;
    esac
done

#------------------------------
# Checking necessary arguments
#------------------------------
if [ -z $problemCode ];
then
    echo "Argument -c (Problem Code) missed"
    exit 1;
fi

if [ -z $problemName ];
then
    echo "Argument -n (Problem Name) missed"
    exit 1;
fi

#------------------------------
# Create the code file
#------------------------------
cp ./codes/template.cpp ./codes/${problemCode}_${problemName}.cpp