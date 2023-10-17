#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Neuronas.h"
#include <string>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

Neuronas *neu=new Neuronas();

int i,o=120,p=120,r=78,g=233,b=222,neuronas=0,idb;
double v=20;

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonM_clicked()
{
    int n=1,fila;

     ui->plainTextEditMostrar->clear();
    if(neuronas>0)
    {
        while(n<neuronas)
        {
            neu->mostrar(i,v,o,p,r,g,b,n);
            ui->tableWidgetMostrar->insertRow(ui->tableWidgetMostrar->rowCount());
            fila=ui->tableWidgetMostrar->rowCount()-1;
            ui->tableWidgetMostrar->setItem(fila,0, new QTableWidgetItem(QString::number(i)));
            ui->tableWidgetMostrar->setItem(fila,1, new QTableWidgetItem(QString::number(v)));
            ui->tableWidgetMostrar->setItem(fila,2, new QTableWidgetItem(QString::number(o)));
            ui->tableWidgetMostrar->setItem(fila,3, new QTableWidgetItem(QString::number(p)));
            ui->tableWidgetMostrar->setItem(fila,4, new QTableWidgetItem(QString::number(r)));
            ui->tableWidgetMostrar->setItem(fila,5, new QTableWidgetItem(QString::number(g)));
            ui->tableWidgetMostrar->setItem(fila,6, new QTableWidgetItem(QString::number(b)));
            ui->stackedWidget->setCurrentIndex(2);

            QString mostrar;
            mostrar.setNum(i);
            ui->plainTextEditMostrar->insertPlainText(mostrar);
            mostrar.setNum(v);
            ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
            mostrar.setNum(o);
            ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
            mostrar.setNum(p);
            ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
            mostrar.setNum(r);
            ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
            mostrar.setNum(g);
            ui->plainTextEditMostrar->insertPlainText("\t" + mostrar);
            mostrar.setNum(b);
            ui->plainTextEditMostrar->insertPlainText("\t" + mostrar +"\n");

            n=n+1;
        }
    }
    else
    {
        ui->labelMostrar->setText("No hay neuronas guardadas.");
        return;
    }
    ui->labelMostrar->clear();
    ui->labelMostrar2->clear();
}

void MainWindow::on_pushButtonRegresar_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->tableWidgetMostrar->clear();

    while(ui->tableWidgetMostrar->rowCount()!=0)
    {
        ui->tableWidgetMostrar->removeRow(0);
    }

}


void MainWindow::on_pushButtonAI_clicked()
{
    neu->insertarinicio(i,v,o,p,r,g,b);
    neuronas++;
    ui->labelMostrar->setText("Neurona insertada al inicio de la lista.");
}


void MainWindow::on_spinBoxID_valueChanged(int arg1)
{
    i=arg1;
}


void MainWindow::on_doubleSpinBoxV_valueChanged(double arg1)
{
    v=arg1;
}


void MainWindow::on_spinBoxX_valueChanged(int arg1)
{
    o=arg1;
}

void MainWindow::on_spinBoxY_valueChanged(int arg1)
{
    p=arg1;
}


void MainWindow::on_spinBoxR_valueChanged(int arg1)
{
    r=arg1;
}


void MainWindow::on_spinBoxG_valueChanged(int arg1)
{
    g=arg1;
}


void MainWindow::on_spinBoxB_valueChanged(int arg1)
{
    b=arg1;
}




void MainWindow::on_pushButtonAF_clicked()
{
    neu->insertarfinal(i,v,o,p,r,g,b);
    neuronas++;
    ui->labelMostrar->setText("Neurona insertada al final de la lista.");
}



void MainWindow::on_pushButtonGuardar_clicked()
{
    QString guardar = QFileDialog::getSaveFileName(this,"Guarde el archivo","C://","Archivo de Texto(*.txt)");
    QFile file(guardar);

    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
             QMessageBox::warning(this,"ERROR","No se pudo abrir el archivo");
    }
    QTextStream out(&file);
    QString text = ui->plainTextEditMostrar->toPlainText();
    out<<text;
    file.flush();
    file.close();
    ui->labelMostrar->setText("Lista de neuronas guardada con exito.");
    ui->labelMostrar2->setText("Dirección: " + guardar);
}


void MainWindow::on_pushButtonRecuperar_clicked()
{

    QString recuperar = QFileDialog::getOpenFileName(this,"Abre el archivo","C://","Archivos de Texto(*.txt)");
    QFile file(recuperar);

    string re= recuperar.toStdString();



    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
             QMessageBox::warning(this,"ERROR","No se pudo abrir el archivo");
    }
    QTextStream in(&file);

    ifstream arch;
    arch.open(re,ios::in);

    while(!arch.eof())
    {
             arch >>i>>v>>o>>p>>r>>g>>b;
             neu->insertarfinal(i,v,o,p,r,g,b);
             neuronas++;
    }

    ui->labelMostrar->setText("Lista de neuronas recuperada con exito.");
    ui->labelMostrar2->setText("Dirección: " + recuperar);
}


void MainWindow::on_pushButtonBN_clicked()
{
    int fila=0;
    ui->tableWidgetMostrar2->insertRow(ui->tableWidgetMostrar2->rowCount());
    neu->buscar(idb,i,v,o,p,r,g,b);
    if(i==-1)
    {
        ui->label_2->setText("No se encontró el ID");
    }
    else if(i==idb)
    {
        ui->tableWidgetMostrar2->setItem(fila,0, new QTableWidgetItem(QString::number(i)));
        ui->tableWidgetMostrar2->setItem(fila,1, new QTableWidgetItem(QString::number(v)));
        ui->tableWidgetMostrar2->setItem(fila,2, new QTableWidgetItem(QString::number(o)));
        ui->tableWidgetMostrar2->setItem(fila,3, new QTableWidgetItem(QString::number(p)));
        ui->tableWidgetMostrar2->setItem(fila,4, new QTableWidgetItem(QString::number(r)));
        ui->tableWidgetMostrar2->setItem(fila,5, new QTableWidgetItem(QString::number(g)));
        ui->tableWidgetMostrar2->setItem(fila,6, new QTableWidgetItem(QString::number(b)));
        ui->label_2->clear();
    }
}



void MainWindow::on_spinBoxBN_valueChanged(int arg1)
{
    idb=arg1;
}



void MainWindow::on_pushButton_clicked()
{
    int n=1;
    ui->stackedWidget->setCurrentIndex(1);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush brush;
    QColor brushColor;
    while(n<neuronas)
    {
        neu->mostrar(i,v,o,p,r,g,b,n);
        brushColor.setRgb(r,g,b);
        brush.setColor(brushColor);
        brush.setStyle(Qt::SolidPattern);
        QPen pen(Qt::black);
        pen.setWidth(0);

        ellipse = scene->addEllipse(o,p,v,v,pen,brush);
        n=n+1;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->graphicsView->clearMask();

}


void MainWindow::on_pushButtonO_clicked()
{
    if(neuronas==0)
    {
        ui->labelMostrar->setText("No hay neuronas guardadas.");
    }
    else
    {
        neu->ordenarID(neuronas);
        ui->labelMostrar->setText("Lista de neuronas ordenada");
    }
}


void MainWindow::on_pushButtonO2_clicked()
{
    if(neuronas==0)
    {
        ui->labelMostrar->setText("No hay neuronas guardadas.");
    }
    else
    {
        neu->ordenarV(neuronas);
        ui->labelMostrar->setText("Lista de neuronas ordenada");
    }
}

