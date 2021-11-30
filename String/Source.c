#include <stdio.h>
#include <stdlib.h>



int string_length(char* c) {
	char* t;
	for (t = c; *t != NULL; t++);
	
	return t - c;
}

void string_copy(char* a, char* b) {
	for (; *a != NULL; a++) {
		*b += *a;
	}
}

void string_concatonate(char* a, char* b) {
	for (; *a != NULL; a++);
	for (; *b!=NULL; b++) {
		*a += *b;
	}
}

int string_compare(char* a, char* b) {
	for (; *a == *b; a++, b++) {
		if (*a == '\0') {
			return 0;
		}
	}
	return *a - *b;
}

char* string_char(char* s, char c) {
	for (; *s != NULL; s++) {
		if (*s == c) {
			return s;
		}
	}
	return NULL;
}

char* string_string(char* str, char* sub) {
	char* s, * t;
	for (; *str; str++) {
		for (s = str, t = sub; *s == *t; s++, t++) {
			if (*(t + 1) == '\0') {
				return str;
			}
		}
	}
	return NULL;
}

int main() {
	char s[100];
	char t[] = "Zdravo";
	char u[] = " svima";
	char r[] = "racunari";

	string_copy(s, t);
	printf("%s\n", s);

	string_concatonate(s, u);
	printf("%s\n", s);
	printf("%i \n", string_char(r, 'n') - r);
	printf("%d\n", string_char(r, 'a') - r);
	printf("%d\n", string_string(r, "racun") - r);
	printf("%d\n", string_string(r, "ari") - r);
	printf("%d\n", string_string(r, "cun") - r);
	printf("%p\n", string_string(r, "cna"));
	return 0;
}