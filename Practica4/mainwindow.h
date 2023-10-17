#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "qgraphicsscene.h"
#include <QDebug>
#include <QMainWindow>
#include <QtCore>
#include <QtGui>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:


    void on_pushButtonM_clicked();

    void on_pushButtonRegresar_clicked();

    void on_pushButtonAI_clicked();

    void on_spinBoxID_valueChanged(int arg1);

    void on_doubleSpinBoxV_valueChanged(double arg1);

    void on_spinBoxX_valueChanged(int arg1);

    void on_spinBoxY_valueChanged(int arg1);

    void on_spinBoxR_valueChanged(int arg1);

    void on_spinBoxG_valueChanged(int arg1);

    void on_spinBoxB_valueChanged(int arg1);


    void on_pushButtonAF_clicked();

    void on_pushButtonGuardar_clicked();

    void on_pushButtonRecuperar_clicked();


    void on_pushButtonBN_clicked();

    void on_spinBoxBN_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButtonO_clicked();

    void on_pushButtonO2_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse;

};
#endif // MAINWINDOW_H
