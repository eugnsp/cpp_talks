#include <iostream>
#include <tuple>
#include <type_traits>

template<std::size_t index>
using my_size_t = std::integral_constant<std::size_t, index>;

template<std::size_t index>
inline constexpr auto my_size_c = my_size_t<index>{};

template<class... Ts> class my_tuple
{
public:
    my_tuple(Ts... args) : tuple_(args...)
    {}

	template<std::size_t index>
    auto get(my_size_t<index>)
    {
        return std::get<index>(tuple_);
    }

private:
    std::tuple<Ts...> tuple_;
};

template<std::size_t index, class... Ts>
void print_nth(my_tuple<Ts...> tuple)
{
    std::cout << tuple.get(my_size_c<index>) << std::endl;
}

int main()
{
    my_tuple<char, char, char> tuple('a', 'b', 'c');
    print_nth<1>(tuple);
}
