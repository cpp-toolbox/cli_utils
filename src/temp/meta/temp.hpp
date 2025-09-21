#ifndef META_TEMP_HPP
#define META_TEMP_HPP

#include "../../utility/meta_utils/meta_utils.hpp"
#include "../temp.hpp"
#include <regex>
#include <optional>

namespace meta_temp {


class MetaTemp {
public:
        MetaTemp(std::vector<meta_utils::MetaType> &concrete_types) : concrete_types(concrete_types) {
        }

public:
    std::vector<meta_utils::MetaType> & concrete_types;
    meta_utils::MetaFunctionSignature mfs_create_header_and_source{"bool create_header_and_source(std::string &filename)", ""};
    std::vector<meta_utils::MetaFunctionSignature> all_meta_function_signatures = {mfs_create_header_and_source};
    std::optional<bool> invoker_that_returns_bool(std::string &invocation) {
        if (std::regex_match(invocation, std::regex(mfs_create_header_and_source.invocation_regex))) {
                return create_header_and_source_string_invoker(invocation);
            }
        
            return std::nullopt;

    }
    std::optional<std::function<bool()>> deferred_invoker_that_returns_bool(std::string &invocation) {
        if (std::regex_match(invocation, std::regex(mfs_create_header_and_source.invocation_regex))) {
                return create_header_and_source_deferred_string_invoker(invocation);
            }
        
            return std::nullopt;

    }
    std::optional<std::string> invoker_that_returns_std_string(std::string &invocation) {
        if (std::regex_match(invocation, std::regex(mfs_create_header_and_source.invocation_regex))) {
                return create_header_and_source_string_invoker_to_string(invocation);
            }
        
            return std::nullopt;

    }
    void start_interactive_invoker() {
        std::cout << "Enter function invocation strings (type 'quit' to exit):\n";
        
            std::string input;
            while (true) {
                std::cout << "> ";
                std::getline(std::cin, input);
        
                if (input == "quit")
                    break;
        
                std::optional<std::string> result = invoker_that_returns_std_string(input);
                if (result.has_value()) {
                    std::cout << "Result: " << result.value() << "\n";
                } else {
                    std::cout << "Invocation failed.\n";
                }
            }
        
            std::cout << "Goodbye!\n";

    }
    std::optional<bool> create_header_and_source_string_invoker(std::string &invocation) {
        std::regex re(R"(^\s*create_header_and_source\s*\(\s*("(?:[^"\\]|\\.)*")\s*\)\s*$)");
            std::smatch match;
            if (!std::regex_match(invocation, match, re)) return std::nullopt;
        
            auto conversion1 = [](const std::string &s) {   if (s.size() >= 2 && s.front() == '"' && s.back() == '"')     return s.substr(1, s.size() - 2);   return s; };
            std::string filename = conversion1(match[1]);
        
            bool result = create_header_and_source(filename);
            return result;

    }
    std::optional<std::function<bool()>> create_header_and_source_deferred_string_invoker(std::string &invocation) {
        std::regex re(R"(^\s*create_header_and_source\s*\(\s*("(?:[^"\\]|\\.)*")\s*\)\s*$)");
            std::smatch match;
            if (!std::regex_match(invocation, match, re)) return std::nullopt;
        
            auto conversion1 = [](const std::string &s) {   if (s.size() >= 2 && s.front() == '"' && s.back() == '"')     return s.substr(1, s.size() - 2);   return s; };
            std::string filename = conversion1(match[1]);
        
        auto deferred_func = [&]() {
            return create_header_and_source(filename);
        };
            return deferred_func;

    }
    std::optional<std::string> create_header_and_source_string_invoker_to_string(std::string &input) {
        auto opt_result = create_header_and_source_string_invoker(input);
            if (!opt_result) return std::nullopt;
            auto conversion = [](const bool &v) { return v ? "true" : "false"; };
            return conversion(*opt_result);

    }
};



} // namespace meta_temp

#endif // META_TEMP_HPP
