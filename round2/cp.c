#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void read_cli_args(int cli_arg_count, char * cli_args[], char * infilename, char * outfilename);
void open_files(char * infilename, char * outfilename, FILE * infile, FILE * outfile);
void copy_files(FILE * infile, FILE * outfile);
void close_files(FILE * infile, FILE * outfile);

int main(int argc, char * argv[])
{
    FILE * infile =  NULL, * outfile = NULL;
    char * infilename = NULL, * outfilename = NULL;

    read_cli_args(argc, argv, infilename, outfilename);
    open_files(infilename, outfilename, infile, outfile);
    copy_files(infile, outfile);
    close_files(infile, outfile);

    return 0;
}

void read_cli_args(int cli_arg_count, char * cli_args[], char * infilename, char * outfilename)
{
    if (cli_arg_count < 3)
    {
        printf("You must specify both an infile and an outfile.\n");
        exit(1);
    }

    infilename = cli_args[1];
    outfilename = cli_args[2];
    printf("INFILE: %s, OUTFILE: %s\n", infilename, outfilename);
}

void open_files(char * infilename, char * outfilename, FILE * infile, FILE * outfile)
{
    printf("Inside open_files\n");
    infile = fopen(infilename, "r");
    outfile = fopen(outfilename, "w");
}

void copy_files(FILE * infile, FILE * outfile)
{
    char inchar;

    printf("Inside copy_files\n");

    while ((inchar = fgetc(infile)) != EOF)
    {
        printf("About to put %c into file\n", inchar);
        fputc(inchar, outfile);
    }
}

void close_files(FILE * infile, FILE * outfile)
{
    printf("Inside close_files\n");
    fclose(infile);
    fclose(outfile);
}
