#pragma once

#include <cstdio>
#include <string>
#include <vector>

namespace utils {

struct BloomFilterConf {
  uint32_t hash_seed{};
  uint32_t max_allow_item{};
  double false_rate{};
};

class BloomFilter {
public:
  bool Init(const BloomFilterConf &conf);
  bool Add(std::vector<uint8_t> &data);
  bool Check(std::vector<uint8_t> &data);
  void Reset();
  bool Dump(const std::string &file = "dump.bin");
  bool Load(const std::string &file = "dump.bin");

private:
  void CalcInternalParams();

  bool is_init_{false};
  uint32_t max_items_{};
  uint32_t filter_bits_{};
  uint32_t hash_func_cnt_{};
  uint32_t hash_seed_{};
  uint32_t add_cnt_{};
  uint32_t filter_bytes_{};
  std::vector<uint8_t> filter_{};
  std::vector<uint32_t> pre_hash_pos_{};
  double false_rate_{};
};

} // namespace utils
