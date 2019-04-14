#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    
    
    QApplication a(argc, argv);
    MainWindow w;
    // w.show();
    std::cout << "Funciona este main yay " << std::endl;

    int** b = w.getImage("/home/lesan2807/Documents/Electrizarte/tira/tiraa/imagen.png");
    std::fstream fs;
    fs.open("/home/lesan2807/Documents/Electrizarte/tira/tiraa/matriz.txt");
    fs << "int a[30][30] =";
    for( int i = 0; i < 30; ++i)
    {
        fs << "{";
        for(int j = 0; j < 30; ++j)
        {
            if( j != 29)
                fs << b[i][j] << ",";
            else
                fs << b[i][j];
        }
        if( i != 29)
            fs << "},";
        else
            fs << "}";

    }
    fs << ";";
    fs.close();

    return a.exec();
}

