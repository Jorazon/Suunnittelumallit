#pragma once

// Interface class for the Prototype pattern
class Prototype {
public:
  virtual Prototype* clone() const = 0;
};
