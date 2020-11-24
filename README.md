#K-Nearest Neighbors
#[INFO]:This code only read .csv format.
	Read 150 data from .csv file. ! it's fixed
	If you want to change this value change defined value from csv_read.h file. Then compile like down below.
	You can change the "," sign from csv_read.c file. It's cause to read another file format.
	For fastest output you should change the comparison value from knn.c file.It's like that
	#Change knn.c file
		line 13:: int comparisons = 5// 5 is desired value
		line 14:: //printf("\nEnter the desired number of comparisons to nearby neighbors: ");
		line 15:: //scanf("%d", &comparisons);
	The program is only tested on GNU/Linux and gcc compiler.

#Setup:
	on command line
	>make

#Run:
	on command line
	>./run

