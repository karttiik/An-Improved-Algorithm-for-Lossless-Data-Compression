#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "CharFreq.h"//read characters from file
#include "comp.h"//generate huffman codes
#include "BitToFile.h"//write generated bit codes to file
#include "head.h"//creates the file header
#include "remove.h"

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

	printf("\n\t\t\tWELCOME TO TEXT COMPRESSION USING HUFFMAN TECHNIQUE.\n\n");
	file();
	HuffmanCodes(char_array, char_freq, ack);
	write(ack);
	create_head(ack);
	remove_a();
	call_deleter("checker.txt");
	printf("Text Compression Successful!\nYour new compressed file is 'compressed_huffman.txt'\n");
	return 0;
}

