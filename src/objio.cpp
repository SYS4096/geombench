#include "geombench/objio.h"

#include <fstream>
#include <iomanip>
#include <unordered_map>

namespace objio
{

int writeObj(const std::string& filename, std::span<const glm::vec3> vertices, std::span<const int> faces, std::span<const int> vertexmap)
{
    std::fstream stream(filename, std::ios::out);

    constexpr auto prec{std::numeric_limits<float>::digits10 + 1};
    stream << std::setprecision(prec);

    for (auto v : vertices)
    {
        stream << "v " << v.x << " " << v.y << " " << v.z << "\n";
    }

    std::unordered_map<int, int> idxMap;
    for (int i = 0; i < (int)vertexmap.size(); ++i)
    {
        idxMap.insert({vertexmap[i], i});
    }

    bool newFace = true;
    for (int i : faces)
    {
        if (newFace)
        {
            stream << "f ";
            newFace = false;
        }

        if (i == -1)
        {
            stream << "\n";
            newFace = true;
        }
        else
        {
            auto it = idxMap.find(i);
            assert(it != idxMap.end());

            stream << (it->second + 1) << " ";
        }
    }
    
    stream.close();

    return 0;
}

} // namespace objio
