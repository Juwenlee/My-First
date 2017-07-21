/* ==================================================================
 *       Filename:  com.c
 *    Description:  4G LTE
 *        Created:  2014年01月06日 13时33分08秒
 *       Compiler:  gcc/g++
 *         Author:  Juwenlee1989@163.com
 *        Company:  Harbin Engineering University
 * ==================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>


void config_com(int  fd)
{
	struct termios opt;
	tcgetattr(fd, &opt);
	cfsetispeed(&opt, B115200);
	cfsetospeed(&opt, B115200);
	opt.c_cflag &= ~CSIZE;
	opt.c_cflag |= CS8;
	opt.c_cflag &= ~PARENB;
	opt.c_iflag &= ~INPCK; 
	opt.c_cflag &= ~CSTOPB;
	if(tcsetattr(fd,  TCSANOW,  &opt) != 0)
	{
		fprintf(stderr,  "set com failure :%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	tcflush(fd,  TCIOFLUSH);
}

int read_line(int fd, char *buf)
{
	int rdnum = 0;
	char * tem = buf;
	while(read(fd, tem, 1))
	{
		rdnum++;
		if(*tem == '\n')
		{
			break;
		}
			tem++;
	}
	*(tem + 1) = 0;
	return rdnum;
}


int main(void)
{
	int comfd;
	comfd = open("/dev/ttyUSB0", O_RDWR);
	if(comfd < 0)
	{
		fprintf(stderr, "open failure: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	config_com(comfd);
	char buffer[255] = {0};

	while(strncmp(buffer, "CONNECT",7) != 0)
	{
		memset(buffer, 0, 255);
		read_line(comfd, buffer);
		printf("%s", buffer);
	}
	printf("4G LTE CONNECT!!!\n");
	return 0;
}

  
