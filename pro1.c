#include <fcnstl.h>
#include <stdio.h>
#include <unistd.h>
int main() {
struct flock f3;
int fd;
f3.l_type = F_WRLCK; 
f3.l_whence = SEEK_SET; 
f3.l_start = 0; 
f3.l_len = 0; 
f3.l_pid = getpid(); 
fd = open("locked_file", O_RDWR | O_EXCL); 
fcntl(fd, F_SETLKW, &f3); 
usleep(20000000);
printf("\n release lock \n");
f3.l_type = F_UNLCK;
fcntl(fd, F_SETLK, &f3); 
}
