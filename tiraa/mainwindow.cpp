#include "mainwindow.h"

#include <QPixmap>
#include <QImage>
#include <QVector>
#include <QRgb>
#include <stdio.h>
#include <QString>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{

}

int** MainWindow::getImage(QString string){
    QPixmap pixmap;
    pixmap.QPixmap::load(string);
    QImage image = pixmap.toImage();
    // Allocate a vector of vectors
      int** matrix = (int**)malloc(30 * sizeof(int*));
      for ( int row_index = 0; row_index < 30; ++row_index )
         matrix[row_index] = (int*)malloc(30 * sizeof(int));
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
    for (int i = 0; i < image.height(); ++i)
    {
        for(int j = 0; j < image.width(); ++j)
        {
            if( rojos[i][j] != 255 && azules[i][j] != 255 && verdes[i][j] != 255)
                matrix[i][j] = 1;
            else {
                matrix[i][j] = 0;
            }
            //std::cout << matrix[i][j] << " ";
        }
        //std::cout << std::endl;
    }


    return matrix;
}
