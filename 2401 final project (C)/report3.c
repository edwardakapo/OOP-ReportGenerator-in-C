#include "defs.h"

// report 3

/*
purpose: filters the data from the linked list and performs some calculations then prints out report 3
in: list, a pointer to a DataListType struct and a head pointer to a linked list.
*/
void createReportThree(DataListType *list){
  DataNodetype *currNode;
  float gradIn2014 = 0;
  float gradIn2015 = 0;
  float gradIn2016 = 0;
  float gradIn2017 = 0;
  float allGrads2014 = 0;
  float allGrads2015 = 0;
  float allGrads2016 = 0;
  float allGrads2017 = 0;
  char countryCode[5];
  char countryName[20];
  sumAllDegree(list,&allGrads2014,&allGrads2015,&allGrads2016,&allGrads2017);

  currNode = list->head;
  strcpy(countryName,currNode->data->cName);
  strcpy(countryCode,currNode->data->cCode);
  while(currNode!=NULL){
    if(strcmp(currNode->data->cCode,countryCode)==0){
      sumDegreeInYear(currNode, &gradIn2014,&gradIn2015, &gradIn2016,&gradIn2017);
    }
  else{
    calcDegreePercent(&gradIn2014,&gradIn2015, &gradIn2016,&gradIn2017,allGrads2014,allGrads2015,allGrads2016,allGrads2017);
    printReportThree(countryCode,countryName,gradIn2014,gradIn2015,gradIn2016,gradIn2017);
    gradIn2014 = gradIn2015 = gradIn2016 = gradIn2017 = 0;
    strcpy(countryName,currNode->data->cName);
    strcpy(countryCode,currNode->data->cCode);
    sumDegreeInYear(currNode, &gradIn2014,&gradIn2015, &gradIn2016,&gradIn2017);
}
currNode = currNode->next;
  }
  calcDegreePercent(&gradIn2014,&gradIn2015, &gradIn2016,&gradIn2017,allGrads2014,allGrads2015,allGrads2016,allGrads2017);
  printReportThree(countryCode,countryName,gradIn2014,gradIn2015,gradIn2016,gradIn2017);
}



/*
purpose: takes the sum of graduates for different years for one country and does the calculations on them to
          get the percentage of grads for that year in that country
in: grad2014, a pointer to a float, and the sum of all graduates for 2014
in: grad2015, a pointer to a float, and the sum of all graduates for 2015
in: grad2016, a pointer to a float, and the sum of all graduates for 2016
in: grad2017, a pointer to a float, and the sum of all graduates for 2017
in: allGrads2014, the sum of all graaduates for all countries for 2014
in: allGrads2015, the sum of all graaduates for all countries for 2015
in: allGrads2016, the sum of all graaduates for all countries for 2016
in: allGrads2017, the sum of all graaduates for all countries for 2017
*/
void calcDegreePercent(float *grad2014,float *grad2015, float *grad2016,float *grad2017, float allGrads2014, float allGrads2015, float allGrads2016,float allGrads2017){
    (*grad2014) = ((*grad2014)/allGrads2014)*100;
    (*grad2015) = ((*grad2015)/allGrads2015)*100;
    (*grad2016) = ((*grad2016)/allGrads2016)*100;
    (*grad2017) = ((*grad2017)/allGrads2017)*100;

}

/*
purpose: prints out the calculated data into a report
in: code, a string that holds the country code
in: name, a string that holds the country name
in: grad2014, the sum of all graduates for 2014
in: grad2015, the sum of all graduates for 2015
in: grad2016, the sum of all graduates for 2016
in: grad2017, the sum of all graduates for 2017
*/
void printReportThree(char *code,char *name,float grads2014,float grads2015, float grads2016, float grads2017){
    printf("%4s %17s %6.2f%% %6.2f%% %6.2f%% %6.2f%%\n",code,name,grads2014,grads2015,grads2016,grads2017);

}

/*
purpose: calculate the sum of all types of degrees for a countries for a year
in: list, a pointer to a DataListType struct and a head pointer to a linked list.
in: grad2014, a pointer to a float, and the sum of all graduates for 2014
in: grad2015, a pointer to a float, and the sum of all graduates for 2015
in: grad2016, a pointer to a float, and the sum of all graduates for 2016
in: grad2017, a pointer to a float, and the sum of all graduates for 2017
*/
void sumDegreeInYear(DataNodetype *currNode, float *grads2014, float *grads2015, float *grads2016,float *grads2017){

        if(currNode->data->year == 2014 && (strcmp(currNode->data->gender,"T") == 0)){
          (*grads2014) += currNode->data->population;
        }
        if(currNode->data->year == 2015 && (strcmp(currNode->data->gender,"T") == 0)){
          (*grads2015)+= currNode->data->population;
        }
        if(currNode->data->year == 2016 && (strcmp(currNode->data->gender,"T") == 0)){
          (*grads2016) += currNode->data->population;
        }
        if(currNode->data->year == 2017 && (strcmp(currNode->data->gender,"T") == 0)){
          (*grads2017) += currNode->data->population;
        }
}

/*
purpose:  calculate the sum of all type of degree for all countries for a year
in: allGrads2014, the sum of all graaduates for all countries for 2014
in: allGrads2015, the sum of all graaduates for all countries for 2015
in: allGrads2016, the sum of all graaduates for all countries for 2016
in: allGrads2017, the sum of all graaduates for all countries for 2017
*/
void sumAllDegree(DataListType *list, float *allGrads2014, float *allGrads2015, float *allGrads2016, float *allGrads2017){
    DataNodetype *currNode;
    currNode = list->head;

    while(currNode!=NULL){
      if(currNode->data->year == 2014 && (strcmp(currNode->data->gender,"T") == 0)){
        (*allGrads2014) += currNode->data->population;
      }
      if(currNode->data->year == 2015 && (strcmp(currNode->data->gender,"T") == 0)){
        (*allGrads2015)+= currNode->data->population;
      }
      if(currNode->data->year == 2016 && (strcmp(currNode->data->gender,"T") == 0)){
        (*allGrads2016) += currNode->data->population;
      }
      if(currNode->data->year == 2017 && (strcmp(currNode->data->gender,"T") == 0)){
        (*allGrads2017) += currNode->data->population;
      }
      currNode = currNode->next;
    }
}
