/**
* This software is provided as is, without warranty of any kind.
*/
#include <algorithm>
#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <random>
#include <string>

namespace {

// List of all characters allowed in passwords fields
constexpr std::array<char, 94> allowed_chars = {
    '!', '"', '#', '$',  '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.',
    '/', '0', '1', '2',  '3', '4', '5',  '6', '7', '8', '9', ':', ';', '<',
    '=', '>', '?', '@',  'A', 'B', 'C',  'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N',  'O', 'P', 'Q',  'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', '[', '\\', ']', '^', '_',  '`', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j',  'k', 'l', 'm',  'n', 'o', 'p', 'q', 'r', 's', 't',
    'u', 'v', 'w', 'x',  'y', 'z', '{',  '|', '}', '~'};

} // namespace

int main() {
    std::random_device rdevice;
    size_t desired_length = 64 + static_cast<size_t>(rdevice()) % 32;

    std::string password;
    password.reserve(desired_length);

    std::generate_n(
        std::back_insert_iterator<decltype(password)>(password), desired_length,
        [&]() { return allowed_chars[rdevice() % allowed_chars.size()]; });

    std::cout << password << '\n';
}
