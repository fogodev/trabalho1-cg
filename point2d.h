#ifndef TRAB1_POINT2D_H
#define TRAB1_POINT2D_H

#include <cmath>

template <typename T>
struct point
{
  T x, y;
  
  point(T x, T y) noexcept :
      x(x),
      y(y)
  { }
  
  // Formula to change coordinates for OpenGL
  point<T> change_coordinates(T dim_x, T dim_y)
  {
    return point((2. * x) / dim_x - 1., -(2. * y) / dim_y + 1.);
  }
  
  // Some operator overloads
  point<T>& operator+=(const point<T>& other)
  {
    x += other.x;
    y += other.y;
    
    return *this;
  }
  
  point<T>& operator-=(const point<T>& other)
  {
    x -= other.x;
    y -= other.y;
    
    return *this;
  }
  
  point<T>& operator*=(double scalar)
  {
    x *= scalar;
    y *= scalar;
    
    return *this;
  }
  
  point<T>& operator/=(double scalar)
  {
    x /= scalar;
    y /= scalar;
    
    return *this;
  }
  
  point<T> operator+(const point<T>& other)
  {
    return point<T>(x + other.x, y + other.y);
  }
  
  point<T> operator-(const point<T>& other)
  {
    return point<T>(x - other.x, y - other.y);
  }
  
  point<T> operator*(double scalar)
  {
    return point<T>(x * scalar, y * scalar);
  }
  
  point<T> operator/(double scalar)
  {
    return point<T>(x / scalar, y / scalar);
  }
  
  // Rotation matrix
  void rotate(T theta)
  {
    T x_rot = x * cos(theta) + y * sin(theta);
    T y_rot = -x * sin(theta) + y * cos(theta);
    
    x = x_rot;
    y = y_rot;
  }
};

#endif //TRAB1_POINT2D_H
