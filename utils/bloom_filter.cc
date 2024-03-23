#include "bloom_filter.h"

namespace {

constexpr int kMagicCode = 0x01464C42;

#pragma pack(1)

struct BloomFilterFileHeader {
  uint32_t magic_header;
  uint32_t seed;
  uint32_t count;
  uint32_t max_items;
  uint32_t filter_bits;
  uint32_t hash_funcs;
  uint32_t resv[6];
  uint32_t file_crc;
  uint32_t filter_size;
  double false_rate;
};

#pragma pack()

} // namespace

namespace utils {

bool BloomFilter::Init(const BloomFilterConf &conf) {
  if (is_init_) {
    return false;
  }

  max_items_ = conf.max_allow_item;
  false_rate_ = conf.false_rate;
  hash_seed_ = conf.hash_seed;

  CalcInternalParams();

  is_init_ = true;
  return true;
}

} // namespace utils