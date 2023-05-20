#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_new_file_triggered()
{

}


void MainWindow::on_open_file_triggered()
{

}


void MainWindow::on_save_file_triggered()
{

}


void MainWindow::on_save_as_triggered()
{

}


void MainWindow::on_paste_triggered()
{

}


void MainWindow::on_cut_triggered()
{

}


void MainWindow::on_copy_triggered()
{

}


void MainWindow::on_bolder_triggered()
{

}


void MainWindow::on_italic_triggered()
{

}


void MainWindow::on_underline_triggered()
{

}


void MainWindow::on_font_triggered()
{

}


void MainWindow::on_about_triggered()
{

}


void MainWindow::on_undo_triggered()
{

}


void MainWindow::on_redo_triggered()
{

}


void MainWindow::on_exit_triggered()
{

}


void MainWindow::on_print_triggered()
{

}

