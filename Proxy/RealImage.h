#pragma once

#include <string>

#include "Image.h"

// On System A
class RealImage : public Image {
private:
  std::string filename;
  void loadImageFromDisk();
public:
  RealImage(std::string filename);
  void displayImage();
  void showData();
};

/**
  * @brief Loads the image from the disk
*/
void RealImage::loadImageFromDisk() {
  printf("Loading %s\n", filename.c_str());
}

/**
  * @brief Constructor
  * @param filename
*/
RealImage::RealImage(std::string filename) {
  this->filename = filename;
    loadImageFromDisk();
}

/**
  * @brief Displays the image
*/
void RealImage::displayImage() {
  printf("Displaying %s\n", filename.c_str());
}

/**
 * @brief Displays filename
*/
void RealImage::showData() {
  printf("%s\n", filename.c_str());
}
