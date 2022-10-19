#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STB_IMAGE_IMPLEMENTATION
#include "./std_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "./std_image/stb_image_write.h"
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#include "./std_image/stb_image_resize.h"

#include "./logger/log.h"

void cmd_read(int argc, char **argv) {
  int width, height, channels;
  for (int i = 0; i < argc; i++) {
    char *filename = argv[i];
    if (access(filename, F_OK) != 0) {
      log_warn("[图片：%s] 文件不存在", filename);
      continue;
    }
    unsigned char *img = stbi_load(filename, &width, &height, &channels, 0);
    log_info("[图片：%s] 长：%d 宽：%d 通道数：%d", filename, width, height, channels);
    stbi_image_free(img);
  }
}

void cmd_resize(int argc, char **argv) {
  float size = atof(argv[0]);
  log_info("缩放比例为 %f", size);
  for (int i = 1; i < argc; i += 1) {
    // 校验
    char *filename = argv[1];
    char *extn = strrchr(filename, '.');
    if (strcmp(extn, ".jpg") != 0) {
      log_warn("不支持 jpg 之外的类型：%s", extn);
      continue;
    }

    // 加载图片
    log_info("加载 %s ...", filename);
    int x, y, channels;
    unsigned char *img = stbi_load(filename, &x, &y, &channels, 0);
    int new_x = size * x;
    int new_y = size * y;
    unsigned char *data = (unsigned char *)malloc(new_x * new_y * channels);
    if (data == NULL) {
      log_warn("加载图片失败！");
      continue;
    }

    // 改变图片尺寸
    stbir_resize(img, x, y, 0, data, new_x, new_y, 0, STBIR_TYPE_UINT8, channels, STBIR_ALPHA_CHANNEL_NONE, 0,
                 STBIR_EDGE_CLAMP, STBIR_EDGE_CLAMP, STBIR_FILTER_BOX, STBIR_FILTER_BOX, STBIR_COLORSPACE_SRGB, NULL);

    // 拼接新图片名
    char *new_filename = malloc(sizeof(char) * strlen(filename) + strlen(argv[0]));
    strncpy(new_filename, filename, strlen(filename) - strlen(extn));
    strcat(new_filename, argv[0]);
    strcat(new_filename, extn);

    // 写入
    stbi_write_jpg(new_filename, new_x, new_y, channels, data, 0);

    // 收尾
    log_info("[%s] -> [%s]", filename, new_filename);

    stbi_image_free(img);
    stbi_image_free(data);
  }
}

void cmd_chcolor(int argc, char **argv) {
  //
}

void cmd_join(int argc, char **argv) {
  int x, y, channels;
  unsigned char *img = stbi_load(argv[0], &x, &y, &channels, 0);
  for (int i = 0; i < x * y * channels; i++) {
    img[i] = 0;
  }
  
}

void cmd_compress(int argc, char **argv) {
  //
}
