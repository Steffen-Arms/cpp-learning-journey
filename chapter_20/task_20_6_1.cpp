#include <algorithm>
#include <array>
#include <functional>
#include <iostream>
#include <string>

struct Student
{
    std::string studentName{};
    int points{0};
};

int main()
{
    std::array<Student, 8> arr{{{"Albert", 3},
                                {"Ben", 5},
                                {"Christine", 2},
                                {"Dan", 8}, // Dan has the most points (8).
                                {"Enchilada", 4},
                                {"Francis", 1},
                                {"Greg", 3},
                                {"Hagrid", 5}}};

    Student bestMan =
        *std::max_element(arr.begin(), arr.end(),
                          [](const Student& a, const Student& b) -> bool
                          {
                              if (a.points < b.points)
                              {
                                  return true;
                              }
                              else
                              {
                                  return false;
                              }
                          });

    std::cout << bestMan.studentName << " is the best student. \n";
}
