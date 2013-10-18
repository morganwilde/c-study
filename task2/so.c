#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <stdio.h>

double getftime(
    void )
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec*1e-6;
}

static double lasttime;

void display(
    void )
{
    int width, height;
    double finishtime, delta_t;

    static float angle = 0;

    width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);

    glClearColor( 0.5, 0.5, 0.5, 1.0 );
    /* combine the clearing flags for more efficient operation */
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT );

    glViewport(0, 0, width, height);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 90, (float)width/(float)height, 1, 12 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    gluLookAt( 0, 4, 4, 0, 0, 0, 0, 1, 0 );

    glEnable( GL_DEPTH_TEST );

    glRotated( angle, 1, 0, 0 );
    glColor3f( 1, 0, 0 );
    glutSolidSphere( 1, 20, 20 );
    glColor3f( 0.8, 0.8, 0 );
    glutWireSphere( 1, 20, 20 );
    glColor3f( 0, 0, 1 );
    glutSolidTorus( 1, 2, 40, 40 );
    glDisable( GL_DEPTH_TEST );

    glutSwapBuffers();

    finishtime = getftime();
    delta_t = finishtime - lasttime;

    angle = fmodf(angle + 10*delta_t, 360);

    lasttime = finishtime;
}
int main(
    int argc,
    char **argv )
{
    glutInit( &argc, argv );
    glutInitWindowSize( 600, 600 );
    /* glutInitDisplayMode must be called before glutCreateWindow, flags are prefixed with GLUT_ not GL */
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutCreateWindow( "Depth Buffer" );
    glutDisplayFunc( display );
    /* register glutPostRedisplay for continuous animation */
    glutIdleFunc(glutPostRedisplay);

    lasttime = getftime();
    glutMainLoop(  );
}