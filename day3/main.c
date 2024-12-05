#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define INPUT "longinput.txt"

int main() {
    FILE *file = fopen(INPUT, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Seek to the end of the file to determine its size
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file); // Reset the file pointer to the beginning

    // Allocate memory to store the file contents
    char *s = (char *)malloc(fileSize + 1);
    if (s == NULL) {
        perror("Memory allocation failed");
        fclose(file);
        return 1;
    }

    // Read the file into the allocated memory
    fread(s, 1, fileSize, file);
    s[fileSize] = '\0'; // Null-terminate the string

    fclose(file);

    // Print the file contents
    //printf("File Content:\n%s\n", s);

	char numBuf[4]; // 3 digit number + null
	int j = 0;
	int i = 0;
	int num1 = 0;
	int num2 = 0;
	long long sum = 0;

	// Read through the string s until EOF	
	while( i < fileSize){
		num1 = 0;
		num2 = 0;
		if( s[i++] == 'm'){
			if (s[i++] == 'u'){
				if(s[i++] == 'l'){
					if(s[i++] == '('){
						// read number after mul(
						// if its not a digit we skip
						while( isdigit(s[i]) ) {
							numBuf[j++] = s[i++];
						}
						// num1 is 0 if character after ( is not a digit
						numBuf[j] = 0;
						num1 = atoi(numBuf);
						j = 0;
						// check for comma and move past it
						if ( s[i++] == ',' ){
							// read second number after ',' until ')'
							while( isdigit(s[i]) ) {
								numBuf[j++] = s[i++];
							}
							numBuf[j] = 0;
							num2 = atoi(numBuf);
							j = 0;
							// only add the sum if the mul command is valid ending with ')'
							if ( s[i] == ')' )
								sum += num1 * num2;
						}
					}
				}
			}
		}
	}

	printf("Final sum: %lld\n", sum);

    // Clean up
    free(s);
    return 0;
}

