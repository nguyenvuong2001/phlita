#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *infile, *outfile; 
  char arr[1001][1001], s;
  int i = 0, j = 0;
  int a=0,c=0,b=1;
  infile= fopen("matrix_of_incendence74.txt", "r");
  while (!feof(infile))
  {
      fscanf(infile,"%c",&s);
      if (s=='0' || s=='1') a=a+1;
      if (s=='\n') b=b+1;
  }
  c=a/b;
  fclose(infile);
  infile= fopen("matrix_of_incendence74.txt", "r");	
  while (!feof(infile))
  {
    fscanf(infile, "%c", &s);
    if (s != ' ' && s != '\n')
    {
      arr[i][j] = s;
      j++;
      if (j == c)
      {
        i++;
        j = 0;
      }
    }
  }
fclose(infile);
printf("The matrix of edges and vertices: ");
	printf("\n"); 
	for (i = 0; i < b; i++) { 
		for (j = 0; j < c; j++) {
			printf("%2c", arr[i][j]); 
		}
		printf("\n");
	}
 
printf("------------------\n");
  if (c > (( b- 1) * (b - 2) / 2)) // graph connectivity theorem
  
  {
    printf("graph -connected graph\n");
  }
  else
  {
    printf("graph - disconnected graph\n");
  }
  printf("------------------\n");
outfile = fopen("vuongvn3.dot", "w");
fprintf(outfile, "graph graphname {\n");
// fprintf(outfile,"list of pairs of vertices connected by edges \n");

for (int k=0;k<b;k++)
{
  fprintf(outfile, "%d;\n",k+1 );
}


for (int k=0;k<b;k++)
{
	// fprintf(outfile, "vertex %d\n",k+1 );
	int n=0;
  int nums[c];
  for(int d=0;d<c;d++ ) nums[d]=0;
    for(int m=0;m<c; m++)
	  { 
			if (arr[k][m] == '1')
			{

				for( int l=k;l<b;l++)
				{
					if ( arr[l][m]=='1' && l!=k )
					{
						fprintf(outfile, "%d  -- %d;\n", k+ 1,l+1);
					}
        }

			}
      if(arr[k][m] == '0') nums[m]=0;
      if(arr[k][m]=='1')
      {
        nums[m]=nums[m]+1;
        for (int x=0;x<b;x++)
        {
          if (arr[x][m]=='1' && x!=k ) nums[m]=nums[m]+1;
        }
      }
    }
    for(int i=0;i<c;i++)
    {
      if(nums[i]==1) n=1;
    }
    if(n==1)
    {
       fprintf(outfile, "%d  -- %d;\n", k+ 1,k+1);
       n=0;
    }
  
}
fprintf(outfile, "}");

fclose(outfile);



}
