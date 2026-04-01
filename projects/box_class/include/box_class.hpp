#pragma once

#include <iostream>
#include <algorithm>

class Box {
    int length;
    int width;
    int height;

public:

    Box(int l = 0, int w = 0, int h = 0)
        : length(l), width(w), height(h) {}

    [[nodiscard]] int length1() const {
        return length;
    }

    void set_length(const int length) {
        this->length = length;
    }

    [[nodiscard]] int width1() const {
        return width;
    }

    void set_width(const int width) {
        this->width = width;
    }

    [[nodiscard]] int height1() const {
        return height;
    }

    void set_height(const int height) {
        this->height = height;
    }

    Box operator+(const Box& other_box) const {
        return Box(
            std::max(length, other_box.length),
            std::max(width, other_box.width),
            this->height + other_box.height
        );
    }

    friend std::ostream& operator<<(std::ostream& os, const Box& b) {
        os << "Box(L: " << b.length << ", W: " << b.width << ", H: " << b.height << ")";
        return os;
    }
};