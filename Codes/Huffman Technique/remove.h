//function to remove 'a' from the binary output
void remove_a() {
	
	FILE *fp, *fr;
	int ch;
	fp = fopen("checker.txt","r");
	fr = fopen("compressed_huffman.txt","w");
	fseek(fp, +1, SEEK_CUR);
	while((ch=fgetc(fp))!=EOF) {
		fputc(ch, fr);
	}
}
