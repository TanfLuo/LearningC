#include <stdio.h>
int main()
{
	char* str1 =(char *)malloc(sizeof(char) * 100);
	char  str2[23] = "i love asas ";
	char  str21[23];
	char * str3 = "luotanfa";
	printf("sizeof str3:%p\n", sizeof str3);
	printf("sizeof *str3:%p\n", sizeof *str3);
	int a = 100;
	int * len1 = &a;
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	struct io{int x};
	struct io ss = {21};
	str1[0] = 0;
	//str2 = "dsjdjsjsdj";
	//for (size_t i = 0; i < len2; i++) str1[i] = str2[i];
	//for (size_t i = 0; i < len3; i++) str1[i + len2] = str3[i];
	//str1[strlen(str2) + strlen(str3)] = '\0';
	str1 = strcat(str1, str2);
	str1 = strcat(str1, str3);
	str1 = strcat(str1, " djskdsj");
	printf("str1:%s\nstr2:%s\nstr3:%s\n",str1,str2,str3);
	printf("adr of str1:%p\n",str1);
	printf(" &str2 :%p\n",&str2 );
	printf("adr of  str2:%p\n",str2);
	printf("adr of str3:%p\n",&str3);
	printf("content of str1:%p\n", *&str1);
	printf("content of str1:%p\n", str1);
	printf("content of &ss:%p\n", *&ss);
	printf("content of ss:%p\n", ss);
	printf("content of *\(\"luotanfa\"\):%p\n", *("luotanfa"));
	printf("content of *\(\"luotanfa\"+1\):%p\n", *("luotanfa"+1));
	printf("content of *\(&\"luotanfa\"\):%p\n", *(&"luotanfa"));
	printf("content of  &\"luotanfa\":%p\n",  &"luotanfa");
	printf("content of  *\(char*\)&\"luotanfa\":%p\n",  *(char*)&"luotanfa");
	printf("content of  *\(\(\(char*\)&\"luotanfa\"\)+1:%p\n",  *(((char*)&"luotanfa")+1));
	printf("content of *&str2:%p\n", *&str2);
	printf("sizeof *&str2:%p\n", sizeof (*&str2));
	//printf("sizeof *&str2:%p\n", sizeof (*&str2));
	printf("content of *\(int*\)str2:%p\n", *(int*)str2);
	printf("content of *\(char*\)str2:%p\n", *(char*)str2);
	printf("sizeof &str2[0]:%p\n", sizeof &str2[0]);
	printf("sizeof &str2:%p\n", sizeof &str2);
	printf("sizeof str2:%p\n", sizeof str2);
	printf("sizeof str2[0]:%p\n", sizeof str2[0]);
	printf("content of *str2:%p\n", *str2);
	printf("content of str3:%p\n", str3);
	printf("content of *&len2:%p\n", *&len2);
	printf("content of  &len2:%p\n",  &len2);
	printf("content of  *len1:%p\n",  *len1);
	printf("content of   len1:%p\n",   len1);
	free(str1);
	str1 = NULL;
	
	return 0;
}
