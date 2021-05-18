#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

void main(){
  FILE *infile;
  char countryCode[15];
  char countryName[20];
  char degree[15];
  char gender[15];
  int year;
  int population;
  int choice;

    DataListType datalist;
    initDataList(&datalist);
    RTArrayType reportTwoArr;
    initArray(&reportTwoArr);


    // read from file and add data to list
     infile = fopen("grad.dat","r");
     if(!infile){
       printf("Error could not open grad data file");
     }
     while(fscanf(infile,"%s %s %s %s %d %d",countryCode,countryName,degree,gender,&year,&population)!=EOF){
       DataType *newData;
       initData(&newData,countryCode,countryName,degree,gender,year,population);
       addToDataList(&datalist,newData);
     }
     fclose(infile);
     while(choice != 0){
       printf("\n-------------------------------------------------------------\n");
       printf("\n Select a report from the menu that you would like to see\n");
       printf("\n (1) report 1\n");
       printf("\n (2) report 2\n");
       printf("\n (3) report 3\n");
       printf("\n (4) report 4\n");
       printf("\n (5) report 5\n");
       printf("\n (0)  EXIT\n");
       printf("\n-------------------------------------------------------------\n");
       scanf("%d", &choice);
       if(choice == 1){
         //report1
          printf("\n  creating report 1....\n");
          printf("\n Report on the graduate percentage for each country, for each degree, for all years and all genders\n");
          printf(" \n CODE       COUNTRY         L6       L7      L8    TOTAL\n");
          createReportOne(&datalist);
          printf("\n Where “L6” is a Bachelor’s degree, “L7” is a Master’s, and “L8” is a Doctorate\n");
       }
       if(choice == 2){
         // report2
         printf("\n creating report 2.....\n");
         printf("\n Report on the top five and bottom five countries for the percentage of female graduates in a specific country for 7 years and all degrees\n");
         createReportTwo(&datalist,&reportTwoArr);
         cleanupArray(&reportTwoArr);
         //free in here
       }
       if(choice == 3){
         // report 3
         printf("\ncreating report 3......\n");
         printf("\n Report on the graduate percantage for each country by year from 2014 to 2017 for all types of degrees and all genders\n");
         printf("\n CODE         COUNTRY     2014   2015     2016   2017 \n");
         createReportThree(&datalist);
       }
       if(choice == 4){
         // report 4
         printf("\ncreating report 4.............\n");
         printf("\n Report on the female and male graduate percantage for each year for all countries and all types of degrees\n");
         printf(" \n YEAR   FEMALE    MALE\n");
         createReportFour(&datalist);
       }
       if(choice == 5){
         //report 5
         printf("\ncreating report 5.........\n");
         printf("\n Report on the graduate percentage for each year, for each degree, for all countries and all genders \n");
         printf("\n YEAR     L6    L7       l8 \n");
         createReportFive(&datalist);
       }
       if(choice < 0 || choice > 5){
         printf("\n ERROR INVALID INPUT!\n");
       }
     }
     cleanuplist(&datalist);

     // make datalist dynamic
    }
