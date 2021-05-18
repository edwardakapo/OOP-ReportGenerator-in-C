#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char cCode [15];
  char cName[20];
  char gender[15];
  char degree[15];
  int year;
  int population;
}DataType;

typedef struct Node{
  DataType *data;
  struct Node *next;
}DataNodetype;

typedef struct {
  int nextId;
  DataNodetype *head;
}DataListType;

typedef struct {
  char countryCode[5];
  char countryName[20];
  float percentFemale;
} ReportTwoType;

typedef struct {
  int size;
  ReportTwoType **elements;
} RTArrayType;

//functions
//Datalist
void initData(DataType**,char*,char*,char*,char*,int,int);
void initDataList(DataListType*);
void initDataNode(DataNodetype**);
void printDatalist(DataListType*);
void addToDataList(DataListType*,DataType*);
void cleanuplist(DataListType*);
//report 1
void createReportOne(DataListType*);
void calculateReportOne(float*,float*,float*,float*,int,int,int,int);
void printReportOne(char*,char*,float,float,float,float);
void sumOneDegree(DataListType*,int*,int*,int*,int*);
void sumDegreeInCountry(DataNodetype*,float*,float*,float*);
//report 2
void createReportTwo(DataListType*,RTArrayType*);
void initReportTwoData(ReportTwoType**,char*,char*,float);
void initArray(RTArrayType*);
void addToArray(RTArrayType*,char*,char*,float);
void sortArray(RTArrayType*);
void printArray(RTArrayType*);
void sumPercentFemale(DataNodetype*,float*,float*);
void cleanupArray(RTArrayType*);
//report 3
void createReportThree(DataListType*);
void calcDegreePercent(float*,float*,float*,float*,float,float,float,float);
void printReportThree(char*,char*,float,float,float,float);
void sumDegreeInYear(DataNodetype*,float*,float*,float*,float*);
void sumAllDegree(DataListType*,float*,float*,float*,float*);
// report 4
void createReportFour(DataListType*);
void printReportFour(int,float,float);
void calcGenderPercent(float*,float*);
void sumGenderInYear(DataNodetype*,float*,float*);
void findLastYear(DataListType*,int*);
// report 5
void createReportFive(DataListType*);
void printReportFive(int,float,float,float);
void sumAllDegreeInYear(DataNodetype*,float*,float*,float*);
void calcEachDegreePercent(float*,float*,float*);
