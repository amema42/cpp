#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0]
                  << " <filename> <s1> <s2>\n";
        return 1;
    }

    // extract/get arg params
    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    // Validate non-empty search string.
    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty\n";
        return 1;
    }

    // open: "input file"
    std::ifstream infile(filename.c_str());
    if (!infile) {
        std::cerr << "Error: cannot open file " << filename << '\n';
        return 1;
    }

    // open "output file"
    const std::string outname = filename + ".replace";
    std::ofstream outfile(outname.c_str());
    if (!outfile)
    {
        std::cerr << "Error: cannot create file " << outname << '\n';
        return 1;
    }

    // process file \n-by-\n
    std::string line;
    while (std::getline(infile, line))
    {
        std::string result;
        size_t prev = 0, pos;
        while ((pos = line.find(s1, prev)) != std::string::npos)
        {
            // .append (1) segment and (2) substitution
            result.append(line, prev, pos - prev);
            result += s2;
            prev = pos + s1.length();
        }
        // .append remaining text.
        result.append(line, prev, std::string::npos);
        outfile << result << '\n';
    }
    return 0;
}
