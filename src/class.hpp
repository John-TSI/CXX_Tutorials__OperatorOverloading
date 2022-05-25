#ifndef CLASS_HPP
#define CLASS_HPP

#include<string>
#include"named_type.hpp"


namespace _ns
{
    using ID_t = Named_Type<int, struct ID_tag>;
    using cCode_t = Named_Type<char, struct cCode_tag>;
	using sCode_t = Named_Type<std::string, struct sCode_tag>;

    class Encoder
    {
        ID_t ID;
        cCode_t cCode;
        sCode_t sCode;


        public:
            Encoder(const ID_t& iInput, const cCode_t& cInput, const sCode_t& sInput) : ID(iInput), cCode(cInput), sCode(sInput) {}
            std::string GenerateCode() const { return "@{" + std::to_string(ID.Get()) + cCode.Get() + "_" + sCode.Get() + "?}"; }

            friend std::weak_ordering operator<=>(const Encoder& lhs, const Encoder& rhs);
			friend bool operator==(const Encoder& lhs, const Encoder& rhs);
            friend std::string operator+(const Encoder& lhs, const Encoder& rhs);
    };
}

#endif