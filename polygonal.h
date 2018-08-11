#ifndef TRAB1_POLYGONAL_H
#define TRAB1_POLYGONAL_H

#include <vector>
#include "point2d.h"

template <typename T>
class polygonal
{
    std::vector<point<T>> points;
  
  public:
    void add_point(const point<T>& point)
    {
      points.push_back(point);
    }
    
    void smooth_edges()
    {
      std::vector<point<T>> new_points;
      
      // Pushing first point
      new_points.push_back(points[0]);
      
      for (size_t index = 0; index != points.size() - 1; ++index) {
        auto initial_point = points[index];
        auto final_point = points[index + 1];
        
        // First quarter point
        new_points.emplace_back(initial_point + (final_point - initial_point) / 4.0);
        
        // Mid point
        new_points.emplace_back(initial_point + (final_point - initial_point) / 2.0);
        
        // Last quarter point
        new_points.emplace_back(initial_point + ((final_point - initial_point) / 4.0) * 3);
      }
      
      // Pushing last point
      new_points.push_back(points[points.size() - 1]);
      
      // Moving new points
      points = std::move(new_points);
    }
    
    // Some C++ iterators bullshit
    auto begin() -> decltype(points.begin())
    {
      return points.begin();
    }
    
    // Some C++ iterators bullshit
    auto end() -> decltype(points.end())
    {
      return points.end();
    }
};

#endif //TRAB1_POLYGONAL_H
