#pragma once

#include <stddef.h>

#include <glm/glm.hpp>

namespace geomrand
{

glm::vec3 getPointInUnitBall();
glm::vec3 getPointOnUnitSphere();
void generateSpherePlanes(size_t count, bool onSphere, std::vector<glm::vec4>& planes);

} // namespace geomrand

