# Optional Homework7 Pathless, due: Monday, May 09, 11:00 a.m.

This homework assignment is **optional**. 
If you decide to go for it, and the grade is better than the lowest grade of your other homeworks (except hw0), 
then the grade of hw7 will replace such lowest grade.

This homework assignment is almost the same as hw6. 
Please refer to hw6 for details on imput files.

## Program specification

The main program should be called `pathless` and the syntax in which it will be as follows:

`pathless "city=FILENAME_CITIES;people=FILENAME_STUDENTS;visit=FILENAME_DESTINATIONS"`

The parameters are exactly the same as in hw6.

Your program will work exactly in the same way as hw6 when the input file contains exactly one line (with start, and end cities).
Hence, example 1 in hw6 will work exactly in the same way.

### What is different?

After your program traverses the shortest-path to find students that will receive scholarships 
(and the students have been output, if any), the edges of such path are to be removed from the graph.

In the example 1, both the edge that connect ElPaso with DelRio, 
and the edge that connects DelRio with Laredo will be removed from the graph.

### Example 2

Example of a destinations input-file that has repeated lines:

      ElPaso  Laredo
      ElPaso  Laredo

For the example students input-file and example graph, your program would outpu:

      Leo
      Simmons
      Phil
      Olaf
      Teddy
      Jiaying
      Erica

The first three are from the path from ElPaso to Laredo (via DelRio). 
The rest are from the shortest path from ElPaso to Laredo after two edges are removed from the graph; 
the path happens to go through Odessa, SanAngelo, Austin, and SanAntonio.

## Example test cases

They would be similar to those in hw6 
but your program likely will not be tested with test cases that give exactly the same output than that of hw6.

# Output

The format of the output will be the same as in hw6.

## Assumptions

Same as those in hw6.

## Requirements

* Place your codes in a folder named: `hw7` (Failure to do so will cause your program to have a zero grade due to inability for doing automated grading).
* Your program should not produce any unexpected output because doing so will interfere with automated grading and some test cases will fail.
* You can not assume a maximum number of lines in the input file.
