#include <stdio.h>
#include <stdlib.h>

void insertionSort(int array[], int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];// Compare key with each element on the left of it until an element smaller than it is found.
    int j = step - 1;     // For descending order, change key<array[j] to key>array[j].
    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main(){
  FILE *infile, *outfile; 
  char arr[1001][1001], s;
  int i = 0, j = 0;
  int a=0,c=0,b=1;
  infile= fopen("matrix_of_incendence74.txt", "r");
  while (!feof(infile)){
    fscanf(infile,"%c",&s);
    if (s=='0' || s=='1') a=a+1;
    if (s=='\n') b=b+1;
  }
  c=a/b;// b=the number of vertices --- c= the number of edge
  fclose(infile);
  infile= fopen("matrix_of_incendence74.txt", "r");	
  while (!feof(infile)){
    fscanf(infile, "%c", &s);
    if (s != ' ' && s != '\n'){
      arr[i][j] = s;
      j++;
      if (j == c){
        i++;
        j = 0;
      }
    }
  }

int array[b];//array of degrees of given vertices
int arr_sort[b];//array of order lists of vertices to sort
for (int i=0;i<b;i++) array[i]=0;
for (int i=0;i<b;i++){
  for(int j=0; j<c;j++){
    if(arr[i][j]=='1'){
      array[i]++;
    }
  }
}
for (int i=0;i<b;i++) arr_sort[i]=array[i]; //Initialize the array to be sorted
outfile = fopen("vuongvn.dot", "w");

fprintf(outfile, "list of vertices and their degrees{\n");
fprintf(outfile, "vertices :");//print the list of vertices and their degrees
for (int k=0;k<b;k++){
  fprintf(outfile, "%d  ",k+1 );
}
fprintf(outfile, "\n");
fprintf(outfile, "degrees  :");
for (int k=0;k<b;k++){
  fprintf(outfile, "%d  ",array[k] );
}
fprintf(outfile, "\n");
fprintf(outfile, "}");
 
 
int size = sizeof(arr_sort) / sizeof(arr_sort[0]);//Sort in ascending order of vertex degree
insertionSort(arr_sort, size);
fprintf(outfile, "\n");
fprintf(outfile, "\n");

fprintf(outfile, "list of vertices and their degrees after sorting(insertion sort method){\n");
fprintf(outfile, "vertices :");//list of vertices and their degrees after sorting
for (int k=0;k<b;k++){ 
  int j=0;
  for(int i=0;i<b;i++){
    if(arr_sort[k]==array[i] && j==0){
      fprintf(outfile, "%d  ",i+1 );
      j++;
      array[i]=arr_sort[0]-1;
    }
  }
}
fprintf(outfile, "\n");
fprintf(outfile, "degrees  :");
for (int k=0;k<b;k++){
  fprintf(outfile, "%d  ",arr_sort[k] );
}
fprintf(outfile, "\n");
fprintf(outfile, "}");
fprintf(outfile, "\n");
fprintf(outfile, "\n");

for (int i=0;i<b;i++) array[i]=0;// Initialize the initial array
for (int i=0;i<b;i++){
  for(int j=0; j<c;j++){
    if(arr[i][j]=='1'){
      array[i]++;
    }
  }
}

fprintf(outfile, "list of vertices of even and increasing degree{\n");
fprintf(outfile, "vertices :");//list of vertices of even and increasing degree
for (int k=0;k<b;k++){ 
  int j=0;
  for(int i=0;i<b;i++){
    if(arr_sort[k]==array[i] && j==0 && arr_sort[k]%2==0){
      fprintf(outfile, "%d  ",i+1 );
      j++;
      array[i]=arr_sort[0]-1;
    }
  }
}
fprintf(outfile, "\n");
fprintf(outfile, "degrees  :");
for (int k=0;k<b;k++){
  if( arr_sort[k]%2==0){
    fprintf(outfile, "%d  ",arr_sort[k] );
  }
}
fprintf(outfile, "\n");
fprintf(outfile, "}");
fclose(outfile);
}