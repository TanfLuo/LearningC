#include <stdio.h>
#include <stdbool.h>
#include <winsock.h>
 
 
union {
    int number;
    char s;
} test;
 
bool testBigEndin() {
    test.number = 0x01000002;
    return (test.s == 0x01);
}

int a = 0x01020304;
char *b = (char*)&a;
 
int main(int argc, char **argv) {
    if (testBigEndin()) {
        printf("\r\nbig-endian");
    } else {
        printf("\r\nlittle-endian");
    }
	
	printf("\r\nint a = 0x01020304;");
	int i = 0;
	for(i;i < 4;i++)
	{
		printf("\r\na[%d]=0X%02X",i,*(b+i));
	}
	a = htonl(a);
	printf("\r\na = htonl(a);");
	i=0;
	for(i;i < 4;i++)
	{
		printf("\r\na[%d]=0X%02X",i,*(b+i));
	}
	a = htonl(a);
	printf("\r\na = htonl(a);");
	i=0;
	for(i;i < 4;i++)
	{
		printf("\r\na[%d]=0X%02X",i,*(b+i));
	}
	
	
	
}