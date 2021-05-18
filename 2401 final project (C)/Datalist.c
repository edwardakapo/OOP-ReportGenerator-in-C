#include "defs.h"

// use this .c file to create the data list

/*
purpose: initialize the data list and set its fields to NULL and 0
in: data, a pointer to a DataListType struct
*/
void initDataList(DataListType *list){
list->head = NULL;
list->nextId = 0;
}

/*
purpose: initialize the data nodes, dynamically alocate memory for it
 and set its fields to NULL
in: node, a double pointer to a DataNodeType struct

*/
void initDataNode(DataNodetype **node){
  *node = malloc(sizeof(DataNodetype));
  (*node)->data = NULL;
  (*node)->next = NULL;
}

/*
purpose: initialize the datatype, dynamically alocate memory for it
          and set its fields to NULL
in: data, a double pointer to a DataType struct
in: countryCode, a string with a code name for a country
in: countryName,  a string with the name of a country
in: gender, a string with a code for the gender
in: degree, a string with a code for the degree
in: year, an int for the year
in: population, an int for the population
*/
void initData(DataType **data, char *countryCode,char *countryName, char *gender, char *degree,int year,int population){
  *data = malloc(sizeof(DataType));
  strcpy((*data)->cCode, countryCode);
  strcpy((*data)->cName,countryName);
  strcpy((*data)->gender, gender);
  strcpy((*data)->degree,degree);
  (*data)->year = year;
  (*data)->population = population;
}


/*
purpose: adds data to a list
in: list, a pointer to a DataListType struct
in: data, a pointer to a DataType struct
*/
void addToDataList(DataListType *list, DataType *data){
  DataNodetype *currNode;
  DataNodetype *newNode;
  if(list->nextId == 0){
    initDataNode(&newNode);
    list->head = newNode;
    newNode->data = data;
    (list->nextId)++;
  }
  else{
    currNode = list->head;
    initDataNode(&newNode);
    newNode->data = data;
    while(currNode->next != NULL){
      currNode = currNode->next;
    }
    currNode->next = newNode;
    (list->nextId)++;
  }
}

/*
purpose: prints the list of data
in: list, a pointer to a DataListType struct
*/
void printDatalist(DataListType *list){
  DataNodetype *currNode = list->head;
  printf("LIST OF DATA\n");
  while(currNode!=NULL){
    printf("%4s %20s %2s %3s %5d %10d\n",currNode->data->cCode,currNode->data->cName,currNode->data->gender,currNode->data->degree,currNode->data->year,currNode->data->population);
    currNode = currNode->next;
  }
}
/*
purpose: calls free on the list to free up all the dynamically allocated memeory
in: list, a DataListType struct
*/
 void cleanuplist(DataListType *list){
   DataNodetype *currNode;
   DataNodetype *nextNode;

   currNode = list->head;
   while(currNode!=NULL){
     nextNode = currNode->next;
     free(currNode->data);
     free(currNode);
     currNode = nextNode;
   }
   free(currNode);
   free(nextNode);
 }
