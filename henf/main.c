#include <stdio.h>

#define s   socket
#define so  setsockopt
#define bd  bind
#define l   listen
#define a   accept
#define r   read
#define w   write
#define c   close
int s(),so(),bd(),l(),a(),r(),w(),c();

#define BSZ 1024

#define AIP(x) ((int*)x)

#define EXIT    b

#define S       (b+1)
#define SE      (b+5)
#define SADDR   (b+6)
#define SADDRP  0x1f,0x90  // port: 8080
#define SADDRA  0x7f,0,0,1 // addr: 127.0.0.1
#define SADDRS  SADDRP,SADDRA
#define SADDRSZ 16
#define SARGS   2,1,6
#define SOARGS  1,15,SE,1
#define SBUFSZ  512
#define SBUF    (b+(BSZ-SBUFSZ))
#define SA      (SADDR+SADDRSZ)
#define RDSZ    (SADDR+SADDRSZ+4)

static volatile char b[BSZ] = {0, 0,0,0,0, 1, 2,0,SADDRS,0,0,0,0,0,0,0,0 };

int main(int argc, char **argv) {
    while(!*EXIT) printf("%1$.*2$d%3$hn\r\033[K%5$s",0,s(SARGS),AIP(S),r(a(*AIP(S),0,l(*AIP(S),2-bd(*AIP(S),SADDR,SADDRSZ-so(*AIP(S),SOARGS)))?0:0),SBUF,SBUFSZ),SBUF);
    return 0;
}
