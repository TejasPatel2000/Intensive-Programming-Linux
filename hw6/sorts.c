/* HW6 read cafefully and follow all the instructions/comments
   this program compiles and runs as is although it's not doing much.
   DO NOT CHANGE THE SEED. Changing seed gives a different sequence of
   numbers but we want the same numbers for comparison purposes.

   FLOATING point radix sort requires some substantial changes to this code
   float n, lst[N],tmp[N];
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdint.h>

#define OK 1
#define NOK 0
#define NELM 100/* default 100 elements */
#define N 1048576/* 2^20 or 1 meg elements  */
//#define N 2097152
//#define N 4194304
//#define N 8388608
//#define N 16777216
//#define N 33554432

void selection_sort();
void swap();

void merge_sort();
void msort_recursive();

void int_radix_sort();
void float_radix_sort();
void swap();
void self_check();
void f_init_lst();

int rand(void);
void srand();
int rand_r();
void init_lst();
void print_lst();

int n, lst[N], buf[N];

float f_lst[N], f_buf[N];
int main(int argc,char **argv) {

  // long int del_sec,del_msec;
  struct timeval tv_s,tv_e;
  // printf("%d",gettimeofday(&tv_s, NULL));
  if (argc>1) n = atoi(argv[1]);
  else n = NELM;
  printf("n=%d\n",n);
  //  init_lst(lst,n);
  // f_init_lst(f_lst,n);
  //  print_lst(lst,n);
  
  // gettimeofday(&tv_s, NULL);
  //  selection_sort(lst,n);
  //  merge_sort(lst,buf,n);
  //  int_radix_sort(lst,buf,n);
  //  float_radix_sort(f_lst,f_buf,n);
  //  gettimeofday(&tv_e, NULL);

  /****
    PRINT elapsed time in sec and milli secs
  ****/
  /*
    print_lst(lst,n);
    self_check(lst, n);
    self_check(buf, n);
   */
  // print_lst(f_lst,n);
  
  // self_check(f_lst,n);
  // self_check(f_buf,n);
  long int del_sec;
  int sz = 10;
  printf("Sorts\n");
  /*
  for(int i =0; i<5; i++)
    {
      init_lst(lst,sz);
      printf("Size: %d ", sz);
      gettimeofday(&tv_s,NULL);
      selection_sort(lst, sz);
      gettimeofday(&tv_e, NULL);
      del_sec = (tv_e.tv_sec - tv_s.tv_sec);
      long long del_msec = (tv_e.tv_sec*1000LL + tv_e.tv_usec/1000) - (tv_s.tv_sec*1000LL + tv_s.tv_usec/1000);
      // elapsedTime += (tv_e.tv_usec - tv_s.tv_sec) / 1000.0;
      printf("Time for Selection Sort: %ld sec", del_sec);
      printf(" OR %lld msec\n", del_msec);
      sz *= 10;
    }
    sz=10; */
  for(int i =0; i<6; i++)
    {
      init_lst(lst,sz);
      printf("Size: %d \n", sz);
      gettimeofday(&tv_s,NULL);
      selection_sort(lst, sz);
      gettimeofday(&tv_e, NULL);
      del_sec = (tv_e.tv_sec - tv_s.tv_sec);
      long long del_msec = (tv_e.tv_sec*1000LL + tv_e.tv_usec/1000) - (tv_s.tv_sec*1000LL + tv_s.tv_usec/1000);
      // elapsedTime += (tv_e.tv_usec - tv_s.tv_sec) / 1000.0;
      printf("Time for Selection Sort: %ld sec", del_sec);
      printf(" OR %lld msec\n", del_msec);
      
      
      init_lst(lst, sz);
      gettimeofday(&tv_s,NULL);
      merge_sort(lst, buf, sz);
      gettimeofday(&tv_e, NULL);
      del_sec = (tv_e.tv_sec - tv_s.tv_sec);
      del_msec = (tv_e.tv_sec*1000LL + tv_e.tv_usec/1000) - (tv_s.tv_sec*1000LL + tv_s.tv_usec/1000);
      // elapsedTime += (tv_e.tv_usec - tv_s.tv_sec) / 1000.0;
      printf("Time for Merge Sort: %ld sec", del_sec);
      printf(" OR %lld msec\n", del_msec);
      
      init_lst(lst,sz);
      gettimeofday(&tv_s,NULL);
      int_radix_sort(lst,buf, sz);
      gettimeofday(&tv_e, NULL);
      del_sec = (tv_e.tv_sec - tv_s.tv_sec);
      del_msec = (tv_e.tv_sec*1000LL + tv_e.tv_usec/1000) - (tv_s.tv_sec*1000LL + tv_s.tv_usec/1000);
      // elapsedTime += (tv_e.tv_usec - tv_s.tv_sec) / 1000.0;
      printf("Time for Int Radix Sort: %ld sec", del_sec);
      printf(" OR %lld msec\n", del_msec);

      f_init_lst(f_lst,sz);
      gettimeofday(&tv_s,NULL);
      float_radix_sort(f_lst,f_buf, sz);
      gettimeofday(&tv_e, NULL);
      del_sec = (tv_e.tv_sec - tv_s.tv_sec);
      del_msec = (tv_e.tv_sec*1000LL + tv_e.tv_usec/1000) - (tv_s.tv_sec*1000LL + tv_s.tv_usec/1000);
      // elapsedTime += (tv_e.tv_usec - tv_s.tv_sec) / 1000.0;
      printf("Time for Float Radix Sort: %ld sec", del_sec);
      printf(" OR %lld msec\n\n", del_msec);
      sz *= 10;
      
  }
  
  return 0;
}

void swap(int *x, int *y)
{
  int temp = *x;
  *x = *y;
  *y = temp;
}

void selection_sort(int lst[],int n){
  // fill here
  int i, j, minIndex;
  
  for (i = 0; i<n-1; i++)
    {
      minIndex=i;
      for(j=i+1; j<n; j++)
	{
	  if(lst[j] < lst[minIndex])
	    minIndex=j;
	}
      swap(&lst[minIndex], &lst[i]);
    }
}

void merge_sort(int lst[], int buf[], int n){
  msort_recursive(lst, buf, 0, n-1);
}

//use recursion
void msort_recursive(int lst[], int buf[], int left, int right){
  // fill here
  if(right <= left){
    return;
  }
  int mid = (left + right) / 2;
  msort_recursive(lst, buf, left, mid);
  msort_recursive(lst, buf, mid+1, right);
  int left_pointer = left;
  int right_pointer = mid + 1;
  int counter;
  
  for(counter = left; counter<=right; counter++) {
    if(left_pointer == mid + 1) {
      buf[counter] = lst[right_pointer];
      right_pointer++;
    } else if (right_pointer == right + 1){
      buf[counter] = lst[left_pointer];
      left_pointer++;
    }else if (lst[left_pointer] < lst[right_pointer]) {
      buf[counter] = lst[left_pointer];
      left_pointer++;
    } else {
      buf[counter] = lst[right_pointer];
      right_pointer++;
    }
    
  }
  
  for (counter = left; counter<= right; counter++) {
    lst[counter] = buf[counter];
  }
}

//fix the bucket size to 256. run 4 passes where each pass processes 8 bits
//use lst and tmp only. do not use any more memory of size n.
void radix_sort(int group) {
  int i,j,mask,buckets;
  int flag,*src,*dst;
  
  for (i=0; i<n; i=i+group) {
    // set src/dst to lst/buf depending on iter number
    // fill here with what's discussed in class
    // ...
  }
}
void int_radix_sort(int lst[], int tmp[], int n){
  /*int p,q,mask,buckets;
  int flag, *src, *dst;
  for (p=0; p<s; p=p+group){
    
  }*/
  int max = lst[0];
  for(int i=1; i<n; i++){
    if(lst[i]>max){
      max=lst[i];
    }
  }
  
  for(int place=1; max/place>0; place=place*10){
    int i, buckets[10] = {0};
    for(i=0; i<n; i++){
      buckets[(lst[i]/place)%10]++;
    }

    for(i=1; i<10; i++){
      buckets[i] += buckets[i-1];
    }

    for(i = n-1; i>=0; i--){
      tmp[buckets[(lst[i]/place) % 10]- 1] = lst[i];
      buckets[(lst[i]/place)%10]--;
    }

    for(i = 0; i<n; i++){
      lst[i] = tmp[i];
    }
    
  }
  
  
}

void float_radix_sort(float lst[], float tmp[], int n){
  int lst1[n];
  int tmp1[n];
  for(int i =0; i<n; i++){
    lst1[i] = (int)lst[i];
    tmp1[i] = (int)tmp[i];
  }
  int_radix_sort(lst1, tmp1, n);
  for(int i =0; i<n; i++){
    lst[i] = lst1[i];
  }
}

void print_lst(int *l,int n){
  int i;
  for (i=0; i<n; i++) {
    printf("%d ",l[i]);
  }
  printf("\n");
}

void init_lst(int *l,int n){
  int i;
  //  int seed = time(0) % 100;/* seconds since 1/1/1970 */
  //  printf ("seed=%d\n", seed);
  srand(1234);/* SEED */
  for (i=0; i<n; i++) {
    l[i] = rand();
  }
}

void f_init_lst(float *l, int n){
  srand(1234);
  for(int i=0; i<n; i++){
    l[i] = (float)rand();
  }
}

void self_check(int *lst,int n) {
  int i,j,flag=OK,*lstp;
  
  lstp = lst;
  for (i=0;i<n-1;i++)
    if (lstp[i] > lstp[i+1]) { flag = NOK; break; }

  if (flag == OK) printf("sorted\n");
  else printf("NOT sorted at %d\n",i);
}

/* End of file */
