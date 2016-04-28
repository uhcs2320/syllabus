# hw6 Shortypath, due: Tuesday, May 03, 11:00 p.m.

You will create a C++ program that will simulate the awarding of scholarships to candidates to "The University of Fake Scholarships"
via visiting cities in the state of Texas through one or more shortest-path destinations.
In real universities, awarding of scholarships applicants follows a well-thought procedure created and revised by experts.
This homework assignment is about an an arbitrary method to award scholarships (completely made up).
The fundamental data structure concept to practice is graphs (via finding shortest path).

## Input

The input is a set of three plain-text files: students, cities, destinations.

### Input: students

The students input-file contains candidates for scholarships.

Example students input-file:

      # students
      149	Luther	Abiline
      200	Strucker	Abiline
      218	Werner	Abiline
      8	Alisha	Amarillo
      134	Kebo	Amarillo
      191	Robert	Amarillo
      194	Rosalind	Amarillo
      14	Andrew	Austin
      95	Gordon	Austin
      125	Jiaying	Austin
      68	Daniel	Beaumont
      182	Palamas	Beaumont
      203	Sunil	Beaumont
      44	Calvin	Brownsville
      92	Glenn	Brownsville
      101	Hobes	Brownsville
      206	Talbot	Brownsville
      20	Anne	CollegeStation
      23	Antoine	CollegeStation
      86	Garret	CollegeStation
      107	Ian	CorpusChristi
      146	Lincoln	CorpusChristi
      170	Mike	CorpusChristi
      212	Victoria	CorpusChristi
      32	Bobbi	Dallas
      104	Hunter	Dallas
      155	Mack	Dallas
      83	Fitz	DelRio
      119	Jemma	DelRio
      197	Simmons	DelRio
      65	Daisy	ElPaso
      98	Grant	ElPaso
      140	Leo	ElPaso
      161	May	Houston
      215	Ward	Houston
      53	Catty	Laredo
      131	Katty	Laredo
      164	Melinda	Laredo
      185	Phil	Laredo
      38	Calista	Lubbock
      47	Cat	Lubbock
      50	Catherine	Lubbock
      59	Chyler	McAllen
      71	David	McAllen
      116	James	McAllen
      122	Jeremy	McAllen
      56	Charles	Midland
      128	Kara	Midland
      137	Krystof	Midland
      77	Elsa	Odessa
      143	Lexie	Odessa
      152	MacFarlane	Odessa
      176	Olaf	Odessa
      2	Addison	SanAngelo
      11	Amelia	SanAngelo
      158	Mark	SanAngelo
      209	Teddy	SanAngelo
      29	Arizona	SanAntonio
      41	Callie	SanAntonio
      80	Erica	SanAntonio
      26	April	Texarkana
      113	Jackson	Texarkana
      179	Owen	Texarkana
      188	Richard	Texarkana
      35	Burke	Victoria
      74	Derek	Victoria
      173	Miranda	Victoria
      5	Alex	Waco
      89	George	Waco
      110	Izzie	Waco
      17	Anna	WichitaFalls
      62	Cristina	WichitaFalls
      167	Meredith	WichitaFalls


The columns on the students file are:

1. The person name. They will not be repeated.

2. A score is a number in the range of 0 to 1000. It will not have decimals.

3. The City where the student lives.

### Input: Cities

The cities input-file contains the distance between cities.
Each line will identify distance between two cities.
The information on this file will correspond to a weighted graph (undirected).

Example cities input-file:

      # city1, city2, distance
      ElPaso  DelRio 428
      ElPaso  Odessa 284
      ElPaso   Midland  305
      DelRio   SanAngelo   156
      DelRio   Laredo   178
      DelRio   Odessa   261
      DelRio   SanAntonio  156
      Laredo   SanAntonio  155
      Laredo   McAllen  148
      McAllen  Brownsville 59
      Brownsville CorpusChristi  164
      CorpusChristi  Laredo   147
      CorpusChristi  Victoria 86
      CorpusChristi  SanAntonio  143
      Victoria SanAntonio  117
      Victoria Houston  125
      SanAntonio  Austin   79
      SanAntonio  Houston  197
      Houston  Austin   165
      Houston  CollegeStation 98
      Houston  Beaumont 84
      Beaumont CollegeStation 157
      CollegeStation Waco  91
      CollegeStation Austin   107
      CollegeStation Texarkana   272
      Texarkana   Beaumont 262
      Texarkana   Dallas   179
      Dallas   Waco  95
      Dallas   WichitaFalls   138
      Dallas   Abiline  181
      Austin   Waco  102
      Waco  Abiline  184
      Abiline    SanAngelo 89
      SanAngelo   Austin   205
      SanAngelo   Odessa   132
      Odessa   Midland  22
      Midland  Abiline  148
      Midland  Lubbock  117
      Lubbock  Amarillo 124
      Lubbock  WichitaFalls   209
      Lubbock  Abiline  163
      Amarillo WichitaFalls   143
      WichitaFalls   Abiline  152

The columns on the cities file are:

1. The name of a city.

2. The name of another city.

3. The distance between the two cities.


### Input: Destinations

The destinations input-file contains a list of pairs of cities.
There will be at least one pair of cities in the file (that is, at least one line).

Example destinations input-file:

      # start city, end-city
      ElPaso  Laredo

The columns on the file are:

1. The city from which to **start**.

2. The **end** city.

## Program specification

The main program should be called `shortypath` and the syntax in which it will be tested is as follows:

`shortypath "city=FILENAME_CITIES;people=FILENAME_STUDENTS;visit=FILENAME_DESTINATIONS"`

The parameter `city` specifies the name of the cities input-file.

The parameter `people` specifies the name of the students input-file.

The parameter `visit` specifies the name of the destinations input-file.

Your program will work with each pair of cities in the destinations input-file (basically, one line at a time).
Each line in the destinations input-file identifies two cities: **start** city and **end** city.
The shortest-path from such two cities needs to be determined via a shortest-path algorithm: Dijkstra's.
You must code your own implementation of Dijkstra's algorithm.

For the example input files above, the shortest-path for the two cities in the destinations input-file is:

      ElPaso   -->  DelRio -->   Laredo

Next, all cities in the path are to be *visited* from the **start** city to the **end** city, and at each city the student with the top score (of that city) is offered an scholarship.
The action of a student being offered a scholarship is reflected by your program output of the student name.

For the shortest-path above and the example students input-file, your program would output:

      Leo
      Simmons
      Phil

Only one student is to be selected from each city, regardless of how many times the city is visited.

### Example 2

Example of a different destinations input-file:

      # start city, end-city
      ElPaso  DelRio
      ElPaso  McAllen

For the this example 2, your program would output:

      Leo
      Simmons
      Phil
      Jeremy

The first two students were output when visiting the cities along the path from ElPaso to DelRio.
The other two students were output when visiting the cities along the path from ElPaso to McAllen
(ElPaso and DelRio are visited again but no student is selected because one was previously selected already for each city).

## Example test cases

* Only one pair of cities in the destinations input-file
   * Start city and end city are directly connected (such as in example 2 for the path from ElPaso to DelRio).
   * Start city and end city are directly connected but the shortest-path is not through the edge that connects them directly
      * Example: From ElPaso to DelRio but when the distance indicated in the input file for these two cities is much larger, such as 2000.
      The shortest-path would not be through the direct edge of such two cities but instead through other cities (such as Odessa in the example data here)
   * Start city and end city are not directly connected
      * Start city: ElPaso, end city: Texarkana.
      * Start city: Amarillo, end city: Brownsville.
* Two pairs of cities in the destinations input-file
   * The exact same cities are listed twice:  
      `Amarillo Brownsville`  
      `Amarillo Brownsville`
   * The exact same cities are listed twice but in opposite order.  
      `Amarillo Brownsville`  
      `Brownsville Amarillo`
   * There is a city in common:  
   `Amarillo Brownsville`  
   `Amarillo Austin`
   * Other examples:  
   `Amarillo Brownsville`  
   `Laredo Texarkana`
* More than two pairs of cities in the destinations input-file
   * Example A:  
   `Amarillo Brownsville`  
   `CorpusChristi ElPaso`  
   `ElPaso Beaumont`  
   `Victoria Texarkana`
   * Multiple lines of the same cities:  
   `Brownsville Lubbock`  
   `Brownsville Lubbock`  
   `Brownsville Lubbock`  
   `Brownsville Lubbock`  

# Output

Your program will output to the console (such as via cout, or printf) the names of the students, one per line.
Each line must be in the format of person name followed by end-line character; for example: `cout << name << endl;`

Your program must follow the output format exactly to allow for automated grading
(and to avoid failing test cases due to things such as output of an empty line at the end).


## Assumptions

It is OK for you to assume the following:
* Names of people, and names of cities will contain letters only, and the names will be exactly one word (of at least one letter but no bigger than 156 letters)
* There will always be enough candidates to choose from at every city.

* About the input files:
  * Each input file can fit in main memory (not larger than 100Kb).
  * Lines are terminated with an end-of-line character.
  * Lines that start with the symbol `#` should be considered comments and therefore skipped.
  * Items (that is, columns) will be separated by one tab character (namely, `\t`).
  * There will not be empty lines in any input file but there may be any number of lines with comments.
  * Input data will be valid. For example, there will always be at least one student per city.

## Requirements

* Place your codes in a folder named: `hw6` (Failure to do so will cause your program to have a zero grade due to inability for doing automated grading).
* Your program should not produce any unexpected output because doing so will interfere with automated grading and some test cases will fail.
* You can not assume a maximum number of lines in the input file.

## Extra Credit

No extra credit. See hw7 if you're interested in a homework assignment for extra credit.

## Last note

Maybe-useful map for the sample data in this assignment.

![Texas Cities, subset](http://www.bls.gov/regions/southwest/images/18795.png)
