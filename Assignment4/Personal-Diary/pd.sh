#!/bin/bash
###
 # @Author: Ou Yixin
 # @Date: 2021-05-06 21:31:06
 # @LastEditors: Ou Yixin
 # @LastEditTime: 2021-05-06 22:00:16
 # @Description: 
 # @FilePath: /Personal-Diary/pd.sh
### 
make
echo "******************************************"
echo "Welcome to your diary!"
echo "Here are 4 commands for you to use:"
echo "\"pdadd yyyy-mm-dd\""
echo "\"pdremove yyyy-mm-dd\""
echo "\"pdshow yyyy-mm-dd\""
echo "\"pdlist\" or \"pdlist yyyy-mm-dd yyyy-mm-dd\""
echo "******************************************"
echo "Please enter your command:"
read value1 value2 value3
if [ $value1 == "pdadd" ]
then
    ./pdadd $value2
elif [ $value1 == "pdremove" ]
then
    ./pdremove $value2
elif [ $value1 == "pdshow" ]
then
    ./pdshow $value2
elif [ $value1 == "pdlist" ]
then
    if [ -z $value2 ]
    then
        ./pdlist
    else
        ./pdlist $value2 $value3
    fi
else
    echo "Wrong command. Please Try again."
    bash ./pd.sh
fi