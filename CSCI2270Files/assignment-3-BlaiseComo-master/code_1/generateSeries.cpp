#include "generateSeries.hpp"
#include<iostream>

using namespace std;

void generateSeries(int* &arr, int &n, int &m, int &arraySize){

    arr[0] = n;

    for (int i = 1; i < arraySize; i++) {

        arr[i] = arr[i-1] * m;

    }

}