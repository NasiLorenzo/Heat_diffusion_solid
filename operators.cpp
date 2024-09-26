#include "operators.hpp"

namespace Diff {
auto laplacian_CDD(Section2D const& fw_x, Section2D const& bw_x,
                   Section2D const& fw_y, Section2D const& bw_y,
                   Section2D& self) {
  auto result = (fw_x.temp - 2 * self.temp + bw_x.temp);
  result += (fw_y.temp - 2 * self.temp + bw_y.temp);
  return result;
}
auto laplacian_FDD(Section2D const& fw_x, Section2D const& ffw_x,
                   Section2D const& fw_y, Section2D const& ffw_y,
                   Section2D& self) {
  auto result = (self.temp - 2 * fw_x.temp + ffw_x.temp);
  result += (self.temp - 2 * fw_y.temp + ffw_y.temp);
}

}  // namespace Diff