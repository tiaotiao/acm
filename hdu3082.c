/*
HDU 3082
http://acm.hdu.edu.cn/showproblem.php?pid=3082

Simplify The Circuit

Time Limit: 2000/1000 MS (Java/Others)    Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 1089    Accepted Submission(s): 496


Problem Description
You may be puzzled by the complicated circuits ever. Now let us simplify them.
The task is: give you a parallel circuit(并联电路); you should calculate the resistance value （电阻）of it.
You may suppose the parallel circuit is made up of several simple series circuits（简单的串联电路）.
 

Input
The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.
Each test case starts with a line contains only one integer n (0 < n <= 20), indicating the number of simple series circuits. Next n lines are the descriptions of each simple series circuit. The wire is consisted by the character “-”. And resistances are show by positive integers, means their resistance values. The line’s length is shorter than 100 characters, and the count of resistance in each simple series circuit is no more than 20.
I assure all the calculations by integers using in this problem will not overflow the integer.
 

Output
For each case, please output the resistance value of the parallel circuit.
 

Sample Input
2
1
---5----
2
----2----3-1----
---2---2-------2-
 

Sample Output
5.00
3.00
 

Author
possessor WC
 

Source
HDU 2nd “Vegetable-Birds Cup” Programming Open Contest
*/

// Accepted  0MS	1412K

#include <stdio.h>
#include <string.h>


int series_resistance(char* s) {
    int num = 0;
    int r = 0;
    
    for (int i =0; s[i]; i++) {
        if ('0' <= s[i] && s[i] <= '9') {
            num = num*10 + (s[i] - '0');
            continue;
        }
        
        if (num != 0) {
            r += num;
            num = 0;
        }
    }
    
    if (num != 0) {
        r += num;
    }
    return r;
}

void slove() {
    int n;
    scanf("%d\n", &n);
    
    char s[100];
    float rr = 0;
    
    for (int i = 0; i < n; i++) {
        gets(s);
        
        int r = series_resistance(s);
        
        rr += 1.0/r;
    }
    
    float R = 1.0/rr;
    
    printf("%.2f\n", R);
}

int main() {
    int T;
    scanf("%d\n", &T);
    
    for (int t = 0; t < T; t++) {
        slove();
    }
    
    return 0;
}

