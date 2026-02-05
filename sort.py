import os
import shutil

for i in range(1, 10):
    d = f'{i}000-{i}999'
    if not os.path.exists(d):
        os.makedirs(d)

for filename in os.listdir('.'):
    if not os.path.isfile(filename) or not filename.endswith('.cpp'):
        continue
    if not filename[0].isdigit():
        continue

    subdir = f'{filename[0]}000-{filename[0]}999'
    dst = os.path.join(subdir, filename)

    if os.path.exists(dst):
        os.remove(filename)   # 删除 ./ 下未整理文件
    else:
        shutil.move(filename, dst)
