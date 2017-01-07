#include <Qt3DCore>
#include <Qt3DRender>
#include <Qt3DExtras>
#include <QDebug>
#include "window.h"
#include "main.h"
#include "robotview.h"
#include "qt3dwindow.h"




int RobotView::showScene() {
    // Debug message
    qDebug() << "Creating 3D view" << endl;

    // Root entity, everything that is going to be displayed needs to be parented to this
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity;

    // Material
    Qt3DRender::QMaterial *material = new Qt3DExtras::QPhongMaterial(rootEntity);

    // Robot entity, the robot mesh, material, and transforms make up this entity
    Qt3DCore::QEntity *robotEntity = new Qt3DCore::QEntity(rootEntity);

    // Robot mesh
    Qt3DRender::QMesh *robotMesh = new Qt3DRender::QMesh;
    robotMesh->setMeshName("RobotMesh");
    robotMesh->setSource(QUrl(QStringLiteral("qrc:/mesh/teapot.obj")));

    // Robot transform (position, rotation, and scale)
    Qt3DCore::QTransform *robotTransform = new Qt3DCore::QTransform;
    robotTransform->setScale3D(QVector3D(1, 1, 1));
    robotTransform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));
    robotTransform->setRotationX(0.0f);
    robotTransform->setRotationY(0.0f);
    robotTransform->setRotationZ(0.0f);

    // Adding the components that make up the robot model to the robot entity
    robotEntity->addComponent(robotMesh);
    robotEntity->addComponent(robotTransform);
    robotEntity->addComponent(material);

    // Create window for displaying the 3D view
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow;
    view->resize(500, 350);

    // Create a camera and set is as the camera for the 3D view window
    Qt3DRender::QCamera *camera = view->camera();
    // Configure the camera. (field of view, aspect ratio, near plane, far plane)
    camera->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    camera->setPosition(QVector3D(0, 0, 40.0f));
    camera->setViewCenter(QVector3D(0, 0, 0));

    // Setting the entity that is the parent to the robot model as the root entity for the 3D view window
    view->setRootEntity(rootEntity);
    view->show();
    return 0;
}
