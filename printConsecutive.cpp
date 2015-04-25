//
//  printConsecutive.cpp
//  arrays.cpp
//
//  Created by brian hudnall on 4/10/13.
//  Copyright (c) 2013 brian hudnall. All rights reserved.
//

#include "printConsecutive.h"

void printConsecutive(int array[], int n){
    
    const int CONSEC = 3;
    int totalCount = 0;
    int highestSub;
    int lowestSub;
    double total = 0.0;
    double average;
    double newAve;
    double highAve;
    double lowAve;
    bool moreThanTwo = false;
    
    for (int i = 0; i < CONSEC; i++){
        total += array[i];
        totalCount++;
    }
    average = total / CONSEC;
    cout << "\nfirst average: " << average << endl;
    highestSub = totalCount;
    lowestSub = totalCount;
    lowAve = average;
    highAve = average;
    for (totalCount = 1; totalCount <= CONSEC; totalCount++){
        cout << "\nRun through count: " << totalCount << endl;
        while (totalCount < (n - 2)){
            total = 0;
            int newMax = totalCount + CONSEC;
            for(int j = totalCount; j < newMax; j++){
                total += array[j];
                totalCount++;
            }
            newAve = total / CONSEC;
            if ((newAve == highAve) && (highestSub > CONSEC)){
                moreThanTwo = true;
            }
            if (newAve > highAve){
                highAve = newAve;
                cout << "\nsuccessive average: " << highAve << endl;
                highestSub = totalCount;
                moreThanTwo = false;
            }
            if (newAve < lowAve){
                lowAve = newAve;
                lowestSub = totalCount;
            }
        }
    }
    if (moreThanTwo == false){
        cout << "\nThe following three numbers are the"
        << " consecutive elements within the array"
        << " that have the greatest average: ";
        for (int i = (highestSub - 2); i <= highestSub; i++){
            cout << i << " ";
        }
    }
    else {
        cout << "\nThe following three numbers are the"
        << " consecutive elements within the array"
        << " that have the lowest average: ";
        for(int i = (lowestSub - 2); i <= lowestSub; i++){
            cout << i << " ";
        }
    }
    return;
}