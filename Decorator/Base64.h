#pragma once

#include <string>
#include <stdexcept>

namespace Base64 {

  static const char* base64_chars[2]{
   //00000000001111111111222222
   //01234567890123456789012345
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
   //22223333333333444444444455
   //67890123456789012345678901
    "abcdefghijklmnopqrstuvwxyz"
   //5555555566
   //2345678901
    "0123456789"
   //66
   //23
    "+/",

    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789"
    "-_"
  };

  static size_t char_pos(const char chr) {
    if (chr >= 'A' && chr <= 'Z') return chr - 'A';
    else if (chr >= 'a' && chr <= 'z') return chr - 'a' + 26; // position of 'a' in chars string
    else if (chr >= '0' && chr <= '9') return chr - '0' + 52; // position of '0' in chars string
    else if (chr == '+' || chr == '-') return 62; // position of '+' and '-' in chars string
    else if (chr == '/' || chr == '_') return 63; // position of '/' and '_' in chars string
    else throw std::runtime_error("Input is not valid base64-encoded data.");
  }

  static std::string encode(std::string data, bool url = false) {
    size_t length = data.length();
    std::string encoded;
    encoded.reserve((length + 2) * 3 / 4);

    const char* data_c_str = data.c_str();

    const char* chars = base64_chars[url];
    char trailing_char = url ? '.' : '=';

    size_t pos = 0;

    while (pos < length) {
      encoded.push_back(chars[(data_c_str[pos + 0] & 0b11111100) >> 2]);

      if (pos + 1 < length) {
        encoded.push_back(chars[((data_c_str[pos + 0] & 0b00000011) << 4) + ((data_c_str[pos + 1] & 0xf0) >> 4)]);

        if (pos + 2 < length) {
          encoded.push_back(chars[((data_c_str[pos + 1] & 0b00001111) << 2) + ((data_c_str[pos + 2] & 0b11000000) >> 6)]);
          encoded.push_back(chars[data_c_str[pos + 2] & 0b00111111]);
        }
        else {
          encoded.push_back(chars[(data_c_str[pos + 1] & 0b00001111) << 2]);
          encoded.push_back(trailing_char);
        }
      }
      else {
        encoded.push_back(chars[(data_c_str[pos + 0] & 0b00000011) << 4]);
        encoded.push_back(trailing_char);
        encoded.push_back(trailing_char);
      }

      pos += 3;
    }

    return encoded;
  }

  static std::string decode(std::string const& data) {
    if (data.empty()) return std::string();

    size_t length = data.length();
    std::string decoded;
    decoded.reserve(length / 4 * 3);

    const char* data_c_str = data.c_str();

    size_t pos = 0;

    while (pos < length - 1) {
      size_t pos_1 = char_pos(data_c_str[pos + 1]);

      decoded.push_back((char) ((char_pos(data_c_str[pos + 0])) << 2) + ((pos_1 & 0b00110000) >> 4));

      if ((pos + 2 < length) && data_c_str[pos + 2] != '=' && data_c_str[pos + 2] != '.') {
        size_t pos_2 = char_pos(data_c_str[pos + 2]);
        decoded.push_back(((pos_1 & 0b00001111) << 4) + ((pos_2 & 0b00111100) >> 2));

        if ((pos + 3 < length) && data_c_str[pos + 3] != '=' && data_c_str[pos + 3] != '.') {
          decoded.push_back((char) char_pos(data_c_str[pos + 3]) + ((pos_2 & 0b00000011) << 6));
        }
      }

      pos += 4;
    }
    
    return decoded;
  }

}
