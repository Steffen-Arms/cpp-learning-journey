#include <string_view>
#include <vector>

int main()
{

    std::vector task_a{2, 4, 6, 8, 10, 12};

    const std::vector task_b{1.2, 3.4, 5.6, 7.8};

    using namespace std::literals::string_view_literals;
    const std::vector task_c{"Alex"sv, "Brad"sv, "Charles"sv, "Dave"sv};

    std::vector task_d{12};

    std::vector<int> task_e(12);

    return 0;
}
