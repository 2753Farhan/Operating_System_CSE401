#! /usr/bin/bash
# echo "Hello world"

# #system variable
# echo $BASH
# echo $BASH_VERSION
# echo $HOME
# echo $PWD
# echo The random value is $RANDOM


# #user variable:
# name=Shuvro
# echo The name is $name

# # 10val=10
# # echo value $10val


# #Take input from user:

# echo "Enter name : "
# read name
# echo "Entered name : $name"

# echo "Enter names: "
# read name1 name2 name3
# echo "Names : $name1 , $name2 , $name3"


# read -p 'username : ' user_var #to show the prompt and take input in a line
# echo "Hello $user_var"


# read -p 'username : ' user_var
# read -sp 'password : ' pass_var #here -sp makes the password silent
# echo "Hello $user_var"
# echo "your password is $pass_var"



# #using array to store values:

# echo "Enter names: "
# read -a names
# echo "Names : ${names[0]} ${names[1]}"

# echo "Enter name: "
# read                       #default input variable is REPLY
# echo "Names : $REPLY"

# # pass arguments to bash script
# echo $0 $1 $2 $3

# args=($@)

# echo ${args[1]} ${args[2]} ${args[3]}
# echo $@
# echo $#


#if statement

count=10

if [ $count > 9 ]
then 
    echo "condition is true"
fi