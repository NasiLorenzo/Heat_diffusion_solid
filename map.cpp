#include "map.hpp"
namespace Diff {
std::size_t PosID_hash::operator()(PosID const& other) const noexcept {
  std::hash<int> int_hasher;
  auto result = int_hasher(other[0]);
  std::for_each(other.begin() + 1, other.end(), [&](auto& ID_comp) {
    result ^= int_hasher(ID_comp) + (result << 6) + 0x9e3779b9 + (result >> 2);
  });
  return result;
}

bool operator==(PosID const& lhs, PosID const& rhs) {
  return std::equal(lhs.begin(), lhs.end(), rhs.begin());
}
}  // namespace Diff