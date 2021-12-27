/**
 * CS333 Project 6 - task 1
 * case insensitive word counter in C
 * 
 * Tamsin Rogers
 * 11/11/21
 *
 * gcc -o task1 task1.c task1_test.txt
 * ./task1 task1_test.txt
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/* count the number of occurrences of every word in a text file */
int main(int argc, char *argv[])
{
    int maxSize = 1000;
    int  (*counter) = malloc(maxSize*sizeof(int)); 					// counter 
    unsigned char (*word)[20] = malloc(maxSize*sizeof(*word)); 		// word array
    int size = 0;

    if(argc < 2)
    {
        printf("error: lack of arguments");
        return 1;
    }
    
    if(argv[1] == NULL)
    {
        printf("error: filename");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r"); 								// open file
    unsigned char value[20];   										// string holder, length = buffer size
    
    while(fscanf(fp, "%s", value) != EOF)
    {
        unsigned char singularword[20]; 
        int l=0;

        for(int i=0;value[i];i++){
            if(value[i]!='.' && value[i]!=',' )						// check for periods & commas 
            { 
                singularword[l]=tolower(value[i]); 					// cast to lowercase
                l++;
            }
   
        }
        
        if (size==0)
        {
            for(int i=0; i<l;i++)
            {
                word[size][i]=singularword[i];
            }
            counter[size]=1;
            size++;
        }
        
        else
        {
            int flag=0;
            
            for(int i=0; i<size; i++)
            {
               
                for(int a=0; a<20 ;a++)
                {
                   
                    if(word[i][a] == singularword[a])
                    {
                      
                        if(a == 19)
                        {
                            flag=1;
                            counter[i]++;
                            break;
                        }
                        
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if(flag == 0)
            {
                for(int i=0; i<l;i++)
                {
                    word[size][i] = singularword[i];
                }
                
                counter[size] = 1;
                size++;
            }
        } 
        
        memset(singularword, 0, sizeof(singularword));
    }    
    
    int max = 0;
    int biggestNumberIndex = 0;
    int printed = 0;
    
    for(int i=0;i<size;i++)
    {
        if(counter[i]>max)
        {
            max=counter[i]; 					// update largest count number 
            biggestNumberIndex=i; 				// update largest number index

        }
    }
    
    for(int i=max;i>0;i--)
    {
        for(int a=0;a<size;a++)
        {
            if(counter[a]==i)
            {
                printf("%s " ,word[a]);			// print word
                printf("%d\n", counter[a]);		// print word frequency
                printed++;
            }
            
            if(printed>20)
            {
                break;
            }
        }
        
        if(printed>20)
        {
            break;
        }
    }     
}