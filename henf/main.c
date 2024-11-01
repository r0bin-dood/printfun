#include <stdio.h>

#define s   socket
#define d   dup2
#define so  setsockopt
#define bd  bind
#define l   listen
#define a   accept
#define o   open
#define r   read
#define w   write
#define c   close
int s(),d(),so(),bd(),l(),a(),r(),w(),c(),o();

#define BSZ 1024

#define AIP(x) ((int*)x)

#define EXIT    b

#define S       (b+1)
#define SE      (b+5)
#define SE2     (b+9)
#define SADDR   (b+10)
#define SADDRP  0x1f,0x90  // port: 8080
#define SADDRA  0x7f,0,0,1 // addr: 127.0.0.1
#define SADDRS  SADDRP,SADDRA
#define SADDRSZ 16
#define SARGS   2,1,6
#define SOARGS  1,2,SE2,1
#define SOARGS2 1,15,SE2,1
#define SBUFSZ  512
#define SBUF    (b+(BSZ-SBUFSZ))
#define SA      (SADDR+SADDRSZ)
#define WRSTR   (SADDR+SADDRSZ+4)
#define WRSTRSZ 20

#define SECHECK(x) (*AIP(SE)<=6?x:-1)

static volatile char b[BSZ] = {0, 2,0,0,0, 1,0,0,0, 1, 2,0,SADDRS,0,0,0,0,0,0,0,0, 4,0,0,0, 'H','T','T','P','/','1','.','1',' ','2','0','0',' ','O','k','\r','\n','\r','\n', '-'};

char *fmt = "%2$.38s...\n%4$s\n%3$hhn";
#define arg c(w(*AIP(SA),WRSTR,r(d(a(*AIP(S),0,l(SECHECK(*AIP(S)),bd(SECHECK(*AIP(S)),SADDR,so(d(SECHECK(s(SARGS)),*AIP(S)),SOARGS)?SADDRSZ:SADDRSZ)?1:1)?0:0),*AIP(SA)),SBUF,SBUFSZ-1)?r(o(av[1],0),WRSTR+(WRSTRSZ-1),256)+WRSTRSZ:WRSTRSZ)?*AIP(SA):*AIP(SA)),SBUF,AIP(SE),WRSTR

int main(int ac, char **av) {
    while(!*EXIT) printf(fmt,arg);
    return 0;
}
