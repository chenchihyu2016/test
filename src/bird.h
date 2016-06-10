#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f

class Bird : public GameItem
{
public:
    Bird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void setLinearVelocity(b2Vec2 velocity);
    virtual void specialFunc()=0;
};
class piggy : public Bird{
public:
    piggy(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
        Bird(x,y,radius,timer,pixmap,world,scene){}
    virtual void specialFunc();
};
class redBird : public Bird{
public:
    redBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
        Bird(x,y,radius,timer,pixmap,world,scene){}
    virtual void specialFunc();
};
class whiteBird : public Bird{
public:
    whiteBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
        Bird(x,y,radius,timer,pixmap,world,scene){}
    virtual void specialFunc();
};
class blueBird : public Bird{
public:
    blueBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
        Bird(x,y,radius,timer,pixmap,world,scene){}
    virtual void specialFunc();
};
class blackBird : public Bird{
public:
    blackBird(float x, float y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
        Bird(x,y,radius,timer,pixmap,world,scene){}
    virtual void specialFunc();
};
#endif // BIRD_H

#ifndef BOX_H
#define BOX_H
/*
#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
*/
#define BOX_DENSITY 3.0f
#define BOX_FRICTION 0.1f
#define BOX_RESTITUTION 0.35f

class thing : public GameItem
{
public:
    thing(float x, float y, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};
#endif // BIRD_H

