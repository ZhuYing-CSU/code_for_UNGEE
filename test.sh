#!/bin/bash
# Test Program Files with examples
#
# Usage: ./test.sh code name
# ----------------------------------------

################################################################
# Help
################################################################
Help(){
    # Display the help menu
    echo "Test Program Files with examples"
    echo 
    echo "Syntax: ./test.sh [ -h | -c code]"
    echo "Options:"
    echo "-h    display this help menu"
    echo "-c    problem code"
}

################################################################
# Main Program
################################################################

#-----------------------------------------
# Read options from stdin
#-----------------------------------------
while getopts c:h: option;
do
    case $option in
        h) # display Help
            Help
            exit;;
        c) # init problem code
            problemCode=$OPTARG;;
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

#------------------------------
# Find the relevant problem
#------------------------------
programFile=$(find ./codes -name "${problemCode}*")
programFileName=${programFile%.cpp}

#------------------------------
# Generate test examples
#------------------------------
if [ $(python generator.py -c $problemCode) ];
then
    exit 1;
fi

#------------------------------
# Test the code file
#------------------------------
gcc  $programFile -o ${programFileName}.out # compile the code file
cat ./examples/${problemCode}.txt | ${programFileName}.out # test the program 
rm ${programFileName}.out # clean the executable file