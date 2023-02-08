#include "MainWindow.h"
#include "ImageModel.h"
#include "PixelDelegate.h"

#include <QtWidgets>

//#if defined(QT_PRINTSUPPORT_LIB)
//#include <QtPrintSupport/qtprintsupportglobal.h>
//#if QT_CONFIG(printdialog)
//#include <QPrinter>
//#include <QPrintDialog>
//#endif
//#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    currentPath = QDir::homePath();
    model = new ImageModel(this);

    QWidget *centralWidget = new QWidget;

    view = new QTableView;
    view->setShowGrid(false);
    view->horizontalHeader()->hide();
    view->verticalHeader()->hide();
    view->horizontalHeader()->setMinimumSectionSize(1);
    view->verticalHeader()->setMinimumSectionSize(1);
    view->setModel(model);

    PixelDelegate *delegate = new PixelDelegate(this);
    view->setItemDelegate(delegate);

    QLabel *pixelSizeLabel = new QLabel(tr("Pixel size:"));
    QSpinBox *pixelSizeSpinBox = new QSpinBox;
    pixelSizeSpinBox->setMinimum(4);
    pixelSizeSpinBox->setMaximum(32);
    pixelSizeSpinBox->setValue(12);

    QMenu *fileMenu = new QMenu(tr("&File"), this);
    QAction *openAction = fileMenu->addAction(tr("&Open..."));
    openAction->setShortcuts(QKeySequence::Open);
    QAction *quitAction = fileMenu->addAction(tr("E&xit"));
    quitAction->setShortcuts(QKeySequence::Quit);

    QMenu *helpMenu = new QMenu(tr("&Help"), this);
    QAction *aboutAction = helpMenu->addAction(tr("&About"));

    menuBar()->addMenu(fileMenu);
    menuBar()->addSeparator();
    menuBar()->addMenu(helpMenu);

    QObject::connect(openAction, &QAction::triggered, this, &MainWindow::chooseImage);
    QObject::connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    QObject::connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutBox);

    QObject::connect(pixelSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), delegate, &PixelDelegate::setPixelSize);
    QObject::connect(pixelSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged), this, &MainWindow::updateView);

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(pixelSizeLabel);
    controlsLayout->addWidget(pixelSizeSpinBox);
    controlsLayout->addStretch(1);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(view);
    mainLayout->addLayout(controlsLayout);
    centralWidget->setLayout(mainLayout);

    this->setCentralWidget(centralWidget);
    this->setWindowTitle(tr("Pixelator"));
    this->resize(640, 480);
}

MainWindow::~MainWindow()
{
}

void MainWindow::chooseImage()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose an image"), currentPath, "*");
    if (!fileName.isEmpty())
        openImage(fileName);
}

void MainWindow::openImage(const QString &fileName)
{
    QImage image;

    if (image.load(fileName)) {
        model->setImage(image);
        if (!fileName.startsWith(":/")) {
            currentPath = fileName;
            setWindowTitle(tr("%1 - Pixelator").arg(currentPath));
        }
        updateView();
    }
}

void MainWindow::showAboutBox()
{
    QMessageBox::about(this, tr("About the Pixelator example"),
                            tr("This example demonstrates how a standard view and a custom\n"
                            "delegate can be used to produce a specialized representation\n"
                            "of data in a simple custom model."));
}

void MainWindow::updateView()
{
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
}
