#include <stdio.h>
#include <stdlib.h>

int main()
{
  FILE *infile, *outfile; 
  char arr[1001][1001], s;
  int i = 0, j = 0;
  infile= fopen("matrix_of_incendence74.txt", "r");
  while (!feof(infile))
  {
    fscanf(infile, "%c", &s);
    if (s != ' ' && s != '\n')
    {
      arr[i][j] = s;
      j++;
      if (j == 17)
      {
        i++;
        j = 0;
      }
    }
  }

outfile = fopen("vuongvn.gv", "w");
fprintf(outfile, "graph graphname {\n");
fprintf(outfile,"list of pairs of vertices connected by edges \n");

for (int k=0;k<5;k++)
{
	fprintf(outfile, "vertex %d\n",k+1 );
	int n=0;
    for(int m=0;m<17; m++)
	{ 
			if (arr[k][m] == '1')
			{
				for( int l=k;l<5;l++)
				{
					if ( arr[l][m]=='1' && l!=k )
					{
						fprintf(outfile, "%d  -- %d;\n", k+ 1,l+1);
					}
                     
                    if (arr[k][m] != arr[l][m]  )
					{
                        n=1;
					}

				}
              
			}
    }
    if(n=1)
    {
       fprintf(outfile, "%d  -- %d;\n", k+ 1,k+1);
    }

    fprintf(outfile, "\n");
}
fprintf(outfile, "}");

fclose(outfile);

}
