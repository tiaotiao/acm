/*
PKU 1163 The Triangle
http://poj.org/problem?id=1163

Description

7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

(Figure 1)
Figure 1 shows a number triangle. Write a program that calculates the highest sum of numbers passed on a route that starts at the top and ends somewhere on the base. Each step can go either diagonally down to the left or diagonally down to the right. 

Input

Your program is to read from standard input. The first line contains one integer N: the number of rows in the triangle. The following N lines describe the data of the triangle. The number of rows in the triangle is > 1 but <= 100. The numbers in the triangle, all integers, are between 0 and 99.

Output

Your program is to write to standard output. The highest sum is written as an integer.

Sample Input

5
7
3 8
8 1 0 
2 7 4 4
4 5 2 6 5

Sample Output

30

Source

IOI 1994
*/

// Accepted 7064K	563MS

#include <stdio.h>
#include <string.h>

int main() {
	int i,j,k;
	int s[101][101];
	memset(&s, 0, sizeof(s));

	int N;
	scanf("%d", &N);	// totally N lines

	int n,x,max=0;
	for (n = 1; n <= N; n++) { // for N lines
		for (i = 1; i <= n; i++) { // read the line
			scanf("%d", &x);
			s[n][i] = x + (s[n-1][i-1] > s[n-1][i] ? s[n-1][i-1] : s[n-1][i]);
			max = max > s[n][i] ? max : s[n][i];
		}
	}

	printf("%d", max);

	return 0;
}
