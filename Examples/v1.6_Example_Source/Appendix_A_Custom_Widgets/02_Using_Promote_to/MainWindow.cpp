#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. Add on Form of Designer
    // -> promoted widgets
    // -> add a name
    // ---> base: QWidget
    // ---> check header file name
    // 2. Drag Widget and drop on Form
    // 3. Promote to promoted widget
    // -> It will appear ui->gridLayout->addWidget(sample, 0, 1);

    SampleWidget* sample = new SampleWidget;
    ui->gridLayout->addWidget(sample, 0, 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

