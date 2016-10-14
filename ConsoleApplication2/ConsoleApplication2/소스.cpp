
#include <stdio.h>

#ifdef WIN32
#define popen _popen
#define pclose _pclose
#endif

FILE *stream = popen("ssh pr0ximo@192.168.2.144 cat /home/pr0ximo/2008.csv", "r");

int main(int argc, char **argv)
{
	if (stream)
	{
		char buf[512] = { 0, };
		while (fgets(buf, 511, stream))
			printf("%s", buf);
		pclose(stream);
	}
}