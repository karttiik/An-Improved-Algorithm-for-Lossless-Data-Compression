#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "unhuff_file.h"
#include "decomp.h"

void call_deleter(char *filer) {
	
	int status;
	status = remove(filer);
	if (status == 0)
		printf("\n");
	else {
		printf("Unable to delete the file\n");
	}
}

void main() {

	printf("\t\t\tWelcome to Decompressor\n");
	fetch();
	call_decoder(data, freqq, size_new);
	call_deleter("new__head.txt");
}
