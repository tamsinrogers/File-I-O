/**
 * CS333 Projecct 6 - case insensitive word counter in C++
 * 
 * 11/11/2021
 * Tamsin Rogers
 *
 *  g++ -o task1cpp task1.cpp
 * ./task1cpp task1_test.txt
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    
    int counter[1000]; 									//counter 
    
    unsigned char word[1000][20]; 						//array of all words
    int size =0;

    if(argc < 2){
        printf("Not enought arguments used");

        return 1;
    }
    if(argv[1] == NULL){
        printf("There was no filename provided");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r"); 					// open the file for reading
    unsigned char value[20];   							// holder variable for the string, has set length with corresponds to buffer size
    while(fscanf(fp, "%s", value) != EOF){
        unsigned char singularword[20]; 
        int l=0;
        
        for(int i=0;value[i];i++)
        { 												//lowercase the word and then increase the length of the word 
            if(value[i]!='.' && value[i]!=',' )
            { 											//testing to check for periods and commas 
                singularword[l]=tolower(value[i]); 		//lower cases everything 
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
            for(int i=0; i<size;i++)
            {
               
                for(int a=0;a<20;a++)
                {
                   
                    if(word[i][a]==singularword[a])
                    {
                        
                        if(a==19)
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
            
            if(flag==0)
            {
                for(int i=0; i<l;i++)
                {
                    word[size][i]=singularword[i];
                }
                counter[size]=1;
                size++;
            }

        }
        memset(singularword, 0, sizeof(singularword));
        
    }  
    
    int max=0;
    int biggestNumberIndex=0;
    int printed=0;
    for(int i=0;i<size;i++){
        
        if(counter[i]>max){
            max=counter[i]; 				//update the largest count number 
            
            biggestNumberIndex=i; 			//update the index of the largest number 
            
        }

        
    }
    
    for(int i=max;i>0;i--)
    {
        for(int a=0;a<size;a++)
        {
            if(counter[a]==i)
            {
                cout<< word[a]<<" ";
                cout<<  counter[a]<<"\n";
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




    


