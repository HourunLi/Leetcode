import os

dir = "E:/CodeLearning/Leetcode/SourceCode/"
file_names = os.listdir(dir)

for name in file_names:
    name_list = name.split(".")
    if(name_list[-1] == "cpp"):
        name_list[0] = "0"*(4-len(name_list[0])) + name_list[0]
        new_name = "_".join(name_list[0:-1]) + "." + name_list[-1]
        os.rename(dir+name, dir+new_name)
