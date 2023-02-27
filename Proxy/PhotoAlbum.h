#pragma once

#include <vector>

#include "Image.h"

class PhotoAlbum {
private:
  std::vector<Image*> images;
public:
  void AddImage(Image* image);
  void ListImages();
  void DisplayImage(int index);
};

void PhotoAlbum::AddImage(Image* image) {
  images.push_back(image);
}

void PhotoAlbum::ListImages() {
  int i = 1;
  for (Image* image : images) {
    printf("%d) ", i++);
    image->showData();
  }
}

void PhotoAlbum::DisplayImage(int index) {
  if (index >= images.size()) return;
  images.at(index)->displayImage();
}
