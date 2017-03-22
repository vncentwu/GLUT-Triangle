#include <GL/glut.h>  // includes necessary OpenGL headers

void display() {

    glShadeModel(GL_SMOOTH);  // smooth color interpolation
    glEnable(GL_DEPTH_TEST);  // enable hidden surface removal
    glClearColor((float)191/255, (float)87/255, 0,(float) 255/255);   
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    //glBegin(GL_TRIANGLE);  // every 3 vertexes makes a triangle
        /*glColor4ub(255, 0, 0, 255);    // RGBA=(1,0,0,100%)
        glVertex3f(-0.8,  0.8,  0.3);  // XYZ=(-8/10,8/10,3/10)
        glColor4ub(0, 255, 0, 255);    // RGBA=(0,1,0,100%)
        glVertex3f( 0.8,  0.8, -0.2);  // XYZ=(8/10,8/10,-2/10)
    
        glColor4ub(0, 0, 255, 255);    // RGBA=(0,0,1,100%)
        glVertex3f( 0.0, -0.8, -0.2);*/  // XYZ=(0,-8/10,-2/10)
    glBegin(GL_TRIANGLES);
     	glColor4ub(0, 0, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( -0.9, 0.8, 0);
        //glColor4ub(0, 255, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( -0.6, 0.8, 0);
        //glColor4ub(0, 0, 255, 255);    // RGBA=(1,0,0,100%)
	glVertex3f(-0.3, -0.2, 0);
	

        //glColor4ub(255, 0, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( -0.6, 0.8, 0);
        //glColor4ub(0, 255, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( -0.3, -0.2, 0);
        //glColor4ub(0, 0, 255, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0, -0.2, 0);


        //glColor4ub(255, 0, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( -0.3, -0.2, 0);
        //glColor4ub(0, 255, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0.3, -0.2, 0);
        glColor4ub(0, 0, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0, -0.7, 0);

    
        //glColor4ub(255, 0, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0, -0.2,  0);
        //glColor4ub(0,  0, 255, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0.3, -0.2, 0);
        glColor4ub(0, 0, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0.6, 0.8, 0);


        //glColor4ub(255, 0, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0.6, 0.8, 0);
        //glColor4ub(0, 255, 0, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0.9, 0.8, 0);
        //glColor4ub(0, 0, 255, 255);    // RGBA=(1,0,0,100%)
	glVertex3f( 0.3, -0.2, 0);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv) {  // request double-buffered color window with depth buffer
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);
    glutCreateWindow("Vincent Wu");
    glutDisplayFunc(display); // function to render window
    glutMainLoop();
}
