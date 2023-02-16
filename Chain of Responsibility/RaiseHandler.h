#pragma once

class RaiseHandler {
protected:
  RaiseHandler* superior;
public:
  virtual bool Handle(double increase) = 0;
  void SetSuperior(RaiseHandler* superior);
};

void RaiseHandler::SetSuperior(RaiseHandler* superior) {
  this->superior = superior;
}
