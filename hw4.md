# (DRAFT)

# Makeup Queue

You will create a C++ program that will simulate the scheduling and time it takes to apply makeup to actors when there is only one person applying makeups. 
Scheduling of processes in an operating system to simulate multitasking when there is only one processor (based on threads) is done similarly.
The fundamental data structure will be array-based queues.

## Input 

The input is a plan-text file, where each line is terminated with an end-of-line character.
Each line will identify the time of arrival of an actor or actress as well as the duration to apply his or her make up.
To simplify we will assume that the time and duration are given in minutes, where the initial time is 0 minutes.
Lines in the input file that start with the symbol `#` should be considered comments and therefore skipped.

Example 1:

    #person arrival duration
    Meredith  0 4
    Cristina  1 3
    Alex  2 1
    Izzie 2 2
    George  3 1
    Miranda 4 2
    Derek 5 3
    Burke 7 1
    Richard 7 1
    Jackson 8 1
    April 9 2
    Owen  10 1
    Arizona 12 2
    Callie  12 2
    Erica 13  1
    Mark 13 1
    Addison 14  3
    Teddy 14  1
    Amelia  18  2
    Lexie 20  2

Each line that is not a comment will have exactly three items: name, arrival, and duration. 
Such items will be separated by tab character.
There will not be empty lines in the input file but there may be any number of lines with comments.

## Theory

You must use arrays to simulate a circular queue.
The number of elements that the queue will contain is a parameter to the program.
There will be two scheduling policies: round-robin, and FIFO. 
Each scheduling policy most likely will produce different outcomes.

## Program specification

The main program should be called `upfront` and the syntax in which it will be tested is as follows:
`upfront "input=FILENAME;size=INTEGER;scheduling=SCHEDULE;quantum=NUMBER"`

The parameter `size` specifies the maximum number of items that the queue can contain. 

The parameter `scheduling` indicates the scheduling policy. Scheduling can be `FIFO` for first-in, first-out.
Scheduling can be `roundrobin` for round-robin policy.

The parameter `quantum` applies only to round-robin scheduling.

## Assumptions

** The input file can fit in main maimory (not larger than 10kb)
** Names of people are all letters; times are always numbers (non negative)
