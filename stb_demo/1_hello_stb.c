#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./std_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./std_image/stb_image_write.h"

#include "./logger/log.h"

void read_meta(const char *filename);

int main(int argc, char const *argv[]) {

  log_info("加载图片 ...");
  int width, height, channels;
  char *filename = "./example.jpg";
  unsigned char *img = stbi_load(filename, &width, &height, &channels, 0);

  log_info("读取图片信息 ...");
  log_info("[图片：%s] 长：%d 宽：%d 通道数：%d", filename, width, height, channels);

  filename = "demo3.jpg";
  img = stbi_load(filename, &width, &height, &channels, 0);
  log_info("[图片：%s] 长：%d 宽：%d 通道数：%d", filename, width, height, channels);

  log_info("释放 ...");
  stbi_image_free(img);

  return 0;
}

void read_meta(const char *filename) {
  int width, height, channels;
  unsigned char *img = stbi_load(filename, &width, &height, &channels, 0);
  log_info("[图片：%s] 长：%d 宽：%d 通道数：%d", filename, width, height, channels);
}