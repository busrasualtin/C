#include<stdio.h>

int strlen_arr(char str[])
{
	int count;
	count = 0;
	while(str[count] != '\0')
		count++;
	return count;
}

int strlen(char *str)
{
	int count;
	count = 0;
	//while(str[count] != '\0')
	while(*(str+count) != '\0')
		count++;
	return count;	
}

int is_palindrome(char *s)
{
	int i, j;
	i = 0;
	j = strlen(s)-1;
	if(j < 0) {
		j = 0;
	}
	while(i <= j && s[i] == s[j]) {
		i++;
		j--;
	}
	if(i > j) {
		i--;
		j++;
	}
	return s[i] == s[j];
}

int is_palindrome_v2(char *s)
{
	int i, j;
	int ip;
	i = 0;
	j = strlen(s)-1;
	ip = 1;
	while(i <= j && ip) {
		if(s[i] == s[j]) {
			i++;
			j--;
		}
		else {
			ip = 0;
		}
	}
	return ip;
}

int main()
{
	char s[] = "string";
	char *p = "string";
	char *q = "string";
	
	printf("%p %p %p %p\n", p, q, s, &s);
	p = s;
	printf("%p %p %p\n", p, q, s);
	
	
	printf("%d\n", strlen_arr(s));
	printf("%d\n", strlen(s));
	
	printf("%d\n", is_palindrome(""));
	printf("%d\n", is_palindrome("x"));
	printf("%d\n", is_palindrome("xx"));
	printf("%d\n", is_palindrome("xyx"));
	printf("%d\n", is_palindrome("xyzyx"));
	printf("%d\n", is_palindrome("xyztzyx"));
	
	printf("%d\n", is_palindrome("xy"));
	printf("%d\n", is_palindrome("xyz"));
	printf("%d\n", is_palindrome("xyzzx"));
	printf("%d\n", is_palindrome("xyztyzx"));
	
	printf("\n");
	
	printf("%d\n", is_palindrome_v2(""));
	printf("%d\n", is_palindrome_v2("x"));
	printf("%d\n", is_palindrome_v2("xx"));
	printf("%d\n", is_palindrome_v2("xyx"));
	printf("%d\n", is_palindrome_v2("xyzyx"));
	printf("%d\n", is_palindrome_v2("xyztzyx"));
	
	printf("%d\n", is_palindrome_v2("xy"));
	printf("%d\n", is_palindrome_v2("xyz"));
	printf("%d\n", is_palindrome_v2("xyzzx"));
	printf("%d\n", is_palindrome_v2("xyztyzx"));
	
	return 0;
}

