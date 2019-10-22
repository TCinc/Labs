/** lab25.h
* ================================================================
* Name: Charleen Muyot
* Section: T3/4
* Project: Lab25
* Doc Statement:
* =================================================================
*/

#ifndef LAB25_LAB25_H
#define LAB25_LAB25_H

#endif //LAB25_LAB25_H

typedef struct PointsOnLine {
    double x;
    double y;
} Point;

typedef struct USAFStruct{
    char baseName[50];
    int bldgsOwned;
    int structsOwned;
    char city[50];
    char state[30];
}USAFBaseData;

void getPoints (Point* point1, Point* point2);
double getDistance(Point point1, Point point2);

int getNumLines(char filename[]);
void readFile(char filename[], USAFBaseData**baseStruct, int lines);
void printData(USAFBaseData**bases, int numBases);
