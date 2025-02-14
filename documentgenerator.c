/*
	Question :
	C program documentation extractor to streamline the process of understanding and maintaining C codebases.
	
	Note : 
	1] Provided program extracts content between delimeters (multiline comments) as it is including spaces, tabs, special characters 
	and newline i.e everything enclosed between delimeters will be considered as part of documentation.

        2] Even though c doesn’t support nested comments, given program handles nested documentation comments also.
        
        3] Documentation is displayed on terminal after execution of program and as well as it is saved in desired file. 
*/



#include <stdio.h>

int main()
{
	FILE *fp, *fp1;
	char fname[25], docfile[25], c, nextc;
	int cl = 0;

 	printf("\nC code documentation extractor");
    	printf("\n\nEnter name of C file to extract documentation from : ");
    	scanf("%s", fname);
    	printf("\nEnter name of file where you want to save extracted documentation : ");
    	scanf("%s", docfile);
    	printf("_____________________________________________________________________________\n\n");

    	fp = fopen(fname, "r");

    	if (fp == NULL) 
    	{
        	printf("Error: Unable to open %s file\n\n", fname);
		return 0;
    	}

	fp1 = fopen(docfile, "w");
	
	if (fp1 == NULL) 
    	{
        	printf("Error: Unable to open / create %s file\n\n", docfile);
		return 0;
    	}

	
    	printf("C program Documentation : ");
    	printf("\n----------------------------------------------------------------------------\n");

    	while ((c = fgetc(fp)) != EOF)
    	{
        	if (c == '/' && (nextc = fgetc(fp)) == '*')
        	{
        		cl++;
        		fprintf(fp1,"\n");
        		printf("\n");
        	}
        	else if (c == '*' && (nextc = fgetc(fp)) == '/')
			cl--; 
			
        	else if (cl > 0)
        	{
        		putc(c,fp1);
                	printf("%c", c);
                }
    	}
	
	printf("\n_____________________________________________________________________________");
	
    	fclose(fp);
    	fclose(fp1);
    	
    	printf("\n\nDocumentation is succesfully saved in %s.\n\n",docfile);
}


