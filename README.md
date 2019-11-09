# Basic-calculator-for-Linux-systems
# calculla
simple calculator for better understanding working of modern interpreters and compilers &amp; a good linux command for calculating arithmatic operations in bash scripts

there are a few good commands in linux ( bc or expr ) for doing arithmatic caluclations for bash scripts but none of them provides the facility of performing mathematical operations with easy to use syntax . 

"calculla" is very easy to use in bash scripts .

this project will also help those students who want to understand functionanility of interpreters. 

#How to use calculla?

3 ways;

# first:
calculla ( that's it !)

# second:

calculla [expression]
example:

calculla 5*4-2/5*100+6

# third
for using calculla in bash scripts

output=$(calculla 1+2) 
or
output=$(calculla $1+$2+$3) for positional arguments

# cognition
to better understand how " calculla " works , remove the comments preceding cout object in the program . This will help in understanding the program flow . 
