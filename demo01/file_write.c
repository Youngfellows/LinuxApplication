#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc,char *argv[])
{
	//open file
	if(argc<2)
	{
		printf("please input filename\n");
		exit(1);
	}else
	{
		int fd;
		umask(0000);
		fd = open(argv[1],O_RDWR|O_CREAT,0664);
		if(fd < 0)
		{
			printf("error\n");
			exit(1);
		}else
		{
			printf("success=%d\n",fd);
			//write string to file
			char buf[] = "\n欢迎来到深圳南山区!\n";
			int result = write(fd,buf,strlen(buf));	

			//文件偏移
			lseek(fd,5,SEEK_SET);
			char buf2[1024];
			memset(buf2,0,1024);
			//读文件
			read(fd,buf2,1024);
			printf("buf2=%s\n",buf2);			

			if(result != -1)
			{
				//read success
				printf("buf=%s\n",buf);
			}else
			{
				printf("read file error\n");
			}
			//关闭文件
			close(fd);
			printf("closed\n");
		}		
	}
}
