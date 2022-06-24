#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

//  Anggota Kelompok
//  Nicolaus Ardy Yoga Arimbawa (672020096)
//  Hasan Dwi Santoso (672020198)
//  Usman Syach (672020201)
//  Mahesa Rio Aditya (672020202)
//  Bayu Andy Daniswara (672020258)

const int width = 1280;
const int height = 720;
int i;
float sudut;
double x_geser, y_geser, z_geser;

float pitch = 0.0, yaw = 0.0;
float camX = 0.0, camZ = 0.0, terbang = 25.0;

void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

struct Motion {
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void init() {
    glClearColor(0.529, 0.807, 0.921, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void panggung(float x) {
    glColor3f(0.412f, 0.412f, 0.412f);
    glPushMatrix();
    glTranslatef(0, 2, -250);
    glScalef(2, 0, 2);
    glutSolidCube(x);
    glPopMatrix();
}

void paving_alas(float x) {
    //glColor3f(0.663f, 0.663f, 0.663f);
    glColor3f(0.412f, 0.412f, 0.412f);
    glPushMatrix();
    glTranslatef(0, 5, 400);
    glScalef(1.5, 0, 4);
    glutSolidCube(x);
    glPopMatrix();
}

void paving(float x) {
    glColor3f(0.663f, 0.663f, 0.663f);
    glPushMatrix();
    glTranslatef(0, 7, 400);
    glScalef(2, 0, 6);
    glutSolidCube(x);
    glPopMatrix();
}

void alas() {
    glColor3f(0.502f, 0.502f, 0.502f);
    glPushMatrix();
    glTranslatef(0, 9, -230);
    glScalef(2.2, 0.7, 2);
    glutSolidCube(500);
    glPopMatrix();
}

void lantai1() {
    //ruangan1
    glColor3f(0.82, 0.82, 0.82);
    glPushMatrix();
    glTranslatef(0, 242, -216);
    glScalef(1.6, 1.2, 1.3);
    glutSolidCube(450);
    glPopMatrix();

    //lantaibiru
    glColor3f(0, 0.01, 0.22);
    glPushMatrix();
    glTranslatef(0, 124.5, -210);
    glScalef(1.6, -0.3, 1.3);
    glutSolidCube(500);
    glPopMatrix();

    //dinding merah kiri 1 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-330.5, 327, 67.5);
    glScalef(0.6, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-189.5, 327, 67.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-100, 327, 67.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 1 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(329.5, 327, 67.5);
    glScalef(0.6, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(110, 327, 67.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(199.5, 327, 67.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //Pintu
    glColor3f(0.69, 0.61, 0.47);
    glPushMatrix();
    glTranslatef(7, 327, 67.5);
    glScalef(1.4, 2.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 1 BLKG
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-330.5, 327, -502);
    glScalef(0.6, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 2 BLKG
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-189.5, 327, -502);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 3 blkg
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-100, 327, -502);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 1 blkg
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(329.5, 327, -502);
    glScalef(0.6, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2 blkg
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(110, 327, -502);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 blkg
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(199.5, 327, -502);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-227, 438, 91.5);
    glScalef(2.6, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-227, 297, 91.5);
    glScalef(2.6, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(226, 438, 91.5);
    glScalef(2.3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(226, 297, 91.5);
    glScalef(2.3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //nico

    // KIRI 

    //dinding merah kiri 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-353.5, 327, 47.5);
    glRotatef(90, 0, 90, 1);
    glScalef(0.6, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-353.5, 327, -93.5);
    glRotatef(90, 0, 90, 1);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 3
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-353.5, 327, -338);
    glRotatef(90, 0, 90, 1);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 4
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-353.5, 327, -479);
    glRotatef(90, 0, 90, 1);
    glScalef(0.6, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //Pintu kiri
    glColor3f(0.69, 0.61, 0.47);
    glPushMatrix();
    glTranslatef(-353.5, 327, -215.75);
    glRotatef(90, 0, 90, 1);
    glScalef(1.4, 2.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(8, 442.5, -357.5);
    glScalef(2.2, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(7, 297 + 4.5, -357.5);
    glScalef(2.2, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri 3
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(432, 442.5, -357.5);
    glScalef(2.1, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri 4
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(432, 297 + 4.5, -357.5);
    glScalef(2.1, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();


    // KANAN

    //dinding merah kanan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(353.5, 327, 47.5);
    glRotatef(90, 0, 90, 1);
    glScalef(0.6, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(353.5, 327, -93.5);
    glRotatef(90, 0, 90, 1);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(353.5, 327, -338);
    glRotatef(90, 0, 90, 1);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 4
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(353.5, 327, -479);
    glRotatef(90, 0, 90, 1);
    glScalef(0.6, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //Pintu kanan
    glColor3f(0.69, 0.61, 0.47);
    glPushMatrix();
    glTranslatef(353.5, 327, -215.75);
    glRotatef(90, 0, 90, 1);
    glScalef(1.4, 2.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(8, 436, 350);
    glScalef(2.2, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(7, 295, 350);
    glScalef(2.2, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan 3
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(432, 436, 350);
    glScalef(2.1, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan 4
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(432, 295, 350);
    glScalef(2.1, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //BELAKANG

     //dinding Datar kiri depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-130, 438 + 6, -518.5);
    glScalef(4.8, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-130, 297 + 6, -518.5);
    glScalef(4.8, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(226, 438 + 6, -518.5);
    glScalef(2.3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(226, 297 + 6, -518.5);
    glScalef(2.3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 3
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-100, 327, 67.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();



}

void genteng_torii_utama() {
    glColor3f(0.545f, 0.000f, 0.000f);
    glBegin(GL_QUADS);
    glVertex3f(-8.5f, -0.5f, 0.5f);
    glVertex3f(8.5f, -0.5f, 0.5f);
    glVertex3f(9.2f, 0.2f, 0.2f);
    glVertex3f(-9.2f, 0.2f, 0.2f);
    glEnd();
}

void genteng_torii() {

    //glPushMatrix();
    //glTranslatef(212, 168.5, 569.5);
    //glScalef(40, 13, 40);
    glColor3f(0.545f, 0.000f, 0.000f);
    glBegin(GL_QUADS);
    // depan
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);

    // belakang
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    // kiri
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    // kanan
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // alas
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    //glPopMatrix();
}


void torii() {
    glColor3f(0.863f, 0.078f, 0.235f); //torii kiri
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(212, 700, 0);
    gluCylinder(gluNewQuadric(), 15.0f, 15.0f, 310.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.000f, 0.000f, 0.000f); //torii kiri bawah
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(212, 700, 0);
    gluCylinder(gluNewQuadric(), 17.0f, 17.0f, 30.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii kanan
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-212, 700, 0);
    gluCylinder(gluNewQuadric(), 15.0f, 15.0f, 310.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.000f, 0.000f, 0.000f); //torii kanan bawah
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-212, 700, 0);
    gluCylinder(gluNewQuadric(), 17.0f, 17.0f, 30.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii tengah
    glPushMatrix();
    glScalef(29, 2, 0.5);
    glTranslatef(0, 120, 1400);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii tengah atas
    glPushMatrix();
    glScalef(32, 2, 0.5);
    glTranslatef(0, 160, 1400);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kanan
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glScalef(16, 1.2, 0.5);
    glTranslatef(-44, 110, 425);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kanan2
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glScalef(16, 1.2, 0.5);
    glTranslatef(-44, 48, 425);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kanan depan
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-212, 570, 0);
    gluCylinder(gluNewQuadric(), 13.0f, 13.0f, 155.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.000f, 0.000f, 0.000f); //torii kanan depan bawah
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-212, 570, 0);
    gluCylinder(gluNewQuadric(), 16.0f, 16.0f, 30.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kanan belakang
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-212, 830, 0);
    gluCylinder(gluNewQuadric(), 13.0f, 13.0f, 155.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.000f, 0.000f, 0.000f); //torii papan kanan bawah
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-212, 830, 0);
    gluCylinder(gluNewQuadric(), 16.0f, 16.0f, 30.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kiri
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glScalef(16, 1.2, 0.5);
    glTranslatef(-44, 110, -425);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kiri 2
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glScalef(16, 1.2, 0.5);
    glTranslatef(-44, 48, -425);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kiri depan
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(212, 570, 0);
    gluCylinder(gluNewQuadric(), 13.0f, 13.0f, 155.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.000f, 0.000f, 0.000f); //torii papan kiri depan bawah
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(212, 570, 0);
    gluCylinder(gluNewQuadric(), 16.0f, 16.0f, 30.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kiri belakang
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(212, 830, 0);
    gluCylinder(gluNewQuadric(), 13.0f, 13.0f, 155.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.000f, 0.000f, 0.000f); //torii papan kiri belakang bawah
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(212, 830, 0);
    gluCylinder(gluNewQuadric(), 16.0f, 16.0f, 30.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kanan ujung depan
    glPushMatrix();
    glTranslatef(212, 159, 569.5);
    glScalef(1.5, 0.5, 1.5);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kanan ujung belakang
    glPushMatrix();
    glTranslatef(211.5, 159.5, 830.5);
    glScalef(1.5, 0.5, 1.5);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kiri ujung depan
    glPushMatrix();
    glTranslatef(-212, 159, 569.5);
    glScalef(1.5, 0.5, 1.5);
    glutSolidCube(20.0);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan kiri ujung blkg
    glPushMatrix();
    glTranslatef(-211.5, 159, 830.5);
    glScalef(1.5, 0.5, 1.5);
    glutSolidCube(20.0);
    glPopMatrix();

    glPushMatrix(); //genteng kanan depan
    glTranslatef(212, 168.5, 569.5);
    glScalef(50, 15, 50);
    genteng_torii();
    glPopMatrix();

    glPushMatrix(); //genteng kanan belakang
    glTranslatef(212, 169.5, 830);
    glScalef(50, 15, 50);
    genteng_torii();
    glPopMatrix();

    glPushMatrix(); //genteng kiri depan
    glTranslatef(-212, 168.5, 569.5);
    glScalef(50, 15, 50);
    genteng_torii();
    glPopMatrix();

    glPushMatrix(); //genteng kiri belakang
    glTranslatef(-212, 169, 830);
    glScalef(50, 15, 50);
    genteng_torii();
    glPopMatrix();

    glPushMatrix(); //genteng utama sisi depan
    glTranslatef(0, 344.5, 693);
    glScalef(40, 40, 40);
    genteng_torii_utama();
    glPopMatrix();

    glPushMatrix(); //genteng utama sisi belakang
    glRotatef(180, 0, 1, 0);
    glTranslatef(0, 344.5, -708);
    glScalef(40, 40, 40);
    genteng_torii_utama();
    glPopMatrix();

    glColor3f(0.545f, 0.000f, 0.000f); //pangkal genteng
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(-700.5, 350, -367.5);
    gluCylinder(gluNewQuadric(), 6.0f, 6.0f, 735.0f, 32, 32);
    glPopMatrix();

    glColor3f(0.863f, 0.078f, 0.235f); //torii papan
    glPushMatrix();
    glScalef(2, 3, 0.5);
    glTranslatef(0, 90.5, 1400);
    glutSolidCube(20.0);
    glPopMatrix();
}


void ground() {
    glBegin(GL_QUADS);
    glColor3f(0.235f, 0.702f, 0.443f);
    glVertex3f(-1000.0, 0, -1000.0);

    glColor3f(0.235f, 0.702f, 0.443f);
    glVertex3f(1000.0, 0, -1000.0);

    glColor3f(0.235f, 0.702f, 0.443f);
    glVertex3f(1000.0, 0, 1000.0);

    glColor3f(0.235f, 0.702f, 0.443f);
    glVertex3f(-1000.0, 0, 1000.0);
    glEnd();
}



void pagar_lantai1depan() {
    //DEPAN
    //pagar atas 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(319.5 + 58, 267, 249.5);
    glScalef(2.9, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-318 - 60, 267, 249.5);
    glScalef(3, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(319.5 + 58, 204, 249.5);
    glScalef(2.9, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-318 - 60, 204, 249.5);
    glScalef(3, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //CAGAK
    //CAGAK merah kanan  Depan

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242, 227, 253.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(376, 227, 253.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(510, 227, 253.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //CAGAK merah kiri Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(108 + -619, 227, 253.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242 + -619, 227, 253.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(376 + -619, 227, 253.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();



}


void pagar_lantai1belakang() {
    //DEPAN
    //pagar atas 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(263, 267, -718);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-264, 267, -718);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(263, 204, -718);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-264, 204, -718);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //CAGAK
    //CAGAK merah kanan  Depan

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(108, 227, -714);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242, 227, -714);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(376, 227, -714);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(510, 227, -714);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //CAGAK merah kiri Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(108 + -619, 227, -714);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242 + -619, 227, -714);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(376 + -619, 227, -714);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(510 + -619, 227, -714);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

}

void pagar_lantai1kiri() {
    //CAGAK KIRI
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 227, -563.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 227, -425);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 227, -286.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 227, -148);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 227, -9.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 227, 129);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-514, 267, -246);
    glScalef(0.3, 0.08, 10);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-514, 203.5, -246);
    glScalef(0.3, 0.08, 10);
    glutSolidCube(100);
    glPopMatrix();


}

void pagar_lantai1kanan() {
    //CAGAK Kanan

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 227, -563.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 227, -425);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 227, -286.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 227, -148);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 227, -9.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 227, 129);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(512, 267, -246);
    glScalef(0.3, 0.08, 10);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(512, 203.5, -246);
    glScalef(0.3, 0.08, 10);
    glutSolidCube(100);
    glPopMatrix();

}

void atap() {
    //atap depan
    glPushMatrix();
    glTranslatef(7.0, 895, -7.5);

    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);
    glVertex3f(-256.0, 0.0, 0);
    glVertex3f(256.0, 0.0, 0);
    glVertex3f(256.0, -60.0, 200);
    glVertex3f(-256.0, -60.0, 200);
    glEnd();
    glPopMatrix();

    //atap depan samping kiri
    glPushMatrix();
    glTranslatef(7.0, 895, -7.5);
    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);
    glVertex3f(-256.0, 0.0, 0);
    glVertex3f(-256.0, -60.0, 200);
    glVertex3f(-456.0, 0.0, 200);
    glVertex3f(256.0, -60.0, 200);
    glEnd();
    glPopMatrix();

    //atap depan samping kanan 
    glPushMatrix();
    glTranslatef(7.0, 895, -7.5);
    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);
    glVertex3f(256.0, 0.0, 0);
    glVertex3f(256.0, -60.0, 200);
    glVertex3f(456.0, 0.0, 200);
    glVertex3f(-256.0, -60.0, 200);
    glEnd();
    glPopMatrix();



    //atap belakang
    glPushMatrix();
    glTranslatef(7.0, 895, -424);

    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);
    glVertex3f(-256.0, 0.0, 0);
    glVertex3f(256.0, 0.0, 0);
    glVertex3f(256.0, -60.0, -200);
    glVertex3f(-256.0, -60.0, -200);
    glEnd();
    glPopMatrix();

    //atap belakang samping kanan
    glPushMatrix();
    glTranslatef(7.0, 895, -424);
    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);
    glVertex3f(-256.0, 0.0, 0);
    glVertex3f(-256.0, -60.0, -200);
    glVertex3f(-456.5, 0, -200);
    glVertex3f(256.0, -60.0, -200);
    glVertex3f(-256.0, -60.0, -200);

    glEnd();
    glPopMatrix();

    //atap belakang samping kiru
    glPushMatrix();
    glTranslatef(7.0, 895, -424);
    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);
    glVertex3f(256.0, 0.0, 0);
    glVertex3f(256.0, -60.0, -200);
    glVertex3f(456.0, 0.0, -200);
    glVertex3f(-256.0, -60.0, -200);
    glVertex3f(256.0, -60.0, -200);
    glEnd();
    glPopMatrix();

    //atap kanan
    glPushMatrix();
    glTranslatef(677.5, 895, -422.5);

    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);
    glVertex3f(-214.5, -60.0, -1.5);
    glVertex3f(-214.5, -60.0, 414.5);
    glVertex3f(-414.5, 0.0, 414.5);
    glVertex3f(-414.5, 0.0, -1.5);
    glEnd();
    glPopMatrix();

    //atap kanan samping kiri 
    glPushMatrix();
    glTranslatef(7.0, 895, -7.5);
    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);

    glVertex3f(256.0, 0.0, 0);
    glVertex3f(456.5, -60.0, 0);
    glVertex3f(456.5, 0, 200);
    glVertex3f(456.5, -60., -414.5);
    glVertex3f(456.5, -60.0, 0);
    glEnd();
    glPopMatrix();

    //atap kanan samping knan
    glPushMatrix();
    glTranslatef(7.0, 895, -7.5);
    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);

    glVertex3f(256.0, 0.0, -414.5);
    glVertex3f(456.5, -60.0, -414.5);
    glVertex3f(456.5, 0, -614.5);
    glVertex3f(456.5, -60.0, 0);
    glVertex3f(456.5, -60.0, -414.5);
    glEnd();
    glPopMatrix();

    //atap kiri
    glPushMatrix();
    glTranslatef(7.0, 895, -422.5);

    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);
    glVertex3f(-256.0, 0.0, -1.5);
    glVertex3f(-256.0, 0.0, 414.5);
    glVertex3f(-456.5, -60.0, 414.5);
    glVertex3f(-456.5, -60.0, -1.5);
    glEnd();
    glPopMatrix();

    //atap kiri samping kanan 
    glPushMatrix();
    glTranslatef(7.0, 895, -7.5);
    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);

    glVertex3f(-256.0, 0.0, 0);
    glVertex3f(-456.5, -60.0, 0);
    glVertex3f(-456.5, 0, 198.5);
    glVertex3f(-456.5, -60., -256);
    glVertex3f(-456.5, -60.0, 0);
    glEnd();
    glPopMatrix();

    //atap kiri samping kiri
    glPushMatrix();
    glTranslatef(7.0, 895, -7.5);
    glBegin(GL_POLYGON);
    glColor3f(0.24, 0.47, 0.29);

    glVertex3f(-256.0, 0.0, -414.5);
    glVertex3f(-456.5, -60.0, -414.5);
    glVertex3f(-456.5, 0, -614.5);
    glVertex3f(-456.5, -60.0, 0);
    glVertex3f(-456.5, -60.0, -414.5);
    glEnd();
    glPopMatrix();

}

void lantai2() {
    //layer lantai merah
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(0, 516.5, -210);
    glScalef(2.05, 0.02, 1.75);
    glutSolidCube(500);
    glPopMatrix();

    //layer lantai 
    glColor3f(0.14, 0.13, 0.13);
    glPushMatrix();
    glTranslatef(0, 527, -210);
    glScalef(2.1, 0.02, 1.8);
    glutSolidCube(500);
    glPopMatrix();

    //ruang lantai 2
    glColor3f(0.82, 0.82, 0.82);
    glPushMatrix();
    glTranslatef(7, 724, -216);
    glScalef(1.6, 1.2, 1.3);
    glutSolidCube(320);
    glPopMatrix();

    //Pintu
    glColor3f(0.69, 0.61, 0.47);
    glPushMatrix();
    glTranslatef(1, 642, -8.5);
    glScalef(1.2, 2.2, -0.2);
    glutSolidCube(100);
    glPopMatrix();

    //Atap lt2
    glPushMatrix();
    glTranslatef(-6, 2, -7);
    atap();
    glPopMatrix();

    //atas atap lt2
    glColor3f(0.24, 0.47, 0.29);
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    glTranslatef(1.5, -875.5, -210.5);
    glScalef(700, 80, 580);

    glBegin(GL_QUADS);
    // FRONT
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    // BACK
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    // LEFT
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // RIGHT
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // BOTTOM
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    glPopMatrix();
}


void pagar_lantai2belakang() {
    //pagar atas 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(263, 558.5, -645);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-264, 558.5, -645);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 3 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(263, 607, -645);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 4 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-264, 607, -645);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //CAGAK
    //CAGAK merah kanan  Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(108, 590, -641);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242, 590, -641);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(376, 590, -641);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(510, 590, -641);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();


    //CAGAK merah kiri Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(108 + -619, 590, -641);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242 + -619, 590, -641);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(376 + -619, 590, -641);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(510 + -619, 590, -641);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();
}

void pagar_lantai2kanan() {
    //CAGAK Kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 590, -563.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 590, -425);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 590, -286.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 590, -148);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 590, -9.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(509.5, 590, 129);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(512, 558.5, -222);
    glScalef(0.3, 0.08, 9);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(512, 558.5, -222);
    glScalef(0.3, 0.08, 9);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(512, 607, -222);
    glScalef(0.3, 0.08, 9);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(512, 607, -222);
    glScalef(0.3, 0.08, 9);
    glutSolidCube(100);
    glPopMatrix();

}

void pagar_lantai2kiri() {
    //CAGAK KIRI
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 590, -563.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 590, -425);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 590, -286.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 590, -148);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 590, -9.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-511.5, 590, 129);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-514, 558.5, -222);
    glScalef(0.3, 0.08, 9);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-514, 558.5, -222);
    glScalef(0.3, 0.08, 9);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-514, 607, -222);
    glScalef(0.3, 0.08, 9);
    glutSolidCube(100);
    glPopMatrix();

    //pagar bawah 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-514, 607, -222);
    glScalef(0.3, 0.08, 9);
    glutSolidCube(100);
    glPopMatrix();

}

void pagar_lantai2depan() {
    //pagar atas 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(263, 558.5, 216.5);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-264, 558.5, 216.5);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 3 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(263, 607, 216.5);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 4 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-264, 607, 216.5);
    glScalef(5.5, 0.08, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //CAGAK
    //CAGAK merah kanan  Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(108, 590, 212.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242, 590, 212.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(376, 590, 212.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(510, 590, 212.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();


    //CAGAK merah kiri Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(108 + -619, 590, 212.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242 + -619, 590, 212.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(376 + -619, 590, 212.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(510 + -619, 590, 212.5);
    glScalef(0.3, 1.5, 0.3);
    glutSolidCube(100);
    glPopMatrix();
}

void dinding_lantai2() {
    //dinding merah kiri 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-239, 707.5, -14.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-90, 707.5, -14.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-150, 707.5, -14.5);
    glScalef(0.2, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(246.5, 707.5, -14.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(90, 707.5, -14.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(150, 707.5, -14.5);
    glScalef(0.2, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-227 + 67 + 53, 438 + 365, -14.5);
    glScalef(3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-227 + 67, 297 + 365, -14.5);
    glScalef(1.8, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(256 + -96.5 + -51, 438 + 365, -14.5);
    glScalef(3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(256 + -96.5, 297 + 365, -14.5);
    glScalef(1.8, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //KIRI

    //dinding merah kana 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(246.5 + 55.5, 707.5, -238);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(90 + 55.5, 707.5, -238);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();





    //dinding Datar kanan depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(230, 438 + 365, -238);
    glScalef(1.8, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(230, 297 + 365, -238);
    glScalef(1.8, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //KANAN

    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(246.5 + 55.5, 707.5, 268);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(90 + 55.5, 707.5, 268);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();





    //dinding Datar kanan depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(230, 438 + 365, 268);
    glScalef(1.8, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(230, 297 + 365, 268);
    glScalef(1.8, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();




    //BELAKANG
    //dinding merah kiri 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-239, 707.5, -426.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-105, 707.5, -426.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(246.5, 707.5, -426.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(105, 707.5, -426.5);
    glScalef(0.4, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();


    //dinding Datar kiri depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-227 + 67 + 53, 438 + 365, -426.5);
    glScalef(3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-227 + 67 + 53, 297 + 365, -426.5);
    glScalef(3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(256 + -96.5 + -51, 438 + 365, -426.5);
    glScalef(3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(256 + -96.5 + -51, 297 + 365, -426.5);
    glScalef(3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();
}

void lantai3() {
    //layer lantai merah
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(0, 921, -210);
    glScalef(1.15, 0.02, 0.85);
    glutSolidCube(500);
    glPopMatrix();

    //layer lantai 
    glColor3f(0.14, 0.13, 0.13);
    glPushMatrix();
    glTranslatef(0, 931, -210);
    glScalef(1.2, 0.02, 0.9);
    glutSolidCube(500);
    glPopMatrix();

    //ruang lantai 3
    glColor3f(0.82, 0.82, 0.82);
    glPushMatrix();
    glTranslatef(7, 1090, -216);
    glScalef(1.6, 1.1, 1.3);
    glutSolidCube(280);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 327.5, -27.5);
    glScalef(0.85, 1.0, 0.87);
    atap();
    glPopMatrix();

    glColor3f(0.24, 0.47, 0.29);
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    glTranslatef(1.5, -1205 + y_geser, -210.5);
    glScalef(650, 80, 580);

    glBegin(GL_QUADS);
    // FRONT
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    // BACK
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    // LEFT
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // RIGHT
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // BOTTOM
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    glPopMatrix();

    //Pintu
    glColor3f(0.69, 0.61, 0.47);
    glPushMatrix();
    glTranslatef(2.0, 1016.5, -40);
    glScalef(1.0, 1.6, -0.2);
    glutSolidCube(100);
    glPopMatrix();
}


void pagar_lantai3belakang() {
    //pagar atas 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.5, 983.5, -430);
    glScalef(6.3, 0.08, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.5, 952.5, -430);
    glScalef(6.3, 0.08, 0.1);
    glutSolidCube(100);
    glPopMatrix();


    //CAGAK
    //CAGAK merah kanan  Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0, -427.5);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242.5 + -62.5, 983.0, -427.5);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(193.5 + -62.5 + -79.5, 983.0, -427.5);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(144.5 + -62.5 + -129.5, 983.0, -427.5);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-47.5 + -126, 983.0, -427.5);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-47.5 + -126 + -119, 983.0, -427.5);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

}


void pagar_lantai3kanan() {
    //CAGAK Kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0, 7 + -70);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();


    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0, -63 + -74);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0, -137 + -127);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0, -264 + -93);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(523 + -227, 958.5 + 25.5, -213.5);
    glScalef(0.1, 0.08, 4.9);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(523 + -227, 925.5 + 25.5, -213.5);
    glScalef(0.1, 0.08, 4.9);
    glutSolidCube(100);
    glPopMatrix();
}


void pagar_lantai3kiri() {
    //CAGAK Kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5 + -584, 983.0, 7 + -70);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();


    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5 + -584, 983.0, -63 + -74);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5 + -584, 983.0, -137 + -127);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5 + -584, 983.0, -264 + -93);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(296 + -584 + -9.5, 958.5 + 25.5, -213.5);
    glScalef(0.1, 0.08, 4.9);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(296 + -584 + -9.5, 925.5 + 25.5, -213.5);
    glScalef(0.1, 0.08, 4.9);
    glutSolidCube(100);
    glPopMatrix();

}


void pagar_lantai3depan() {

    //pagar atas 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.5, 983.5, 8.5);
    glScalef(6.3, 0.08, 0.1);
    glutSolidCube(100);
    glPopMatrix();



    //pagar atas 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.5, 952.5, 8.5);
    glScalef(6.3, 0.08, 0.1);
    glutSolidCube(100);
    glPopMatrix();


    //CAGAK
    //CAGAK merah kanan  Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0, 7);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242.5 + -62.5, 983.0, 7);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(193.5 + -62.5 + -79.5, 983.0, 7);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(144.5 + -62.5 + -129.5, 983.0, 7);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-47.5 + -126, 983.0, 7);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-47.5 + -126 + -119, 983.0, 7);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

}

void dinding_lantai3() {
    //dinding merah kiri 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-205.5, 1035.5, -40.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();


    //dinding merah kiri 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-90, 1035.5, -40.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(218.5, 1035.5, -40.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(90, 1035.5, -40.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();


    //dinding Datar kiri depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(7.5, 1144.5, -45.5);
    glScalef(4.0, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-141.5, 1004.5, -45.5);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(141.5, 1004.5, -45.5);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //KIRI



    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(218.5 + 73, 1035.5, -200.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(90 + 73, 1035.5, -200.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();



    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(141.5 + 86, 1004.5, -200.5);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(141.5 + 86, 1144.5, -200.5);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();


    //KANAN
    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(218.5 + 73, 1035.5, 240.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(90 + 73, 1035.5, 240.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();



    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(141.5 + 86, 1004.5, 240.5);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(141.5 + 86, 1144.5, 240.5);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();



    //BELAKANG
    //dinding merah kiri 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-206.5, 1024.5, -386.5);
    glScalef(0.3, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kiri 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-105, 1024.5, -386.5);
    glScalef(0.3, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(220.5, 1024.5, -386.5);
    glScalef(0.3, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(105, 1024.5, -386.5);
    glScalef(0.3, 3.7, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 1
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(7.5, 1144.5, -386.5);
    glScalef(4.0, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(5.5, 1016, -387);
    glScalef(4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();


}

void lantai4() {
    //layer lantai merah
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(0, 1249, -210);
    glScalef(1.25, 0.02, 1.05);
    glutSolidCube(500);
    glPopMatrix();

    //layer lantai 
    glColor3f(0.14, 0.13, 0.13);
    glPushMatrix();
    glTranslatef(0, 1259, -210);
    glScalef(1.3, 0.02, 1.1);
    glutSolidCube(500);
    glPopMatrix();

    //ruang lantai 3
    glColor3f(0.82, 0.82, 0.82);
    glPushMatrix();
    glTranslatef(7, 1401.5, -216);
    glScalef(1.6, 1.1, 1.3);
    glutSolidCube(250);
    glPopMatrix();

    //Pintu
    glColor3f(0.69, 0.61, 0.47);
    glPushMatrix();
    glTranslatef(2.0 + x_geser, 1401.5 + -60.5, -50.5 + -5.5);
    glScalef(1.0, 1.6, -0.2);
    glutSolidCube(100);
    glPopMatrix();

    //atap lantai 4
    glColor3f(0.24, 0.47, 0.29);
    glPushMatrix();
    glTranslatef(6.5, 1615, -231.5);
    glScalef(500, 150, 500);

    glBegin(GL_QUADS);
    // FRONT
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    // BACK
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    // LEFT
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.2f, 0.2f, 0.2f);
    glVertex3f(-0.2f, 0.2f, -0.2f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    // RIGHT
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.2f, 0.2f, -0.2f);
    glVertex3f(0.2f, 0.2f, 0.2f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // BOTTOM
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    glPopMatrix();


    //kotak_tower
    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glTranslatef(4, 1652, -231.5);
    glScalef(2, 0.15, 2);
    glutSolidCube(100);
    glPopMatrix();

    //bulat_tower
    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glTranslatef(4, 1652, -231.5);
    glutSolidSphere(50, 60, 60);
    glPopMatrix();

    //menara
    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glTranslatef(4, 1652 + 192.5, -231.5);
    glScalef(0.15, 3, 0.15);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(9, -230.5, -1731.5);
    glScalef(1, 1, 1);
    glutSolidTorus(5, 15, 4, 30);
    glPopMatrix();

    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(9, -230.5, -1731.5 - 40);
    glScalef(1, 1, 1);
    glutSolidTorus(5, 15, 4, 30);
    glPopMatrix();

    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(9, -230.5, -1731.5 - 80);
    glScalef(1, 1, 1);
    glutSolidTorus(5, 15, 4, 30);
    glPopMatrix();

    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(9, -230.5, -1731.5 - 120);
    glScalef(1, 1, 1);
    glutSolidTorus(5, 15, 4, 30);
    glPopMatrix();

    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(9, -230.5, -1731.5 - 160);
    glScalef(1, 1, 1);
    glutSolidTorus(5, 15, 4, 30);
    glPopMatrix();

    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(9, -230.5, -1731.5 - 200);
    glScalef(1, 1, 1);
    glutSolidTorus(5, 15, 4, 30);
    glPopMatrix();

    glColor3f(0.87, 0.67, 0.03);
    glPushMatrix();
    glTranslatef(4, 1552 + 440, -231.5);
    glutSolidSphere(15, 60, 60);
    glPopMatrix();




    //Dinding tegak
    //dinding merah kiri 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-188.5, 1035.5 + 321, -50.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();


    //dinding merah kiri 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-90 + 17, 1035.5 + 321, -50.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(188.5 + 17, 1035.5 + 321, -50.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(90 - 17, 1035.5 + 321, -50.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //DINDING DATAR DEPAN
    //dinding Datar kiri depan 1

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(7.5, 1100.5 + 66.5 + 286.5, -53);
    glScalef(4.0, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-131.5, 1004.5 + 66.5 + 286.5, -53);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kanan depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(141.5, 1004.5 + 66.5 + 286.5, -53);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //KIRI


    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(188.5 + 17 + 91, 1035.5 + 321, -182);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(90 - 17 + 91, 1035.5 + 321, -182);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();




    //dinding Datar 
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(141.5 + 91, 1004.5 + 66.5 + 286.5, -184);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar 
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(141.5 + 91, 1100.5 + 66.5 + 286.5, -184);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();


    //KANAN


    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(188.5 + 17 + 91, 1035.5 + 321, 220);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(90 - 17 + 91, 1035.5 + 321, 220);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();




    //dinding Datar 
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(141.5 + 91, 1004.5 + 66.5 + 286.5, 220);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar 
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glRotatef(90, 0, 90, 1);
    glTranslatef(141.5 + 91, 1100.5 + 66.5 + 286.5, 220);
    glScalef(1.4, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();


    //BELAKANG
  //dinding merah kiri 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-188.5, 1035.5 + 321, -378.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();


    //dinding merah kiri 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-90 + 17, 1035.5 + 321, -378.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 2 Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(188.5 + 17, 1035.5 + 321, -378.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //dinding merah kanan 3 depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(90 - 17, 1035.5 + 321, -378.5);
    glScalef(0.3, 3.7, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    //DINDING DATAR belakang
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(7.5, 1100.5 + 66.5 + 286.5, -53 + -319);
    glScalef(4.0, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //dinding Datar kiri depan 2
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(7.5, 1004.5 + 66.5 + 286.5, -53 + -319);
    glScalef(4.0, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();
}

void pagar_lantai4belakang() {
    //pagar atas 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.5, 983.5 + 340, -430 + -49);
    glScalef(6.3, 0.08, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.5, 952.5 + 340, -430 + -49);
    glScalef(6.3, 0.08, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    //CAGAK
    //CAGAK merah kanan  Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0 + 330, -427.5 + -49);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242.5 + -62.5, 983.0 + 330, -427.5 + -49);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(193.5 + -62.5 + -79.5, 983.0 + 330, -427.5 + -49);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(144.5 + -62.5 + -129.5, 983.0 + 330, -427.5 + -49);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-47.5 + -126, 983.0 + 330, -427.5 + -49);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-47.5 + -126 + -119, 983.0 + 330, -427.5 + -49);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();
}

void pagar_lantai4depan() {

    //pagar atas 1 kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.5, 983.5 + 340, 57);
    glScalef(6.3, 0.08, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas 2 kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-0.5, 952.5 + 340, 57);
    glScalef(6.3, 0.08, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    //CAGAK
    //CAGAK merah kanan  Depan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0 + 330, 57);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(242.5 + -62.5, 983.0 + 330, 57);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(193.5 + -62.5 + -79.5, 983.0 + 330, 57);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(144.5 + -62.5 + -129.5, 983.0 + 330, 57);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-47.5 + -126, 983.0 + 330, 57);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-47.5 + -126 + -119, 983.0 + 330, 57);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();
}

void pagar_lantai4kanan() {
    //CAGAK Kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0 + 330, 7 + -70);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();


    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0 + 330, -63 + -74);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0 + 330, -137 + -127);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(291.5, 983.0 + 330, -264 + -93);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(523 + -227, 983.0 + 340, -213.5);
    glScalef(0.1, 0.08, 5.2);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(523 + -227, 952.5 + 340, -213.5);
    glScalef(0.1, 0.08, 5.2);
    glutSolidCube(100);
    glPopMatrix();
}

void pagar_lantai4kiri() {
    //CAGAK Kanan
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-291.5, 983.0 + 330, 7 + -70);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();


    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-291.5, 983.0 + 330, -63 + -74);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-291.5, 983.0 + 330, -137 + -127);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-291.5, 983.0 + 330, -264 + -93);
    glScalef(0.2, 1.0, 0.17);
    glutSolidCube(100);
    glPopMatrix();

    //pagar atas  kiri
    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-296, 983.0 + 340, -213.5);
    glScalef(0.1, 0.08, 5.2);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(-296, 952.5 + 340, -213.5);
    glScalef(0.1, 0.08, 5.2);
    glutSolidCube(100);
    glPopMatrix();
}


void pohon1() {
    //pohon1
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(282, 8.5, 928);
    glScalef(0.8, 0.15, 0.8);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(282, 70.5, 928);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(282, 105, 928);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(282, 141.5, 928);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(282, 174.5, 928);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

    //pohon2
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(-280, 8.5, 928);
    glScalef(0.8, 0.15, 0.8);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(-280, 70.5, 928);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-280, 105, 928);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-280, 141.5, 928);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-280, 174.5, 928);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

}

void pohon2() {
    //pohon3kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(282, 8.5, 505.5);
    glScalef(0.8, 0.15, 0.8);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(282, 70.5, 505.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(282, 105, 505.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(282, 141.5, 505.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(282, 174.5, 505.5);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

    //pohon4kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(466.5, 8.5, 505.5);
    glScalef(0.8, 0.15, 0.8);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(466.5, 70.5, 505.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(466.5, 105, 505.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(466.5, 141.5, 505.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(466.5, 174.5, 505.5);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

    //pohon5kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(651, 8.5, 505.5);
    glScalef(0.8, 0.15, 0.8);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(651, 70.5, 505.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(651, 105, 505.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(651, 141.5, 505.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(651, 174.5, 505.5);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

    //pohon6kiri
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(-282, 8.5, 505.5);
    glScalef(0.8, 0.15, 0.8);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(-282, 70.5, 505.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-282, 105, 505.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-282, 141.5, 505.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-282, 174.5, 505.5);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

    //pohon7kiri
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(-466.5, 8.5, 505.5);
    glScalef(0.8, 0.15, 0.8);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(-466.5, 70.5, 505.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-466.5, 105, 505.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-466.5, 141.5, 505.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-466.5, 174.5, 505.5);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();

    //pohon5kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(-651, 8.5, 505.5);
    glScalef(0.8, 0.15, 0.8);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(-651, 70.5, 505.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-651, 105, 505.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-651, 141.5, 505.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-651, 174.5, 505.5);
    glutSolidSphere(20, 50, 50);
    glPopMatrix();
}

void pohon3() {

    //pohon1kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(855.5, 8.5, 312.5);
    glScalef(1.2, 0.15, 1.2);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(855.5, 70.5, 312.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(855.5, 178.5, 312.5);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(882, 116.5, 312.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(832.5, 119.5, 312.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();

    //pohon2kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(855.5, 8.5, 12.5);
    glScalef(1.2, 0.15, 1.2);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(855.5, 70.5, 12.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(855.5, 178.5, 12.5);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(882, 116.5, 12.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(832.5, 119.5, 12.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();

    //pohon3kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(855.5, 8.5, -287.5);
    glScalef(1.2, 0.15, 1.2);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(855.5, 70.5, -287.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(855.5, 178.5, -287.5);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(882, 116.5, -287.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(832.5, 119.5, -287.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();

    //pohon4kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(855.5, 8.5, -587.5);
    glScalef(1.2, 0.15, 1.2);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(855.5, 70.5, -587.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(855.5, 178.5, -587.5);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(882, 116.5, -587.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(832.5, 119.5, -587.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();

}

void pohon4() {

    //pohon1kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(-855.5, 8.5, 312.5);
    glScalef(1.2, 0.15, 1.2);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(-855.5, 70.5, 312.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-855.5, 178.5, 312.5);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-882, 116.5, 312.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-832.5, 119.5, 312.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();

    //pohon2kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(-855.5, 8.5, 12.5);
    glScalef(1.2, 0.15, 1.2);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(-855.5, 70.5, 12.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-855.5, 178.5, 12.5);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-882, 116.5, 12.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-832.5, 119.5, 12.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();

    //pohon3kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(-855.5, 8.5, -287.5);
    glScalef(1.2, 0.15, 1.2);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(-855.5, 70.5, -287.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-855.5, 178.5, -287.5);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-882, 116.5, -287.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-832.5, 119.5, -287.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();

    //pohon4kanan
    glColor3f(0.6, 0.6, 0.6);
    glPushMatrix();
    glTranslatef(-855.5, 8.5, -587.5);
    glScalef(1.2, 0.15, 1.2);
    glutSolidCube(100);
    glPopMatrix();
    //batang
    glColor3f(0.44, 0.22, 0.04);
    glPushMatrix();
    glTranslatef(-855.5, 70.5, -587.5);
    glScalef(0.15, 1.2, 0.15);
    glutSolidCube(100);
    glPopMatrix();
    //daun
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-855.5, 178.5, -587.5);
    glutSolidSphere(50, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-882, 116.5, -587.5);
    glutSolidSphere(40, 50, 50);
    glPopMatrix();
    glColor3f(0.07, 0.46, 0.04);
    glPushMatrix();
    glTranslatef(-832.5, 119.5, -587.5);
    glutSolidSphere(30, 50, 50);
    glPopMatrix();

}


void mejo() {
    //mejo
    glColor3f(0.871, 0.722, 0.529);
    glPushMatrix();
    glTranslatef(5, 124.5 + 140, -223.0);
    glScalef(1.0, 0.05, 0.8);
    glutSolidCube(320);
    glPopMatrix();

    //kaki mejo
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(5 + 145, 264.5 - 38, -223.0 + 113);
    glScalef(1.0, 2.0, 1.0);
    glutSolidCube(30);
    glPopMatrix();

    //kaki mejo
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(5 - 145, 264.5 - 38, -223.0 + 113);
    glScalef(1.0, 2.0, 1.0);
    glutSolidCube(30);
    glPopMatrix();

    //kaki mejo
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(5 - 145, 264.5 - 38, -223.0 - 113);
    glScalef(1.0, 2.0, 1.0);
    glutSolidCube(30);
    glPopMatrix();

    //kaki mejo
    glColor3f(0.627, 0.322, 0.176);
    glPushMatrix();
    glTranslatef(5 + 145, 264.5 - 38, -223.0 - 113);
    glScalef(1.0, 2.0, 1.0);
    glutSolidCube(30);
    glPopMatrix();

}

void bantal_lungguh() {

    //bantal1
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(5, -46, -223.0 + 18);
    glutSolidTorus(10, 30, 60, 100);
    glPopMatrix();

    glColor3f(0.5, 1, 1);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(5, -46, -193);
    glutSolidSphere(22, 60, 100);
    glPopMatrix();

    //bantal2
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(5, -46 - 350, -223.0 + 18);
    glutSolidTorus(10, 30, 60, 100);
    glPopMatrix();

    glColor3f(0.5, 1, 1);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(5, -46 - 350, -193);
    glutSolidSphere(22, 60, 100);
    glPopMatrix();

    //bantal3
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(5 + 200, -46 - 180, -223.0 + 18);
    glutSolidTorus(10, 30, 60, 100);
    glPopMatrix();

    glColor3f(0.5, 1, 1);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(5 + 200, -46 - 180, -193);
    glutSolidSphere(22, 60, 100);
    glPopMatrix();

    //bantal4
    glColor3f(1, 1, 1);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(5 - 200, -46 - 180, -223.0 + 18);
    glutSolidTorus(10, 30, 60, 100);
    glPopMatrix();

    glColor3f(0.5, 1, 1);
    glPushMatrix();
    glRotatef(90, 360, 0, 1);
    glTranslatef(5 - 200, -46 - 180, -193);
    glutSolidSphere(22, 60, 100);
    glPopMatrix();

}

void teko() {

    glColor3f(0.13, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(5, 287, -223.0);
    glutSolidTeapot(20);
    glPopMatrix();

}

void matahari() {
    glColor3f(1, 0.95, 0);
    glPushMatrix();
    glTranslatef(282, 2105, 928);
    glutSolidSphere(100, 100, 100);
    glPopMatrix();
}

void tong() {
    glColor3f(0.75, 0.75, 0.73);
    glPushMatrix();
    glTranslatef(282, 4, 312);
    glRotatef(180, 0, 1, 1);
    gluCylinder(gluNewQuadric(), 20.0, 20.0, 40.0, 60.0, 100);
    glPopMatrix();

    glColor3f(0.64, 0.64, 0.64);
    glPushMatrix();
    glTranslatef(282, -3.5, 311.5);
    glutSolidSphere(21, 60, 100);
    glPopMatrix();

    glColor3f(0.75, 0.75, 0.73);
    glPushMatrix();
    glTranslatef(-282, 4, 312);
    glRotatef(180, 0, 1, 1);
    gluCylinder(gluNewQuadric(), 20.0, 20.0, 40.0, 60.0, 100);
    glPopMatrix();

    glColor3f(0.64, 0.64, 0.64);
    glPushMatrix();
    glTranslatef(-282, -3.5, 311.5);
    glutSolidSphere(21, 60, 100);
    glPopMatrix();
}

void alas_gelas(int sisi, int x, int y) {
    glBegin(GL_POLYGON);
    int r = 6;
    for (int i = 0; i < sisi; i++) {
        glVertex2f((r * cos(2 * 3.14159265 * i / sisi)) + x, (r * sin(2 * 3.14159265 * i / sisi)) + y);
    }
    glEnd();
}

void gelas_object() {
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glRotatef(270, 1, 0, 0);
    glTranslatef(5, 162, 273);
    gluCylinder(gluNewQuadric(), 6.0, 8.0, 15.0, 60.0, 100);
    glPopMatrix();

    glPushMatrix();//alas
    glRotatef(90, 1, 0, 0);
    glTranslatef(5, -362, -273);
    alas_gelas(360, 0, 200);
    glPopMatrix();

}

void gelas() {
    gelas_object();

    glPushMatrix();
    glTranslatef(5, 0, -163);
    gelas_object();
    glTranslatef(100, 0, 103);
    gelas_object();
    glTranslatef(-230, 0, -5);
    gelas_object();
    glPopMatrix();
}

void tangga() {
    //1
    glColor3f(0.412f, 0.412f, 0.412f);
    glPushMatrix();
    glTranslatef(0, 17, 402.5);
    glScalef(3.5, 0.2, 2.65);
    glutSolidCube(100);
    glPopMatrix();


    //2
    glColor3f(0.462f, 0.462f, 0.462f);
    glPushMatrix();
    glTranslatef(0, 37, 385);
    glScalef(3.5, 0.2, 2.3);
    glutSolidCube(100);
    glPopMatrix();

    //3
    glColor3f(0.412f, 0.412f, 0.412f);
    glPushMatrix();
    glTranslatef(0, 57, 367.5);
    glScalef(3.5, 0.2, 1.95);
    glutSolidCube(100);
    glPopMatrix();

    //4
    glColor3f(0.462f, 0.462f, 0.462f);
    glPushMatrix();
    glTranslatef(0, 77, 350);
    glScalef(3.5, 0.2, 1.6);
    glutSolidCube(100);
    glPopMatrix();

    //5
    glColor3f(0.412f, 0.412f, 0.412f);
    glPushMatrix();
    glTranslatef(0, 97, 332.5);
    glScalef(3.5, 0.2, 1.25);
    glutSolidCube(100);
    glPopMatrix();

    //6
    glColor3f(0.462f, 0.462f, 0.462f);
    glPushMatrix();
    glTranslatef(0, 117, 315);
    glScalef(3.5, 0.2, 0.9);
    glutSolidCube(100);
    glPopMatrix();

    //7
    glColor3f(0.412f, 0.412f, 0.412f);
    glPushMatrix();
    glTranslatef(0, 137, 297.5);
    glScalef(3.5, 0.2, 0.55);
    glutSolidCube(100);
    glPopMatrix();

    //8
    glColor3f(0.462f, 0.462f, 0.462f);
    glPushMatrix();
    glTranslatef(0, 157, 280);
    glScalef(3.5, 0.2, 0.2);
    glutSolidCube(100);
    glPopMatrix();

}

void lampuu() {
    //paling ngisor
    glColor3f(0.58f, 0.58f, 0.58f);
    glPushMatrix();
    glTranslatef(153, 191, 220);
    glScalef(0.5, 0.2, 0.5);
    glutSolidCube(100);
    glPopMatrix();

    //munggah 1
    glColor3f(0.65f, 0.65f, 0.65f);
    glPushMatrix();
    glTranslatef(153, 201, 220);
    glScalef(0.4, 0.2, 0.4);
    glutSolidCube(100);
    glPopMatrix();

    //munggah 2
    glColor3f(0.58f, 0.58f, 0.58f);
    glPushMatrix();
    glTranslatef(153, 206, 220);
    glScalef(0.3, 0.2, 0.3);
    glutSolidCube(100);
    glPopMatrix();

    //munggah 3
    glColor3f(0.65f, 0.65f, 0.65f);
    glPushMatrix();
    glTranslatef(153, 230, 220);
    glScalef(0.2, 1.2, 0.2);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.58f, 0.58f, 0.58f);
    glPushMatrix();
    glTranslatef(153, 270, 220);
    glScalef(0.25, 0.08, 0.25);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(0.58f, 0.58f, 0.58f);
    glPushMatrix();
    glTranslatef(153, 290, 220);
    glScalef(0.25, 0.1, 0.25);
    glutSolidCube(100);
    glPopMatrix();

    //efek lampu
    glColor3f(1.0f, 1.5f, 0.0f);
    glPushMatrix();
    glTranslatef(153, 282, 226);
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(1.0f, 1.5f, 0.0f);
    glPushMatrix();
    glTranslatef(147, 282, 220);
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(1.0f, 1.5f, 0.0f);
    glPushMatrix();
    glTranslatef(159, 282, 220);
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(100);
    glPopMatrix();

    glColor3f(1.0f, 1.5f, 0.0f);
    glPushMatrix();
    glTranslatef(153, 282, 215);
    glScalef(0.1, 0.1, 0.1);
    glutSolidCube(100);
    glPopMatrix();


    //atep
    glPushMatrix();
    glTranslatef(153, 309, 220);
    glScalef(30, 30, 30);
    glColor3f(0.87f, 0.87f, 0.87f);
    glBegin(GL_QUADS);
    // depan
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);

    // belakang
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);

    // kiri
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);

    // kanan
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.3f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);

    // alas
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();
    glPopMatrix();
}

void lampuu2() {

    glPushMatrix();
    glTranslatef(-319, 0, 0);
    lampuu();
    glPopMatrix();
}

void lampion() {

    glColor3f(1.0, 0.99, 0.54);
    glPushMatrix();
    glTranslatef(282, 1000, 311.5);
    glutSolidSphere(10, 60, 100);
    glPopMatrix();

    glColor3f(1.0, 0.99, 0.54);
    glPushMatrix();
    glTranslatef(282, 1023.5, 311.5);
    glutSolidSphere(10, 60, 100);
    glPopMatrix();

    glColor3f(1.0, 0.99, 0.54);
    glPushMatrix();
    glTranslatef(282, 997, 311.5);
    glRotatef(180, 0, 1, 1);
    gluCylinder(gluNewQuadric(), 10.0, 10.0, 30.0, 60.0, 100);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(282, 1011, 311.5);
    glScalef(0.3, 0.8, 0.3);
    glutSolidCube(50);
    glPopMatrix();

    glColor3f(0.68, 0.1, 0.1);
    glPushMatrix();
    glTranslatef(282, 1035, 311.5);
    glScalef(0.3, 5.85, 0.3);
    glutSolidCube(10);
    glPopMatrix();

}


void fixlampion() {

    //lt1
    //depan
    glPushMatrix();
    glTranslatef(165, -540, -102);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60, -540, -102);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-285, -540, -102);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-510, -540, -102);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-735, -540, -102);
    lampion();
    glPopMatrix();

    //belakang
    glPushMatrix();
    glTranslatef(165, -540, -939);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-60, -540, -939);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-285, -540, -939);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-510, -540, -939);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-735, -540, -939);
    lampion();
    glPopMatrix();

    //kanan
    glPushMatrix();
    glTranslatef(165, -540, -270);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(165, -540, -270 + -168);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(165, -540, -438 + -168);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(165, -540, -606 + -168);
    lampion();
    glPopMatrix();

    //kiri
    glPushMatrix();
    glTranslatef(-735, -540, -270);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-735, -540, -270 + -168);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-735, -540, -438 + -168);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-735, -540, -606 + -168);
    lampion();
    glPopMatrix();


    //lt2
    //kiri
    glPushMatrix();
    glTranslatef(-735 + 11, -540 + 372, -774 + -154.5);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-724, -223.5, -645);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-724, -223.5, -645 + 267);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-724 + 15, -223.5 + 56.5, -645 + 267 + 223);
    lampion();
    glPopMatrix();

    //kanan
    glPushMatrix();
    glTranslatef(-724 + 877, -168, -928.5);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-724 + 877, -223.5, -645);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-724 + 877, -223.5, -645 + 267);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-724 + 15 + 877, 167 - 333, -645 + 267 + 223);
    lampion();
    glPopMatrix();

    //depan
    glPushMatrix();
    glTranslatef(168 + -315, -166 + -51, -155);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-147 + -285, -217, -155);
    lampion();
    glPopMatrix();

    //belakang
    glPushMatrix();
    glTranslatef(168 + -315, -166 + -51, -155 - 756);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-147 + -285, -217, -155 - 756);
    lampion();
    glPopMatrix();

    //lt2
   //kiri
    glPushMatrix();
    glTranslatef(-724 + 73.5, -168 + 329, -928.5 + 61.5);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-724 + 73.5, -168 + 329, -928.5 + 61.5 + 682);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-650.5 + 752, 161, -185);
    lampion();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-650.5 + 752, 161, -185 + -685);
    lampion();
    glPopMatrix();

}


void bintang1() {
    glPushMatrix();

    glRotatef(90, 1, 1, 0);
    glutSolidCone(10.0, 25.0, 20, 20);
    glPopMatrix();
}

void bintang2() {
    glPushMatrix();
    glRotatef(90, 1, -1, 0);
    glutSolidCone(10.0, 25.0, 20, 20);
    glPopMatrix();
}

void bintang() {
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glTranslatef(282, 500, 800);
    glutSolidSphere(10, 60, 100);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(281, 500, 800);
    glRotatef(180, 0, 1, 1);
    glutSolidCone(10.0, 25.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(242 + 41.5, 500, 800);
    glRotatef(90, 0, 1, 0);
    glutSolidCone(10.0, 25.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(222 + 58.5, 500, 800);
    glRotatef(-90, 0, 1, 0);
    glutSolidCone(10.0, 25.0, 20, 20);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(222 + 58.5, 500, 800);
    glRotatef(10, 0, -1, -1);
    bintang1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(222 + 58.5, 500, 800);
    glRotatef(10, 0, 1, 1);
    bintang2();
    glPopMatrix();

}

void cagakireng() {
    //lANTAI 1
    //CAGAK HITAM DEPAN
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(307.5, 178.5, 182.5);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-307.5, 178.5, 182.5);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(307.5, -653, 182.5);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-307.5, -653, 182.5);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();

    //CAGAK IRENG KANAN KIRI
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(486, 178.5 + -391, 182.5);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-486, 178.5 + -391, 182.5);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();

    //lANTAI 2
    //CAGAK HITAM DEPAN
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(169, 108, 529);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-169, 108, 529);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();

    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(169, -552.5, 529);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-169, -552.5, 529);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();

    //CAGAK IRENG KANAN KIRI
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(393.5, 178.5 + -391, 529);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(180, 0, 1, 1);
    glTranslatef(-393.5, 178.5 + -391, 529);
    gluCylinder(gluNewQuadric(), 5.0f, 5.0f, 330.0f, 12, 12);
    glPopMatrix();
}


void draw() {
    // Mulai tuliskan isi pikiranmu disini
    //Dasar Bangunan
    panggung(700);
    paving_alas(300);
    paving(200);
    alas();

    //Bangunan Kuil lantai 1
    lantai1();
    cagakireng();
    //Bangunan Kuil Lantai 2
    lantai2();
    dinding_lantai2();
    //Bangunan Kuil Lantai 3
    lantai3();
    dinding_lantai3();
    //Bangunan Kuil Lantai 4
    lantai4();
    //pagar lantai 1
    pagar_lantai1depan();
    pagar_lantai1belakang();
    pagar_lantai1kiri();
    pagar_lantai1kanan();
    //pagar lantai 2
    pagar_lantai2depan();
    pagar_lantai2belakang();
    pagar_lantai2kanan();
    pagar_lantai2kiri();
    //pagar lantai 3
    pagar_lantai3depan();
    pagar_lantai3belakang();
    pagar_lantai3kanan();
    pagar_lantai3kiri();
    //pagar lantai 4
    pagar_lantai4depan();
    pagar_lantai4belakang();
    pagar_lantai4kanan();
    pagar_lantai4kiri();

    //tangga
    tangga();

    //10 Object
    pohon1();
    pohon2();
    pohon3();
    pohon4();
    torii();
    mejo();
    bantal_lungguh();
    teko();
    matahari();
    tong();
    gelas();
    lampuu();
    lampuu2();
    fixlampion();

    ground();
    cout << "X_GESER = " << x_geser << "     Y_GESER = " << y_geser << "      Z_GESER = " << z_geser << endl;
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y) {
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}


void camera() {
    if (motion.Forward) {
        camX += cos((yaw + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 2;
    }
    if (motion.Backward) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 2;
    }
    if (motion.Left) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Right) {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 2;
    }
    if (motion.Naik) {
        terbang -= 2.0;
    }
    if (motion.Turun) {
        terbang += 2.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;


    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25)
        terbang = 24;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case '6':
        x_geser += 0.5;
        break;
    case '4':
        x_geser -= 0.5;
        break;
    case '8':
        y_geser += 0.5;
        break;
    case '2':
        y_geser -= 0.5;
        break;
    case '9':
        z_geser -= 0.5;
        break;
    case '1':
        z_geser += 0.5;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("TR GRAFKOM H KELOMPOK 4");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    return 0;
}