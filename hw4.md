# hw4 Makeup Queue

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
    Alex  8 1
    Izzie 8 2
    George  9 1
    Miranda 10 2
    Derek 11 3
    Burke 13 1
    Richard 13 1
    Jackson 14 1
    April 15 2
    Owen  16 1
    Arizona 18 2
    Callie  18 2
    Erica 19  1
    Addison 20 3
    Mark 20  2
    Teddy 20  1
    Amelia  24  2
    Lexie 26  2

Each line that is not a comment will have exactly three items: name, arrival, and duration. 
Such items will be separated by one tab character (that is, `\t`).
There will not be empty lines in the input file but there may be any number of lines with comments.

## Theory

You must use arrays to simulate a circular queue.
The number of elements that the queue will contain is a parameter to the program.
There will be two scheduling policies: round-robin, and FIFO. 
Each scheduling policy most likely will produce different outcomes.

You are encouraged to write your program so that it processes each line of the input file only once as it is reading the file. 


## Program specification

The main program should be called `upfront` and the syntax in which it will be tested is as follows:

`upfront "input=FILENAME;size=INTEGER;scheduling=SCHEDULE;quantum=NUMBER"`

The parameter `input` specifies the name of the input file.

The parameter `size` specifies the maximum number of items that the queue can contain. 

The parameter `scheduling` indicates the scheduling policy. Scheduling can be `fifo` for first-in, first-out.
Scheduling can be `roundrobin` for round-robin policy.

The parameter `quantum` is an integer greater than zero, and it applies only to round-robin scheduling. It will always be there with a number but such information can be just ignored for `fifo` scheduling (or for the extra credit option).

Example of program calls:

`upfront "input=gray.txt;size=22;scheduling=fifo;quantum=4"`

## Output

Your program will output to the console (such as via cout, or printf) with four columns separated by one tab character (except for the cases of `waiting` and `relax`).
The first column is the time, the second is the name of the person, the third is the duration, and the fourth is the status.
Your program must follow the output format exactly to facilitate automated grading (and to avoid failing test cases due to things such as output of an empty line at the end).

Output for the input example.  (output is partial, just for illustration purposes).

    0   Meredith    4   makeup
    1   Meredith    4   makeup
    2   Meredith    4   makeup
    3   Meredith    4   completed
    4   Cristina    3   makeup
    5   Cristina    3   makeup
    6   Cristina    3   completed
    7   waiting
    8   Alex    1   completed
    9   Izzie   2   makeup
    10   Izzie   2   completed
    11  relax
    12  relax
    13  George  1   completed
    
## Assumptions

* The input file can fit in main maimory (not larger than 10kb) and it will always have at least one person to work with.
* Names of people are all letters only and exactly one word no bigger than 156 characters
* Arrival and duration times are always numbers (non negative)
* The order of processing is the order in which people are listed in the input file
* There will not be repeated names in the input file
* The start of applying makeup is right at the beginning of the arrival time (unless that the person is waiting their turn)
* The arrival time of a person listed at line n will never be smaller than the arrival time of persons listed at lines before line n
* Sharing test cases does not imply that you will do the extra-credit option

## Requirements

* You must build your own array-based circular queue so that the `size` parameter matches the number of elements that the queue can hold. 
* For round-robin scheduling, only the number of persons that fit in the queue are given makeups (parameter `size`). If a person is done before its quantum expires, then your program needs to switch to the next available person instead of wasting time of the person that applies the make up.
* The person that applies makeup takes a 2-minutes `relax` break every time that he or she has completed makeup for four persons.
* When the person that applies makeup has nobody to work with, the line should indicate `waiting`
* Place your codes in a folder named: `hw4` (Failure to do so will cause your program to have a zero grade due to inability for doing automated grading).
* Your program should not produce any unexpected output when it is doing intermediate calculations because doing so will interfere with automated grading and some test cases will fail.
* You can not assume a maximum number of lines in the input file.

## Extra Credit

The 10 points extra credit is for handling a scheduling that will be called `shortfifo` that will pick the shortest duration person in the cases where 2 or more persons have the same arrival time. The example 1 above under `shortfifo` scheduling would have different scheduling than `fifo` scheduling only for the cases of Teddy, Mark, and Addison. Teddy would go before Mark, and Addison would go after Mark. 

One condition to get any extra credit added up beyond 100 points (scale is 0-100), is to share at least one test case either via the google-group, or via adding a file into the [syllabus](https://github.com/uhcs2320/syllabus) github repository (name the file with prefix `test4-` such as `test4-anna1.txt`).
