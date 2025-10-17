import re
import os

# Files in order of inclusion
files = ["concepts.hpp", "print.hpp"]
output_file = "generated/cpprint.hpp"

# Make sure the output folder exists
os.makedirs("generated", exist_ok=True)

def process_file(filename):
    lines = []
    with open(filename, "r") as f:
        for line in f:
            # Skip #pragma once and empty includes
            if "#pragma once" in line:
                continue
            # Optional: skip includes of your own headers
            if re.match(r'#include\s+"', line):
                continue
            lines.append(line)
    return lines

with open(output_file, "w") as out:
    # Add pragma once for header-only usage
    out.write("#pragma once\n\n")    # Optional: add a comment

    out.write("// Automatically generated cpp file\n\n")

    # Standard library includes (ensure self-contained)
    std_includes = ["<iostream>", "<string>", "<sstream>", "<vector>", "<queue>", "<tuple>"]
    for inc in std_includes:
        out.write(f"#include {inc}\n")
    out.write("\n")

    # Insert all files
    for f in files:
        lines = process_file(f)
        out.writelines(lines)
        out.write("\n")

    # End of generated code comment
    out.write("// End of generated cpp file\n")

print(f"Generated C++ source file: {output_file}")