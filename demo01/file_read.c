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
			//read file
			char buf[1024];
			memset(buf,0,1024);//申请内存
			int returnnum = read(fd,buf,1024);
			if(returnnum != -1)
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
