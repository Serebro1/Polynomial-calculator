#pragma once
#include "polinom.h"
class PolinomParser {
public:
    std::string cleanInput(const std::string& input) {

        std::string cleaned = std::regex_replace(input, std::regex("\\s+"), "");

        return cleaned;
    }

    std::vector<std::string> splitMonomials(const std::string& input) {
        std::vector<std::string> monomials;
        std::string current;
        bool isNegative = false;

        for (char c : input) {
            if (c == '+' || c == '-') {
                if (!current.empty()) {
                    monomials.push_back(isNegative ? "-" + current : current);
                    current.clear();
                }
                isNegative = (c == '-');
            }
            else {
                current += c;
            }
        }
        if (!current.empty()) {
            monomials.push_back(isNegative ? "-" + current : current);
        }

        return monomials;
    }

    Polinom parsePolinomial(const std::string& polynomialStr) {
        Polinom res;
        std::string cleaned = cleanInput(polynomialStr);
        if (cleaned.empty()) {
            throw std::invalid_argument("Entered empty line!");
        }
        if (!validateInput(cleaned)) {
            throw std::invalid_argument("Invalid symbols in polynomial!");
        }
        std::vector<std::string> monomsStr = splitMonomials(cleaned);
        std::vector<Monom> monoms;
        for (const auto& str : monomsStr) {
            Monom m = parseMonomial(str);
            res += m;
        }
        return res;
    }

    Monom parseMonomial(const std::string& monomialStr) {
        Monom monomial;
        std::regex monomialRegex(R"(([+-]?\d*\.?\d*)(?:\*?([xyz]\^?\d*))*)");
        std::smatch match;

        if (std::regex_match(monomialStr, match, monomialRegex)) {
            
            monomial.coeff = match[1].str() != "" ? std::stod(match[1].str()) : 1;

            std::regex varRegex(R"(([xyz])\^?(\d*))");
            auto varsBegin = std::sregex_iterator(monomialStr.begin(), monomialStr.end(), varRegex);
            auto varsEnd = std::sregex_iterator();

            for (std::sregex_iterator i = varsBegin; i != varsEnd; ++i) {
                std::smatch varMatch = *i;
                char var = varMatch[1].str()[0];

                int power = varMatch[2].str() != "" ? std::stoi(varMatch[2].str()) : 1;
                
                switch (var) {
                case 'x': monomial.x = power; break;
                case 'y': monomial.y = power; break;
                case 'z': monomial.z = power; break;
                }
            }
        }
        else {
            throw std::invalid_argument("Parsing monom: Invalid monomial format: " + monomialStr);
        }

        return monomial;
    }

    bool validateInput(const std::string& input) {
        std::regex validCharsRegex(R"(^[+-]?(\d*\.?\d*)?(\*?[xyz]\^?\d*)*([+-](\d*\.?\d*)?(\*?[xyz]\^?\d*)*)*$)");
        if (!std::regex_match(input, validCharsRegex)) {
            throw std::invalid_argument("Validator: Invalid polynomial format!");
        }
        return true;
    }

    bool validateExpression(const std::string& input){
        std::regex validCharsRegex(R"(^-?(?:\d+(?:-(?:-?\d+)|[+*]-?\d+)*)$)");
        if (!std::regex_match(input, validCharsRegex)) {
            throw std::invalid_argument("Validator: Invalid expression format!");
        }
        return true;
        }
};