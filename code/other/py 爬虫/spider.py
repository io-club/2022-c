#! /bin/sh

import os
import json

f = open("./music.txt", mode="r")
lines = f.readlines()
for line in lines:
    name = line
    cmd = f'''
      curl 'https://www.eggvod.cn/music/' \
        -H 'Accept: application/json, text/javascript, */*; q=0.01' \
        -H 'Accept-Language: zh-CN,zh;q=0.9,en;q=0.8,ru;q=0.7,be;q=0.6' \
        -H 'Cache-Control: no-cache' \
        -H 'Connection: keep-alive' \
        -H 'Content-Type: application/x-www-form-urlencoded; charset=UTF-8' \
        -H 'Origin: https://www.eggvod.cn' \
        -H 'Pragma: no-cache' \
        -H 'Referer: https://www.eggvod.cn/music/?name={name}&type=netease' \
        -H 'Sec-Fetch-Dest: empty' \
        -H 'Sec-Fetch-Mode: cors' \
        -H 'Sec-Fetch-Site: same-origin' \
        -H 'User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/105.0.0.0 Safari/537.36' \
        -H 'X-Requested-With: XMLHttpRequest' \
        -H 'sec-ch-ua: "Google Chrome";v="105", "Not)A;Brand";v="8", "Chromium";v="105"' \
        -H 'sec-ch-ua-mobile: ?0' \
        -H 'sec-ch-ua-platform: "Linux"' \
        --data-raw 'input={name}&filter=name&type=netease&page=1' \
        --compressed
    '''
    f = os.popen(cmd, "r")
    l = f.read()
    j = json.loads(l)
    for row in j["data"]:
        name = row["title"]
        mp3_url = row["url"]
        filename = f"{name}.mp3"
        os.system(f"wget {mp3_url} -O '{filename}'")
        break
    # break
