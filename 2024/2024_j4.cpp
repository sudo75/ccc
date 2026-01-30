#include <iostream>

int getNextUniqueCharIndex(std::string string, int current_index, int string_len);

int main() {

    std::string intended;
    std::cin >> intended;

    std::string actual;
    std::cin >> actual;

    int intended_len = intended.length();
    int actual_len = actual.length();
    int actual_index_offset = 0;

    bool quiet = false;
    bool silly = false;

    char quiet_key;

    char silly_key_intended;
    char silly_key_actual;

    for (int i = 0; i < intended_len; i++) {
        char intended_char = intended[i];
        char actual_char = actual[i];

        // std::cout << "Actual char: " << actual_char << '\n';

        if (silly && quiet) break;

        if (intended_char != actual_char) {
            // go to next unique char in intended string
            int next_unique_intended_char_index = getNextUniqueCharIndex(intended, i, intended_len);
            char next_unique_intended_char = intended[next_unique_intended_char_index];

            // std::cout << "intended_char: " << intended_char << '\n';
            // std::cout << "actual_char: " << actual_char << '\n';
            // std::cout << "next_unique_intended_char_index: " << next_unique_intended_char_index << '\n';
            // std::cout << "next_unique_intended_char: " << next_unique_intended_char << '\n';


            if (next_unique_intended_char == actual_char && !quiet) {
                quiet = true;

                quiet_key = intended_char;

                actual_index_offset += i - next_unique_intended_char_index;
            }

            if (next_unique_intended_char == actual[next_unique_intended_char_index + actual_index_offset] && !silly) {
                silly = true;

                silly_key_actual = actual_char;
                silly_key_intended = intended_char;
            }

        }

    }

    if (silly) std::cout << silly_key_intended << ' ' << silly_key_actual << '\n';
    else std::cout << '-' << '\n';

    if (quiet) std::cout << quiet_key << '\n';
    else std::cout << '-' << '\n';

    return 0;
}

int getNextUniqueCharIndex(std::string string, int current_index, int string_len) {
    char starting_char = string[current_index];
    for (int i = current_index + 1; i < string_len; i++) {
        char char_to_compare = string[i];

        if (starting_char != char_to_compare) return i;
    }

    return -1;
}