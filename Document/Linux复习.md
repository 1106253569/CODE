1. 操作系统的功能

- 存储管理进程和处理机管理文件管理设备管理用户接口

2. IDE硬盘的设备名第一个主盘为hda[]()从盘为hdb
3. 主分区最多是4个，逻辑分区不限
4. 一共有6个虚拟控制台切换的方法

   - CTRL+ALT+F1-F6
5. 用户shell提示符

   1. 管理者用户 #
   2. 普通用户 $
6. 登陆和退出的方法

   - 登陆：1. 默认图形方法 2. 切换用户su+用户名
   - 退出：logout exit ctrl+d
7. 目录

- /bin

  - 普通用户所使用的命令文件（二进制文件）
- /sbin

  - 管理者用户使用的命令文件（二进制文件）
  - /usr/sbin系统管理员常用的二进制命令文件
- /dev

  - 设备文件存储目录
- /home

  - 普通用户的主目录
- /root

  - 管理者用户的主目录

8. 常用命令

   1. cp - 所要复制的文档复制的目的地
   2. mv - 所要移动的文档移动的目的地原目录移动为重命名
   3. rm- 可删除所有文件
   4. rmdir- 删除目录用的空目录
   5. echo-输出 echo“”引号内可引用参数 echo‘’引号内任何字符作为字符串
   6. clear-清屏
   7. su-切换用户
   8. pwd显示当前工作目录
   9. passwd-更改用户密码passwd+用户名
   10. cat-显示文件内容cat+文件名
   11. more-显示文件内容是从开头进行显示继续显示按回车或者空格回车是一行一行的显示空格是一屏一屏的
   12. head和tail 是显示文件的开头或者结尾
   13. 新建一个文件的方法
       1. touch+文件名空文件
       2. vi+文件名新建一个空文件进入文件进行编辑
   14. grep-查找字符串 find 查找文件名
9. 文件的分类

   1. 普通文件
      1. 文本文件
      2. 二进制文件
   2. 目录文件
   3. 设备文件
   4. 符号链接文件
10. 文件路径

    1. 绝对路径 /root/list
    2. 相对路径 ./list
11. 改变目录

    1. cd / -从当前目录到根目录
    2. cd ..-从当前目录到上层目录
    3. ./square-执行当前目录下的文件
    4. /-根目录
    5. ../-上层目录
    6. ./-当前目录
12. 目录

    - 新建目录

      - mkdir
    - 删除目录

      - rmdir
      - rm –rf
13. ls 显示当前目录下内容

- 显示所有内容（包括隐藏文件）

  - ls–a
- 显示所有文件的详细信息

  - ls–l

14. 硬链接和符号链接（软连接）的区别

- 硬链接
  - 新建一个文件的节点，一处更改另一处同时更改，一处删除另一处不受影响，同时删除所有节点才可以将文件删除
- 软链接
  - 相当于windows中的快捷方式，删除软链接源文件不受影响，删除源文件软链接不可用

15. chmod的用法

- Chmod  u（所有者）+r（可读） file

  - g（同组用户）+w（可写）
  - o（其他用户）+x（可执行）
  - a（所有用户）
- chmod 4+2+1 file

  - 4 可读
  - 2 可写
  - 1 可执行
- Chmod 753 file

  - 给file文件的所有者用户增加可读可写可执行权限
  - 给同组用户增加可读可执行权限
  - 给其他用户增加可写可执行权限。

16. 用户和用户组的管理

- 新增一个用户
  - useradd
  - adduser
- 删除一个用户
  - userdel
- 新增一个用户组
  - groupadd
- 删除一个用户组
  - groupdel

17. 联机帮助命令

    1. man-即可以帮助查询linux内置命令，也可以查询linux外部命令
    2. help-只能查询shell内置命令
    3. --help-只能查询linux外部命令
18. 进程

    1. 查看一个进程 ps
    2. 查看所有的分进程 ps –aux
    3. 强制杀死一个进程的指令 kill -9（进程号）
19. 文本编辑器的三种模式

- 命令模式

  - 开始进入vi编辑器的时候就是命令模式
  - 在命令模式下输入：

    - h-左移一个字符
    - l-右移一个字符
    - j-上移一行
    - k-下移一行
    - 光标移至
      - 行首0
      - 行尾$
- 插入模式

  - 进入-在命令模式下按键盘的a或者I
  - 退出-插入模式按esc 进入命令模式
- 底行模式

  - 底行模式下的指令

    - :w-保存的指令
    - :q-退出
    - :wq-保存退出
    - :q!-不保存退出

20. 查看用户使用了多少磁盘空间，我们可以使用：df –t。
21. shell脚本中变量  $\$x$（前面加符号）传入参数的使用 $1 $2…..
22. kill向指定的进程发出特定的信号，信号强制杀死进程。
23. 通常Linux的安装至少需要两个分区，分别是：

    1. 根分区
    2. 交换分区。
24. Linux系统进程类型

    1. 交互进程
    2. 批处理进程
    3. 守护进程。
25. 解压

    - 为了将当前目录下的归档文件myftp.tgz解压缩到当前目录下，我们可以使用：

      - tar -xzvf myftp.tgz
    - 将/home/stud1/wang目录做归档压缩，并将压缩后的文件(test.tar.gz)保存到/home目录下，实现此任务的命令为：

      - tar -czvf /home/test.tar.gz  /home/stud1/wang。
26. 在Linux系统中，用来存放系统所需要的配置文件和子目录的目录是/dev。
27. 在超级用户下显示Linux系统中正在运行的全部进程，应使用的命令及参数是px  -e （ 或px  -A）。
28. 在shell编程时，使用方括号表示测试条件的规则是：方括号两边必须有空格。
29. root文件系统一旦安装完毕，内核将启动名为init的程序，这也是引导过程完成后，内核运行的第一个程序。
30. 在linux下，我们通常使用gcc工具进行C源程序的编译，使用gdb工具进行代码调试。
31. 在缺省情况下，使用ls -color命令显示当前目录下的所有文件时，对于可执行文件一般显示为绿颜色。
32. 当程序正从键盘上读取标准输入时，如果希望终止输入，告诉系统已经输完了全部内容，可以键入Ctrl+Z。
33. 我们可以修改默认的启动级别为5，使得系统重启后自动采用X  Window方式登录。
34. 设计一个Shell程序，在/userdata目录下建立30个目录，即user1～user30，并设置每个目录的权限，其中其他用户的权限为：读；文件所有者的权限为：读、写、执行；文件所有者所在组的权限为：读、执行。

- 参考答案 (用for循环)：
- ```
  #!/bin/bash
  if
  	[ ! -d /userdata ]
  then
  	mkdir /userdata
  fi
  cd /userdata
  for((i=1;i<=30;i++))
  do
  	mkdir user$i
  	chmod 754 user$i
  done
  ```

35. 已知一C程序包含了三个C文件：头文件：max.h（存放函数声明），源文件：max.c（存放函数定义）和main.c（进行函数调用），这三个文件不需要编写，请写出在linux下使用gcc编译及运行此C程序的两种方法。

- 参考答案：
  - 编译及连接：   gcc  -o main(可执行文件名字自取)  main.c -max.c
  - 运行可执行文件： ./main

其它可以参考课上PPT和平时作业
