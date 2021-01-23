#include <iostream>
#include <tuple>
#include <type_traits>

template<class... Ts> class my_tuple
{
public:
    my_tuple(Ts... args) : tuple_(args...)
    {}

	template<std::size_t index>
    auto get(std::integral_constant<std::size_t, index>)
    {
        return std::get<index>(tuple_);
    }

private:
    std::tuple<Ts...> tuple_;
};

template<std::size_t index, class... Ts>
void print_nth(my_tuple<Ts...> tuple)
{
    std::cout << tuple.get(std::integral_constant<std::size_t, index>{}) << std::endl;
}

int main()
{
    my_tuple<char, char, char> tuple('a', 'b', 'c');
    print_nth<1>(tuple);
}
