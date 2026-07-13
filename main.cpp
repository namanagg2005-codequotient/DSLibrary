#include <iostream>
#include "dynamicArray.h"
using namespace std;

int main(){
    DynamicArray<int>* myArray =  new DynamicArray<int>();
    myArray->append(10);
    myArray->append(20);
    cout<<(*myArray)[0];
}