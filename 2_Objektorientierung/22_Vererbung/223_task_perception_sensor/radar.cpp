#include "radar.hpp"

Radar::Radar(){};

Radar::Radar(double max_range, double detection_probability);

Radar::~Radar(){};

bool Radar::detect_object(Object obj);
