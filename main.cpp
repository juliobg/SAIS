#include "sa-is.h"

#include <cassert>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>

std::string random_string(std::string::size_type length) {
  static auto &chrs = "0123456789"
                      "abcdefghijklmnopqrstuvwxyz"
                      "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  thread_local static std::mt19937 rg{std::random_device{}()};
  thread_local static std::uniform_int_distribution<std::string::size_type>
      pick(0, sizeof(chrs) - 2);

  std::string s;

  s.reserve(length);

  while (length--)
    s += chrs[pick(rg)];

  return s;
}

template <typename T> std::vector<int> naive(const T &data) {
  std::vector<int> result(data.size() + 1, -1);
  for (int i = 0; MAKE_UNSIGNED(i) < data.size() + 1; i++) {
    result[MAKE_UNSIGNED(i)] = i;
  }
  std::sort(result.begin(), result.end(), [&data](int a, int b) {
    return MAKE_UNSIGNED(a) == data.size()
               ? true
               : data.substr(MAKE_UNSIGNED(a)) < data.substr(MAKE_UNSIGNED(b));
  });

  return result;
}

int main() {

  for (int i = 0; i < 10; i++) {
    auto str = random_string(10000u);

    auto start = std::chrono::steady_clock::now();
    auto r = sais_suffix_array(str, 256);
    auto end = std::chrono::steady_clock::now();
    std::cout << "time with SA-IS: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                       start)
                     .count()
              << " ms" << std::endl;
    start = std::chrono::steady_clock::now();
    auto r2 = naive(str);
    end = std::chrono::steady_clock::now();
    std::cout << "time with naive algorithm: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end -
                                                                       start)
                     .count()
              << " ms" << std::endl
              << std::endl;

    assert(r == r2);
  }

  std::string str("thisastringfortesting");
  auto sa = sais_suffix_array(str);
  for (std::size_t i = 1; i < sa.size(); i++) {
    std::cout << std::setw(2) << std::setfill('0') << sa[i] << " "
              << str.substr(sa[i]) << std::endl;
  }

  return 0;
}
