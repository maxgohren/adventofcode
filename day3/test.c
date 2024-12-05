#include <stdio.h>

int main()
{
	int s[10] = {1,2,3,4,5,6,7,8,9,0};
	int d = 0;
	while ( d < 10){
		if( s[d++] == 2){
			printf("%d\n", s[d++]);
		}
	}

	return 0;
}
