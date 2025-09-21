#include <iostream>
#include <string>
#include <vector>
#include "utility/meta_utils/meta_utils.hpp"
#include "utility/text_utils/text_utils.hpp"

#ifdef GENERATED_META_PROGRAM
#include "meta_program/meta_program.hpp"
#endif

int main(int argc, char *argv[]) {
    std::vector<std::string> signatures_to_block = {"Node parse_block(const std::string &s, size_t &pos)"};

    auto settings = meta_utils::StringInvokerGenerationSettingsForHeaderSource(
        "src/utility/text_utils/text_utils.hpp", "src/utility/text_utils/text_utils.cpp", true, true,
        signatures_to_block, meta_utils::FilterMode::Blacklist);

    meta_utils::generate_string_invokers_program_wide({settings}, meta_utils::meta_types.get_concrete_types());

#ifdef GENERATED_META_PROGRAM
    meta_program::MetaProgram mp(meta_utils::concrete_types);

    if (argc > 1) {
        std::string arg1 = argv[1];
        if (arg1 == "--interactive") {
            // Interactive mode
            mp.start_interactive_invoker();
        } else {
            // Invocation mode: everything after argv[1] is treated as the invocation string
            std::string invocation;
            for (int i = 1; i < argc; ++i) {
                if (i > 1)
                    invocation += " ";
                invocation += argv[i];
            }

            auto opt_result = mp.invoker_that_returns_std_string(invocation);
            if (opt_result) {
                std::cout << opt_result.value() << std::endl;
            } else {
                std::cerr << "Error: Could not resolve invocation: " << invocation << std::endl;
                return 1;
            }
        }
    } else {
        std::cerr << "Usage: " << argv[0] << " [--interactive | <invocation>]" << std::endl;
        return 1;
    }
#endif

    return 0;
}
