#include "defs.h"

// report 5
/*
purpose: Filters the data from the linked list and performs some calculations then prints out report 4
in: list, a pointer to a DataListType struct and a head pointer to a linked list.
*/
void createReportFive(DataListType *list){
  DataNodetype *currNode;
  currNode = list->head;
  float l6 = 0;
  float l7 = 0;
  float l8 = 0;
  int year = 2010;
  int lastyear = 0;
  findLastYear(list,&lastyear);

  for (int i = year; i < lastyear+1;i++){
    while(currNode!=NULL){
      if(currNode->data->year == year){
        sumAllDegreeInYear(currNode, &l6,&l7,&l8);
      }
      currNode = currNode->next;
    }
    calcEachDegreePercent(&l6,&l7,&l8);
    printReportFive(year,l6,l7,l8);
    l6=l7=l8=0;
    currNode = list->head;
    year++;
  }
}

/*
purpose: prints out the calculated data into report
in: year, an int that holds the year that the data is being filtered for
in: l6, the percantge of poeple with L6 degrees to the total population of that year
in: l7, the percantge of poeple with L77degrees to the total population of that year
in: l8, the percantge of poeple with L8 degrees to the total population of that year
*/
void printReportFive(int year, float l6,float l7,float l8){
  printf("%6d %6.2f%% %6.2f%% %6.2f%%\n",year,l6,l7,l8);
}

/*
purpose: takes in the currNode and filters through the data, then adds it to the correct running total.
in: currNode, a pointer to a DataNodetype struct, that contains some data
in: l6, the percantge of poeple with L6 degrees to the total population of that year
in: l7, the percantge of poeple with L77degrees to the total population of that year
in: l8, the percantge of poeple with L8 degrees to the total population of that year
*/
void sumAllDegreeInYear(DataNodetype *currNode, float *l6,float *l7,float *l8){
  if((strcmp(currNode->data->degree,"L6") == 0) && (strcmp(currNode->data->gender,"T") == 0) ){
    (*l6) += currNode->data->population;
  }
  if((strcmp(currNode->data->degree,"L7") == 0) && (strcmp(currNode->data->gender,"T") == 0) ){
    (*l7) += currNode->data->population;
  }
  if((strcmp(currNode->data->degree,"L8") == 0) && (strcmp(currNode->data->gender,"T") == 0) ){
    (*l8) += currNode->data->population;
  }
}

/*
purpose: take the sum of people with l6,l7 and l8 degrees in a year and get their percentages
in: l6, a pointer to a float and the percantge of poeple with L6 degrees to the total population of that year
in: l7, a pointer to a float and the percantge of poeple with L7degrees to the total population of that year
in: l8, a pointer to a float and the percantge of poeple with L8 degrees to the total population of that year
*/
void calcEachDegreePercent(float *l6,float *l7,float *l8){
  float total = (*l6)+(*l7)+(*l8);
  (*l6) = ((*l6)/total)*100;
  (*l7) = ((*l7)/total)*100;
  (*l8) = ((*l8)/total)*100;

}
