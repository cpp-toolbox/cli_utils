#include "temp.hpp"

#include <fstream>
#include <algorithm>
#include <cctype>

bool create_header_and_source(const std::string &filename) {
    // Create uppercase guard name (e.g. "MYCLASS_HPP")
    std::string guard = filename;
    std::transform(guard.begin(), guard.end(), guard.begin(), [](unsigned char c) { return std::toupper(c); });
    guard += "_HPP";

    // Create header file
    std::ofstream header(filename + ".hpp");
    if (!header.is_open()) {
        return false;
    }
    header << "#ifndef " << guard << "\n";
    header << "#define " << guard << "\n\n";
    header << "// " << filename << " declarations go here\n\n";
    header << "#endif // " << guard << "\n";
    header.close();

    if (!header) {
        return false; // failure during writing
    }

    // Create source file
    std::ofstream source(filename + ".cpp");
    if (!source.is_open()) {
        return false;
    }
    source << "#include \"" << filename << ".hpp\"\n\n";
    source << "// " << filename << " definitions go here\n";
    source.close();

    if (!source) {
        return false; // failure during writing
    }

    return true;
}
