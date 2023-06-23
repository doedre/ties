import ties.math;

int main()
{
  using namespace ties::types;
  static_assert(ties::math::abs(-12) == 12);
  static_assert(ties::math::abs(limits<i8>::min) == -128);
  static_assert(ties::math::count_ones(0b10010) == 2);
  static_assert(ties::math::count_zeros(static_cast<u8>(0b10010010)) == 5);
  static_assert(ties::math::trailing_zeros(static_cast<i8>(0b10000000)) == 7);
  static_assert(ties::math::trailing_zeros(static_cast<i8>(0b00000000)) == 8);
  static_assert(ties::math::trailing_zeros(static_cast<u8>(0b00000000)) == 8);
  static_assert(ties::math::trailing_ones(static_cast<u8>(0b11111111)) == 8);
  static_assert(ties::math::trailing_ones(static_cast<i8>(0b11111111)) == 8);
  static_assert(ties::math::trailing_ones(static_cast<u8>(0b00000000)) == 0);
  static_assert(ties::math::leading_zeros(static_cast<i8>(0b11111111)) == 0);
  static_assert(ties::math::leading_zeros(static_cast<u8>(0b11111111)) == 0);
  static_assert(ties::math::leading_zeros(static_cast<i8>(0b00011111)) == 3);
  static_assert(ties::math::leading_ones(static_cast<u8>(0b00011111)) == 0);
  static_assert(ties::math::leading_ones(static_cast<u8>(0b11111111)) == 8);
  static_assert(ties::math::leading_ones(static_cast<i8>(0b11111111)) == 8);

  {
    constexpr auto res = ties::math::carrying_add(2_u64, 2_u64, 0_u64);
    static_assert(res.get<0>() == 4_u64);
    static_assert(res.get<1>() == false);
  }
  {
    constexpr auto res = ties::math::carrying_add(~0_u64, 0_u64, 0_u64);
    static_assert(res.get<0>() == ~0_u64);
    static_assert(res.get<1>() == false);
  }
  {
    constexpr auto res = ties::math::carrying_add(~0_u64, 1_u64, 0_u64);
    static_assert(res.get<0>() == 0_u64);
    static_assert(res.get<1>() == true);
  }

  {
    constexpr auto res = ties::math::borrowing_sub(0_u32, 1_u32, 0_u32);
    static_assert(res.get<0>() == ~0_u32);
    static_assert(res.get<1>() == true);
  }

  return 0;
}
