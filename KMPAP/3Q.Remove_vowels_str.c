
#include<stdio.h>
int main() {
	int i = 0;
	char str[20];

	printf("Enter a string:");
	scanf("%[^\n]s", str); // Corrected format specifier

	for (; str[i] != '\0'; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
				str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
			// Shift characters to the left to remove the vowel
			for (int j = i; str[j] != '\0'; j++) {
				str[j] = str[j + 1];
			}
			i--; // Decrement i to handle consecutive vowels
		}
	}

	printf("Output: %s\n", str);

	return 0;
}

