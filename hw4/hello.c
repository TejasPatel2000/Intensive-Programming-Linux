 #include <stdio.h>
#include <string.h>
// Use percent p--> Address
// %x --> Hex character
int main(int argc, char *argv[])
{
  printf("argv %p %p", &argv[0], &argv);
  printf("\n");
  printf("argc %14x %p", argc, &argc);
  printf("\n\n");


  for(int i=0; i<argc; i++){
    printf("argv+%d",i);
    printf(" %p", &argv[i][0]);
    printf(" %p", &argv[i]);
    printf("\n");
  }
  
  int letterCounter=0;
  printf("\n");
  char space[1]= "\0";
  for(int i = 0; i<argc; i++)
    {
      for( int ch=0; ch<strlen(argv[i]); ch++)
	{
	  if(letterCounter!=0 && letterCounter%4==0)
	    {
	      printf(" %p", &argv[i][ch]);
	      printf("\n");
	    }
	  printf(" %x ", argv[i][ch]);
	  letterCounter++;
	  /*if(letterCounter%4==0)
	    {
	      printf(" %p", &argv[i][ch]);
	      printf("\n");
	      }*/  
	}
      if(letterCounter%4==0){
	printf(" %p", &argv[i][strlen(argv[i])]);
	printf("\n");
      }
      printf(" %2x ", '\0');
      letterCounter++;
    }
  int diff= letterCounter%4;
  if(letterCounter%4!=0)
    {
      printf("%19p", &argv[argc-1][strlen(argv[argc-1])+diff-1]);
    }
  printf("\n\n");
  return 0;
}
