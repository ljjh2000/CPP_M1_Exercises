#include <iostream>
#include <vector>
int add(const int a, const int b)
{
    return a + b;
}
void add_to(int &a, const int b)
{
    a += b;
}

int const count_a_occurrences(const std::string &s);

void update_loop(const float &dt, std::string &errors_out);

bool are_all_positives(const std::vector<int> &values, int negative_indices_out[],
                       size_t &negative_count_out);

std::string const concatenate(const char *str1, const char *str2);

int main()
{
    const int x{10};
    int y = add(x, x);
    add_to(y, 22);
    std::cout << y << std::endl;
    return 0;
}