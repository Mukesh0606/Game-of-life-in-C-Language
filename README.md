# Game-of-life-in-C-Language
This is a C Program for Game of life which uses file handling for both inout and output. And It also runs for 500 generations.

Question: 

Game of Life. Explained Below. Develop a Sequential Code for the Game. Ensure you use File I/O. "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
1. Any live cell with fewer than two live neighbors dies as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population.
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

Example 1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]


Answer:

In Main function, Opening the input file in read mode and output file in write mode. It uses Fscanf function to read input string from file and Gives output in different file (Gameoflife Output).

Input file: Gameoflife input1

C file: Gameoflife1.c

Output file: Gameoflifeoutput

Compile: gcc -o Gameoflife Gameoflife1.c

Run: ./Gameoflife.
