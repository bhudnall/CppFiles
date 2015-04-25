/*
    Name  : Brian Hudnall

    Purpose : Creates a random array with a maximum number of values that
        is provided by the user. The values within the array are then printed.
        The program then calculates the average and the number of values
        that are greater than the average. The program also prints the three
        consecute subscripts that contain values with the highest average.
        The program then prints the number of unique values within the array
        in the form of a percentage.
    Description: The program asks the user for a value which is passed on 
        to the fillArray function. fillArray created an array filled with 
        random values. The values are then printed with 10 values per line.
        The average is then calculated and the number of values within 
        the array that are greater than the average are printed. The program
        then calculates the three consecutive values within the array that 
        have the highest average, the subscripts are then printed. The last 
        calculation is the number of unique values within the array, which 
        is printed in the form of a percentage.
 */

#include <iostream>
#include <time.h>
using namespace std;
void fillArray(int [], int);
void printArray(int [], int);
double average(int [], int);
int countAboveAverage(int [], int, double);
void printConsecutive(int [], int);
int search(int[], int, int);
double coverage(int [], int);

int main()
{
    const int MAX = 100;
    int array[MAX];
    int n;
    
    cout << "Enter an integer between 3 and 100: ";
    cin >> n;
    
    fillArray(array, n);
    printArray(array, n);
    cout << "\n\nThe count above average is: "
    << countAboveAverage(array, n, average(array, n)) << endl;
    printConsecutive(array, n);
    cout << "\n\nThe coverage is " << coverage(array, n) << endl;
    
    return 0;
}
/*
    Function : fillArray
    Description : Fills the array with random values. The values range
        from 0 to 100 and the number of values is indicated by the n value.
*/
void fillArray(int array[], int n){
    
    int randValue;
    srand(time(NULL));
    
    for(int i = 0; i < n; i++){
        randValue = rand();
        randValue = randValue % 100;
        array[i] = abs(randValue);
    }
    return;
}
/*
    Function : printArray
    Description : Prints the array with 10 values per line. Each value
        has a comma after it unless it is the last value.
*/
void printArray(int array[], int n){
    
    cout << "\nThe following numbers are within your array: " << endl;
    cout << array[0];
    for(int i = 1; i < n; i++){
        if ((i > 1) && (i % 10 == 0)){
            cout << endl;
        }
        cout << ", " << array[i];
    }
    return;
}
/*
    Function : average
    Description : Finds the average of the values within an array.
*/
double average(int array[], int n){
    
    double average = 0;
    double total = 0;
    for (int i = 0; i < n; i++){
        total += array[i];
    }
    average = total / n;
    return average;
}
/*
    Function : countAboveAverage
    Description : Counts the number of values that are higher
        than the array average.
*/
int countAboveAverage(int array[], int n, double average){
    
    int count = 0;
    for(int i = 0; i < n; i++){
        if (array[i] > average){
            count++;
        }
    }
    return count;
}
/*
    Function : printConsecutive
    Description : Prints the three consecutive subscripts that have the highest
        average.
*/
void printConsecutive(int array[], int n){
    
    int const CONSEC = 3;
    double maxValue = 0;
    int maxIndex;
    double total;
    double average;
    for(int i = 0; i < (n - 2); i++){
        total = array[i] + array[i + 1] + array[i + 2];
        average = total / CONSEC;
        if (average > maxValue){
            maxValue = average;
            maxIndex = i;
        }
    }
    cout << "\nThe subscript locations of the three consecutive values "
         << "that yield the maximum average are: " << maxIndex
         << " " << maxIndex + 1 << " " << maxIndex + 2 << endl;
    
    return;
}
/*
    Function : search
    Description : Used exclusively by the coverage function, search
        returns the subscropt of the location entered or -1 if 
        the value isn't found.
*/
int search(int array[], int n, int key){
    int result = -1;
    for(int i = 0; i < n; i++){
        if (key == array[i]){
            result = i;
        }
    }
    return result;
}
/*
    Function : coverage
    Description : returns the number of unique values within the array
        in the form of a percentage.
*/
double coverage(int array[], int n){
    const int MAX = 100;
    int count = 0;
    double percent;
    int result;
    for(int i = 0; i <= MAX; i++){
        result = search(array, n, i);
        if (result >= 0){
            count++;
        }
    }
    percent = (double)count / MAX;
    return percent;
}










