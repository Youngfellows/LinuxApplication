#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	int in, out;
	char c;
	//打开文件
	in = open("file.in",O_RDONLY,0666);
	out = open("file.out",O_WRONLY|O_CREAT,0666);
	
	//读文件
	while(read(in,&c,1))
	{
		//写文件
		write(out,&c,1);
	}
	//关闭流
	close(in);
	close(out);
	return 1;
}
