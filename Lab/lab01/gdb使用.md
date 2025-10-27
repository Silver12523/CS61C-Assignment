###### gdb使用

为了方便，不开虚拟机直接用powershell，今天发现powershell是没有vim指令的。（顺嘴一提，防止忘记）

cd到指定目录之后，通过

```
gcc -g -o hello hello.c
```

编译程序。注意：没有-g就无法使用gdb。-o hello这两个参数是连在一起的，将最终的可执行文件命名为hello。

```
gdb hello
```

将hello文件加载到gdb调试器中

```
(gdb)break 6 //在第六行设置断点
(gdb)b 6 //同上
(gdb)b main //在main函数开始处设置断点
(gdb)run //简写r
(gdb)continue
(gdb)clear //清除所有断点，断点不会自己消失
(gdb)kill
```

接下来可以通过不同方式排查问题，比如查看变量的值

```
print count //打印count变量
```

详细查看gdb5_reference_paper.pdf



###### 重定向

```
run < name.txt
```

程序需要输入参数的时候，用‘<’符号将其重定向到name.txt，相当于这个txt里的内容就是输入
