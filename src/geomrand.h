#pragma once

#include <stddef.h>

#include <glm/glm.hpp>

namespace geomrand
{

static glm::vec3 getPointInUnitBall();
static glm::vec3 getPointOnUnitSphere();
static void generateSpherePlanes(size_t count, bool onSphere, std::vector<glm::vec4>& planes);

} // namespace geomrand

