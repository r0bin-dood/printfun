#include <stdio.h>

#define N 10

#define EXIT        b[0]
#define MAX         b[1]
#define SECRET_NUM  b[2]
#define GUESSED_NUM b[3]
#define SCANF_FMT   b[8]
#define RAND        (((((long)&printf>>16)&0xFF))%MAX)

char b[16] = {0, N, 1};

char *fmt = "%1$.*2$d%3$hhn\r\033[KGuess 0 - %4$d:%7$s\n";
#define arg         0, RAND, &SECRET_NUM, MAX, \
                    *(&SCANF_FMT+1)='d', SCANF_FMT=(scanf(&SCANF_FMT, &GUESSED_NUM)==EOF?:'%'), \
                    ((SECRET_NUM==GUESSED_NUM)?"\r\033[KYou won!\0":" "), \
                    EXIT=(SECRET_NUM==GUESSED_NUM)

int main() {
    while(!EXIT) printf(fmt, arg);
    return 0;
}
