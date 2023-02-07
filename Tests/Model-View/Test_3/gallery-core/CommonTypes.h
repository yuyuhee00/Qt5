#pragma once

#include <memory>
#include <vector>

class Album;
using albumT = std::unique_ptr<Album>;
using albumVec = std::vector<albumT>;
using albumsT = std::unique_ptr<albumVec>;

class Picture;
using pictureT = std::unique_ptr<Picture>;
using pictureVec = std::vector<pictureT>;
using picturesT = std::unique_ptr<pictureVec>;
