static char data[127];
static int freqq[127];
static int size_new = 0;
#define MAXCHAR 1000
void fetch() {
	int i = 0,j = 0,flag = 0;
	FILE *fp;
	char str[MAXCHAR];
	char ch;
	fp = fopen("new__head.txt", "r");
	if (fp == NULL) {
		printf("Could not open file");
	}
	while((ch = fgetc(fp)) != EOF) {
		if(ch == '\n') {
			flag = 1;
		}
		if(flag == 1) {
			while (fgets(str, MAXCHAR, fp) != NULL) {
				while(str[j] != '\0') {
					if(str[j] == ':') {
						if(str[j - 1] == ' ') {
							if(str[j - 2] == ' ') {
								data[size_new] = ' ';
								int m = j + 1;
								int p = 0;
								int num[10];
								int n = 0;
								while(str[m] != ' ' && str[m] != '\0') {
									num[p] = str[m];
									p++;
									m++;
								}
								int size = p - 1;
								for(int q=0; q<p; q++) {
									int c = num[q] - '0';
									n = n + c*pow(10, size);
									size--;
								}
								freqq[size_new] = n;
							}
							else {
								freqq[size_new] = '/';
								int m = j - 1;
								int p = 0;
								int num[10];
								int n = 0;
								while(str[m] != ' ' && str[m] != '\0') {
									num[p] = str[m];
									p++;
									m++;
								}
								int size = p - 1;
								for(int q=0; q<p; q++) {
									int c = num[q] - '0';
									n = n + c*pow(10, size);
									size--;
								}
								freqq[size_new]=n;
							}
						}
						else {
							int x = str[j - 1];
							if(x == 0) {
								data[size_new] = '\n';
							}
							else {
								data[size_new] = str[j - 1];
							}
							int m = j + 1;
							int p = 0;
							int num[10];
							int n = 0;
							while(str[m] != ' ' && str[m] != '\0') {
								num[p] = str[m];
								p++;
								m++;
							}
							int size = p-1;
							for(int q=0; q<p; q++) {
								int c = num[q] - '0';
								n = n + c*pow(10,size);
								size--;
							}	
							freqq[size_new] = n;
						}
						size_new++;
					}
					j++;
				}
        			j = 0;
    			}
		}
	}
    	fclose(fp);
}
