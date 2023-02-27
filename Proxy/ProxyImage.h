#pragma once

#include <string>

#include "Image.h"
#include "RealImage.h"

class ProxyImage : public Image {
private:
  std::string filename;
  RealImage* image = nullptr;
public:
  ProxyImage(std::string filename);
  void displayImage();
  void showData();
};

/**
 * Constructor
 * @param filename
*/
ProxyImage::ProxyImage(std::string filename) {
  this->filename = filename;
}

/**
 * Displays the image
*/
void ProxyImage::displayImage() {
  if (image == nullptr) {
    image = new RealImage(filename);
  }
  image->displayImage();
}

/**
 * @brief Displays filename
*/
void ProxyImage::showData() {
  printf("%s\n", filename.c_str());
}
