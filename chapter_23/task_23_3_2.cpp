
#include <functional>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Teacher
{
  private:
    std::string m_name{};

  public:
    Teacher(std::string_view name) : m_name{name} {}

    const std::string& getName() const { return m_name; }

    friend std::ostream& operator<<(std::ostream& out, const Teacher& teacher);
};

std::ostream& operator<<(std::ostream& out, const Teacher& teacher)
{
    out << teacher.m_name;
    return out;
}

class Department
{
  private:
    std::vector<std::reference_wrapper<const Teacher>> m_teachers{};
    // const Teacher& m_teacher; // This dept holds only one teacher for
    // simplicity, but it could hold many teachers

  public:
    Department() = default;

    friend std::ostream& operator<<(std::ostream& out,
                                    const Department& department);

    void add(Teacher& teacher) { m_teachers.emplace_back(teacher); }
};

std::ostream& operator<<(std::ostream& out, const Department& department)
{
    out << "These are the teacher of the department: \n";
    for (const auto& teacher : department.m_teachers)
    {
        out << "Teacher: " << teacher << '\n';
    }

    return out;
}

int main()
{
    // Create a teacher outside the scope of the Department
    Teacher t1{"Bob"};
    Teacher t2{"Frank"};
    Teacher t3{"Beth"};

    {
        // Create a department and add some Teachers to it
        Department department{}; // create an empty Department

        department.add(t1);
        department.add(t2);
        department.add(t3);

        std::cout << department;

    } // department goes out of scope here and is destroyed

    std::cout << t1.getName() << " still exists!\n";
    std::cout << t2.getName() << " still exists!\n";
    std::cout << t3.getName() << " still exists!\n";

    return 0;
}
