#ifndef TEMP_FIELD_HPP
#define TEMP_FIELD_HPP
#include <iostream>
#include <random>

#include "map.hpp"
namespace Diff {

static const double diff_param{5.};
struct Section2D {
  PosID position;
  double temp;
};

using MyMap = std::unordered_map<PosID, Section2D const*, PosID_hash>;

struct neighbors{
    PosID fw_x;
    PosID fw_y;
    PosID bw_x;//
    PosID bw_y;

};

class TempField {
  TempField(std::default_random_engine& eng, int length, int height,
            double tempmin, double tempmax, double diff_param, double delt)
      : _height(height),
        _length(length),
        _diff_param(diff_param),
        _delt(delt),
        _field{generate_field(eng, _length, _height, tempmin, tempmax)},
        _map(length * height) {
    update_map(_map, _field);
  }
 void update();
 private:
  const int _length;
  const int _height;
  const double _diff_param;
  const double _delt;
  std::vector<Section2D> _field;
  MyMap _map;
};

auto generate_pos(std::size_t index, double length, double width);
void update_map(MyMap& map);
std::vector<Section2D> generate_field(std::default_random_engine& eng,
                                      int length, int width, double tempmin,
                                      double tempmax);

}  // namespace Diff
#endif