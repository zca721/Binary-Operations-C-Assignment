#include <stdio.h>
#include <stdlib.h>

void printArray(int size, int arr[]) {
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int *padZeros(int *bin1, int size1, int *bin2, int size2, int *outSide) {
    int *array = malloc(sizeof(int) * *outSide);
    if (size1 < size2) {
        *outSide = size2;
        int *array = malloc(sizeof(int) * *outSide);
        int offset1 = size2 - size1;
        int iterationSize1 = size2 - size1;
        int count1 = 0;
        for (int i = 0; i < iterationSize1 + 1; i++) {
            array[offset1] = bin1[i];
            offset1++;

            // Adds zeros to the front of the array
            if (count1 < iterationSize1) {
                array[i] = 0;
            }
            count1++;
        }

        return array;
    } else if (size2 < size1) {
        *outSide = size1;
        int *array = malloc(sizeof(int) * *outSide);
        int offset2 = size1 - size2;
        int iterationSize2 = size1 - size2;
        int count2 = 0;
        for (int i = 0; i < iterationSize2 + 1; i++) {
            array[offset2] = bin2[i];
            offset2++;

            // Adds zeros to the front of the array
            if (count2 < iterationSize2) {
                array[i] = 0;
            }
            count2++;
        }

        return array;
    }

    return array;
}

int *trimLeading(int *bin, int size, int *outSide) {
    int index = 0;
    int altSize = size;
    while (bin[index] == 0 && altSize != 1) {
        index++;
        altSize--;
    }

    *outSide = size - index;
    int *trimArray = malloc(sizeof(int) * *outSide);
    for (int i = 0; i < *outSide; i++) {
        trimArray[i] = bin[i + index];
    }

    return trimArray;
}

/*
 *  Binary Negate Operation
 */
int *binNegate(int *bin, int size, int *outSide) {
    *outSide = size;
    int *negateArray = malloc(sizeof(int) * *outSide);
    for (int i = 0; i < *outSide; i++) {
        negateArray[i] = bin[i];
    }
    printf("Start Array: ");
    printArray(*outSide, negateArray);

    int *trimNegateArray1 = trimLeading(negateArray, *outSide, outSide);
    printf("Initial Trim Array: ");
    printArray(*outSide, trimNegateArray1);
    for (int i = 0; i < *outSide; i++) {
        if (trimNegateArray1[i] == 1) {
            trimNegateArray1[i] = 0;
        } else if (trimNegateArray1[i] == 0) {
            trimNegateArray1[i] = 1;
        }
    }
    int *trimNegateArray2 = trimLeading(trimNegateArray1, *outSide, outSide);
    
    return trimNegateArray2;
    free(negateArray);      // may not need
    free(trimNegateArray1); // may not need
    free(trimNegateArray2); // may not need
}

/*
 *  Binary And Operation
 */
int *binAnd(int *bin1, int size1, int *bin2, int size2, int *outSide) {
    int *andArray = malloc(sizeof(int) * *outSide);
    if (size1 < size2) {
        int *tempSize1 = padZeros(bin1, size1, bin2, size2, outSide);
        printf("Padded Array1: ");
        printArray(*outSide, tempSize1);
        printf("Start Array2: ");
        printArray(*outSide, bin2);
        for (int i = 0; i < *outSide; i++) {
            if (tempSize1[i] == 1 && bin2[i] == 1) {
                andArray[i] = 1;
            } else {
                andArray[i] = 0;
            }
        }
    int *trimAndArray = trimLeading(andArray, *outSide, outSide);
    
    return trimAndArray;
    free(andArray);     // may not need
    free(tempSize1);    // may not need
    free(trimAndArray); // may not need
    } else if (size2 < size1) {
        int *tempSize2 = padZeros(bin1, size1, bin2, size2, outSide);
        printf("Start Array1: ");
        printArray(*outSide, bin1);
        printf("Padded Array2: ");
        printArray(*outSide, tempSize2);
        for (int i = 0; i < *outSide; i++) {
            if (bin1[i] == 1 && tempSize2[i] == 1) {
                andArray[i] = 1;
            } else {
                andArray[i] = 0;
            }
        }
    int *trimAndArray = trimLeading(andArray, *outSide, outSide);
    
    return trimAndArray;
    free(andArray);     // may not need
    free(tempSize2);    // may not need
    free(trimAndArray); // may not need
    } else {
        *outSide = size2;
        int *andArray = malloc(sizeof(int) * *outSide);
        printf("Start Array1: ");
        printArray(*outSide, bin1);
        printf("Start Array2: ");
        printArray(*outSide, bin2);
        for (int i = 0; i < *outSide; i++) {
            if (bin1[i] == 1 && bin2[i] == 1) {
                andArray[i] = 1;
            } else {
                andArray[i] = 0;
            }
        }
    int *trimAndArray = trimLeading(andArray, *outSide, outSide);
    
    return trimAndArray;
    free(andArray);     // may not need
    free(trimAndArray); // may not need
    }

    return andArray;
    free(andArray);
}

/*
 * Binary Or Operation
 */
int *binOr(int *bin1, int size1, int *bin2, int size2, int *outSide) {
    int *orArray = malloc(sizeof(int) * *outSide);
    if (size1 < size2) {
        int *tempSize1 = padZeros(bin1, size1, bin2, size2, outSide);
        printf("Padded Array1: ");
        printArray(*outSide, tempSize1);
        printf("Start Array2: ");
        printArray(*outSide, bin2);
        for (int i = 0; i < *outSide; i++) {
            if (tempSize1[i] == 1 || bin2[i] == 1) {
                orArray[i] = 1;
            } else {
                orArray[i] = 0;
            }
        }
    int *trimOrArray = trimLeading(orArray, *outSide, outSide);
    
    return trimOrArray;
    free(orArray);      // may not need
    free(tempSize1);    // may not need
    free(trimOrArray);  // may not need
    } else if (size2 < size1) {
        int *tempSize2 = padZeros(bin1, size1, bin2, size2, outSide);
        printf("Start Array1: ");
        printArray(*outSide, bin1);
        printf("Padded Array2: ");
        printArray(*outSide, tempSize2);
        for (int i = 0; i < *outSide; i++) {
            if (bin1[i] == 1 || tempSize2[i] == 1) {
                orArray[i] = 1;
            } else {
                orArray[i] = 0;
            }
        }
    int *trimOrArray = trimLeading(orArray, *outSide, outSide);
    
    return trimOrArray;
    free(orArray);      // may not need
    free(tempSize2);    // may not need
    free(trimOrArray);  // may not need
    } else {
        *outSide = size1;
        int *orArray = malloc(sizeof(int) * *outSide);
        printf("Start Array1: ");
        printArray(*outSide, bin1);
        printf("Start Array1: ");
        printArray(*outSide, bin2);
        for (int i = 0; i < *outSide; i++) {
            if (bin1[i] == 1 || bin2[i] == 1) {
                orArray[i] = 1;
            }  else {
                orArray[i] = 0;
            }
        }
    int *trimOrArray = trimLeading(orArray, *outSide, outSide);
    
    return trimOrArray;
    free(orArray);      // may not need
    free(trimOrArray);  // may not need
    }

    return orArray;
    free(orArray);      // may not need
}


/*
 * Binary Xor Operation
 */
int *binXor(int *bin1, int size1, int *bin2, int size2, int *outSide) {
    int *xorArray = malloc(sizeof(int) * *outSide);
    if (size1 < size2) {
        int *tempSize1 = padZeros(bin1, size1, bin2, size2, outSide);
        printf("Padded Array1: ");
        printArray(*outSide, tempSize1);
        printf("Start Array2: ");
        printArray(*outSide, bin2);
        for (int i = 0; i < *outSide; i++) {
            if (tempSize1[i] == 1 && bin2[i] == 0) {
                xorArray[i] = 1;
            } else if (tempSize1[i] == 0 && bin2[i] == 1) {
                xorArray[i] = 1;
            } else {
                xorArray[i] = 0;
            }
        }
    int *trimXorArray = trimLeading(xorArray, *outSide, outSide);
    
    return trimXorArray;
    free(xorArray);     // may not need
    free(tempSize1);    // may not need
    free(trimXorArray); // may not need
    } else if (size2 < size1) {
        int *tempSize2 = padZeros(bin1, size1, bin2, size2, outSide);
        printf("Start Array1: ");
        printArray(*outSide, bin1);
        printf("Padded Array2: ");
        printArray(*outSide, tempSize2);
        for (int i = 0; i < *outSide; i++) {
            if (bin1[i] == 1 && tempSize2[i] == 0) {
                xorArray[i] = 1;
            } else if (bin1[i] == 0 && tempSize2[i] == 1) {
                xorArray[i] = 1;
            } else {
                xorArray[i] = 0;
            }
        }
    int *trimXorArray = trimLeading(xorArray, *outSide, outSide);
    
    return trimXorArray;
    free(xorArray);     // may not need
    free(tempSize2);    // may not need
    free(trimXorArray); // may not need
    } else {
        *outSide = size1;
        int *xorArray = malloc(sizeof(int) * *outSide);
        printf("Start Array1: ");
        printArray(*outSide, bin1);
        printf("Start Array2: ");
        printArray(*outSide, bin2);
        for (int i = 0; i < *outSide; i++) {
            if (bin1[i] == 1 && bin2[i] == 0) {
                xorArray[i] = 1;
            } else if (bin1[i] == 0 && bin2[i] == 1) {
                xorArray[i] = 1;
            } else {
                xorArray[i] = 0;
            }
        }
    int *trimXorArray = trimLeading(xorArray, *outSide, outSide);
    
    return trimXorArray;
    free(xorArray);     // may not need
    free(trimXorArray); // may not need
    }

    return xorArray;
    free(xorArray);     // may not need
}

/*
 * Binary Add Operation
 */
int *binAdd(int *bin1, int size1, int *bin2, int size2, int *outSide) {
    int *addArray = malloc(sizeof(int) * *outSide);
    if (size1 < size2) {
        int remainder1 = 0;
        int *tempSize1 = padZeros(bin1, size1, bin2, size2, outSide);
        printf("Padded Array1: ");
        printArray(*outSide, tempSize1);
        printf("Start Array2: ");
        printArray(*outSide, bin2);
        for (int i = *outSide; i >= 0; i--) {
            if (remainder1 == 0 && tempSize1[i] == 0 && bin2[i] == 0) {
                addArray[i] = 0;
            } else if (remainder1 == 0 && tempSize1[i] == 0 && bin2[i] == 1) {
                addArray[i] = 1;
            } else if (remainder1 == 0 && tempSize1[i] == 1 && bin2[i] == 0) {
                addArray[i] = 1;
            } else if (remainder1 == 0 && tempSize1[i] == 1 && bin2[i] == 1) {
                addArray[i] = 0;
                remainder1++;
            } else if (remainder1 == 1 && tempSize1[i] == 1 && bin2[i] == 0) {
                addArray[i] = 0;
            } else if (remainder1 == 1 && tempSize1[i] == 0 && bin2[i] == 1) {
                addArray[i] = 0;
            } else if (remainder1 == 1 && tempSize1[i] == 1 && bin2[i] == 1) {
                addArray[i] = 1;
            } else if (remainder1 == 1 && tempSize1[i] == 0 && bin2[i] == 0) {
                addArray[i] = 1;
                remainder1--;
            } 
        }
    if (remainder1 == 1) {
        *outSide = size2 + 1;
        for (int i = *outSide; i >= 0; i--) {
            addArray[i + 1] = addArray[i];
        }
        addArray[0] = 1;
    }
    int *trimAddArray = trimLeading(addArray, *outSide, outSide);
    
    return trimAddArray;
    free(addArray);     // may not need
    free(tempSize1);    // may not need
    free(trimAddArray); // may not need
    } else if (size2 < size1) {
        int remainder2 = 0;
        int *tempSize2 = padZeros(bin1, size1, bin2, size2, outSide);
        printf("Start Array1: ");
        printArray(*outSide, bin1);
        printf("Padded Array2: ");
        printArray(*outSide, tempSize2);
        for (int i = *outSide; i >= 0; i--) {
            if (remainder2 == 0 && bin1[i] == 0 && tempSize2[i] == 0) {
                addArray[i] = 0;
            } else if (remainder2 == 0 && bin1[i] == 0 && tempSize2[i] == 1) {
                addArray[i] = 1;
            } else if (remainder2 == 0 && bin1[i] == 1 && tempSize2[i] == 0) {
                addArray[i] = 1;
            } else if (remainder2 == 0 && bin1[i] == 1 && tempSize2[i] == 1) {
                addArray[i] = 0;
                remainder2++;
            } else if (remainder2 == 1 && bin1[i] == 1 && tempSize2[i] == 0) {
                addArray[i] = 0;
            } else if (remainder2 == 1 && bin1[i] == 0 && tempSize2[i] == 1) {
                addArray[i] = 0;
            } else if (remainder2 == 1 && bin1[i] == 1 && tempSize2[i] == 1) {
                addArray[i] = 1;
            } else if (remainder2 == 1 && bin1[i] == 0 && tempSize2[i] == 0) {
                addArray[i] = 1;
                remainder2--;
            } 
        }
    if (remainder2 == 1) {
        *outSide = size1 + 1;
        for (int i = *outSide; i >= 0; i--) {
            addArray[i + 1] = addArray[i];
        }
        addArray[0] = 1;
    }
    int *trimAddArray = trimLeading(addArray, *outSide, outSide);
    
    return trimAddArray;
    free(addArray);     // may not need
    free(tempSize2);    // may not need
    free(trimAddArray); // may not need
    } else {
        int remainder3 = 0;
        *outSide = size1;
        int *addArray = malloc(sizeof(int) * *outSide);
        printf("Start Array1: ");
        printArray(*outSide, bin1);
        printf("Start Array2: ");
        printArray(*outSide, bin2);
        for (int i = *outSide; i >= 0; i--) {
            if (remainder3 == 0 && bin1[i] == 0 && bin2[i] == 0) {
                addArray[i] = 0;
            } else if (remainder3 == 0 && bin1[i] == 0 && bin2[i] == 1) {
                addArray[i] = 1;
            } else if (remainder3 == 0 && bin1[i] == 1 && bin2[i] == 0) {
                addArray[i] = 1;
            } else if (remainder3 == 0 && bin1[i] == 1 && bin2[i] == 1) {
                addArray[i] = 0;
                remainder3++;
            } else if (remainder3 == 1 && bin1[i] == 1 && bin2[i] == 0) {
                addArray[i] = 0;
            } else if (remainder3 == 1 && bin1[i] == 0 && bin2[i] == 1) {
                addArray[i] = 0;
            } else if (remainder3 == 1 && bin1[i] == 1 && bin2[i] == 1) {
                addArray[i] = 1;
            } else if (remainder3 == 1 && bin1[i] == 0 && bin2[i] == 0) {
                addArray[i] = 1;
                remainder3--;
            } 
        }
    if (remainder3 == 1) {
        *outSide = size1 + 1;
        for (int i = *outSide; i >= 0; i--) {
            addArray[i + 1] = addArray[i];
        }
        addArray[0] = 1;
    }
    int *trimAddArray = trimLeading(addArray, *outSide, outSide);
    
    return trimAddArray;
    free(addArray);     // may not need
    free(trimAddArray); // may not need
    }

    return addArray;
    free(addArray);     // may not need
}

int main() {
    int negateVal = 0;
    int *negateSide = &negateVal;
    int negateArray[9] = {1, 0, 0, 1, 1, 1, 0, 1, 1};\
    int *negateTemp = binNegate(negateArray, 9, negateSide);
    printf("Negate Array: ");
    printArray(*negateSide, negateTemp);
    free(negateTemp);
    printf("\n");
   
    int andVal = 0;
    int *andSide = &andVal;
    int andArray1[9] = {1, 0, 0, 1, 1, 1, 0, 0, 1};
    int andArray2[4] = {1, 1, 0, 0};
    int *andTemp = binAnd(andArray1, 9, andArray2, 4, andSide);
    printf("And Array: ");
    printArray(*andSide, andTemp);
    free(andTemp);
    printf("\n");

    int orVal = 0;
    int *orSide = &orVal;
    int orArray1[9] = {1, 0, 0, 1, 1, 1, 0, 0, 1};
    int orArray2[4] = {1, 1, 0, 0};
    int *orTemp = binOr(orArray1, 9, orArray2, 4, orSide);
    printf("Or Array: ");
    printArray(*orSide, orTemp);
    free(orTemp);
    printf("\n");

    int xorVal = 0;
    int *xorSide = &xorVal;
    int xorArray1[9] = {1, 0, 0, 1, 1, 1, 0, 0, 1};
    int xorArray2[4] = {1, 1, 0, 0};
    int *xorTemp = binXor(xorArray1, 9, xorArray2, 4, xorSide);
    printf("Xor Array: ");
    printArray(*xorSide, xorTemp);
    free(xorTemp);
    printf("\n");

    int addVal = 0;
    int *addSide = &addVal;
    int addArray1[5] = {1, 1, 0, 0, 1};
    int addArray2[4] = {1, 1, 0, 0};
    int *addTemp = binAdd(addArray1, 5, addArray2, 4, addSide);
    printf("Add Array: ");
    printArray(*addSide, addTemp);
    free(addTemp);
    printf("\n");

    int trimVal = 0;
    int *trimSide = &trimVal;
    int binaryArray[9] = {0, 0, 0, 1, 1, 1, 0, 0, 1};
    int *temp = trimLeading(binaryArray, 9, trimSide);
    printf("Trim Leading Zeros: ");
    printArray(*trimSide, temp);
    free(temp);
    printf("\n");

}