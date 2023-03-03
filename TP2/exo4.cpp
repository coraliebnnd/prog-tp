#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	
	Array& lowerArray = w->newArray(size);
    Array& greaterArray = w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split
    int pivot = toSort[0];
    for(int i = 1; i < size; i++){
        if(toSort[i]<pivot){
            lowerArray[lowerSize] = toSort[i];
            lowerSize = lowerSize+1;
        }else{
            greaterArray[greaterSize] = toSort[i];
            greaterSize = greaterSize+1;
        }
    }
	
	// recursiv sort of lowerArray and greaterArray
    if(lowerSize>1){
        recursivQuickSort(lowerArray, lowerSize);
    }

    if(greaterSize>1){
        recursivQuickSort(greaterArray, greaterSize);
    }
    // merge
    int i = 0;
        for(int j = 0; j<lowerSize; j++){
            toSort[i] = lowerArray[j];
            i++;
        }
        toSort[i]=pivot;
        i++;
        for(int k = 0; k<greaterSize; k++){
            toSort[i] = greaterArray[k];
            i++;
        }


}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
