#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "lab25.h"

/** lab25.c
* ================================================================
* Name: Charleen Muyot
* Section: T3/4
* Project: Lab 25
* Doc Statement:]
* =================================================================
*/
#define FILENAME "lab25Data.csv"

int main(){

    double totalDistance = 0;
    int numLines = 0;
    int i = 0;

    Point* point1 = (Point*)malloc(sizeof(Point));
    Point * point2 = (Point*)malloc(sizeof(Point));;

    getPoints (point1, point2);

    totalDistance = getDistance(*point1, *point2);

    printf("%lf\n", totalDistance);

    numLines = getNumLines(FILENAME);
    USAFBaseData**pointer = (USAFBaseData**)malloc(sizeof(USAFBaseData*)*numLines);
    for (i=0; i<numLines; ++i){
        pointer[i] = malloc(sizeof(USAFBaseData));
    }

    readFile(FILENAME, pointer, numLines);

    printData(pointer, numLines);

}

void getPoints (Point* point1, Point* point2){

    printf("Input x and y values of two points\n");
    scanf("%lf %lf", &(*point1).x, &(*point1).y);
    scanf("%lf %lf", &(*point2).x, &(*point2).y);
}

double getDistance(Point point1, Point point2){
    double distanceX = 0;
    double distanceY = 0;
    double totDistance= 0;

    distanceX = (point1).x - (point2).x;
    distanceY = (point1).y - (point2).y;

    totDistance = sqrt(pow(distanceX,2)+pow(distanceY,2));

    return totDistance;

}

int getNumLines(char filename[]){
    char c;
    int count = 0;

    FILE* fp = fopen(filename, "r");

    if (fp==NULL){
        printf("Could not open the file %s", filename);
        return 0;
    }

    for (c=getc(fp); c!=EOF; c=getc(fp)){
        if (c=='\n')
            count = count + 1;
    }
    fclose(fp);

    return count;
}

void readFile(char filename[], USAFBaseData**baseStruct, int lines){
    int i = 0;
    char temp[100];

    FILE* fp = fopen(filename, "r");

    fgets(temp,1000,fp);

    for(i=0; i<lines; ++i){
        fscanf(fp, "%[^\n,],", baseStruct[i]->baseName);
        fscanf(fp, "%d,", &baseStruct[i]->bldgsOwned);
        fscanf(fp, "%d,", &baseStruct[i]->structsOwned);
        fscanf(fp, "%[^\n,],", baseStruct[i]->city);
        fscanf(fp, "%[^\n,],", baseStruct[i]->state);
        fgets(temp,1000,fp);
    }

}

void printData(USAFBaseData**bases, int numBases) {
    int i;

    for (i = 0; i < numBases; ++i) {
        printf("%s, ", bases[i]->baseName);
        printf("%d, ", bases[i]->bldgsOwned);
        printf("%d, ", bases[i]->structsOwned);
        printf("%s, ", bases[i]->city);
        printf("%s\n", bases[i]->state);
    }
}
