#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./std_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./std_image/stb_image_write.h"

#include "./log.c/src/log.h"

void read_meta(const char *filename);

int main(int argc, char const *argv[]) {
  log_info("加载图片 ...");
  int width, height, channels;
  unsigned char *img =
      stbi_load("./example.jpg", &width, &height, &channels, 0);
  read_meta("example.jpg");

  log_info("准备工作 ...");
  size_t img_size = width * height * channels;
  int gray_channels = channels == 4 ? 2 : 1; // 如果是 4 通道，需要一个透明度
  size_t gray_img_size = width * height * gray_channels;

  unsigned char *gray_img = malloc(gray_img_size);

  if (gray_img == NULL) {
    log_error("[ERROR] Unable to allocate memory for gray image!");
    exit(1);
  }

  log_info("计算新图片 ...");
  unsigned char *p = img;
  unsigned char *pg = gray_img;
  while (p != img + img_size) {
    // 三个通道按顺序，直接取平均数
    *pg = (uint8_t)((*p + *(p + 1) + *(p + 2)) / 3.0);
    if (channels == 4) {
      *(pg + 1) = *(p + 3);
    }

    p += channels;
    pg += gray_channels;
  }

  log_info("写入 ...");
  stbi_write_jpg("demo3.jpg", width, height, gray_channels, gray_img, 100);

  log_info("释放 ...");
  stbi_image_free(img);
  free(gray_img);
  return 0;
}

void read_meta(const char *filename) {
  int width, height, channels;
  unsigned char *img = stbi_load(filename, &width, &height, &channels, 0);
  log_info("[图片：%s] 长：%d 宽：%d 通道数：%d", filename, width, height,
           channels);
}