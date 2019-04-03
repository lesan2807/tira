#include "mainwindow.h"

#include <QPixmap>
#include <QImage>
#include <QVector>
#include <QRgb>
#include <stdio.h>
#include <QString>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}

QPixmap MainWindow::getImage(QString string){
    QPixmap pixmap;
    pixmap.QPixmap::load(string);
    QImage image = pixmap.toImage();
    QVector<QVector<int>> rojos(image.height());
    QVector<QVector<int>> verdes(image.height());
    QVector<QVector<int>> azules(image.height());
    for(int i = 0; i < image.height(); ++i) // to get each line
    {
        QRgb* rgb = (QRgb*)image.scanLine(i); // get line at i
        for(int j = 0; j < image.width(); ++j) // iterate over each pixel in each line
        {
            rojos[i]<<qRed(*rgb);
            verdes[i]<<qGreen(*rgb);
            azules[i]<<qBlue(*rgb);
            //*rgb = qRgb(qRed(color), qGreen(color), qBlue(color)); // manipulate the image
            ++rgb; // increment rgb to go to the next pixel
        }
    }
    short tamano = image.width()*image.height()*3;
    char* colores = (char*)malloc(tamano);
    int contador =0;
    for(int i = 0; i < image.height();i++){
        for(int j = 0; j < image.width();j++){
            colores[contador]=(char) rojos[i][j];
            contador++;
            colores[contador]=(char) verdes[i][j];
            contador++;
            colores[contador]=(char) azules[i][j];
            contador++;
        }
    }
    /*for(int i = 0; i <tamano ;i++){
        printf("%u,",(unsigned)(colores[i]&0xFF));
    }*/
    printf("\n %d", tamano);
   /* for(int i = 0; i < image.height(); ++i){
        for(int x = 0; x < image.width(); ++x){
            printf("%d %d %d .",rojos[i][x],verdes[i][x],azules[i][x]);
        }
        printf("\n");
    }*/
    free(colores);
    return pixmap;
}
