#include <stdlib.h>
//#include <glut.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

class Point
{
	public: 
		GLfloat x;
		GLfloat y;
		GLfloat z;
		Point(){}
		Point(GLfloat x, GLfloat y, GLfloat z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

};



class Cube
{

	//vector<Point> cube;
	Point** cube_front;
	Point** cube_back;
	Point** cube_left;
	Point** cube_right;
	Point** cube_top;
	Point** cube_bottom;
	Point* origin;
	Cube** children_cubes;
	GLfloat size;
	int iterations;

	
	public:
		static int numCubes;
	Cube(){};
	Cube(Point* origin, GLfloat size, int iterations)
	{
		numCubes++;
		this->size = size;
		this->origin = origin;
		this->iterations = iterations;
		children_cubes = new Cube*[20];
		
		if(iterations!=0)
			makeChildrenCubes();
		else
			initCubes(origin);
		//cout << "# of cubes: " << numCubes << endl;
		//cout << "size: " << size << "  origin: "<< origin->x << ", " << origin->y << ", " << origin->z <<endl;
	}


	void initCubes(Point* origin)
	{	
		//TOP FACE
		cube_top = new Point*[4];
		cube_top[0] = new Point( size/2.0f + origin->x, size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_top[1] = new Point(-size/2.0f + origin->x, size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_top[2] = new Point(-size/2.0f + origin->x, size/2.0f + origin->y,  size/2.0f + origin->z);
		cube_top[3] = new Point( size/2.0f + origin->x, size/2.0f + origin->y,  size/2.0f + origin->z);
 
		// Bottom face (y = -size/2.0f + origin->x)
		cube_bottom = new Point*[4];
		cube_bottom[0] = new Point( size/2.0f + origin->x, -size/2.0f + origin->y,  size/2.0f + origin->z);
		cube_bottom[1] = new Point(-size/2.0f + origin->x, -size/2.0f + origin->y,  size/2.0f + origin->z);
		cube_bottom[2] = new Point(-size/2.0f + origin->x, -size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_bottom[3] = new Point( size/2.0f + origin->x, -size/2.0f + origin->y, -size/2.0f + origin->z);
 
		// Front face  (z = size/2.0f + origin->x)
		cube_front = new Point*[4];
		cube_front[0] = new Point( size/2.0f + origin->x,  size/2.0f + origin->y, size/2.0f + origin->z);
		cube_front[1] = new Point(-size/2.0f + origin->x,  size/2.0f + origin->y, size/2.0f + origin->z);
		cube_front[2] = new Point(-size/2.0f + origin->x, -size/2.0f + origin->y, size/2.0f + origin->z);
		cube_front[3] = new Point( size/2.0f + origin->x, -size/2.0f + origin->y, size/2.0f + origin->z);
 
		// Back face (z = -size/2.0f + origin->x)
		cube_back = new Point*[4];
		cube_back[0] = new Point( size/2.0f + origin->x, -size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_back[1] = new Point(-size/2.0f + origin->x, -size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_back[2] = new Point(-size/2.0f + origin->x,  size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_back[3] = new Point( size/2.0f + origin->x,  size/2.0f + origin->y, -size/2.0f + origin->z);
 
		// Left face (x = -size/2.0f + origin->x)
		cube_left = new Point*[4];
		cube_left[0] = new Point(-size/2.0f + origin->x,  size/2.0f + origin->y,  size/2.0f + origin->z);
		cube_left[1] = new Point(-size/2.0f + origin->x,  size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_left[2] = new Point(-size/2.0f + origin->x, -size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_left[3] = new Point(-size/2.0f + origin->x, -size/2.0f + origin->y,  size/2.0f + origin->z);
 
		// Right face (x = size/2.0f + origin->x)
		cube_right = new Point*[4];
		cube_right[0] = new Point(size/2.0f + origin->x,  size/2.0f + origin->y, -size/2.0f + origin->z);
		cube_right[1] = new Point(size/2.0f + origin->x,  size/2.0f + origin->y,  size/2.0f + origin->z);
		cube_right[2] = new Point(size/2.0f + origin->x, -size/2.0f + origin->y,  size/2.0f + origin->z);
		cube_right[3] = new Point(size/2.0f + origin->x, -size/2.0f + origin->y, -size/2.0f + origin->z);
	}

	void makeChildrenCubes()
	{
		GLfloat ns = size/3.0f;

		//left cubes
		children_cubes[0] = new Cube(new Point(-ns + origin->x, -ns + origin->y, -ns + origin->z), ns, iterations - 1);
		children_cubes[1] = new Cube(new Point(-ns + origin->x, -ns + origin->y,  ns + origin->z), ns, iterations - 1);
		children_cubes[2] = new Cube(new Point(-ns + origin->x, -ns + origin->y,  0 + origin->z), ns, iterations - 1);
		children_cubes[3] = new Cube(new Point(-ns + origin->x,  ns + origin->y, -ns + origin->z), ns, iterations - 1);
		children_cubes[4] = new Cube(new Point(-ns + origin->x,  ns + origin->y,  ns + origin->z), ns, iterations - 1);
		children_cubes[5] = new Cube(new Point(-ns + origin->x,  ns + origin->y,  0 + origin->z), ns, iterations - 1);
		children_cubes[6] = new Cube(new Point(-ns + origin->x,  0  + origin->y, -ns + origin->z), ns, iterations - 1);
		children_cubes[7] = new Cube(new Point(-ns + origin->x,  0  + origin->y,  ns + origin->z), ns, iterations - 1);


		//right cubes
		children_cubes[8] = new Cube(new Point( ns + origin->x, -ns + origin->y, -ns + origin->z), ns, iterations - 1);
		children_cubes[9] = new Cube(new Point( ns + origin->x, -ns + origin->y,  ns + origin->z), ns, iterations - 1);
		children_cubes[10] = new Cube(new Point( ns + origin->x, -ns + origin->y,  0 + origin->z), ns, iterations - 1);
		children_cubes[11] = new Cube(new Point( ns + origin->x,  ns + origin->y, -ns + origin->z), ns, iterations - 1);
		children_cubes[12] = new Cube(new Point( ns + origin->x,  ns + origin->y,  ns + origin->z), ns, iterations - 1);
		children_cubes[13] = new Cube(new Point( ns + origin->x,  ns + origin->y,  0 + origin->z), ns, iterations - 1);
		children_cubes[14] = new Cube(new Point( ns + origin->x,  0  + origin->y, -ns + origin->z), ns, iterations - 1);
		children_cubes[15] = new Cube(new Point( ns + origin->x,  0  + origin->y,  ns + origin->z), ns, iterations - 1);

		//center cubes
		children_cubes[16] = new Cube(new Point( 0 + origin->x, -ns + origin->y, -ns + origin->z), ns, iterations - 1);
		children_cubes[17] = new Cube(new Point( 0 + origin->x, -ns + origin->y,  ns + origin->z), ns, iterations - 1);
		children_cubes[18] = new Cube(new Point( 0 + origin->x,  ns + origin->y, -ns + origin->z), ns, iterations - 1);
		children_cubes[19] = new Cube(new Point( 0 + origin->x,  ns + origin->y,  ns + origin->z), ns, iterations - 1);
	}


	void drawCubes()
	{
		if(iterations == 0)
		{
			glColor3f(0.0f, 1.0f, 0.0f);     // Green
			drawCubes(cube_front);
			glColor3f(1.0f, 0.5f, 0.0f);     // Orange
			drawCubes(cube_back);
			glColor3f(1.0f, 0.0f, 0.0f);     // Red
			drawCubes(cube_left);
			glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
			drawCubes(cube_right);
			glColor3f(0.0f, 0.0f, 1.0f);     // Blue
			drawCubes(cube_top);
			glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
			drawCubes(cube_bottom);
		}
		else
		{
			for(int i = 0; i<20; i++)
				children_cubes[i]->drawCubes();
		}





	}

	void drawCubes(Point** cube)
	{	
		glBegin(GL_QUADS);
			glNormal3d(0, 0, 1);
			glVertex3f(cube[0]->x, cube[0]->y, cube[0]->z);
			glVertex3f(cube[1]->x, cube[1]->y, cube[1]->z);
			glVertex3f(cube[2]->x, cube[2]->y, cube[2]->z);
			glVertex3f(cube[3]->x, cube[3]->y, cube[3]->z);
		glEnd();
	}
};

Cube* cube;
int Cube::numCubes = 0;
bool mousePressed;
bool middlePressed;
GLfloat x_click;
GLfloat y_click;
GLfloat y_rotate;
GLfloat x_rotate;
GLfloat Perm_y_rotate;
GLfloat Perm_x_rotate;
bool lighting_enabled;
bool perspective_mode_enabled =  true;
bool auto_rotate_enabled = false;
GLfloat zoom = 0;
GLfloat perm_zoom = 0;
int rotate_speed;
int auto_rotate_speed = 1;
void drawFloor();
void draw_text(int x, int y, float r, float g, float b, int font, char *string);
int iterations = 0;
int BuildPopupMenu();
void myReshape(GLsizei width, GLsizei height);

//standard set-up
void myDisplay()
{
	myReshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
	//BuildPopupMenu ();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//draw_text(100.0f, 100.0f, 1.0f, 1.0f, 0.0f, NULL, "HELLO WORLD");

	glTranslatef(0.0f, 0.0f, -7.0f + perm_zoom + zoom);

	//gluLookAt(0, 0, 0, 0.0, 0.0, -100, 0.0, 1.0, 0.0);

	if(lighting_enabled)
		glEnable(GL_LIGHTING);
	else
		glDisable(GL_LIGHTING);

	GLfloat light_ambient[] =
	{0.2, 0.2, 0.2, 1.0};
	GLfloat light_diffuse[] =
	{1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular[] =
	{1.0, 1.0, 1.0, 1.0};
	GLfloat light_position[] =
	{1.0f, 1.0f, -7.0f, 0.0};

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//drawFloor();
	
	float auto_rotate_deg = auto_rotate_enabled ? glutGet(GLUT_ELAPSED_TIME)/100.0f : 0;
	//cout << auto_rotate_deg << endl;
	glRotatef(Perm_x_rotate + x_rotate + auto_rotate_deg * auto_rotate_speed, 1, 0, 0); //rotating object, camera static'
	glRotatef(Perm_y_rotate + y_rotate + auto_rotate_deg * auto_rotate_speed, 0, 1, 0);
	cube->drawCubes();
	//draw_text(20, 20, 0.0f, 1.0f, 1.0f, NULL, "HELLO WORLD");
	
	glFlush();
	glutSwapBuffers();
}

void draw_text(int x, int y, float r, float g, float b, int font, char *string)
{
  glColor3f( r, g, b );
  glRasterPos3f(x, y, -5.0f);
  int len, i;
  len = (int)strlen(string);
  for (i = 0; i < len; i++) {
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
  }
}

void drawFloor()
{
	glColor3f(1.0f, 1.0f, 1.0f); 
	glBegin(GL_QUADS);
		glVertex3f(-50.0f, -1.0f, -50.0f);
		glVertex3f(-50.0f, -1.0f,  50.0f);
		glVertex3f(50.0f, -1.0f,   50.0f);
		glVertex3f(50.0f, -1.0f, -50.0f);
	glEnd();
}

void idle()
{
	glutPostRedisplay();
}


void myReshape(GLsizei width, GLsizei height)
{
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   if(perspective_mode_enabled)
		gluPerspective(45.0f, aspect, 0.1f, 100.0f);
   else
	   glOrtho(-2.0, 2.0, -2.0, 2.0, 0.1f, 100.0f);
}

void initGL()
{
	glClearColor(0.0, 0.0, 0.0, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	//glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glDisable(GL_CULL_FACE);


	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);


}

void MouseButton(int button, int state, int x, int y) {
  // Respond to mouse button presses.
  // If button1 pressed, mark this state so we know in motion function.
	

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		perm_zoom += zoom;
		zoom = 0;
		mousePressed = true;
		x_click = x;
		y_click = y;
	}
	else if(button == GLUT_LEFT_BUTTON)
	{
		 mousePressed = false;

		 Perm_x_rotate += x_rotate;
		 Perm_y_rotate +=  y_rotate;
		 x_rotate = 0;
		 y_rotate = 0;
		 x_click = 0;
		 y_click = 0;
	}
	else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{

		middlePressed = true;
		x_click = x;
		y_click = y;
	}
	else if(button == GLUT_MIDDLE_BUTTON)
	{
		 middlePressed = false;

		 perm_zoom += zoom;
		 zoom = 0;
		 x_click = 0;
		 y_click = 0;
	}

		
		

	//cout << "BUTTON: " << button << endl;
}

void MouseMotion(int x, int y) {
  // If button1 pressed, zoom in/out if mouse is moved up/down.
	if(x_click == 0 && y_click == 0)
		return;
  if (mousePressed)
    {
      x_rotate = y - y_click;
	  y_rotate = x - x_click;
	  //cout << "xrotate: " << x_rotate << endl;
    }
  if(middlePressed)
  {
	  zoom = ((float)(y - y_click))/100.0f;
  }

	glutPostRedisplay();

}

enum {
  MENU_LIGHTING = 1,
  MENU_POLYMODE,
  MENU_PERSPECTIVE,
  MENU_AUTO_ROTATE,
  MENU_TEXTURING,
  MENU_INCREASE_ROTATE_SPEED,
  MENU_INCREASE_AUTO_ROTATE_SPEED,
  MENU_DECREASE_ROTATE_SPEED,
  MENU_DECREASE_AUTO_ROTATE_SPEED,
  MENU_LEVEL_0,
  MENU_LEVEL_1,
  MENU_LEVEL_2,
  MENU_LEVEL_3,
  MENU_LEVEL_4,
  MENU_LEVEL_5,
  MENU_EXIT
};



void SelectFromMenu(int idCommand) {
  switch (idCommand)
    {
		 case MENU_PERSPECTIVE:
			perspective_mode_enabled = !perspective_mode_enabled;
			break;
		 case MENU_LIGHTING:
			lighting_enabled = !lighting_enabled;
			break;
		 case MENU_AUTO_ROTATE:
			 auto_rotate_enabled = !auto_rotate_enabled;
			 break;
		 case MENU_INCREASE_ROTATE_SPEED:
			 rotate_speed++;
			 break;
		 case MENU_INCREASE_AUTO_ROTATE_SPEED:
			 auto_rotate_speed++;
			 break;
		 case MENU_DECREASE_ROTATE_SPEED:
			 rotate_speed--;
			 break;
		 case MENU_DECREASE_AUTO_ROTATE_SPEED:
			 auto_rotate_speed--;
			 break;
		 case MENU_LEVEL_1:
			 iterations = 1;
			 cube = new Cube(new Point(0, 0, 0), 1.0, iterations);
			 break;
		 case MENU_LEVEL_2:
			 iterations = 2;
			 cube = new Cube(new Point(0, 0, 0), 1.0, iterations);
			 break;
		 case MENU_LEVEL_3:
			 iterations = 3;
			 cube = new Cube(new Point(0, 0, 0), 1.0, iterations);
			 break;
		 case MENU_LEVEL_4:
			 iterations = 4;
			 cube = new Cube(new Point(0, 0, 0), 1.0, iterations);
			 break;
		 case MENU_LEVEL_0:
			 iterations = 0;
			 cube = new Cube(new Point(0, 0, 0), 1.0, iterations);
			 break;
		 case MENU_LEVEL_5:
			 iterations = 5;
			 cube = new Cube(new Point(0, 0, 0), 1.0, iterations);
			 break;
    }
  // Almost any menu selection requires a redraw
  glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y) {
  switch (key)
  {
  case 27:             // ESCAPE key
	  exit (0);
	  break;
  case 'l':
	  SelectFromMenu(MENU_LIGHTING);
	  break;
  case 'r':
	  SelectFromMenu(MENU_AUTO_ROTATE);
	  break;
  case 'p':
	  SelectFromMenu(MENU_PERSPECTIVE);
	  break;
  case 't':
	  SelectFromMenu(MENU_TEXTURING);
	  break;
  case '+':
	  SelectFromMenu(MENU_INCREASE_AUTO_ROTATE_SPEED);
	  break;
  case '-':
	  SelectFromMenu(MENU_DECREASE_AUTO_ROTATE_SPEED);
	  break;
  case '0':
	  SelectFromMenu(MENU_LEVEL_0);
	  break;
	case '1':
	  SelectFromMenu(MENU_LEVEL_1);
	  break;
	case '2':
	  SelectFromMenu(MENU_LEVEL_2);
	  break;
	case '3':
	  SelectFromMenu(MENU_LEVEL_3);
	  break;
	case '4':
	  SelectFromMenu(MENU_LEVEL_4);
	  break;
	case '5':
	  SelectFromMenu(MENU_LEVEL_5);
	  break;
	}
}

int BuildPopupMenu (void) {
  int menu;
  menu = glutCreateMenu (SelectFromMenu);
		glutAddMenuEntry ("Toggle Auto rotate\tr", MENU_AUTO_ROTATE);



	glutAddMenuEntry ("Toggle lighting\tl", MENU_LIGHTING);



  glutAddMenuEntry ("Toggle perspective\tp", MENU_PERSPECTIVE);
  glutAddMenuEntry ("Increase auto rotate speed\t+", MENU_INCREASE_AUTO_ROTATE_SPEED);
  glutAddMenuEntry ("Decrease auto rotate speed\t-", MENU_DECREASE_AUTO_ROTATE_SPEED);
  glutAddMenuEntry ("Recursion level: 0\t0", MENU_LEVEL_0);
  glutAddMenuEntry ("Recursion level: 1\t1", MENU_LEVEL_1);
  glutAddMenuEntry ("Recursion level: 2\t2", MENU_LEVEL_2);
  glutAddMenuEntry ("Recursion level: 3\t3", MENU_LEVEL_3);
  glutAddMenuEntry ("Recursion level: 4\t4", MENU_LEVEL_4);
  glutAddMenuEntry ("Exit demo\tEsc", MENU_EXIT);
  glutAddMenuEntry ("--------------------\t-------------------", -1);
  glutAddMenuEntry ("Rotate:\tLeft click + drag", -1);
  glutAddMenuEntry ("Zoom:\tMiddle click + drag", -1);
  return menu;
}



int main(int argc, char* argv[])
{
	iterations = (argc < 2) ? 2 : atoi(argv[1]);
	if(iterations>4)
		iterations = 4;
	cube = new Cube(new Point(0, 0, 0), 1.0, iterations);
	glutInit(&argc, argv); //init glut library

	glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Vincent's Menger Cube: <  RIGHT CLICK FOR MENU  >");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(myDisplay);
	glutMouseFunc(MouseButton);
	glutMotionFunc(MouseMotion);
	glutKeyboardFunc(Keyboard);
	glutIdleFunc(idle);
	int val = BuildPopupMenu ();
	//cout << "val" << val << endl;
	glutAttachMenu (GLUT_RIGHT_BUTTON);
	initGL();
	glutMainLoop();	

	
	delete(cube);
}


