#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <stdio.h>
#include "math.h"
#include <stdlib.h> 
#include <utility>
#include "vec.cpp"
using namespace std;

double spx,spy,spz;
int viewx,viewy;



class Sphere{
  vector3d c;
  double r;

};

class Plane{
  vector3d x,y,z;

};

class Object{
  int type;
  Sphere s;
  Plane p;
  double ka[3],kd[3],ks[3];
  double exp;
};


 class lightsource{
  double intensity[3];
  vector3d direction;
  
 };



struct rgbf {float r; float g; float b;};
//WBL 9 May 2007 Based on
//http://www.codeguru.com/cpp/w-d/dislog/commondialogs/article.php/c1861/
//Common.h
void toRGBf(const float h, const float s, const float v,
      rgbf* rgb)
{
  /*
RGBType rgb;
  if(!h  && !s)
  {
    rgb.r = rgb.g = rgb.b = v;
  }
  */
  //rgbf* rgb = (rgbf*) out;
double min,max,delta,hue;
  
  max = v;
  delta = max * s;
  min = max - delta;

  hue = h;
  if(h > 300 || h <= 60)
  {
    rgb->r = max;
    if(h > 300)
    {
      rgb->g = min;
      hue = (hue - 360.0)/60.0;
      rgb->b = ((hue * delta - min) * -1);
    }
    else
    {
      rgb->b = min;
      hue = hue / 60.0;
      rgb->g = (hue * delta + min);
    }
  }
  else
  if(h > 60 && h < 180)
  {
    rgb->g = max;
    if(h < 120)
    {
      rgb->b = min;
      hue = (hue/60.0 - 2.0 ) * delta;
      rgb->r = min - hue;
    }
    else
    {
      rgb->r = min;
      hue = (hue/60 - 2.0) * delta;
      rgb->b = (min + hue);
    }
  }
  else
  {
    rgb->b = max;
    if(h < 240)
    {
      rgb->r = min;
      hue = (hue/60.0 - 4.0 ) * delta;
      rgb->g = (min - hue);
    }
    else
    {
      rgb->g = min;
      hue = (hue/60 - 4.0) * delta;
      rgb->r = (min + hue);
    }
  }
}


//Convert a wide range of data values into nice colours 
void colour(const float data, float* out) {
  //convert data to angle
  const float a = atan2(data,1)/(2*atan2(1,1)); // -1 .. +1
  const float angle = (1+a)*180; //red=0 at -1,+1

  const float saturation = 1;

  const float h = (data<-1||data>1)? 1 : fabs(data);

  toRGBf(angle,saturation,h,(rgbf*)out);
}



void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  // if (key == GLUT_KEY_RIGHT)
  //   rotate_y += 5;
 
  // //  Left arrow - decrease rotation by 5 degree
  // else if (key == GLUT_KEY_LEFT)
  //   rotate_y -= 5;
 
  // else if (key == GLUT_KEY_UP)
  //   rotate_x += 5;
 
  // else if (key == GLUT_KEY_DOWN)
  //   rotate_x -= 5;
  // else if(key==GLUT_KEY_F1)
  //   view=0;
  // else if(key==GLUT_KEY_F2)
  //   view=1;
  // else if(key==GLUT_KEY_F3)
  //   view=2;
  // else if(key==GLUT_KEY_F4)
  //   view=3;
  // else if(key==GLUT_KEY_F7)
  //   view=4;

 
  //  Request display update
  glutPostRedisplay();
 
}




void display()
{
    glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT);
    float* pixels = new float[viewx*viewy*3];
    for(int i=0;i<viewx*viewy;i++) {
    colour(10.0-((i*20.0)/(viewx*viewy)),&pixels[i*3]);
  } 

  //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //http://msdn2.microsoft.com/en-us/library/ms537062.aspx
  //glDrawPixels writes a block of pixels to the framebuffer.

  glDrawPixels(viewx,viewy,GL_RGB,GL_FLOAT,pixels);

    glFlush();        
    glutSwapBuffers();

}


void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;   
    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity(); 
    //gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glOrtho(-10.0, 10.0, -10.0, 10.0, -100.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
} 












int main (int argc, char **argv)
{
    
    glutInit(&argc, argv); 
    viewx=512;viewy=512;
    glutInitWindowSize(viewx,viewy);
    glutCreateWindow("Solid Sphere");
    spx=0.0;spy=0.0;spz=0.0;
    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
