#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)

	// initialisation
	Array& first = w->newArray(origin.size()/2);
	Array& second = w->newArray(origin.size()-first.size());
	
	// split
    for(int i = 0; i < origin.size()/2; i++){
        first[i]=origin[i];
    }

    int k = 0;
    for(int j = origin.size()-first.size(); j < origin.size(); j++){
        second[k]=origin[j];
        k++;
    }

	// recursiv splitAndMerge of lowerArray and greaterArray

    // merge
}

void merge(Array& first, Array& second, Array& result)
{

}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
