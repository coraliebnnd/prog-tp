#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot

    // check n
    if(n>0){
       // check length of z
        int module = sqrt(z.x*z.x + z.y*z.y);
        if(module<=2){
            Point newZ;
            newZ.x = (z.x*z.x - z.y*z.y) + point.x;
            newZ.y = (2 * z.x * z.y) + point.y;
            return isMandelbrot(newZ, n-1, point);
        }else{
            return n;
        }
    }
    // if Mandelbrot, return 1 or n (check the difference)
    // otherwise, process the square of z and recall
    // isMandebrot
    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



