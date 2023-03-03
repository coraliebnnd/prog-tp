#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
	Array& sorted=w->newArray(toSort.size());

	// insertion sort from toSort to sorted
    sorted[0] = toSort[0];
    int position;
    for(int n=1;n<toSort.size();n++){
        position = n;
        for(int m=0;m<n; m++){
            if(toSort[n]<=sorted[m]){
                position = m;
                break;
            }
        }
        sorted.insert(position,toSort[n]);
    }

	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
