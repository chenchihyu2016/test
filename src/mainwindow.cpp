#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(36,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new Land(16,1.6,32,3,QPixmap(":/ground.png").scaled(width(),height()/6),world,scene));
    itemList.push_back(new Box(37,0.5,3,100,QPixmap(":/box.png").scaled(width()/5,height()/5),world,scene)); //it's the wall
    itemList.push_back(new Box(25, 3.5, 2.6, 3.2,QPixmap(":/box.png").scaled(width()/8,height()/9),world,scene));//it's box one
    itemList.push_back(new Box(29.3, 3.5, 2.8, 3.2,QPixmap(":/box.png").scaled(width()/8,height()/9),world,scene));//it's box two

    thingPtr = new thing(18.0f,5.0f,&timer,QPixmap(":/box.png").scaled(height()/6.0,height()/7.85),world,scene);

    // Create bird (You can edit here)
    //current = new redBird(0.0f,18.0f,0.27f,&timer,QPixmap(":/bird.png").scaled(height()/9.0,height()/9.0),world,scene);
    //current = new blackBird(0.0f,9.0f,0.49f,&timer,QPixmap(":/blackBird.png").scaled(height()/8.0,height()/9.0),world,scene);
    current = new blueBird(0.0f,9.0f,0.25f,&timer,QPixmap(":/blueBird.png").scaled(height()/8.5,height()/9.0),world,scene);
    //current = new whiteBird(0.0f,9.0f,0.25f,&timer,QPixmap(":/whiteBird.png").scaled(height()/9.0,height()/9.0),world,scene);
    piggy  *pig = new  piggy(27.20f,6.0f,0.43f,&timer,QPixmap(":/greenPig.png").scaled(height()/8.0,height()/8.0),world,scene);
    // Setting the Velocity
    current->setLinearVelocity(b2Vec2(30,0));
    itemList.push_back(current);
    itemList.push_back(pig);
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */
       //std::cout << "Move !" << std::endl;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */
        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        //std::cout << "Release !" << std::endl ;
    }
    return false;
}
void MainWindow::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_D||event->key() == Qt::Key_S)
            current->specialFunc();
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/600.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
}
