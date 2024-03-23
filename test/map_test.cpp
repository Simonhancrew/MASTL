#include "utils/time_utils.h"
#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#ifndef USE_STD_MAP
#include <unordered_map>
#else
#include <map>
#endif

namespace {

constexpr int kMapItem = 1e5;

} // namespace

using utils::TickMs;

#ifdef USE_STD_MAP
using Map = std::map<std::string, bool>;
#else
using Map = std::unordered_map<std::string, bool>;
#endif

int main() {
  std::ios::sync_with_stdio(false);
  Map mp;

  std::string main_key = "test-";
  auto st = TickMs();
  for (int i = 0; i < kMapItem; i++) {
    auto sub_key = std::to_string(i);
    mp.emplace(std::piecewise_construct,
               std::forward_as_tuple(main_key + sub_key),
               std::forward_as_tuple(1));
  }
  auto et = TickMs();
  std::cout << "insert " << std::to_string(kMapItem) << " time: " << et - st
            << "ms\n";
  st = TickMs();
  auto item = mp.find(main_key + "100");
  if (item == mp.end()) {
    std::cout << "not found\n";
  } else {
    std::cout << item->first << " is " << item->second << '\n';
  }
  et = TickMs();
  std::cout << "find one time:" << et - st << "ms\n";
  return 0;
}
