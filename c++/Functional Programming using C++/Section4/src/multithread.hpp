#ifndef MULTITHREAD_H
#define MULTITHREAD_H

#include <fplus/fplus.hpp>
#include <iostream>
#include <vector>

namespace multithread {

struct Image {};
struct FaceImage {};
std::vector<Image> images;
FaceImage extract_face(Image) { return {}; }
FaceImage empty_face_image;                                        // dummy
FaceImage add_face_images(FaceImage, FaceImage) { return {}; }     // dummy
FaceImage divide_values(FaceImage, std::size_t) { return {}; }     // dummy

int main() {
    [[maybe_unused]] FaceImage result = fplus::transform_reduce_parallelly(
        extract_face, add_face_images, empty_face_image, images);
    return 0;
}
}     // namespace multithread
#endif     // MULTITHREAD_H