#include <stdio.h>

#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 256
#define MAX_FIELDS 5 /* 5 fields: views,user,upload_time,duration,title */

struct clip *build_a_lst();
struct clip *append();
int find_length();
void print_lst();
void split_line();

struct clip {
  int views;
  char *user;
  char *upload_time;
  char *duration;
  char *title;
  struct clip *next;
};

int main(int argc, char **argv) {
  int n;
  struct clip *head;
  head = build_a_lst(*(argv+1));
  n = find_length(head);
  printf("%d clips\n",n);
  print_lst(head);/* prints the table */
  return 0;
}

struct clip *build_a_lst(char *fn) {
  FILE *fp;
  struct clip *hp;
  char *fields[MAX_FIELDS];
  char line[LINE_LENGTH];
  int cnt=0;
  hp=NULL;
  
  // open fn
  // while no more lines
  // read a line
  // split the line into five substrings/int and store them in a struct
  // append - add the struct at the end of the list
  // return the head pointer holding the list
  fp = fopen(fn, "r");
  if( fp == NULL){
    printf("FILE DNE");
  }
  
  while (fgets(line, sizeof(line), fp)!=NULL) {
    //line[cnt] =
    split_line(fields, line);
    hp = append(hp, fields);
  }
  fclose(fp);
  return hp;
}

/* fields will have five values stored upon return */
void split_line(char **fields,char *line) {
  int i=0;
  char *token, *delim;
  //maybe just comma for delim
  delim = ",\n";
  /* 
     call strtok(line, delim);
     repeat until strtok returns NULL using strtok(NULL, delim);
     use the routine we wrote in class.
  */
  token = strtok(line, delim);
  fields[0] = token;
  while (token != NULL){
    // fields[++i] = token;
    token = strtok(NULL, delim);
    fields[++i] = token;
  }
}

/* set five values into a clip, insert a clip at the of the list */
struct clip *append(struct clip *hp,char **five) {
  struct clip *cp,*tp;
  
  /* 
     malloc tp
     views need to be converted to int using atoi(*five). 
     no malloc needed for int views, provided you converted views to int
     malloc for four fields using malloc(strlen(five[.]))
     strcpy four strings to tp fields
     insert tp at the end of the list pointed by hp
     check if it's the first time or not
     use cp to traverse the list
  */
  tp = malloc(sizeof(struct clip));
  int views = atoi(five[4]);
  //cp->next = hp;
  char* u = (char*)malloc((strlen(five[1]) + 1) * sizeof(char));
  char* upload = (char*)malloc((strlen(five[2]) + 1) * sizeof(char));
  char* duration = (char*)malloc((strlen(five[3]) + 1) * sizeof(char));
  char* t = (char*)malloc((strlen(five[0]) + 1) * sizeof(char));
  
  //tp->views=10;
  tp->views = views;
  strcpy(u, five[1]);
  strcpy(upload, five[2]);
  strcpy(duration, five[3]);
  strcpy(t, five[0]);
  tp->user = u;
  tp->upload_time = upload;
  tp->duration = duration;
  tp->title = t;
  /*
  free(u);
  free(upload);
  free(duration);
  free(t);
  */
  tp->next = NULL;
  cp=hp;
  if(hp == NULL){
    hp = tp;
    hp->next =cp;
  } else if(hp->next ==NULL){
    hp->next=tp;
  }else{
    //cp=hp;
    while(cp->next!=NULL){
      cp = cp->next;
    }
    cp->next=tp;
  }
  
  /*    while(cp != NULL){
	cp = cp->next;
	}
	cp->next = tp; */
  //  free(u);
  // free(upload);
  // free(duration);
  //  free(t);
  return hp;
}

void print_lst(struct clip *cp) {
  /* 
     use a while loop and the statement below to print the list
     printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->id,cp->title,cp->time);
  */
  while(cp != NULL){
    printf("%d,%s,%s,%s,%s\n",cp->views,cp->user,cp->upload_time,cp->duration,cp->title);
    cp = cp->next;
  }
}

int find_length(struct clip *cp){
  int size=0;
  while(cp!=NULL){
    size++;
    cp=cp->next;
  }
  return size++;
}

/* End of file */
