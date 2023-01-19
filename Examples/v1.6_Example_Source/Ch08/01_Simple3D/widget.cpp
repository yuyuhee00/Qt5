#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_camPos3D        = QVector3D(0, 0, 40.0);
    m_camUpVector3D   = QVector3D(0, 1, 0);
    m_camViewCenter3D = QVector3D(0, 0, 0);

    m_view = new Qt3DExtras::Qt3DWindow();
    m_view->defaultFrameGraph()->setClearColor(QColor(77, 77, 77));

    m_rootEntity = new Qt3DCore::QEntity;
    m_view->setRootEntity(m_rootEntity);

    // Camera
    m_camera = m_view->camera();
    m_camera->lens()->setPerspectiveProjection(45.0f, 2.0f, 0.1f, 2000.0f);
    m_camera->setPosition(m_camPos3D);
    m_camera->setUpVector(m_camUpVector3D);
    m_camera->setViewCenter(m_camViewCenter3D);

    // For camera controls
    Qt3DExtras::QOrbitCameraController *camController
                = new Qt3DExtras::QOrbitCameraController(m_rootEntity);
    camController->setLinearSpeed( 50.0f );
    camController->setLookSpeed( 180.0f );
    camController->setCamera(m_camera);

    createRootEntry();

    QWidget *container = QWidget::createWindowContainer(m_view);
    ui->horizontalLayout->addWidget(container);

    connect(ui->xSlider, &QSlider::valueChanged,
            this,        &Widget::setCamPosX_ValueChanged);
    connect(ui->ySlider, &QSlider::valueChanged,
            this,        &Widget::setCamPosY_ValueChanged);
    connect(ui->zSlider, &QSlider::valueChanged,
            this,        &Widget::setCamPosZ_ValueChanged);
}

Widget::~Widget()
{
    delete ui;
}

void  Widget::setCamPosX_ValueChanged()
{
    m_camPos3D.setX(ui->xSlider->value());
    m_camera->setPosition(m_camPos3D);
}

void  Widget::setCamPosY_ValueChanged()
{
    m_camPos3D.setY(ui->ySlider->value());
    m_camera->setPosition(m_camPos3D);
}
void  Widget::setCamPosZ_ValueChanged()
{
    m_camPos3D.setZ(ui->zSlider->value());
    m_camera->setPosition(m_camPos3D);
}

void Widget::createRootEntry()
{
    Qt3DExtras::QExtrudedTextMesh *urlTextMesh
                    = new Qt3DExtras::QExtrudedTextMesh();

    urlTextMesh->setText("www.qt-dev.com");

    Qt3DExtras::QPhongMaterial *urlTextMaterial
                    = new Qt3DExtras::QPhongMaterial();

    urlTextMaterial->setDiffuse(QColor(Qt::green));

    Qt3DCore::QTransform *urlTextTransform = new Qt3DCore::QTransform();
    urlTextTransform->setScale(2.0f);
    urlTextTransform->setTranslation(QVector3D(-10.0f, -4.0f, 15.0f));

    m_textEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_textEntity->addComponent(urlTextMesh);
    m_textEntity->addComponent(urlTextMaterial);
    m_textEntity->addComponent(urlTextTransform);
}
