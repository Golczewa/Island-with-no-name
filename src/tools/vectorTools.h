//
// Created by golczewa on 8.10.2026.
//

#ifndef ISLAND_WITH_NO_NAME_VECTORTOOLS_H
#define ISLAND_WITH_NO_NAME_VECTORTOOLS_H
#include "raylib.h"
#include "cmath"

class VectorTools {
public:
    [[nodiscard]] static float distance(Vector2 vec1,Vector2 vec2);
    [[nodiscard]] static float length(Vector2 vec);
    [[nodiscard]] static Vector2 normalise(Vector2 vec);
};


#endif //ISLAND_WITH_NO_NAME_VECTORTOOLS_H
