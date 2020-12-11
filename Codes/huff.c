#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "CharFreq.h"//read characters from file
#include "comp.h"//generate huffman codes
#include "BitToFile.h"//write generated bit codes to file
#include "head.h"//creates the file header
#include "optimal.h"

void call_deleter(char *filer) {

	int status;
	status = remove(filer);
	if (status == 0)
		printf("Done!");
	else {
		printf("Unable to delete the file\n");
	}
}

int main() {

	printf("\n\t\t\t\t\tWELCOME TO TEXT COMPRESSION.\n\n");
	file();
	HuffmanCodes(char_array, char_freq, ack);
	write(ack);
	optimal();
	reverse();
	reverse_head();
	create_head(ack);
	printf("Text Compression Successful!\nYour new compressed file is 'compressed.txt'\n");
	return 0;
}

