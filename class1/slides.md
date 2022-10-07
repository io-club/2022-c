---
# try also 'default' to start simple
theme: seriph
# random image from a curated Unsplash collection by Anthony
# like them? see https://unsplash.com/collections/94734566/slidev
background: https://source.unsplash.com/collection/94734566/1920x1080
# apply any windi css classes to the current slide
class: 'text-center'
# https://sli.dev/custom/highlighters.html
highlighter: shiki
# show line numbers in code blocks
lineNumbers: false
# some information about the slides, markdown enabled
info: |
  ## Slidev Starter Template
  Presentation slides for developers.

  Learn more at [Sli.dev](https://sli.dev)
# persist drawings in exports and build
drawings:
  persist: false
# use UnoCSS
css: unocss

fonts:
  # basically the text
  sans: 'Noto Serif Simplified Chinese'
  # use with `font-serif` css class from windicss
  serif: 'Robot Slab'
  # for code blocks, inline code, etc.
  mono: 'Fira Code'

colorSchema: 'light'
monaco: true
download: true
favicon: ./favicon.ico
remoteAssets: false

---

# C 语言光速入门


<div class="pt-12">
  <span @click="$slidev.nav.next" class="px-2 py-1 rounded cursor-pointer" hover="bg-white bg-opacity-10">
    next page <carbon:arrow-right class="inline"/>
  </span>
</div>

<div class="abs-tr m-6 flex gap-2">
  <button @click="$slidev.nav.openInEditor()" title="Open in Editor" class="text-xl icon-btn opacity-50 !border-none !hover:text-white">
    <carbon:edit />
  </button>
  <a href="https://github.com/slidevjs/slidev" target="_blank" alt="GitHub"
    class="text-xl icon-btn opacity-50 !border-none !hover:text-white">
    <carbon-logo-github />
  </a>
</div>


<style>
h1 {
  background-color: #4EC5D4;
  background-size: 100%;
  -webkit-background-clip: text;
  -moz-background-clip: text;
  -webkit-text-fill-color: transparent;
  -moz-text-fill-color: transparent;
}
</style>

<!--
The last comment block of each slide will be treated as slide notes. It will be visible and editable in Presenter Mode along with the slide. [Read more in the docs](https://sli.dev/guide/syntax.html#notes)
-->

---
layout: image-right
image: https://source.unsplash.com/collection/94734566/1920x1080
---
# 课程介绍

C 语言入门 +

- qq：2820047809 (Trdthg)

|     |     |
| --- | --- |
| 😆 For | IO Club 成员 |
| 🦊 Presenter | 软件 20 阎明铸 |
| 🐧 QQ | 2820047809 |
| 👾 Github | trdthg |

<div class="abs-bl m-12 flex gap-2">
  <button @click="$slidev.nav.openInEditor()" title="Open in Editor" class="text-xl icon-btn opacity-50 !border-none !hover:text-white">
    <carbon:edit />
  </button>
  <a href="https://github.com/slidevjs/slidev" target="_blank" alt="GitHub"
    class="text-xl icon-btn opacity-50 !border-none !hover:text-white">
    <carbon-logo-github />
  </a>
</div>

<style>
h1 {
  background-color: #2B90B6;
  background-image: linear-gradient(45deg, #4EC5D4 10%, #146b8c 20%);
  background-size: 100%;
  -webkit-background-clip: text;
  -moz-background-clip: text;
  -webkit-text-fill-color: transparent;
  -moz-text-fill-color: transparent;
}
</style>

<!-- 这门课的目的是让搭建快速掌握 C 语言的基本语法，不会讲述 C 的所有细节，例如各个运算符的优先级 (++, *, [])， -->

---
layout: image-right
image: ./images/class1/c_video.jpg
---
# 资源

<small>C 语言学习资料推荐 /</small>

- **视频**：[翁恺 C 语言](https://www.bilibili.com/video/BV19W411B7w1)
- **文档**：

  [阮一峰 C 语言入门教程](https://www.ruanyifeng.com/blog/2021/09/c-language-tutorial.html)

  [C++ 风格指南](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents/)

  各类培训机构的课程文档

- **书籍**：[https://github.com/search?q=书籍](https://github.com/search?q=书籍)

- **算法**：

  - [力扣](https://leetcode.cn/)、[洛谷](https://www.luogu.com.cn/)
  - [OI-Wiki](https://oi-wiki.org/)、[代码随想录](https://www.programmercarl.com/)、[杭电 OJ](http://acm.hdu.edu.cn/listproblem.php?vol=1)、[浙大 OJ](https://pintia.cn/problem-sets/994805342720868352/problems/type/7)

---
layout: image-right
image: https://source.unsplash.com/collection/94734566/1920x1080
---
# 课程内容

- 📽 **C 语言简介** - 应用

- 🧑‍💻 **开发环境** - IDE / 插件

- 📝 **C 语言基本语法** - 数据类型 / 流程控制

- 🤹 **项目实战**

```c
#include <stdio.h>

int main() {
  printf("Hello World！");
  return 0;
}
```

---
layout: image-right
image: images/class1/c_logo1.jpg
---
# C 语言简介

1. 操作系统一般都是由 C 语言编写

    - C 语言可以直接使用操作系统提供的功能

2. C 语言是嵌入式系统的首选编程语言

3. C 语言几乎成为事实标准

4. ###### 高性能 / 可移植 / 手动管理内存...

---
layout: image-right
image: class1/images/hello.jpg
---
# 开发环境搭建

运行 C 语言编写的程序需要的工具

#### 1. 需要什么？

- 任意文本编辑器

- gcc 等编译器

- CMD 等命令行

#### 2. 如何使用？

- 编写代码

- 把 原始的文本文件 编译成 可执行文件

- 运行

> 使用 nano + 命令行 演示

---
---
# 区别

<div grid="~ cols-2 gap-2" m="-t-2">
<div>

#### 2. 疑问

- 什么是 Dev C++？

  ![](https://www.bloodshed.net/data/_uploaded/image/blddevcpp.png)
- 什么是 VS？

  ![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/59/Visual_Studio_Icon_2019.svg/182px-Visual_Studio_Icon_2019.svg.png)

    <span><img src="https://www.win10zjb.com/d/file/rjxz/xtgool/20201027/29b6451d5e7aedb30973686ac8c27140.jpg"/></span>

</div>
<div>

- 它们有什么区别？

- 我应该如何选择？

- gcc 和它们有什么关系？

</div>
</div>

<style>
img {
  height: 50px
}
</style>

---
---
# 编译器

C / Cpp 编译器 & 工具链.[^1]

| 支持平台| 编译器| 工具链  |  Logo  | 安装|
|--|---|----|---|---|
|Linux|**gcc** |GNU| ![](https://www.gnu.org/graphics/heckert_gnu.transp.small.png)|  `apt install gcc` |
|Windows|**gcc** | MinGW[^2] |![](https://www.mingw-w64.org/header.svg)|  `直接下载解压` or _Dev C++_ |
|Windows|**CL** |MSVC| <div> <span> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/59/Visual_Studio_Icon_2019.svg/182px-Visual_Studio_Icon_2019.svg.png"/></span></div> |  下载 VS |
| All |**clang** |Clang & LLVM |![](https://llvm.org/img/LLVMWyvernSmall.png)|  `apt install clang` 使用 VS 安装|

[^1]: 工具链是什么？包含 Binutils、GCC、Glibc

[^2]: Minimalist GNU for Windows

<style>
img {
  height: 40px
}
.footnotes-sep {
  @apply opacity-10;
}
.footnotes {
  @apply text-sm opacity-75;
}
.footnote-backref {
  display: none;
}
</style>

---
---

# 回答


<div grid="~ cols-2 gap-2" m="-t-2">
<div>


1. 什么是 Dev C++？什么是 VS？

    ![](https://upload.wikimedia.org/wikipedia/commons/thumb/5/59/Visual_Studio_Icon_2019.svg/182px-Visual_Studio_Icon_2019.svg.png)

    代码编辑器 + 编译器 + （代码高亮 + 调试 + 一键编译运行等）

3. 它们有什么区别？

    使用的编译器不同，MinGW (gcc)，MSVC (cl)

4. gcc 和它们有什么关系？


</div>
<div>

- 什么是 IDE？

- 什么是 vscode？

  ![](https://code.visualstudio.com/assets/images/code-stable.png)

    - 代码编辑器

    - (代码高亮 + 基本的代码补全等)

</div>
</div>

<style>
img {
  height: 50px
}
</style>

---
---
# 推荐

- cph

- c/c++

---
---

# 目录

<div grid="~ cols-2 gap-2" m="-t-2">
<div>

# C 语言语法

- 数据类型

- 控制流

- 函数

- 数组

- 结构体 & 指针

- 文件 & IO & 标准库

- malloc 内存布局

</div>

<div>

# 通识

- 环境变量

- 编译（器）

- 包管理器 | 第三方库

- IDE / 常用插件

- 格式化 / 补全 / 高亮

- Git / Github

- Markdown / Editor


</div>
</div>


---
layout: cover
---
# 数据类型

<div class="pt-12">
  <span class="border-1 rounded-lg p-4 bg-stone-200 text-black">
    整数类型
  </span>
  <span class="px-6"></span>
  <span class="border-1 rounded-lg p-4 bg-stone-200 text-black">
    浮动数（小数）
  </span>
  <span class="px-6"></span>
  <span class="border-1 rounded-lg p-4 bg-stone-200 text-black">
    字符型
  </span>
</div>

---
---
# 其他语言的类型定义


<div grid="~ cols-2 gap-2" m="-t-2">
<div>

Rust

```rs
fn main() {
    let a: i8 = 127; // (-128, 127) 0111 1111
    let a: i16 = 0;  // 0000 0000 0000 0000
    let a: i32 = 0;  // 0000 0000 0000 0000 0000 0000 0000 0000
    let a: i64 = 0;
    let a: i128 = -111111111111111111111111111111111111111;

    let a: u8 = 255; // (0   , 255) 0000 0000
    let a: u16 = 65535;
    let a: u32 = 0;
    let a: u64 = 0;
    let a: u128 = 311111111111111111111111111111111111111;

    let c: char = 'A';
}
```

</div>
<div>

Go

```go
package main

func main() {
	var a8 int8 = 8
	var a16 int16 = 8
	var a32 int32 = 8
	var a64 int64 = 8

	var u8 uint8 = 0
	var u16 uint16 = 0
	var u32 uint32 = 0
	var u64 uint64 = 0

  // byte 和 uint8
  var c2 uint8 = 'a'
  var c1 byte = 'a'  // byte 是 uint8 的别名，和 uint8 效果相同

	print(a8, a16, a32, a64, u8, u16, u32, u64)
}
```

</div>
</div>


---
---
# 数据类型

C 语言基本数据类型


<div grid="~ cols-2 gap-2" m="-t-2">
<div>

整数类型
```c
char a1 = 127;    // 8   0000 0000 -128 - 127
short a2 = 1;     // 16
int a3 = 0;       // 32
long a4 = 0;      // 64
long long a5 = 0; // 128 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000  0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000

unsigned char b1 = 255;    // 8
unsigned short b2 = 1;     // 16
unsigned int b3 = 0;       // 32
unsigned long b4 = 0;      // 64
unsigned long long b5 = 0; // 128
```
</div>

<div>

浮点类型
```c
float c1 = 1.0;       // 32
double c2 = 1.0;      // 64
long double c3 = 1.0; // 128
```

<div mt-16></div>

字符型

```c
char c1 = 'a';
char c2 = '\0';
```

[ASCII 码对照表](http://c.biancheng.net/c/ascii/)

[转义字符](https://baike.baidu.com/item/转义字符#3)

</div>
</div>

---
layout: cover
---
# 流程控制

<div class="pt-12">
  <span class="border-1 rounded-lg p-4 bg-stone-200 text-black">
    判断 (if, switch)
  </span>
  <span class="px-6"></span>
  <span class="border-1 rounded-lg p-4 bg-stone-200 text-black">
循环 (for, while)
  </span>
</div>

---
---
# if


<div grid="~ cols-2 gap-2" m="-t-2">
<div>

格式

```c
if (xxx) {
  ...
} else if (xxx) {
  ...
} else {
  ...
}
```

当语句只有一条时，可以省略大括号
```c
if (i == 0)
  printf("只有一条语句\n");
else if (i == 1)
  printf("也只有一条语句\n");
else
  printf("还只有一条语句\n");
```

</div>
<div>

作用域

```c
#include <stdio.h>
int main() { // scope 0
  int i = 0;

  { // scope 1
    int a = 0;
    printf("%d", i);
  }

  printf("%d", a);

  { // scope 2
    int b = 0;
    printf("%d", i);
  }

  return 0;
}
```

</div>
</div>

---
---
# switch

<div grid="~ cols-2 gap-2" m="-t-2">
<div>
格式

```c
switch (i)
{
    case 1:
        statement1;
        statement2;
        break;
    case 2:
        statement;
        break;
    ...
    default:
        statement;
}
```

</div>
<div>
小练习：FSM（有限状态机）


```c
#include <stdio.h>
int main() {

  return 0;
}
```

</div>
</div>


---
---
# 循环


<div grid="~ cols-2 gap-2" m="-t-2">
<div>

for

```c
for ( 初始化 ; 终止条件 ; 变量更新 ) {
  ...
}

for (;;) {
  // 无限循环
}
```

while

```c
while (终止条件) {
  ...
}
```

</div>
<div>


Break 和 Continue

```c
#include<stdio.h>
int main() {
  for(int i = 0; i < 5; i++) {
    if (i == 3) {
      continue; //
      break;    //
    }
    printf("%d\n", i); // 0 1 2
  }
}
```

</div>
</div>

---
---
# 函数


<div grid="~ cols-2 gap-2" m="-t-2">
<div>

1. 什么是函数？

  ![](http://s3.amazonaws.com/lyah/fx.png)

  - 函数就好像有输入和输出的机器。

  ![](https://www.shuxuele.com/sets/images/function-cogs.gif)

2. 函数的格式

```c
int add(int a, int b) {
  return a + b;
}
```

</div>
<div>

练习：分段函数 `y = |x|`

```c
#include <stdio.h>

int main() {

  return 0;
}
```

</div>
</div>

<style>
img {
  height: 50px
}
</style>

---
---
# void 是什么类型 ?

### void 在不同地方有不同的含义

1. 用作函数返回值
  ```c
  void printSomeSentence()
  {
      printf("====================\n");
      printf("Company **************\n");
      printf("Fax ****************** \n");
      printf("Email ****************** \n");
      printf("====================\n");
  }
  ```

2. 用作函数参数
  ```c
  void printSomeSentence(void)
  {
      printf("====================\n");
      printf("Company **************\n");
      printf("Fax ****************** \n");
      printf("Email ****************** \n");
      printf("====================\n");
  }
  ```

3. 用作变量类型 (x)

---
---
# main 函数的参数

```c
#include<stdio.h>
int main(int argc, char* argv[]) {
  // argc: 参数数量
  // argv: 参数数组

  return 0;
}
```

[初中生也能看懂的 C/C++类型声明规则教学，很简单的！](https://www.bilibili.com/video/BV1mB4y1L7HB)

---
layout: image-right
image: https://source.unsplash.com/collection/94734566/1920x1080
---

# 数组
固定长度，编译时就知道大小

一维数组
```c
int a[6];

char b[6];

double c[6];
```

使用下标（索引）访问

```c
#include <stdio.h>
int main() {
  char chars[5] = {'a', 'b', 'c', 'd', 'e'};
  //                0    1    2    3    4

  char chars_first = chars[0];
  char chars_last = chars[4];

  for (int i = 0; i < 5; i++) {
    printf("%c\n", chars[i]);
  }
}
```

---
layout: image-left
image: https://source.unsplash.com/collection/94734566/1920x1080
---
# 字符串

字符串

```c
char chars[10] = {'a', 'b', 'c', 'd', 'e', '\0'};
printf("%s", chars);  // abcde
```

字符串以 `\0` 结尾

```c
char chars[10] = {'a', 'b', 'c', 'd', 'e', '\0', 'a', 'b'};
printf("%s", chars);  // abcde
```

字符串的简化写法

```c
char chars[] = {"abcde"};
char chars[] = "abcde";
```
---
layout: image-left
image: https://source.unsplash.com/collection/94734566/1920x1080
---
# C 标准库 string.h [文档](https://www.runoob.com/cprogramming/c-standard-library-string-h.html)
1. 获取字符串长度
```c
#include <string.h>
char str[] = "abcde";
int len = strlen(str);
```

2. 字符串复制
```c
char str1[] = "abcde";
char str2[10];
strcpy(str2 , str1);
```

3. 比较两个字符串是否相等
```c
char str1[] = "aaa";
char str2[] = "bbb";

int res = strcmp(str1, str2);

if (res == 0)
  printf("str1 等于 str2\n");
else
  printf("str1 和 str2 不相等\n");
```

---
---
# 二维数组

```c
#include <stdio.h>
int main(int argc, char *argv[]) {
  int arr[10][10] = {};
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
```

---
---
# main 函数的参数

```c
#include<stdio.h>
int main(int argc, char* argv[]) {

  return 0;
}
```

---
---
# `#define`

<div grid="~ cols-2 gap-2" m="-t-2">
<div>


```c
#define LIGHT 1
#define DARK 1

enum Week {
  Monday = 0,
  Tuesday = 1,
  Wednesday = 2,
};

int main(int argc, char const *argv[]) {
  printf("%d\n", LIGHT);
  return 0;
}
```

</div>
<div>

1.预处理 (Preprocessing)

  - 预处理用于将所有的#include 头文件以及宏定义替换成其真正的内容

2.编译 (Compilation)

  - 将经过预处理之后的程序转换成特定汇编代码

3.汇编 (Assemble)

  - 汇编过程将上一步的汇编代码转换成机器码

4.链接 (Linking)

  - 链接过程将多个目标文以及所需的库文件 (.so / .dll) 链接成最终的可执行文件。

</div>
</div>

---
---
# templete


<div grid="~ cols-2 gap-2" m="-t-2">
<div>



</div>
<div>



</div>
</div>
