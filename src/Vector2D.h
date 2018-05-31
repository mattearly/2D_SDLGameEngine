//
// Created by MJE on 5/30/2018.
//

#ifndef INC_2D_GAMEENGINE_VECTOR2D_H
#define INC_2D_GAMEENGINE_VECTOR2D_H

#include <iostream>

class Vector2D {
public:
    float x, y;

    Vector2D();

    Vector2D(float x, float y);

    Vector2D &Add(const Vector2D &vec);

    Vector2D &Subtract(const Vector2D &vec);

    Vector2D &Multipy(const Vector2D &vec);

    Vector2D &Divide(const Vector2D &vec);

    friend Vector2D &operator+(Vector2D &v1, const Vector2D &v2);

    friend Vector2D &operator-(Vector2D &v1, const Vector2D &v2);

    friend Vector2D &operator*(Vector2D &v1, const Vector2D &v2);

    friend Vector2D &operator/(Vector2D &v1, const Vector2D &v2);

    Vector2D &operator+=(const Vector2D &vec);

    Vector2D &operator-=(const Vector2D &vec);

    Vector2D &operator*=(const Vector2D &vec);

    Vector2D &operator/=(const Vector2D &vec);

    friend std::ostream &operator<<(std::ostream &stream, const Vector2D &vec);
};

#endif //INC_2D_GAMEENGINE_VECTOR2D_H
