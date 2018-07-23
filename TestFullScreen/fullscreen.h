#pragma once
#include<cstdio>
#include <GL/glew.h>     // has to be included before gl.h, or any header that includes gl.h
#include <GL/freeglut.h>
#include "textfile.h"
#include "opencv2/opencv.hpp"



void setShaders();
void load_bind_texture(const cv::String filePath);
