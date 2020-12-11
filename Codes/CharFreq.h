static char char_array[127]={};
static int char_freq[127]={};
static int ack=0; //counts different character in file
static int filesize=0;

void file(){
  char ch;
  char f;
  int i=0;
  int count=0; //count frequency of character
  int j=0;
  int flag=0;
    FILE *fp1 ;
    FILE *fp2 ;
    FILE *fp=fopen("TextFile.txt", "r");
    if (fp == NULL) {
         printf("File not found.\n");
    }
    // calculate size of the file
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    fp1 = fopen("TextFile.txt", "r") ;  // Open the existing file in read mode
    fp2 = fopen("TextFile.txt", "r") ;
    // Check if this filePointer is null
    // which maybe if the file does not exist
    if ( fp1 == NULL || fp2 == NULL )
    {
        printf( "File failed to open." ) ;
    }
    else
    {
        // Read the characters from the file
        // using fgetc() method
        printf("File found successfully!\nHang on...\n");
        while ((ch=fgetc(fp1))!=EOF)
        {
          count=0;
          for(i=0;i<=ack;i++)
          {
            if(char_array[i]==ch)
            {
              flag=1;
              break;
            }
          }
           if(flag==0)
           {
               char_array[j]=ch;
               ack++;
           }
          while((f=fgetc(fp2))!=EOF)
          {
          if(ch==f)
          {
            count++;
          }
          }
          // set the pointer back to start
          fseek(fp2,0, SEEK_SET);
          if(flag==0)
          {
          char_freq[j]=count;
          j++;
          }
          flag=0;
         }
        // Closing the file
        fclose(fp1) ;
        fclose(fp2) ;
    }
}
