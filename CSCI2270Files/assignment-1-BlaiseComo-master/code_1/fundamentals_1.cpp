#include "fundamentals_1.hpp"

int addToArrayDesc(float sortedArray[], int numElements, float newValue){

    if (numElements <= 100) {

        sortedArray[numElements-1] = newValue;

        for (int i = 1; i < numElements; i++) {

            // This is the sorting algorithm that arranges the data in descending order, it is likely not as efficient as it could be but it does the job
            if (sortedArray[i] > sortedArray[i-1]) {

                int temp = sortedArray[i-1];

                sortedArray[i-1] = sortedArray[i];

                sortedArray[i] = temp;

                i = 1;

            }

        }

    }

    return numElements+1;

}

    
