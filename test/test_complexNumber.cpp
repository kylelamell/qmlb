#include "complexNumber.hpp"
#include <iomanip>
#include <iostream>
#include <vector>

struct test_case {
  bool (*test_ptr)();
  std::string test_name;
};

// add normal
bool add_normal() {
  return true;
};

int main() {
  int totalPassed = 0;

  // define all the tests
  const std::vector<test_case> tests = {
    {add_normal, "Add Normal"}
  };

  std::cout << "=======================================" << std::endl;
  std::cout << "test_complexNumber: START" << std::endl;
  std::cout << std::endl;

  for (const test_case test : tests) {
    bool didPass = test.test_ptr();
    if (didPass) ++totalPassed;
    std::cout << test.test_name <<": " << ((didPass) ? "Passed" : "Failed") << std::endl;
  }

  std::cout << "Test Cases Passed: " << totalPassed << "/" << tests.size() << " ";
  std::cout << "(" << std::fixed << std::setprecision(2);
  std::cout << (static_cast<double>(totalPassed)/tests.size()) * 100.0 << "%)" << std::endl;

  std::cout << std::endl;
  std::cout << "test_complexNumber: END" << std::endl;
  std::cout << "=======================================" << std::endl;
}