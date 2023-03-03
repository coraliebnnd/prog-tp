#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w = nullptr;

void selectionSort(Array& toSort){
    // selectionSort
    int minIndex = 0;
    for (uint i=0; i<toSort.size(); i++)
    {
        for(uint j=i; j<toSort.size(); j++){
            if(toSort[minIndex]>toSort[j]){
                minIndex = j;
            }
        }
        if(toSort[minIndex]>toSort[i]){
            minIndex = i;
            toSort.swap(i, minIndex);
        }
        toSort.swap(i, minIndex);
    }
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(selectionSort); // window which display the behavior of the sort algorithm
    w->show();

	return a.exec();
}
