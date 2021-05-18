#include "defs.h"

// report 1

/*
purpose: filters the data from the linked list and perform some calculations then prints out the report 1
in: list,  a pointer to a DataListType struct and a head pointer to a linked list.
*/
void createReportOne(DataListType *list){
  char countryCode[15];
  char countryName[20];
  float l6 = 0;
  float l7 = 0;
  float l8 = 0;
  float total = 0;
  DataNodetype *currNode;
  int totalL6 = 0;
  int totalL7 = 0;
  int totalL8 = 0;
  int sum = 0;
  sumOneDegree(list,&totalL6,&totalL7,&totalL8,&sum);
currNode = list->head;
strcpy(countryName,currNode->data->cName);
strcpy(countryCode,currNode->data->cCode);
while(currNode!=NULL){
if((strcmp(currNode->data->cCode,countryCode))==0){
  sumDegreeInCountry(currNode,&l6,&l7,&l8);
}
else{
  total = (l6+l7+l8);
  calculateReportOne(&l6,&l7,&l8,&total,totalL6,totalL7,totalL8,sum);
  printReportOne(countryCode,countryName,l6,l7,l8,total);

  strcpy(countryName,currNode->data->cName);
  strcpy(countryCode,currNode->data->cCode);
  l6 = l7 = l8 = total = 0;

  sumDegreeInCountry(currNode,&l6,&l7,&l8);
}
currNode = currNode->next;
}
total = (l6+l7+l8);
calculateReportOne(&l6,&l7,&l8,&total,totalL6,totalL7,totalL8,sum);
printReportOne(countryCode,countryName,l6,l7,l8,total);
}

/*
purpose: takes in the currNode and filters through the data, then adds it to the correct running total.
in: currNode, a pointer to a DataNodetype struct, that contains some data
in: l6, a pointer to a float, and the sum of degree l6 for all years and all genders
in: l7, a pointer to a float, and the sum of degree l7 for all years and all genders
in: l8, a pointer to a float, and the sum of degree l8 for all years and all genders
*/
void sumDegreeInCountry(DataNodetype *currNode , float *l6, float *l7, float *l8){

  if((strcmp(currNode->data->gender,"T") == 0) && (strcmp(currNode->data->degree,"L6") == 0)){
    (*l6) += currNode->data->population;
  }
  if((strcmp(currNode->data->gender,"T") == 0) && (strcmp(currNode->data->degree,"L7") == 0)){
      (*l7) += currNode->data->population;
  }
  if((strcmp(currNode->data->gender,"T") == 0) && (strcmp(currNode->data->degree,"L8") == 0)){
      (*l8) += currNode->data->population;
  }
}

/*
purpose: takes the sum of l6 l7 and l8 for one country and does the calculations on them to get the percentages
in: l6, a pointer to a float, and the sum of degree l6 for all years and all genders
in: l7, a pointer to a float, and the sum of degree l7 for all years and all genders
in: l8, a pointer to a float, and the sum of degree l8 for all years and all genders
in: total, a pointer to a float, and the sum of l6, l7 and l8
in: totalL6, the sum of all l6 for all countries for all years
in: totalL7, the sum of all l7 for all countries for all years
in: totalL8 the sum of all l8 for all countries for all years
in: sum, the sum of totalL6, totalL7 and totalL8
*/
  void calculateReportOne(float *l6,float *l7,float *l8,float *total,int totalL6,int totalL7,int totalL8,int sum){
    (*l6) = ((*l6)/totalL6)*100;
    (*l7) = ((*l7)/totalL7)*100;
    (*l8) = ((*l8)/totalL8)*100;
    (*total) = ((*total)/sum)*100;
  }

/*
purpose: prints out the calculated data into a report
in: code, a string that holds the country code
in: name, a string that holds the country name
in: l6, a float that holds the sum of degree l6 in a country
in: l7, a float that holds the sum of degree l7 in a country
in: l8, a float that holds the sum of degree l8 in a country
in: total, the sum of l6, l7 and l8
*/
  void printReportOne(char *code, char *name, float l6, float l7, float l8, float total){

    printf("%4s %17s %6.2f%% %6.2f%% %6.2f%% %6.2f%%\n",code,name,l6,l7,l8,total);

  }

/*
purpose: calculate the sum of one type of degree for all countries
in: list, a pointer to a DataListType struct and a head pointer to a linked list.
in: totalL6, a pointer to an int
in: totalL7, a pointer to an int
in: totalL8, a pointer to an int
in: sum, a pointer to an int

*/
void sumOneDegree(DataListType *list, int *totalL6, int *totalL7, int *totalL8, int *sum){
  DataNodetype *curr;
  curr = list->head;
  while(curr!=NULL){
    if((strcmp(curr->data->gender,"T") == 0) && (strcmp(curr->data->degree,"L6") == 0)){
      (*totalL6) += curr->data->population;
    }
    if((strcmp(curr->data->gender,"T") == 0) && (strcmp(curr->data->degree,"L7") == 0)){
        (*totalL7) += curr->data->population;
    }
    if((strcmp(curr->data->gender,"T") == 0) && (strcmp(curr->data->degree,"L8") == 0)){
        (*totalL8) += curr->data->population;
    }
    curr = curr->next;
  }

(*sum) = (*totalL6) + (*totalL7) + (*totalL8);

}
