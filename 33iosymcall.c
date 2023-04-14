//to demonstrate the use of I/O system calls for console
#include <unistd.h> //header file that provides access to the POSIX operating system API
#include <stdio.h>
#define BUFFER_SIZE 30
int main() 
{
char buffer[BUFFER_SIZE];
int n; 
//read(int __fd, void *__buf, size_t __nbytes)
//write(int __fd, const void *__buf, size_t __n)
//fd-file descriptor; buf-buffer to read data from; nbytes-length of buffer; n- number of bytes read on success
  printf("Enter string: \n");
n = read(0, buffer, BUFFER_SIZE); // 0 is the file discriptor for stdin
printf("Number of characters read: %d\n", n);
 write(1, buffer, n); // 1 is the file discriptor for stdout
return 0;
}


// to demonstrate the use of I/O system calls for file I/O( read, write, open, lseek)
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>//header in the C POSIX library that contains constructs that refer to file control
#define BUFFER_SIZE 30
int main() {
int fd,n;
char buffer[BUFFER_SIZE];
fd = open("m6.c", O_RDWR);
//open(const char *__file, int __oflag, int mode)
/*path to file which you want to use; flags-O_RDONLY: read only, O_WRONLY: write only, O_RDWR: read and write, O_CREAT: create file if it doesn’t exist, O_EXCL: prevent creation if it already exists*/ 
printf("File discriptor is %d\n", fd);
if (fd == -1) 
{
printf("Failed to open file.\n");
exit(0);
}
printf("Reading first 10 characters from file: \n");
n = read(fd, buffer, 10);
write(1, buffer, n);
  //lseek is a system call that is used to change the location of the read/write pointer of a file descriptor
printf("\nSkipping 5 characters from current position in the file: \n");
lseek(fd, 5, SEEK_CUR);//SEEK_CUR - the file offset shall be set to its current location plus offset.
n = read(fd, buffer, 10);
write(1, buffer, n);
 printf("\nGoing 10 characters before the current position in the file: \n");
lseek(fd, -10, SEEK_CUR);
n = read(fd, buffer, 10);
write(1, buffer, n);
printf("\nGoing to 5th last character in the file: \n");
lseek(fd, -5, SEEK_END);//SEEK_END -the file offset shall be set to the size of the file plus offset*/
n = read(fd, buffer, 7);
write(1, buffer, 5);
printf("\nGoing to the 3rd character in the file: \n");
lseek(fd, 3, SEEK_SET);//SEEK_SET-the file offset shall be set to offset bytes.
n = read(fd, buffer, 5);
write(1, buffer, n);
  return 0;
}

//to read from file and write into a new file
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 300
int main() {
int fd1,fd2,n;
char buffer[BUFFER_SIZE];
fd1 = open("m6.c", O_RDONLY);
fd2 = open("copy", O_CREAT | O_WRONLY, 0666);
//permission: read-4, wr-2, exe-1, user, group, others  
printf("File discriptor for m6.c is %d and copied file is %d\n\n", fd1, fd2);
if (fd1 == -1 || fd2 == -1) 
{
printf("Failed to open file.\n");
exit(0);
}
n = read(fd1, buffer, BUFFER_SIZE);
write(fd2, buffer, n);
printf("File has been created and the contents are copied successfully\n");  
return 0;
}
