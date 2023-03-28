#pragma warning(disable : 6031)

#include <iostream>

#include "PhotoAlbum.h"
#include "ProxyImage.h"
#include "Scanner.h"

int main() {
  PhotoAlbum album;
  
  for (int i = 1; i <= 2; i++)
  {
    char intBuf[255]{'\0'};
    _itoa_s(i, intBuf, 10);
    std::string intStr(intBuf);

    album.AddImage(
      new ProxyImage("HiRes_10MB_Photo" + intStr)
    );
  }

  char selection = ' ';

  while (selection != '3') {
    printf("\033[0;0H\033[J");

    printf("[1] List album\n");
    printf("[2] Display image\n");
    printf("[3] Exit\n");
    printf(": ");

    selection = getchar();
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (selection)
    {
    case '1': {
      album.ListImages();
      getchar();
      break;
    }
    case '2': {
      printf("Select image: ");
      int n = getfromcin<int>();
      printf("\n");
      album.DisplayImage(n - 1);
      getchar();
      break;
    }
    default:
      break;
    }
  }
}
