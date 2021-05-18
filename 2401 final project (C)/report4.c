#include "defs.h"
// report 4

/*
purpose: Filters the data from the linked list and performs some calculations then prints out report 4
in: list, a pointer to a DataListType struct and a head pointer to a linked list.
*/
void createReportFour(DataListType *list){
  DataNodetype *currNode;
  currNode = list->head;

  int year = 2010;
  float sumFemale = 0;
  float sumMale = 0;
  int lastyear = 0;
  findLastYear(list,&lastyear);
for (int i = year; i < lastyear+1 ; i++){
  while(currNode!=NULL){
    if(currNode->data->year == year){
      sumGenderInYear(currNode,&sumFemale,&sumMale);
    }
    currNode = currNode->next;
  }
  calcGenderPercent(&sumFemale,&sumMale);
  printReportFour(year,sumFemale,sumMale);
  sumFemale=sumMale=0;
  currNode = list->head;
   year++;
 }
}

/*
purpose: finds the last year in the list of data
in: list, a pointer to a DataListType struct and a head pointer to a linked list.
in: lastyear, the last year in the list of data
*/
void findLastYear(DataListType *list,int *lastyear){
  DataNodetype *curr;
  curr = list->head;
  while(curr->next!=NULL){
    curr = curr->next;
  }
  (*lastyear) = curr->data->year;
}

/*
purpose: prints out the calculated data into report
in: year, an int that holds the year that the data is being filtered for
in: sumFemale, the percantge of female to the total population in a year
in: sumMale, the percentage of male to the total population in a year
*/
void printReportFour(int year, float sumFemale,float sumMale){
  printf(" %6d %6.2f%% %6.2f%%\n",year,sumFemale,sumMale);
}

/*
purpose: take the sum of females and males in a year and gets their percentages
in: sumFemale, a pointer to a float and the percantge of female to the total population in a year
in: sumMale, a pointer to a float and the percentage of male to the total population in a year
*/
void calcGenderPercent(float *sumFemale, float *sumMale){
  float total = (*sumMale) + (*sumFemale);
  (*sumFemale)=((*sumFemale)/total)*100;
  (*sumMale)=((*sumMale)/total)*100;
}

/*
purpose: takes in the currNode and filters through the data, then adds it to the correct running total.
in: currNode, a pointer to a DataNodetype struct, that contains some data
in: sumFemale, the percantge of female to the total population in a year
in: sumMale, the percentage of male to the total population in a year
*/
void sumGenderInYear(DataNodetype *currNode, float *sumFemale, float *sumMale){
  if((strcmp(currNode->data->gender,"F") == 0)){
    (*sumFemale) += currNode->data->population;
  }
  if(strcmp(currNode->data->gender,"M") == 0){
      (*sumMale) += currNode->data->population;
  }

}
