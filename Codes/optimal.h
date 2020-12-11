//optimal code
void optimal() {

	FILE *fp, *fw, *fr;
	int i = 0;
	char ch;
	int s = 0;
	int decNum = 0;
	int rem = 0;
	int f = 0;
	fr = fopen("new_head.txt", "w");
	fp = fopen("binary.dat", "r");
	fw = fopen("compressed.txt", "w");
	if(fp == NULL || fw == NULL) {
		printf("FILE EMPTY!");
	}
	else {
		fseek(fp, -1, SEEK_END);
		s = ftell(fp);
		fseek(fp, -1, SEEK_END);
		fprintf(fw, "%c", 32);
		fprintf(fr, "%c", 32);
	}
	
	while((ch = fgetc(fp))!='a') {
		rem = ch - '0';
		f = decNum;
		decNum += rem*pow(2,i);
		i++;
		//assign a char to a group of bytes when decimal value exceeds 127  
		if(decNum > 127) {
			decNum = f + 33;
			i = i - 1;
			fprintf(fw, "%c", decNum);
			fprintf(fr, "%d", i);
			//counters set to 0
			i = 0;
			decNum = 0;
			fseek(fp, +1, SEEK_CUR);
			s++;
		}
		//moves the cursor to left until the decimal value is 127
		else {
			fseek(fp, -2, SEEK_CUR);
			char ch_new = fgetc(fp);
			fseek(fp, +1, SEEK_CUR);
			if(ch_new == 'a') {
				decNum = decNum + 33;
				fprintf(fw, "%c", decNum);
				fprintf(fr, "%d", i);
			}
		}
		fseek(fp, -2, SEEK_CUR);
		s--;
	}
	printf("Hang on... \n");
	fclose(fp);
	fclose(fw);
	fclose(fr);
}

//function to reverse compressed text
void reverse() {
	
	char ch;
	FILE *f1, *f2;
	f1 = fopen("compressed.txt", "r");
	f2 = fopen("comp__net.txt", "w");
	if(f1 == NULL || f2 == NULL) {
		printf("FILE EMPTY!");
	}
	else {
		fseek(f1, -1, SEEK_END);
		while((ch = fgetc(f1))!=' ')  {
			fprintf(f2, "%c", ch);
			fseek(f1, -2, SEEK_CUR);
		}
		fclose(f1);
		fclose(f2);
	}
}

//function to reverse header information
void reverse_head() {
	
	char ch;
	FILE *f1, *f2;
	f1 = fopen("new_head.txt", "r");
	f2 = fopen("new__head.txt", "w");
	if(f1 == NULL || f2 == NULL) {
		printf("FILE EMPTY!");
	}
	else {
		fseek(f1, -1, SEEK_END);
		while ((ch = fgetc(f1))!=' ') {
			fprintf(f2, "%c", ch);
			fseek(f1, -2, SEEK_CUR);
		}
		fclose(f1);
		fclose(f2);
	}
}
		
