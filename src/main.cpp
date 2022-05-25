#include<iostream>
#include"class.hpp"


namespace _ns
{
    std::weak_ordering operator<=>(const Encoder& lhs, const Encoder& rhs)
	{
		return lhs.sCode.Get() <=> rhs.sCode.Get();  // ignore CppCheck syntaxError
	}

	bool operator==(const Encoder& lhs, const Encoder& rhs)
	{
		return lhs.sCode.Get() == rhs.sCode.Get();
	}

    std::string operator+(const Encoder& lhs, const Encoder& rhs)
    {
        return std::to_string(lhs.ID.Get() + rhs.ID.Get());
    }
}


int main()
{
    _ns::Encoder e1
    {
        _ns::ID_t{12},
        _ns::cCode_t{'J'},
        _ns::sCode_t{"tREE"}
    };

    _ns::Encoder e2
    {
        _ns::ID_t{39},
        _ns::cCode_t{'s'},
        _ns::sCode_t{"fR0gg"}
    };

    std::cout << e1.GenerateCode() << '\n';
    std::cout << e2.GenerateCode() << "\n\n";

    std::cout << std::boolalpha;
    std::cout << "e1 < e2 = " << (e1 < e2) << '\n';
    std::cout << "e1 + e2 = " << (e1 + e2) << '\n';

    return 0;
}