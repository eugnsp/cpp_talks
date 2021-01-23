#include <iostream>
#include <tuple>

template<class... Ts> class my_tuple
{
public:
    my_tuple(Ts... args) : tuple_(args...)
    {}

    template<std::size_t index>
    auto get()
    {
        return std::get<index>(tuple_);
    }

private:
    std::tuple<Ts...> tuple_;
};

template<std::size_t index>
void print_nth(my_tuple<char, char, char> tuple)
{
    std::cout << tuple.get<index>() << std::endl;
}

int main()
{
    my_tuple<char, char, char> tuple('a', 'b', 'c');
    print_nth<1>(tuple);
}
