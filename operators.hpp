#ifndef OPERATORS_HPP
#define OPERATORS_HPP
#include "temp_field.hpp"
namespace Diff {
auto laplacian_CDD_CDD(Section2D const& fw_x, Section2D const& bw_x,
                   Section2D const& fw_y, Section2D const& bw_y, Section2D&);

auto laplacian_FDD_FDD(Section2D const& fw_x, Section2D const& ffw_x,
                   Section2D const& fw_y, Section2D const& ffw_y,
                   Section2D& self);
}  // namespace Diff

#endif