# hw5 Unfair sort, due: Friday, April 22, 11:00 p.m.

You will create a C++ program that will simulate the selection of candidates to "University of Fake Admissions" via sorting.
In real universities, selection of applicants follows a well-thought procedure created and revised by experts.
This homework assignment is about an an arbitrary selection criteria that was designed at random 
by a person that has never been involved in admisisons (and probably will never be). 
Hence, it is extremely unlikely that the method presented here reflects reality (with the exception of sorting based on a score).
The fundamental data structure concept to practice is sorting.

## Input 

The input is a plain-text file, where each line is terminated with an end-of-line character.
Each line will identify a candidate to join the fake university. 
Each line will contain the person name, GPA, QAT score (ficticious standardized test score with range of 0 to 600).
Lines in the input file that start with the symbol `#` should be considered comments and therefore skipped.

Example 1:

    # candiates
    Meredith  4  599  female  domestic
    Cristina  4  600  female  domestic
    Alex  2.8  200  male  domestic
    Izzie 1.8  200  female  domestic
    George  1.9  200  unspecified  domestic
    Miranda  1.0  200  female  domestic
    Derek  1.1  300  male  domestic
    Burke  1.3  100  male  domestic
    Richard  1.3 101  male  domestic
    Jackson  1.4 100  male  domestic
    April  1.5  200  female  farmer
    Owen  1.6  100  male  retired
    Arizona  1.8 202  prefernottoanswer domestic  
    Callie  1.8 222  prefernottoanswer domestic
    Erica 1.3 202  prefernottoanswer domestic
    Addison 1.8 209  female domestic
    Mark 1.9 202  male domestic
    Teddy 3.8 202  prefernottoanswer domestic
    Amelia  2.4 404 female  domestic
    Lexie 2.6  200  female  withdrawn
    MacFarlane  3.9  400  x australian

Each line that is not a comment will have exactly five items: name, GPA, QAT score, gender, and note. 
Such items will be separated by one tab character (that is, `\t`).

(1) The person name. They will not be repeated within the same file.

(2) The GPA is a number in the range of 0.0 to 4.0. It may contain at most 1 digit after the decimal point.

(3) The QAT score is a number in the range of 0 to 600. It will not have decimals.

(4) The gender is exactly one word (letters only).

(5) The note is exactly one word (letters only).

There will not be empty lines in the input file but there may be any number of lines with comments.

## Theory

The number of candidates to accept is indirectly determined by a `pick` parameter to the program.
You are encouraged to write your program so that it reads the input file only once. 
Failure to do so is an indication that your code design needs to be revised.

## Program specification

The main program should be called `unfair` and the syntax in which it will be tested is as follows:

`unfair "input=FILENAME;pick=INTEGER"`

The parameter `input` specifies the name of the input file.

The parameter `pick` is an integer (greater than zero) that specifies how many iterations to do at each round of selection of candidates,
and it also specifies how many candidates to choose from each group at each round (there are 3 groups).

All candidates are to be sorted from highest score to lowest score. 
The order in which individuals are listed is from high score to low score.

For the iteration 1, `score` is to be calculated as follows: score = (100) * GPA + QAT

At iteration 1, the program will output `n` individuals having the highest score that are `female` (this is the first group), 
followed by `n` individuals having the highest score that are `male` (this is the second group), 
followed by `n` individuals having the highest score that are neither `male` nor `female` (this is the third group). 
In iteration 1, `n` is the value of the parameter `pick`.

For the example input test file, this would be the output after iteration 1 (pick value of 3).

    Cristina
    Meredith
    Amelia
    Alex
    Derek
    Mark
    MacFarlane
    Teddy
    Callie

At iteration 2, `score` is to be calculated as follows: score = (90) * GPA + QAT. 

At iteration 2, `n` is the value of the parameter `pick` minus 1.
If `n` reaches zero at any iteration, then no more selection of individuals is done, and the program should end normally 
(that is, without errors).

Then the selection of `n` individuals at iteration 2 is done in a similar way: `n` individuals that are `female`, 
followed by `n` individuals that are `male`, 
followed by `n` individuals that are neither `male` nor `female`. 

For the example input test file, this would be the continuation of the output (produced during iteration 2).

    Lexie
    Addison
    Owen
    Jackson
    George
    Arizona


At iteration 3, `score` is to be calculated as follows: score = (80) * GPA + QAT. 

At iteration 3, `n` is the value of the parameter `pick` minus 2.
Then the selection of individuals at iteration 3 is done in a similar way.

For the example input test file, this would be the continuation of the output (produced during iteration 3), 
and it is also the last part of output.

    Izzie
    Richard
    Erica

And so on and so forth, until there are no more individuals to be chosen (because `n` will eventually reach zero). 
Note that at iteration 11 (or higher), the score is to be calculated as follows: score = (0) * GPA + QAT. 

Example of program calls:

`unfair "input=g.txt;pick=4"`

## Output

Your program will output to the console (such as via cout, or printf) the names of the admitted students, one per line.
Each line must be in the format of person name followed by end-line character; for example: `cout << name << endl;` .
Your program must follow the output format exactly to allow for automated grading 
(and to avoid failing test cases due to things such as output of an empty line at the end).

Output for the input example with value of `3` for the parameter `pick`.

    Cristina
    Meredith
    Amelia
    Alex
    Derek
    Mark
    MacFarlane
    Teddy
    Callie
    Lexie
    Addison
    Owen
    Jackson
    George
    Arizona
    Izzie
    Richard
    Erica


## Assumptions

* The input file can fit in main memory (not larger than 100Kb) and it will always have more candidates than those to be accepted.
* Names of people are all letters only and exactly one word no bigger than 156 characters (minimum of 1)
* Sharing test cases does not imply that you will do the extra-credit option

## Requirements

* Place your codes in a folder named: `hw5` (Failure to do so will cause your program to have a zero grade due to inability for doing automated grading).
* Your program should not produce any unexpected output when it is doing intermediate calculations because doing so will interfere with automated grading and some test cases will fail.
* You can not assume a maximum number of lines in the input file.

## Extra Credit

The 10 points extra credit is for handling cases when there are not enough candidates on the third group (that is, not male, not female). 
When coming up short of individuals for the third group, 
individuals are to be selected from the highest score individuals not having `domestic` in the `note` column.

The condition to get any extra credit added up beyond 100 points (scale is 0-100), 
is to share at least one test case via adding a file into the [syllabus](https://github.com/uhcs2320/syllabus) github 
repository (name the file with prefix `test5-` such as `test4-dallas.txt`).

## Sorting Method

* You must code your own sorting method. It is not allowed to utilize existing sorting methods already implemented elsewhere. 
* There are several choices of what method you will implement.
* Your choice of what method you will implement has to be set no later than 2 days before the due date. Otherwise there is a penalty of 10 points.
* The table below shows the selections of sorting algorithms by most students in the class (the ones that show to class, that is)

|Quicksort|Heapsort|Mergesort|InsertSort|
|:---:|:---:|:---:|:---:|
|Angela|Vincent|Erick  |Jason|
|Chen  |Jesus  |Justin |Minnah|
|Nolan |Steve  |Harshin|Julian|
|Xin   |Nelson |       |Areka|
|April |Joshua |       |Erin|
|Josh  |
