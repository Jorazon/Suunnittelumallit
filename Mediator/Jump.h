#pragma once

class Jump {
private:
  float length_ = 0.0f;
  float style_ = 0.0f;
public:
  void setLength(float length) {
    length_ = length;
  }

  void setStyle(float style) {
    style_ = style;
  }

  float getLength() {
    return length_;
  }

  float getStyle() {
    return style_;
  }
};
