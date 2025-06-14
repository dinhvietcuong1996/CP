"""
Generates C++ template files for programming contests based on a contest name.

Usage:
  python generate_problem_files.py [--template <template_file>] <contest_name>

Example:
  python generate_problem_files.py 1234
  python generate_problem_files.py --template templates/my_special_template.cpp abc001
  python generate_problem_files.py abc001

Behavior:
- Creates a directory: contests/<contest_name>/
- Uses <template_file> (default: 'templates/template.cpp') as the source.

If <contest_name> is all numbers (e.g., "1234"):
  - Generates files: 1234A.cpp, 1234B.cpp, ..., 1234F.cpp
  - Ensures "cin >> T;" is NOT commented out in these files.

If <contest_name> starts with "abc" (e.g., "abc001"):
  - Generates files: abc001_a.cpp, abc001_b.cpp, ..., abc001_f.cpp
  - Comments out "cin >> T;" in these files.
"""

import argparse # Add argparse
import os
import shutil
import sys

def generate_problem_files(contest_name, source_template="templates/template.cpp"):
    # source_template = "templates/template.cpp" # This line is now handled by the function parameter default
    contest_dir = os.path.join("contests", contest_name)

    if not os.path.exists(source_template):
        print(f"Error: Source template file '{source_template}' not found.")
        sys.exit(1)

    if not os.path.exists(contest_dir):
        os.makedirs(contest_dir)

    files_to_generate = []
    cin_t_comment_out = False

    if contest_name.isdigit():
        for char_code in range(ord('A'), ord('G')): # A to F
            files_to_generate.append(os.path.join(contest_dir, f"{contest_name}{chr(char_code)}.cpp"))
    elif contest_name.startswith("abc"):
        cin_t_comment_out = True
        for char_code in range(ord('a'), ord('g')): # a to f
            files_to_generate.append(os.path.join(contest_dir, f"{contest_name}_{chr(char_code)}.cpp"))
    else:
        print(f"Contest name format not recognized: {contest_name}")
        return

    for dest_file in files_to_generate:
        shutil.copyfile(source_template, dest_file)
        if cin_t_comment_out:
            with open(dest_file, 'r') as f:
                lines = f.readlines()
            with open(dest_file, 'w') as f:
                for line in lines:
                    if "cin >> T;" in line and not line.strip().startswith("//"):
                        f.write("//" + line)
                    else:
                        f.write(line)
        else: # Ensure "cin >> T;" is not commented out
            with open(dest_file, 'r') as f:
                lines = f.readlines()
            with open(dest_file, 'w') as f:
                for line in lines:
                    if "//cin >> T;" in line:
                        f.write(line.replace("//cin >> T;", "cin >> T;"))
                    elif line.strip().startswith("//") and "cin >> T;" in line: # handles cases like "// cin >> T;"
                        f.write(line.replace("//", "", 1))
                    else:
                        f.write(line)
        print(f"Generated {dest_file}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate C++ template files for programming contests.")
    parser.add_argument(
        "--template",
        default="templates/template.cpp",
        help="Path to the source template file (default: templates/template.cpp)"
    )
    parser.add_argument(
        "contest_name",
        help="The name of the contest (e.g., 1234, abc001)"
    )
    args = parser.parse_args()

    generate_problem_files(args.contest_name, args.template)
