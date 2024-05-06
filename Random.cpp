#include <iostream>
#include <chrono>

using namespace std;

int sumDigits(long long num) {
  int sum = 0;
  while (num > 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main() {
  using namespace chrono;

  auto start_time = high_resolution_clock::now();

  // Simulate some work that takes time
  long long some_large_number = 1234567890;
  for (int i = 0; i < 100000; i++) {
    some_large_number *= some_large_number;
  }

  auto end_time = high_resolution_clock::now();

  auto elapsed_time = duration_cast<nanoseconds>(end_time - start_time);

  // Get the sum of digits of the elapsed time in nanoseconds
  int digit_sum = sumDigits(elapsed_time.count());

  cout << "Elapsed time in nanoseconds: " << elapsed_time.count() << " ns\n";
  cout << "Sum of digits: " << digit_sum << endl;

  return 0;
}
