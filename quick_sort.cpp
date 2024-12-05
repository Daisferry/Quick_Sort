#include <iostream>

using namespace std;

void quickSort(int* unsArr, int sizeArr)
{

    //return checks for recurivity
    if (sizeArr<=1)
    {
        cout<<unsArr[0]<<'\n';
        return;
    }

    //temp = temporary swap value, i = counter for the whole array, j = finding the pivot location
    int temp, i=0, j=-1;

    //pivot, the base of quick sorting
    int pivot = unsArr[sizeArr-1];
    
    //cycling through the array and locating the pivot , j
    while(i < sizeArr-1)
    {
        i++;
        if(unsArr[i]<=pivot)
        {
            j++;
            temp = unsArr[j];
            unsArr[j] = unsArr[i];
            unsArr[i] = temp;
        }
    }


    //memorizing space needed for sub arrays
    int subArrSize_1 = j;
    int subArrSize_2 = (sizeArr - subArrSize_1) - 1;

    //creating 2 sub arrays in the heap
    int* subArr_1 = new int[subArrSize_1];
    int* subArr_2 = new int[subArrSize_2];


    //inserting numbers into the first array
    for(int k=0; k<subArrSize_1; k++)
    {   
        subArr_1[k] = unsArr[k];
    }
    for(int k=0; k<subArrSize_1; k++)
    {
        cout<<subArr_1[k]<<' ';
    }
    cout<<'\n';

    //inserting numbers into the second array
    for (int k = 0; k < subArrSize_2; k++)
    {
        subArr_2[k] = unsArr[j + 1 + k];
    }
    for (int k = 0; k < subArrSize_2; k++)
    {
        cout<<subArr_2[k]<<' ';
    }
    cout<<'\n';

    //recursively recalling itself untill the size of arrays are 1
    quickSort(subArr_1, subArrSize_1);
    quickSort(subArr_2, subArrSize_2);
    

    //counts the pozition of the unsorted array during sorting
    int unsArr_poz = 0;

    //copying numbers from sub-arrays
    for(int l = 0; l<subArrSize_1; l++)
    {
        unsArr[unsArr_poz] = subArr_1[l];
        unsArr_poz++;
    }


    unsArr_poz++;

    
    for(int l=0; l<subArrSize_2; l++)
    {
        unsArr[unsArr_poz] = subArr_2[l];
        unsArr_poz++;
    }


    //allocating memory by deleting heap arrays
    delete[] subArr_1;
    delete[] subArr_2;

}


int main()
{
    const int numberofElements = 11;
    
    int numberList[numberofElements] = { 10 , 9 , 5 , 4 , 11 , 6 , 1 , 8 , 3 , 2 , 7};


    for(int i=0; i<numberofElements; i++)
    {
        cout<<numberList[i]<<' ';
    }
    cout<<'\n';


    quickSort(numberList , numberofElements);



    for(int i=0; i<numberofElements; i++)
    {
        cout<<numberList[i]<<' ';
    }


    return 0;
}