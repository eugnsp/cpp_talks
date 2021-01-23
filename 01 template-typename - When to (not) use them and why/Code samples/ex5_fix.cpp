#include <iostream>
#include <tuple>
#include <typeinfo>

template<class... Ts> class my_tuple
{
public:
    my_tuple(Ts... args) : tuple_(args...)
    {}

	template<std::size_t index>
	using element_type = std::tuple_element_t<index, std::tuple<Ts...>>;

private:
    std::tuple<Ts...> tuple_;
};

template<std::size_t index, class... Ts>
void print_nth_type(my_tuple<Ts...> tuple)
{
	using T = decltype(tuple);  // = my_tuple<char, char, char>;
    std::cout << typeid(typename T::template element_type<index>).name() << std::endl;
}

int main()
{
    my_tuple<char, char, char> tuple('a', 'b', 'c');
    print_nth_type<1>(tuple);
}
