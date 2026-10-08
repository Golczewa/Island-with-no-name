//
// Created by golczewa on 8.10.2026.
//

#include "vectorTools.h"

[[nodiscard]] float VectorTools::distance(Vector2 vec1, Vector2 vec2) {
    return static_cast<float>(sqrt(pow(vec1.x-vec2.x,2)+pow(vec1.y-vec2.y,2)));
}

[[nodiscard]] float VectorTools::length(Vector2 vec) {
    return distance(vec,{0,0});
}

[[nodiscard]] Vector2 VectorTools::normalise(Vector2 vec) {
    auto len=length(vec);
    if (len==0) {
        return {0,0};
    }
    return {vec.x/len,vec.y/len};
}
