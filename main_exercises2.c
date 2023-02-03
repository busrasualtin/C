#include<stdio.h>

//int length(char str[])
int length(char *str)
{
	int count;
	count = 0;
	while(str[count] != '\0')
		count++;
	return count;
}

int is_letter(char c)
{
	return c >= 'a' && c <= 'z';
}

char capitalize_char_notpreffered(char c)
{
	if(c = 'a') {
		return 'A';
	} else if(c = 'b') {
		return 'B';
	} else if(c = 'c') {
		return 'C';
	}
	//.. and so on
}

char capitalize_char(char c)
{
	return c - 32;
}

void capitalize(char *str)
{
	int i;
	i = 0;
	while(str[i] != '\0') {
		if(is_letter(str[i])) { //capitalize only the letters (a...z)
			str[i] = capitalize_char(str[i]);
		}
		i++;
	}
}

void replace_all(char *str, char c1, char c2)
{
	int i;
	i = 0;
	while(str[i] != '\0') {
		if(str[i] == c1) {
			str[i] = c2;
		}
		i++;
	}
}

int replace_first(char *str, int start, char c1, char c2)
{
	int i;
	i = start;
	while(str[i] != '\0') {
		if(str[i] == c1) {
			str[i] = c2;
			return i;
		}
		i++;
	}
	return -1;
}

int are_equal(char *str1, char *str2)
{
	int i;
	i = 0;
	while(str1[i] == str2[i] && str1[i] != '\0'  && str2[i] != '\0') {
		i++;
	}
	return str1[i]==str2[i];
}

//a comparison function "compare(x,y)" works as follows. 
// - <0 if x < y
// - 0 if x = y
// - >0 if x > y
int compare_old(char *str1, char *str2)
{
	int i;
	i = 0;
	while(str1[i] != '\0' && str2[i] != '\0') {
		if(str1[i] < str2[i]) {
			return -(i+1);
		} else if(str1[i] > str2[i]) {
			return (i+1);
		}
		i++;
	}
	if(str1[i] != '\0') {
		return (i+1);
	} else if(str2[i] != '\0') {
		return -(i+1);
	} else {
		return 0;
	}
}

int compare_char(char c1, char c2)
{
	/*if(c1<c2) {
		return -1;
	}
	else if(c1==c2) {
		return 0;
	}
	else {
		return 1;
	}*/
	return c1-c2;
}

int compare(char *str1, char *str2)
{
	int i, c;
	i = 0;
	while(str1[i] == str2[i] && str1[i] != '\0'  && str2[i] != '\0') {
		i++;
	}
	c = compare_char(str1[i], str2[i]);
	if(c>0) {
		return (i+1);
	} else if(c<0) {
		return -(i+1);
	} else {
		return 0;
	}
}

void encrypt(char *text, char *cipher, char key)
{
	int i;
	i = 0;
	while(text[i] != '\0') {
		cipher[i] = text[i] + key;
		i++;
	}
	cipher[i] = '\0';
}

void decrypt(char *cipher, char *text, char key)
{
	int i;
	i = 0;
	while(cipher[i] != '\0') {
		text[i] = cipher[i] - key;
		i++;
	}
	text[i] = '\0';
}

void encrypt2(char *text, char *cipher, char *key, int kl)
{
	int i;
	i = 0;
	while(text[i] != '\0') {
		cipher[i] = text[i] + key[i%kl];
		i++;
	}
	cipher[i] = '\0';
}

void decrypt2(char *cipher, char *text, char *key, int kl)
{
	int i;
	i = 0;
	while(cipher[i] != '\0') {
		text[i] = cipher[i] - key[i%kl];
		i++;
	}
	text[i] = '\0';
}

int main()
{
	char str[] = "8379kejdskhkaytkrwqk...ığüşöç..IĞÜŞÖÇHNMBCZSA";
	char str2[] = "8379kejdskhkaytkrwqk...ığüşöç..IĞÜŞÖÇHNMBCZSA    ";
	int i;
	
	printf("%s\n", str);
	printf("%d\n", length(str));
	
	capitalize(str);
	printf("%s\n", str);
	
	replace_all(str, 'K', 219);
	printf("%s\n", str);
	
	i = 0;
	while(i != -1) {
		i = replace_first(str, i, 219, 'K');
		printf("%s\n", str);
	}
	
	printf("%d\n", are_equal(str, str));
	printf("%d\n", are_equal(str, str2));
	printf("%d\n", are_equal("qweqwerqwe436457", "qweqwerqwe436457"));
	printf("%d\n", are_equal("qweqwerqwe6457", "qweqwerqwe436457"));
	printf("%d\n", are_equal("qweqwerqwe436457", "qweqwerqwe43645"));
	printf("%d\n", are_equal("qweqwerqwe436457", ""));
	printf("%d\n", are_equal("", ""));
	printf("\n");
	printf("%d\n", compare(str, str));
	printf("%d\n", compare(str, str2));
	printf("%d\n", compare("qweqwerqwe436457", "qweqwerqwe436457"));
	printf("%d\n", compare("qweqwerqwe6457", "qweqwerqwe436457"));
	printf("%d\n", compare("qweqwerqwe436457", "qweqwerqwe43645"));
	printf("%d\n", compare("qweqwerqwe436457", ""));
	printf("%d\n", compare("", ""));
	printf("\n");
	encrypt(str, str2, 'k');
	printf("text:\t%s\ncipher:\t%s\n", str, str2);
	decrypt(str2, str, 'k');
	printf("cipher:\t%s\ntext:\t%s\n", str2, str);
	printf("\n");
	encrypt2(str, str2, "key", 3);
	printf("text:\t%s\ncipher:\t%s\n", str, str2);
	decrypt2(str2, str, "key", 3);
	printf("cipher:\t%s\ntext:\t%s\n", str2, str);
	
	return 0;
}

