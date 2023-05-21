#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_new_file_triggered()
{
    m_currentFile.clear();
    ui->textEdit->clear();
}


void MainWindow::on_open_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "打开文件");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "警告", "无法打开此文件：" + file.errorString());
        return;
    }

    m_currentFile = fileName;
    this->setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_save_file_triggered()
{
    QString fileName;
    if (m_currentFile.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, "保存文件");
        m_currentFile = fileName;
    }

    fileName = m_currentFile;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "警告", "无法保存文件：" + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toHtml();
    out << text;
    file.close();
}


void MainWindow::on_save_as_triggered()
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, "另存文件");
    m_currentFile = fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "警告", "无法保存文件：" + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toHtml();
    out << text;
    file.close();
}


void MainWindow::on_paste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_cut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_copy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_bolder_triggered(bool checked)
{
    ui->textEdit->setFontWeight(checked ? QFont::Bold : QFont::Normal);
}

void MainWindow::on_italic_triggered(bool checked)
{
    ui->textEdit->setFontItalic(checked);
}


void MainWindow::on_underline_triggered(bool checked)
{
    ui->textEdit->setFontUnderline(checked);
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

