#pragma warning(disable : 6031)

#include <stdio.h>

#include "ConcreteFileReadWrite.h"
#include "EncryptedFileReadWrite.h"
#include "Base64.h"

int main() {
  ConcreteFileReadWrite* plain = new ConcreteFileReadWrite();
  FileReadWriteDecorator* encrypted = new EncryptedFileReadWrite(plain);
  FileReadWriteDecorator* megaencrypted = new EncryptedFileReadWrite(encrypted);

  std::string data = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  
  std::cout << "-------------------\n";
  std::cout << "Write plain\n";
  plain->write("plain.txt", data);
  std::cout << "Read plain\n" << plain->read("plain.txt").c_str() << "\n";
  std::cout << "-------------------\n";
  std::cout << "Write encrypted\n";
  encrypted->write("encrypted.txt", data);
  std::cout << "Read plain\n" << plain->read("encrypted.txt").c_str() << "\n";
  std::cout << "Read encrypted\n" << encrypted->read("encrypted.txt").c_str() << "\n";
  std::cout << "-------------------\n";
  std::cout << "Write megaencrypted\n";
  megaencrypted->write("megaencrypted.txt", data);
  std::cout << "Read plain\n" << plain->read("megaencrypted.txt").c_str() << "\n";
  std::cout << "Read encrypted\n" << encrypted->read("megaencrypted.txt").c_str() << "\n";
  std::cout << "Read megaencrypted\n" << megaencrypted->read("megaencrypted.txt").c_str() << "\n";
  std::cout << "-------------------\n";

  getchar();
}
