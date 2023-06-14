export module ties.concepts;

import ties.types;
import ties.type_traits;

using namespace ties::types;

namespace ties::concepts::impl {
  template<typename T1, typename T2>
  inline constexpr bool same_types = false;

  template<typename T>
  inline constexpr bool same_types<T, T> = true;

  template<typename T>
  inline constexpr bool lvalue_reference = false;

  template<typename T>
  inline constexpr bool lvalue_reference<T&> = true;

  template<typename T>
  inline constexpr bool rvalue_reference = false;

  template<typename T>
  inline constexpr bool rvalue_reference<T&&> = true;

  template<typename T>
  inline constexpr bool const_qualified = false;

  template<typename T>
  inline constexpr bool const_qualified<const T> = true;

  template<typename T>
  inline constexpr bool const_qualified<const volatile T> = true;

  template<typename T>
  inline constexpr bool volatile_qualified = false;

  template<typename T>
  inline constexpr bool volatile_qualified<volatile T> = true;

  template<typename T>
  inline constexpr bool volatile_qualified<const volatile T> = true;

  template<typename T>
  inline constexpr bool array_with_unknown_bounds = false;

  template<typename T>
  inline constexpr bool array_with_unknown_bounds<T[]> = true;

  template<typename T>
  inline constexpr bool array_with_known_bounds = false;

  template<typename T, usize Size>
  inline constexpr bool array_with_known_bounds<T[Size]> = true;

  template<typename T>
  inline constexpr bool pointer = false;

  template<typename T>
  inline constexpr bool pointer<T*> = true;
}

export namespace ties::concepts {
  template<typename T1, typename T2>
  concept same_types = impl::same_types<T1, T2>;

  template<typename From, typename To>
  concept convertible_types = requires(From from, To to) {
    static_cast<To>(from);
  };

  template<typename T>
  concept integral =  same_types<T, i8> or
                      same_types<T, u8> or
                      same_types<T, i16> or
                      same_types<T, u16> or
                      same_types<T, i32> or
                      same_types<T, u32> or
                      same_types<T, i64> or
                      same_types<T, u64> or
                      same_types<T, i128> or
                      same_types<T, u128>;

  template<typename T>
  concept floating_point =  same_types<T, f32> or
                            same_types<T, f64> or
                            same_types<T, f128>;

  template<typename T>
  concept signed_integral = same_types<T, i8> or
                            same_types<T, i16> or
                            same_types<T, i32> or
                            same_types<T, i64> or
                            same_types<T, i128>;

  template<typename T>
  concept unsigned_integral = same_types<T, u8> or
                              same_types<T, u16> or
                              same_types<T, u32> or
                              same_types<T, u64> or
                              same_types<T, u128>;

  template<typename T>
  concept arithmetic = integral<T> or floating_point<T>;

  template<typename T>
  concept fundamental = integral<T> or
                        floating_point<T> or
                        same_types<T, void> or
                        same_types<T, nullptr_t>;

  template<typename T>
  concept lvalue_reference = impl::lvalue_reference<T>;

  template<typename T>
  concept rvalue_reference = impl::rvalue_reference<T>;

  template<typename T>
  concept reference = lvalue_reference<T> or rvalue_reference<T>;

  template<typename T>
  concept const_qualified = impl::const_qualified<T>;

  template<typename T>
  concept volatile_qualified = impl::volatile_qualified<T>;

  template<typename T>
  concept pointer = impl::pointer<type_traits::remove_cv_qualifiers<T>>;

  template<typename T>
  concept enum_object = __is_enum(T);

  template<typename T>
  concept scoped_enum_object = enum_object<T> and
      not requires(T val, void(*f)(int)) {
        f(val);    // functions taking an int should not accept scoped enums
      };

  template<typename T>
  concept union_object = __is_union(T);

  template<typename T>
  concept class_object = __is_class(T);

  template<typename T>
  concept function = not lvalue_reference<T> and not rvalue_reference<T> and not const_qualified<const T>;

  template<typename T>
  concept array_with_unknown_bounds = impl::array_with_unknown_bounds<T>;

  template<typename T>
  concept array_with_known_bounds = impl::array_with_known_bounds<T>;

  template<typename T>
  concept array = array_with_unknown_bounds<T> or array_with_known_bounds<T>;

  template<typename T>
  concept incomplete = requires(type_traits::remove_cv_qualifiers<T> val) {
    val = val;   // should fail if incomplete
  };

  template<typename T>
  concept standard_layouted = __is_standard_layout(T);

  template<typename T>
  concept trivially_copyable = __is_trivially_copyable(T);

  template<typename T>
  concept trivial = __is_trivial(T);

  template<typename T, typename... Args>
  concept constructible = __is_constructible(T, Args...);

  template<typename T, typename... Args>
  concept trivially_constructible = __is_trivially_constructible(T, Args...);

  template<typename T>
  concept destructible = requires(T val) {
    val.~T();
  };

  template<typename T>
  concept trivially_destructible = __has_trivial_destructor(T);

  template<typename T>
  concept default_constructible = constructible<T>;

  template<typename T>
  concept trivially_default_constructible = trivially_constructible<T>;

  template<typename T>
  concept copy_constructible = constructible<T, type_traits::add_lvalue_reference<const T>>;

  template<typename T>
  concept trivially_copy_constructible =
      trivially_constructible<T, type_traits::add_lvalue_reference<const T>>;

  template<typename T>
  concept move_constructible = constructible<T, type_traits::add_rvalue_reference<T>>;

  template<typename T>
  concept trivially_move_constructible =
      trivially_constructible<T, type_traits::add_rvalue_reference<T>>;

  template<typename T, typename U>
  concept assignable = __is_assignable(T, U);

  template<typename T, typename U>
  concept trivially_assignable = __is_trivially_assignable(T, U);

  template<typename T>
  concept copy_assignable =
      assignable<type_traits::add_lvalue_reference<T>, type_traits::add_lvalue_reference<const T>>;

  template<typename T>
  concept trivially_copy_assignable =
      trivially_assignable<type_traits::add_lvalue_reference<T>, type_traits::add_lvalue_reference<const T>>;

  template<typename T>
  concept move_assignable =
      assignable<type_traits::add_lvalue_reference<T>, type_traits::add_rvalue_reference<T>>;

  template<typename T>
  concept trivially_move_assignable =
      trivially_assignable<type_traits::add_lvalue_reference<T>, type_traits::add_rvalue_reference<T>>;
}

