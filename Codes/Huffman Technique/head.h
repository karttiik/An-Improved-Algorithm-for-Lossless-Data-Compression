void create_head(int end) {

	FILE *fh;
	fh = fopen("new__head.txt","a");
	fprintf(fh,"\n");
	for(int i=0; i<end; i++) {
		fprintf(fh,"%c:",char_array[i]);
		fprintf(fh,"%d ",char_freq[i]);
	}
	fclose(fh);
}
