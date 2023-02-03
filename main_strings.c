#include<stdio.h>

void print_char_array(char a[], int n)
{
	int i;
	for(i=0; i<n; i++) {
		printf("%c,", a[i]);
	}
}

#define N 10

int main()
{
	char a1[N];
	char a2[N] = {'.', 219, 'x'};
	char a3[] = {'a', 'b', 'c', 'd'};
	
	char s1[] = "abcde";
	char s2[N] = "xyztu";
	char s3[] = {'m', 'n', 'o', 'p', 'q', '\0'}; // '\0' is null character.
	
	char *s4 = "qwert"; //read-only string
	
	printf("%d %d %d\n", sizeof(a1), sizeof(a2), sizeof(a3));
	print_char_array(a1, N);
	printf("\n");
	print_char_array(a2, N);
	printf("\n");
	print_char_array(a3, sizeof(a3)/sizeof(char));
	printf("\n\n");
	
	printf("%d %d %d\n", sizeof(s1), sizeof(s2), sizeof(s3));
	print_char_array(s1, sizeof(s1)/sizeof(char));
	printf("\n");
	print_char_array(s2, N);
	printf("\n");
	print_char_array(s3, sizeof(s3)/sizeof(char));
	printf("\n\n\n");
	
	printf("s1: %s\n", s1);
	printf("s2: %s\n", s2);
	printf("s3: %s\n", s3);
	s1[3] = '\0';
	printf("s1: %s\n", s1);
	printf("\n");
	printf("a1: %s|\n", a1);
	printf("a2: %s|\n", a2);
	printf("a3: %s|\n", a3);
	printf("\n\n");
	
	printf("enter some chars: ");
	scanf("%s", a1);
	//scanf("%s", &a1); //also works
	printf("a1: %s\n", a1);
	printf("a1: ");
	print_char_array(a1, N);
	printf("\n\n\n");
	
	printf("s4: %s\n", s4);
	//s4[2] = '\0'; //program crash
	printf("s4: %s\n", s4);
	
	return 0;
}

