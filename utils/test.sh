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
    echo "-n    the number of test example(s)"
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
        n) # init problem code
            testNum=$OPTARG;;
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

if [ -z $testNum ];
then
    testNum=100
fi

#------------------------------
# Find the relevant problem
#------------------------------
programFile=$(find ./codes -name "${problemCode}*")
programFileName=${programFile%.c}

#------------------------------
# Generate test examples
#------------------------------
echo $testNum
if [ $(python ./utils/generator.py -c ${problemCode} -n ${testNum}) ];
then
    exit 1;
fi

#------------------------------
# Test the code file
#------------------------------
cc  $programFile -o ${programFileName}.out # compile the code file
cat ./examples/${problemCode}.txt | ${programFileName}.out # test the program 
rm ${programFileName}.out # clean the executable file