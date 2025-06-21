#include "geombench/geomrand.h"

#include <random>
#include <benchmark/benchmark.h>

namespace geomrand
{

double getRnd()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::normal_distribution<> distrib(0.0, 1.0); // Mean 0, standard deviation 1
    return distrib(gen);
}

glm::vec3 getPointInUnitBall()
{
    double u = static_cast<double>(rand()) / RAND_MAX; // Generate random number between 0 and 1
    double x1 = getRnd();
    double x2 = getRnd();
    double x3 = getRnd();
    double mag = std::sqrt(x1 * x1 + x2 * x2 + x3 * x3);
    if (mag < std::numeric_limits<double>::epsilon())
    {
        return {0.0f, 0.0f, 0.0f};
    }

    x1 /= mag;
    x2 /= mag;
    x3 /= mag;
    double c = std::cbrt(u);
    return {(float)(x1 * c), (float)(x2 * c), (float)(x3 * c)};
}

glm::vec3 getPointOnUnitSphere()
{
    float x, y, z, d;
    do
    {
        x = ((float)rand()) / ((float)(RAND_MAX)) * 2.0f - 1.0f;
        y = ((float)rand()) / ((float)(RAND_MAX)) * 2.0f - 1.0f;
        z = ((float)rand()) / ((float)(RAND_MAX)) * 2.0f - 1.0f;
    } while (x == 0.0f && y == 0.0f && z == 0.0f);
    d = sqrtf(x * x + y * y + z * z);
    x /= d;
    y /= d;
    z /= d;

    return {x, y, z};
}

void generateSpherePlanes(size_t count, bool onSphere, std::vector<glm::vec4>& planes)
{
    while (count--)
    {
        glm::vec3 v;
        float d;

        if (onSphere)
        {

            v = getPointInUnitBall();
            d = glm::length(v);
            if (d > 1e-3f)
                v = glm::normalize(v);
            else
            {
                v = glm::vec3(1.0f, 0.0f, 0.0f);
                d = 0.5f;
            }
        }
        else
        {
            v = getPointOnUnitSphere();
            d = 1.0f;
        }

        planes.push_back({v.x, v.y, v.z, -d});
    }
}

} // namespace geomrand 

