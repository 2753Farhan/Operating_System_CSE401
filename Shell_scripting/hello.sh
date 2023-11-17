! /usr/bin/bash
echo "Hello world"

#system variable
echo $BASH
echo $BASH_VERSION
echo $HOME
echo $PWD
echo The random value is $RANDOM


#user variable:
name=Shuvro
echo The name is $name

# 10val=10
# echo value $10val


#Take input from user:

echo "Enter name : "
read name
echo "Entered name : $name"

echo "Enter names: "
read name1 name2 name3
echo "Names : $name1 , $name2 , $name3"


read -p 'username : ' user_var #to show the prompt and take input in a line
echo "Hello $user_var"


read -p 'username : ' user_var
read -sp 'password : ' pass_var #here -sp makes the password silent
echo "Hello $user_var"
echo "your password is $pass_var"



#using array to store values:

echo "Enter names: "
read -a names
echo "Names : ${names[0]} ${names[1]}"

echo "Enter name: "
read                       #default input variable is REPLY
echo "Names : $REPLY"

# pass arguments to bash script
echo $0 $1 $2 $3

args=($@)

echo ${args[1]} ${args[2]} ${args[3]}
echo $@
echo $#


#if statement

count=10

if [ $count > 9 ]
then 
    echo "condition is true"
fi

word=a 

if [[ $word == "b"]]
then 
    echo "condition b is true"
elif [[ $word == "a" ]]
then
    echo "condition a istrue"
else 
    echo "condition is false"
fi


# file test operators:
# -e : flag used for checking whether the file exists or not
# -f : whether file exists it is a regular file or not
# -d : flag used for checking whether the directory exists or not
# -b :
# -c :
# -s : flag used for checking whether the file is empty or not
# -r : flag used for checking whether the file have read permission or not
# -w : flag used for checking whether the file have write permission or not
# -x : flag used for checking whether the file have execution permission or not


echo -e "Enter the name of the file : \c"
read file_name 

if [ -f $file_name ]
then
    echo "$file_name found"
else
    echo "$file_name not found"
fi 



# append output to the end of file

echo -e "Enter the name of the file : \c"
read file_name

if [ -f $file_name ]
then 
    if [ -w $file_name ]
    then
        echo "Type some text data. To quit press cntrl+D"
        cat >> $file_name
    else
        echo "The file do not have write permissiions"
    fi
else
    echo "$file_name not exists"
fi


#And operator  :

age=25

if [ $age -gt 18 ] && [ $age -lt 30 ]
then 
    echo "vlaid age"
    else
    exho "age not valid"
fi   


if [ $age -gt 18 -a $age -lt 30 ]
then 
    echo "vlaid age"
    else
    exho "age not valid"
fi 

if [[ $age -gt 18 && $age -lt 30 ]]
then 
    echo "vlaid age"
    else
    exho "age not valid"
fi 

#OR operator  :

# || instead of &&
# -o instead of &&

num1=20.5
num2=5

echo $(( num1 + num2 ))
echo $(( num1 - num2 ))
echo $(( num1 * num2 ))
echo $(( num1 / num2 ))
echo $(( num1 % num2 ))


echo $(expr $num1 + $num2 )
echo $(expr $num1 - $num2 )
echo $(expr $num1 \* $num2 )
echo $(expr $num1 / $num2 )
echo $(expr $num1 % $num2 )

#bc tool

num1=20.5
num2=5

echo "$num1+$num2" | bc
echo "$num1-$num2" | bc
echo "20.5*5" | bc
echo "scale=20;20.5/5" | bc
echo "20.5%5" | bc

num=4
echo "scale=2;sqrt($num)" | bc -l

##case statement

vehicle=$1

case $vehicle in
    "car" )
        echo "Rent of $vehicle is 100 dollar" ;;
    "bicycle" )
        echo "Rent of $vehicle is 80 dollar" ;;
    * )
        echo "Unknown vehicle" ;;
esac




echo -e "Enter a charecter: \c"
read char

case $char in
    [a-z] )
        echo "User entered $value a to z" ;;
    [A-Z] )
        echo "User entered $value A to Z" ;;
    [0-9] )
        echo "User entered $value a to z" ;;
    ? )
        echo "User entered $value special character" ;;
    * )
        echo "Unknown value"
# esac

##Array

os=('ubuntu' 'windows' 'kali')
os[3]='mac'
echo "${os[@]}"
echo "${os[1]}"
echo "${os[3]}"

echo "${#os}"

unset os[2] #remove elements
echo "${os[@]}"


#while loop 

n=1

while [ $n -le 10 ]
do 
    echo "$n"
    n=$(( n+1 ))
done
n=1

while (( $n <= 10 )) 
do 
    echo "$n"
    (( ++n ))
    sleep 1
done
n=1
while (( $n <= 3 )) 
do 
    echo "$n"
    (( ++n ))
    gnome-terminal &
done

## Reading a file

while read p 
do 
    echo $p
done < hello.sh


cat hello.sh | while read p
do
    echo $p
done


while IFS= read -r line #prevents / to be interpreted
do 
    echo $line
done < hello.sh  #we can use file path here also 

## Until loop

n=1

until [ $n -ge 10 ]
do
    echo $n
    n=$(( n+1 ))
done

## For loops

for i in 1 2 3 4 5
do 
    echo $i
done

for i in {1..10}
do 
    echo $i
done

for i in {1..10..2}
do 
    echo $i
done

for (( i=0;i<5;i++ ))
do 
    echo $i
done

#for loop for using commands

for command in ls pwd date
do 
    echo "------------$command---------------"
    $command
done

#for printing all the directories

for item in *
do 
    if [ -d $item ]
    then
        echo $item
    fi
done

## Select loop 
select name in mark john tom ben
do 
    echo "$name selected"
done


select name in mark john tom ben
do 
    case $name in
    mark)
        echo mark selected
        ;;
    john)
        echo john selected
        ;;
    tom)
        echo tom selected
        ;;
    ben)
        echo ben selected
        ;;
    *)
        echo "Error please provide the no. between 1...4"
    esac
done