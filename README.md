提供`README.md`，说明编译步骤（如 “mkdir build && cd build && cmake .. && make”）和运行方法：

```
那我就从整个项目的流程讲起吧：
分模块：1.完成用C语言读取input.txt的内容，并生出result.txt
       2.首先python里面安置好matplotlib
       3.用open()打开文件并识别内容，输出图表
       4.（整个项目卡时最长的）在vscode里面先配置好C++的编译环境，需安装C/C++，C/C++Compile Run,Better C++ Synax这三个主要扩展（从根源解决问题）
       5.在第四步之前去官网下载MinGW,而且要将bin的路径新建到环境变量的Path(不是用户那个)；
       6.在桌面里创建demo文件夹，在vscode里打开该文件夹，在该文件夹里面创建一个新文件，名为CMakeLists.txt，然后vscode就会自动弹出“配置”，这时选择vs2022的默认版本，按键盘的F7就会自动生成一个build的根目录。在创建CMakeLists.txt之前，需要把之前完成第一步的代码，放在一个main.c的文件中，这样一来就生成可执行程序exe。
       7.生成的exe在终端会显示被放在哪里，我的exe放在build里面的Debug里面，当要使用的时候，在终端先cd build,再 cd Debug 表示进入想进的根目录，再.\file_stat.exe就能执行程序了，cd..表示退出当前目录。
       8.在vscode的demo里新建plot.py，把之前第二步的代码复制过来，注意的是编码，python识别的是UTF-8，C/C++识别中文就要改为GBK。
       9.至此，该完成的步骤就基本搞定了。
```

