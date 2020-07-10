// base64 based on https://tools.ietf.org/html/rfc4648
#include <stdio.h>
#include <string.h>

void convert(char, char, char);

char output[50];

int main(int argc, char **argv){
	char input[50];
	fgets(input, sizeof(input), stdin);
	unsigned long len = strlen(input);
	for(unsigned long i=0; i<len/3; i++){
		convert(input[i*3], input[i*3+1], input[i*3+2]);
	}
	if(len%3 == 2)
		convert(input[(len/3)*3], input[(len/3)*3 + 1], ' ');
	if(len%3 == 1)
		convert(input[(len/3)*3], ' ', ' ');

	printf("%s\n", output);
	return 0;
}

void convert(char a, char b, char c) {
	// 252 = 11111100
	int one = (252 & (int)a) >> 2;
	// 3 = 00000011
	int two = (3 & (int)a) << 4;
	if(b != ' ')
		// 240 = 11110000
		two += (240 & (int)b) >> 4;
	// 15 = 00001111
	int three = (15 &  (int)b) << 2;
	if(c != ' ')
		// 192 = 11000000
		three += (192 & (int)c) >> 6;
	else if(b == ' ')
		// 64 => '='
		three = 64;
	int four = 64;
	if(c != ' ')
		// 63 = 00111111
		four = 63 & (int)c;

	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";
	unsigned long len = strlen(output);
	output[len] = alpha[one];
	output[len+1] = alpha[two];
	output[len+2] = alpha[three];
	output[len+3] = alpha[four];
}
