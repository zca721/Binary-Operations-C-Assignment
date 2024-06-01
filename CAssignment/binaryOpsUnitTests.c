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

    printf("Negate Unit Test Cases------------------------------\n");
    int negateValTest1 = 0;
    int *negateSideTest1 = &negateValTest1;
    int negateArrayTest1[3] = {0, 1, 1};\
    int *negateTempTest1 = binNegate(negateArrayTest1, 3, negateSideTest1);
    printf("Output Expected: 0\n");
    printf("Negate Array Test1: ");
    printArray(*negateSideTest1, negateTempTest1);
    free(negateTempTest1);
    printf("\n");

    int negateValTest2 = 0;
    int *negateSideTest2 = &negateValTest2;
    int negateArrayTest2[1] = {0};\
    int *negateTempTest2 = binNegate(negateArrayTest2, 1, negateSideTest2);
    printf("Output Expected: 1\n");
    printf("Negate Array Test2: ");
    printArray(*negateSideTest2, negateTempTest2);
    free(negateTempTest2);
    printf("\n");

    int negateValTest3 = 0;
    int *negateSideTest3 = &negateValTest3;
    int negateArrayTest3[1] = {1};\
    int *negateTempTest3 = binNegate(negateArrayTest3, 1, negateSideTest3);
    printf("Output Expected: 0\n");
    printf("Negate Array Test3: ");
    printArray(*negateSideTest3, negateTempTest3);
    free(negateTempTest3);
    printf("\n");

    printf("And Unit Test Cases---------------------------------\n");
    int andValTest1 = 0;
    int *andSideTest1 = &andValTest1;
    int andArray1Test1[4] = {1, 0, 0, 1};
    int andArray2Test1[4] = {1, 1, 0, 0};
    int *andTempTest1 = binAnd(andArray1Test1, 4, andArray2Test1, 4, andSideTest1);
    printf("Output Expected: 1 0 0 0\n");
    printf("And Array Test1: ");
    printArray(*andSideTest1, andTempTest1);
    free(andTempTest1);
    printf("\n");

    int andValTest2 = 0;
    int *andSideTest2 = &andValTest2;
    int andArray1Test2[2] = {1, 1};
    int andArray2Test2[4] = {0, 0, 0, 1};
    int *andTempTest2 = binAnd(andArray1Test2, 2, andArray2Test2, 4, andSideTest2);
    printf("Output Expected: 1\n");
    printf("And Array Test2: ");
    printArray(*andSideTest2, andTempTest2);
    free(andTempTest2);
    printf("\n");

    int andValTest3 = 0;
    int *andSideTest3 = &andValTest2;
    int andArray1Test3[4] = {1, 1, 1, 1};
    int andArray2Test3[2] = {0, 0};
    int *andTempTest3 = binAnd(andArray1Test3, 4, andArray2Test3, 2, andSideTest3);
    printf("Output Expected: 0\n");
    printf("And Array Test3: ");
    printArray(*andSideTest3, andTempTest3);
    free(andTempTest3);
    printf("\n");

    printf("Or Unit Test Cases----------------------------------\n");
    int orValTest1 = 0;
    int *orSideTest1 = &orValTest1;
    int orArray1Test1[4] = {1, 0, 0, 1};
    int orArray2Test1[4] = {1, 1, 0, 0};
    int *orTempTest1 = binOr(orArray1Test1, 4, orArray2Test1, 4, orSideTest1);
    printf("Output Expected: 1 1 0 1\n");
    printf("Or Array Test1: ");
    printArray(*orSideTest1, orTempTest1);
    free(orTempTest1);
    printf("\n");

    int orValTest2 = 0;
    int *orSideTest2 = &orValTest2;
    int orArray1Test2[2] = {0, 1};
    int orArray2Test2[4] = {0, 0, 0, 0};
    int *orTempTest2 = binOr(orArray1Test2, 2, orArray2Test2, 4, orSideTest2);
    printf("Output Expected: 1\n");
    printf("Or Array Test2: ");
    printArray(*orSideTest2, orTempTest2);
    free(orTempTest2);
    printf("\n");

    int orValTest3 = 0;
    int *orSideTest3 = &orValTest3;
    int orArray1Test3[4] = {0, 0, 0, 0};
    int orArray2Test3[2] = {0, 0};
    int *orTempTest3 = binOr(orArray1Test3, 4, orArray2Test3, 2, orSideTest3);
    printf("Output Expected: 0\n");
    printf("Or Array Test3: ");
    printArray(*orSideTest3, orTempTest3);
    free(orTempTest3);
    printf("\n");

    printf("Xor Unit Test Cases---------------------------------\n");
    int xorValTest1 = 0;
    int *xorSideTest1 = &xorValTest1;
    int xorArray1Test1[4] = {1, 0, 0, 1};
    int xorArray2Test1[4] = {1, 1, 0, 0};
    int *xorTempTest1 = binXor(xorArray1Test1, 4, xorArray2Test1, 4, xorSideTest1);
    printf("Output Expected: 1 0 1\n");
    printf("Xor Array Test1: ");
    printArray(*xorSideTest1, xorTempTest1);
    free(xorTempTest1);
    printf("\n");

    int xorValTest2 = 0;
    int *xorSideTest2 = &xorValTest2;
    int xorArray1Test2[2] = {0, 1};
    int xorArray2Test2[4] = {0, 0, 0, 0};
    int *xorTempTest2 = binXor(xorArray1Test2, 2, xorArray2Test2, 4, xorSideTest2);
    printf("Output Expected: 1\n");
    printf("Xor Array Test2: ");
    printArray(*xorSideTest2, xorTempTest2);
    free(xorTempTest2);
    printf("\n");

    int xorValTest3 = 0;
    int *xorSideTest3 = &xorValTest3;
    int xorArray1Test3[4] = {0, 0, 0, 1};
    int xorArray2Test3[2] = {0, 1};
    int *xorTempTest3 = binXor(xorArray1Test3, 4, xorArray2Test3, 2, xorSideTest3);
    printf("Output Expected: 0\n");
    printf("Xor Array Test3: ");
    printArray(*xorSideTest3, xorTempTest3);
    free(xorTempTest3);
    printf("\n");

    printf("Add Unit Test Cases---------------------------------\n");
    int addValTest1 = 0;
    int *addSideTest1 = &addValTest1;
    int addArray1Test1[3] = {1, 0, 1};
    int addArray2Test1[3] = {1, 0, 0};
    int *addTempTest1 = binAdd(addArray1Test1, 3, addArray2Test1, 3, addSideTest1);
    printf("Output Expected: 1 0 0 1\n");
    printf("Add Array Test1: ");
    printArray(*addSideTest1, addTempTest1);
    free(addTempTest1);
    printf("\n");

    int addValTest2 = 0;
    int *addSideTest2 = &addValTest2;
    int addArray1Test2[1] = {1};
    int addArray2Test2[3] = {0, 0, 0};
    int *addTempTest2 = binAdd(addArray1Test2, 1, addArray2Test2, 3, addSideTest2);
    printf("Output Expected: 1\n");
    printf("Add Array Test2: ");
    printArray(*addSideTest2, addTempTest2);
    free(addTempTest2);
    printf("\n");

    int addValTest3 = 0;
    int *addSideTest3 = &addValTest3;
    int addArray1Test3[3] = {0, 0, 0};
    int addArray2Test3[1] = {0};
    int *addTempTest3 = binAdd(addArray1Test3, 3, addArray2Test3, 1, addSideTest3);
    printf("Output Expected: 0\n");
    printf("Add Array Test3: ");
    printArray(*addSideTest3, addTempTest3);
    free(addTempTest3);
    printf("\n");

    printf("Trim Unit Test Cases--------------------------------\n");
    int trimValTest1 = 0;
    int *trimSideTest1 = &trimValTest1;
    int binaryArrayTest1[4] = {0, 0, 1, 1};
    int *tempTest1 = trimLeading(binaryArrayTest1, 4, trimSideTest1);
    printf("Output Expected: 1 1\n");
    printf("Trim Leading Zeros Test1: ");
    printArray(*trimSideTest1, tempTest1);
    free(tempTest1);
    printf("\n");

    int trimValTest2 = 0;
    int *trimSideTest2 = &trimValTest2;
    int binaryArrayTest2[4] = {0, 0, 0, 0};
    int *tempTest2 = trimLeading(binaryArrayTest2, 4, trimSideTest2);
    printf("Output Expected: 0\n");
    printf("Trim Leading Zeros Test2: ");
    printArray(*trimSideTest2, tempTest2);
    free(tempTest2);
    printf("\n");

    int trimValTest3 = 0;
    int *trimSideTest3 = &trimValTest3;
    int binaryArrayTest3[4] = {0, 0, 0, 1};
    int *tempTest3 = trimLeading(binaryArrayTest3, 4, trimSideTest3);
    printf("Output Expected: 1\n");
    printf("Trim Leading Zeros Test3: ");
    printArray(*trimSideTest3, tempTest3);
    free(tempTest3);
    printf("\n");
}