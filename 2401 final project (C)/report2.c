#include "defs.h"

/*
purpose:  filters the data from the linked list and perform some calculations then prints out the result
in: list, a pointer to a DataListType struct and a head pointer to a linked list.
in: array a pointer to an RTArrayType struct and a pointer to an array of ReportTwoType elements
*/
void createReportTwo(DataListType *list, RTArrayType *array){
DataNodetype *currNode;
char countryName[15];
char countryCode[5];
float sumFemale = 0;
float total = 0;
float value = 0;
currNode = list->head;
strcpy(countryName,currNode->data->cName);
strcpy(countryCode,currNode->data->cCode);
while(currNode!=NULL){
if(strcmp(currNode->data->cCode,countryCode)==0){
  sumPercentFemale(currNode,&sumFemale,&total);
}
else{
value = (sumFemale/total)*100;
addToArray(array,countryCode,countryName,value);
  strcpy(countryName,currNode->data->cName);
  strcpy(countryCode,currNode->data->cCode);
  sumFemale = total = 0;
sumPercentFemale(currNode,&sumFemale,&total);

}
currNode = currNode->next;
}
value = (sumFemale/total)*100;
addToArray(array,countryCode,countryName,value);
//printing
sortArray(array);
printArray(array);
}

/*
purpose: takes in the currNode and filters through the data, then adds it to the correct running total.
in: currNode, a pointer to a DataNodetype struct, that contains some data
in: sumFemale, a pointer to a float, and the sum of all degress, for all years for all females in a country
in: total, a pointer to a float, and the sum of all degress, for all years for all people in a country
*/
void sumPercentFemale(DataNodetype *currNode, float *sumFemale, float *total){

    if(strcmp(currNode->data->gender,"F") == 0){
      (*sumFemale) += currNode->data->population;
    }
    if(strcmp(currNode->data->gender,"T") == 0){
      (*total) += currNode->data->population;
    }
}

/*
purpose: initialize the datatype, dynamically alocate memory for it
          and set its fields to NULL
in: data, a double pointer to a ReportTwoType struct
in: code, a string with the country code
in: name, a string with the coutry name
in: value, a float with the percentage of female graduates to total population for each country
*/
void initReportTwoData(ReportTwoType **data, char *code,char *name,float value){
  (*data) = malloc(sizeof(ReportTwoType));
  strcpy((*data)->countryCode,code);
  strcpy((*data)->countryName,name);
  (*data)->percentFemale = value;
}


/*
purpose:  initialize the datatype and set its fields to NULL
in: array, a pointer to a RTArrayType struct
*/
void initArray( RTArrayType *array){
  array->size = 0;
  array->elements = NULL;
}

/*
purpose: initialize the data then add it to an array
in: array, a pointer to a RTArrayType struct
in: code, a string with  a code for a country
in: name,  a string with the name of a country
in: value, a float with the percentage of female graduates to total population for each country
*/
void addToArray(RTArrayType *array,char *code, char *name, float value){
ReportTwoType *data;
ReportTwoType **newArr;
initReportTwoData(&data,code,name,value);

newArr = calloc(array->size+1,sizeof(ReportTwoType*));

for(int i = 0 ; i < array->size; i++){
  newArr[i] = array->elements[i];
}
newArr[array->size] = data;
free(array->elements);

array->elements = newArr;
(array->size)++;
}

/*
purpose: sorts the array of pointer in descending order of their percentageFemale field
in: array, a pointer to a RTArrayType struct
*/
void sortArray(RTArrayType *array){
ReportTwoType *temp;
int i;
int j;
temp = array->elements[0];
for(i = 0; i < array->size; i++ ){
  for(j = i+1 ; j < array->size; j++){
    if(array->elements[i]->percentFemale < array->elements[j]->percentFemale){
      temp = array->elements[i];
      array->elements[i] = array->elements[j];
      array->elements[j] = temp;
    }
  }
}
}

/*
purpose:  prints the arrays top five and bottom five countries
in: array, a pointer to a RTArrayType struct
*/
void printArray(RTArrayType *array){
  printf("\nTOP FIVE\n\n");
  printf("  CODE         COUNTRY    percent of females\n");
for(int i =0; i < 5; i++){
  printf(" %5s %17s %6.2f%% \n", array->elements[i]->countryCode,array->elements[i]->countryName,array->elements[i]->percentFemale);
}
printf("\nBOTTOM FIVE\n\n");
printf("  CODE         COUNTRY    percent of females\n");
for(int i = array->size-5; i < array->size; i++){
  printf(" %5s %17s %6.2f%% \n", array->elements[i]->countryCode,array->elements[i]->countryName,array->elements[i]->percentFemale);
}
}

/*
purpose: calls free on the array to free up all the dynamically allocated memeory
in: arr, a RTArrayType struct
*/
void cleanupArray(RTArrayType *arr){

    for(int i = 0; i < arr->size; i++){
      free(arr->elements[i]);
    }
    free(arr->elements);
    arr->elements = NULL;
    arr->size = 0;

}
