#include <GL/gl.h>     // The GL Header File
#include <GL/freeglut.h>   // The GL Utility Toolkit (Glut) Header

#include <cmath>
#include <vector>

#include "globals.h"
#include "point2d.h"

void mouse_points(int button, int state, int X, int Y)
{
  // Respond to mouse button presses.
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    // Adding current mouse point to polygonal
    points.add_point(point<double>(X, Y).change_coordinates(width, height));
    glutPostRedisplay();
  }
}

void keyboard_cb(unsigned char key, int X, int Y)
{
  switch (key) {
    case 27:             // ESCAPE key
      points = std::move(polygonal<double>()); // Cleaning canvas
          glutPostRedisplay();
      break;
      
    case 's':
      points.smooth_edges(); // Smoothing
      glutPostRedisplay();
      break;
  }
}

void display_points()
{
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glPointSize(8.0);
  
  glLineWidth(4);
  
  glBegin(GL_LINE_STRIP);
  
  for(const auto& point: points){
    glVertex2d(point.x, point.y); // Drawing lines between points
  }
  
  glEnd();
  glutSwapBuffers();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitWindowSize(width, height);
  glutCreateWindow("Smooth");
  glutKeyboardFunc(keyboard_cb);
  glutMouseFunc(mouse_points);
  
  glutDisplayFunc(display_points);
  glutMainLoop();
  
  return EXIT_SUCCESS;
}
