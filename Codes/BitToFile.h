void write(int end) {

	char ch;
	FILE *fp, *fr;
	fp = fopen("binary.dat", "w");
	fr = fopen("TextFile.txt", "r");
	if (fp == NULL || fr == NULL) {
		printf("FILE EMPTY.");
		exit(1);
	}
	fprintf(fp, "%c", 'a');
	while((ch=fgetc(fr))!=EOF) {
		for(int j=0; j<end; j++) {
			if(ch==dataarr[j]) {
				for(int k=0; k<bitsize[j]; k++) {
					fprintf(fp, "%d", temparr[j][k]);
				}
			}
		}
	}
	fclose(fp);
	fclose(fr);
}
