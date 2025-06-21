#pragma once

#include <span>
#include <string>

#include <glm/glm.hpp>

namespace objio
{

int writeObj(const std::string& filename, std::span<const glm::vec3> vertices, std::span<const int> faces, std::span<const int> vertexmap);

} // namespace objio
