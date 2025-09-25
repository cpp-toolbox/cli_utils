#ifndef META_PROGRAM_HPP
#define META_PROGRAM_HPP

#include "../utility/text_utils/meta/text_utils.hpp"
#include "../utility/fs_utils/meta/fs_utils.hpp"
#include <optional>
#include "../utility/meta_utils/meta_utils.hpp"
#include "../utility/user_input/user_input.hpp"

namespace meta_program {


class MetaProgram {
public:
        MetaProgram(std::vector<meta_utils::MetaType> concrete_types) : concrete_types(concrete_types) {
        }

public:
    std::vector<meta_utils::MetaType>  concrete_types;
    meta_text_utils::MetaTextUtils meta_text_utils{concrete_types};
    meta_fs_utils::MetaFsUtils meta_fs_utils{concrete_types};
    std::string char_to_string(char &v) {
        return std::to_string(v);

    }
    char string_to_char(std::string &s) {
        return static_cast<char>(s.empty() ? 0 : s[0]);

    }
    std::vector<uint8_t> serialize_char(char &v) {
        std::vector<uint8_t> buf(sizeof(char));   std::memcpy(buf.data(), &v, sizeof(char));   return buf;

    }
    size_t size_when_serialized_char(char &v) {
        return sizeof(char);

    }
    char deserialize_char(std::vector<uint8_t> &buf) {
        char v;   std::memcpy(&v, buf.data(), sizeof(char));   return v;

    }
    std::string int_to_string(int &v) {
        return std::to_string(v);

    }
    int string_to_int(std::string &s) {
        return std::stoi(s);

    }
    std::vector<uint8_t> serialize_int(int &v) {
        std::vector<uint8_t> buf(sizeof(int));   std::memcpy(buf.data(), &v, sizeof(int));   return buf;

    }
    size_t size_when_serialized_int(int &v) {
        return sizeof(int);

    }
    int deserialize_int(std::vector<uint8_t> &buf) {
        int v;   std::memcpy(&v, buf.data(), sizeof(int));   return v;

    }
    std::string unsigned_int_to_string(unsigned int &v) {
        return std::to_string(v);

    }
    unsigned int string_to_unsigned_int(std::string &s) {
        return static_cast<unsigned int>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_unsigned_int(unsigned int &v) {
        std::vector<uint8_t> buf(sizeof(unsigned int));   std::memcpy(buf.data(), &v, sizeof(unsigned int));   return buf;

    }
    size_t size_when_serialized_unsigned_int(unsigned int &v) {
        return sizeof(unsigned int);

    }
    unsigned int deserialize_unsigned_int(std::vector<uint8_t> &buf) {
        unsigned int v;   std::memcpy(&v, buf.data(), sizeof(unsigned int));   return v;

    }
    std::string uint8_t_to_string(uint8_t &v) {
        return std::to_string(v);

    }
    uint8_t string_to_uint8_t(std::string &s) {
        return static_cast<uint8_t>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_uint8_t(uint8_t &v) {
        std::vector<uint8_t> buf(sizeof(uint8_t));   std::memcpy(buf.data(), &v, sizeof(uint8_t));   return buf;

    }
    size_t size_when_serialized_uint8_t(uint8_t &v) {
        return sizeof(uint8_t);

    }
    uint8_t deserialize_uint8_t(std::vector<uint8_t> &buf) {
        uint8_t v;   std::memcpy(&v, buf.data(), sizeof(uint8_t));   return v;

    }
    std::string uint32_t_to_string(uint32_t &v) {
        return std::to_string(v);

    }
    uint32_t string_to_uint32_t(std::string &s) {
        return static_cast<uint32_t>(std::stoul(s));

    }
    std::vector<uint8_t> serialize_uint32_t(uint32_t &v) {
        std::vector<uint8_t> buf(sizeof(uint32_t));   std::memcpy(buf.data(), &v, sizeof(uint32_t));   return buf;

    }
    size_t size_when_serialized_uint32_t(uint32_t &v) {
        return sizeof(uint32_t);

    }
    uint32_t deserialize_uint32_t(std::vector<uint8_t> &buf) {
        uint32_t v;   std::memcpy(&v, buf.data(), sizeof(uint32_t));   return v;

    }
    std::string size_t_to_string(size_t &v) {
        return std::to_string(v);

    }
    size_t string_to_size_t(std::string &s) {
        return static_cast<size_t>(std::stoull(s));

    }
    std::vector<uint8_t> serialize_size_t(size_t &v) {
        std::vector<uint8_t> buf(sizeof(size_t));   std::memcpy(buf.data(), &v, sizeof(size_t));   return buf;

    }
    size_t size_when_serialized_size_t(size_t &v) {
        return sizeof(size_t);

    }
    size_t deserialize_size_t(std::vector<uint8_t> &buf) {
        size_t v;   std::memcpy(&v, buf.data(), sizeof(size_t));   return v;

    }
    std::string float_to_string(float &v) {
        return std::to_string(v);

    }
    float string_to_float(std::string &s) {
        return std::stof(s);

    }
    std::vector<uint8_t> serialize_float(float &v) {
        std::vector<uint8_t> buf(sizeof(float));   std::memcpy(buf.data(), &v, sizeof(float));   return buf;

    }
    size_t size_when_serialized_float(float &v) {
        return sizeof(float);

    }
    float deserialize_float(std::vector<uint8_t> &buf) {
        float v;   std::memcpy(&v, buf.data(), sizeof(float));   return v;

    }
    std::string double_to_string(double &v) {
        return std::to_string(v);

    }
    double string_to_double(std::string &s) {
        return std::stod(s);

    }
    std::vector<uint8_t> serialize_double(double &v) {
        std::vector<uint8_t> buf(sizeof(double));   std::memcpy(buf.data(), &v, sizeof(double));   return buf;

    }
    size_t size_when_serialized_double(double &v) {
        return sizeof(double);

    }
    double deserialize_double(std::vector<uint8_t> &buf) {
        double v;   std::memcpy(&v, buf.data(), sizeof(double));   return v;

    }
    std::string short_to_string(short &v) {
        return std::to_string(v);

    }
    short string_to_short(std::string &s) {
        return static_cast<short>(std::stoi(s));

    }
    std::vector<uint8_t> serialize_short(short &v) {
        std::vector<uint8_t> buf(sizeof(short));   std::memcpy(buf.data(), &v, sizeof(short));   return buf;

    }
    size_t size_when_serialized_short(short &v) {
        return sizeof(short);

    }
    short deserialize_short(std::vector<uint8_t> &buf) {
        short v;   std::memcpy(&v, buf.data(), sizeof(short));   return v;

    }
    std::string long_to_string(long &v) {
        return std::to_string(v);

    }
    long string_to_long(std::string &s) {
        return std::stol(s);

    }
    std::vector<uint8_t> serialize_long(long &v) {
        std::vector<uint8_t> buf(sizeof(long));   std::memcpy(buf.data(), &v, sizeof(long));   return buf;

    }
    size_t size_when_serialized_long(long &v) {
        return sizeof(long);

    }
    long deserialize_long(std::vector<uint8_t> &buf) {
        long v;   std::memcpy(&v, buf.data(), sizeof(long));   return v;

    }
    std::string std__string_to_string(std::string &s) {
        return s;

    }
    std::string string_to_std__string(std::string &s) {
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"')     return s.substr(1, s.size() - 2);   return s;

    }
    std::vector<uint8_t> serialize_std__string(std::string &v) {
        std::vector<uint8_t> buf;   size_t len = v.size();   buf.resize(sizeof(size_t) + len);   std::memcpy(buf.data(), &len, sizeof(size_t));   std::memcpy(buf.data() + sizeof(size_t), v.data(), len);   return buf;

    }
    size_t size_when_serialized_std__string(std::string &v) {
        return sizeof(size_t) + v.size();

    }
    std::string deserialize_std__string(std::vector<uint8_t> &buf) {
        if (buf.size() < sizeof(size_t)) return std::string();   size_t len;   std::memcpy(&len, buf.data(), sizeof(size_t));   if (buf.size() < sizeof(size_t) + len) return std::string();   return std::string(reinterpret_cast<const char*>(buf.data() + sizeof(size_t)), len);

    }
    std::string std__filesystem__path_to_string(std::filesystem::path &p) {
        return p.string();

    }
    std::filesystem::path string_to_std__filesystem__path(std::string &s) {
        if (s.size() >= 2 && s.front() == '"' && s.back() == '"')     return std::filesystem::path(s.substr(1, s.size() - 2));   return std::filesystem::path(s);

    }
    std::vector<uint8_t> serialize_std__filesystem__path(std::filesystem::path &p) {
        std::string s = p.string();   std::vector<uint8_t> buf;   size_t len = s.size();   buf.resize(sizeof(size_t) + len);   std::memcpy(buf.data(), &len, sizeof(size_t));   std::memcpy(buf.data() + sizeof(size_t), s.data(), len);   return buf;

    }
    size_t size_when_serialized_std__filesystem__path(std::filesystem::path &p) {
        std::string s = p.string();   return sizeof(size_t) + s.size();

    }
    std::filesystem::path deserialize_std__filesystem__path(std::vector<uint8_t> &buf) {
        if (buf.size() < sizeof(size_t)) return std::filesystem::path();   size_t len;   std::memcpy(&len, buf.data(), sizeof(size_t));   if (buf.size() < sizeof(size_t) + len) return std::filesystem::path();   return std::filesystem::path(std::string(reinterpret_cast<const char*>(buf.data() + sizeof(size_t)), len));

    }
    std::string bool_to_string(bool &v) {
        return v ? "true" : "false";

    }
    bool string_to_bool(std::string &s) {
        return s == "true";

    }
    std::vector<uint8_t> serialize_bool(bool &v) {
        std::vector<uint8_t> buf(1);   buf[0] = v ? 1 : 0;   return buf;

    }
    size_t size_when_serialized_bool(bool &v) {
        return sizeof(uint8_t);

    }
    bool deserialize_bool(std::vector<uint8_t> &buf) {
        return buf[0] != 0;

    }
    std::string meta_utils__MetaType_to_string() {
        return "";

    }
    meta_utils::MetaType string_to_meta_utils__MetaType() {

    }
    std::vector<uint8_t> serialize_meta_utils__MetaType() {

    }
    size_t size_when_serialized_meta_utils__MetaType(meta_utils::MetaType &v) {
        return sizeof(meta_utils::MetaType);

    }
    meta_utils::MetaType deserialize_meta_utils__MetaType() {

    }
    std::optional<std::filesystem::path> invoker_that_returns_std_filesystem_path(std::string &invocation) {
        std::optional<std::filesystem::path> val;
        val = meta_fs_utils.invoker_that_returns_std_filesystem_path(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::vector<std::filesystem::path>> invoker_that_returns_std_vector_std_filesystem_path_(std::string &invocation) {
        std::optional<std::vector<std::filesystem::path>> val;
        val = meta_fs_utils.invoker_that_returns_std_vector_std_filesystem_path_(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::string> invoker_that_returns_std_string(std::string &invocation) {
        std::optional<std::string> val;
        val = meta_text_utils.invoker_that_returns_std_string(invocation);
        if (val)
            return val;
        
        val = meta_fs_utils.invoker_that_returns_std_string(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<bool> invoker_that_returns_bool(std::string &invocation) {
        std::optional<bool> val;
        val = meta_text_utils.invoker_that_returns_bool(invocation);
        if (val)
            return val;
        
        val = meta_fs_utils.invoker_that_returns_bool(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::vector<std::string>> invoker_that_returns_std_vector_std_string_(std::string &invocation) {
        std::optional<std::vector<std::string>> val;
        val = meta_text_utils.invoker_that_returns_std_vector_std_string_(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::unordered_map<std::string, std::string>> invoker_that_returns_std_unordered_map_std_string_std_string_(std::string &invocation) {
        std::optional<std::unordered_map<std::string, std::string>> val;
        val = meta_text_utils.invoker_that_returns_std_unordered_map_std_string_std_string_(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::function<std::filesystem::path()>> deferred_invoker_that_returns_std_filesystem_path(std::string &invocation) {
        std::optional<std::function<std::filesystem::path()>> val;
        val = meta_fs_utils.deferred_invoker_that_returns_std_filesystem_path(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::function<std::vector<std::filesystem::path>()>> deferred_invoker_that_returns_std_vector_std_filesystem_path_(std::string &invocation) {
        std::optional<std::function<std::vector<std::filesystem::path>()>> val;
        val = meta_fs_utils.deferred_invoker_that_returns_std_vector_std_filesystem_path_(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::function<bool()>> deferred_invoker_that_returns_bool(std::string &invocation) {
        std::optional<std::function<bool()>> val;
        val = meta_text_utils.deferred_invoker_that_returns_bool(invocation);
        if (val)
            return val;
        
        val = meta_fs_utils.deferred_invoker_that_returns_bool(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::function<std::vector<std::string>()>> deferred_invoker_that_returns_std_vector_std_string_(std::string &invocation) {
        std::optional<std::function<std::vector<std::string>()>> val;
        val = meta_text_utils.deferred_invoker_that_returns_std_vector_std_string_(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    std::optional<std::function<std::unordered_map<std::string, std::string>()>> deferred_invoker_that_returns_std_unordered_map_std_string_std_string_(std::string &invocation) {
        std::optional<std::function<std::unordered_map<std::string, std::string>()>> val;
        val = meta_text_utils.deferred_invoker_that_returns_std_unordered_map_std_string_std_string_(invocation);
        if (val)
            return val;
        
        return std::nullopt;

    }
    void start_interactive_invoker() {
        std::map<std::string, meta_utils::MetaFunctionSignature> options_dict;
            for (size_t i = 0; i < meta_text_utils.all_meta_function_signatures.size(); ++i) {
            options_dict[std::to_string(i + 1)] = meta_text_utils.all_meta_function_signatures[i];
        }
        if (options_dict.empty()) {
            std::cout << "No functions available." << std::endl;
            return; // nothing to do
        }
        std::vector<std::pair<std::string, meta_utils::MetaFunctionSignature>> sorted_options(options_dict.begin(), options_dict.end());
        std::sort(sorted_options.begin(), sorted_options.end(), [](const auto &a, const auto &b) { return std::stoi(a.first) < std::stoi(b.first); });
        bool keep_running = true;
        while (keep_running) {
            std::cout << "Select a function to invoke:" << std::endl;;
            for (const auto &[key, func] : sorted_options) {
                std::cout << key << ". " << func.to_string() << std::endl;
            }
            std::cout << "q. Quit" << std::endl;
            std::string choice = get_validated_input( []() {
                std::cout << "Enter choice: ";
                std::string s;
                std::getline(std::cin, s);
                return text_utils::trim(s);
            },
            [&](const std::string &input) { return input == "q" || options_dict.find(input) != options_dict.end(); }, "Invalid choice. Please try again.");
            if (choice == "q") {
                std::cout << "Goodbye." << std::endl;
                break;
        }
            meta_utils::MetaFunctionSignature selected = options_dict[choice];
            std::vector<std::string> args;
            for (const auto &param : selected.parameters) {
                std::string val = get_input_with_default("Enter value for " + param.name + " (" + param.type.get_type_name() + ")", "0");
                args.push_back(val);
            }
            std::string invocation = selected.name + "(";
            for (size_t i = 0; i < args.size(); ++i) {
                invocation += args[i];
                if (i < args.size() - 1) {
                    invocation += ", ";
                }
            }
            invocation += ")";
            std::cout << "about to run: " << invocation << std::endl;
            auto result = invoker_that_returns_std_string(invocation);
            if (result.has_value()) {
                std::cout << "Result: " << result.value() << std::endl;
            } else {
                std::cout << "Invocation failed." << std::endl;
            }
            std::string run_again = get_validated_input(
            []() {
                std::cout << "Do you want to run another function? (y/n): ";
                std::string s;
                std::getline(std::cin, s);
                return text_utils::trim(s);
            },
            [](const std::string &input) { return input == "y" || input == "n"; }, "Please enter 'y' or 'n'.");
            if (run_again == "n") {
                keep_running = false;
                std::cout << "Goodbye." << std::endl;
            }
        }

    }
    void list_all_available_functions() {
        std::cout << "--- Functions in namespace: meta_text_utils ---" << std::endl;
            for (const auto &mfs : meta_text_utils.all_meta_function_signatures) {
                std::cout << mfs.to_string() << std::endl;
            }
            std::cout << "--- Functions in namespace: meta_fs_utils ---" << std::endl;
            for (const auto &mfs : meta_fs_utils.all_meta_function_signatures) {
                std::cout << mfs.to_string() << std::endl;
            }

    }
};



} // namespace meta_program

#endif // META_PROGRAM_HPP
