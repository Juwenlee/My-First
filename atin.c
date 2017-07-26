/* ==================================================================
 *    Description:  4G LTE
 *        Created:  2014        Compiler:  gcc/g++
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

char *AT = "AT\n";
char *AT_CFUN_4 = "AT+CFUN=4\n";
char *AT_CFUN_1 = "AT+CFUN=1\n";
char *AT_DSTMEX = "AT^DSTMEX=1,7\n";
char *AT_COPS = "AT+COPS?\n";
char *AT_CGDATA = "AT+CGDATA=\"M-0000\",1\n";

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

void write_com(int fd, char *buf)
{
	int wCount = strlen(buf);
	if(write(fd, buf, wCount) != wCount)
	{
		fprintf(stderr, "write com failure:%s\n", strerror(errno));
	}
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

	write_com(comfd, AT_CFUN_4);
	sleep(1);
	write_com(comfd, AT_CFUN_1);
	sleep(2);
	write_com(comfd, AT_DSTMEX);
	sleep(1);
	write_com(comfd, AT_COPS);
	sleep(1);
	write_com(comfd, AT_CGDATA);
	sleep(3);
	return 0;
}

  
