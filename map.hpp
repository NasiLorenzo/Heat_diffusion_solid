#ifndef MAP_HPP
#define MAP_HPP
#include <unordered_map>
#include <vector>

namespace Diff {
using PosID = std::array<int, 2>;

struct PosID_hash {
  std::size_t operator()(PosID const& other) const noexcept;
};

}  // namespace Diff

#endif