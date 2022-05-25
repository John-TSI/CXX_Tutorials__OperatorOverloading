#ifndef NAMED_TYPE_HPP
#define NAMED_TYPE_HPP

#include <utility>

// Based on NamedType implementation: https://www.fluentcpp.com/2016/12/08/strong-types-for-strong-interfaces/

namespace _ns 
{
	template <typename T, typename Parameter>
	class Named_Type
	{
        T value{};

        public:
            constexpr explicit Named_Type(T const& input) noexcept : value(input) {}
            constexpr explicit Named_Type(T&& input) noexcept : value(std::move(input)) {}

            T& Get() { return value; }
            T const& Get() const { return value; }

            auto operator<=>(const Named_Type&) const = default;
	};
}

#endif