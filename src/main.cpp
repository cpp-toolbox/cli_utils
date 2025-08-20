#include <iostream>
#include "utility/meta_utils/meta_utils.hpp"

#ifdef GENERATED_META_PROGRAM
#include "meta_program/meta_program.hpp"
#endif

int main() {

    auto settings = meta_utils::StringInvokerGenerationSettingsForHeaderSource(
        "src/utility/text_utils/text_utils.hpp", "src/utility/text_utils/text_utils.cpp", true, true);

    meta_utils::generate_string_invokers_program_wide({settings});

#ifdef GENERATED_META_PROGRAM
    meta_program::MetaProgram mp(meta_utils::concrete_types);
    mp.start_interactive_invoker();
#endif

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
