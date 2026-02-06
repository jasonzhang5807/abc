import os
import shutil

for filename in os.listdir('.'):
    if not os.path.isfile(filename) or not filename.endswith('.cpp'):
        continue
    if not filename[0].isdigit():
        continue

    subdir = 'files'
    dst = os.path.join(subdir, filename)

    if os.path.exists(dst):
        os.remove(filename)   # 删除 ./ 下未整理文件
    else:
        shutil.move(filename, dst)