create database helloworld
on primary(
name='helloworld', --名称
filename='F:\sqlserver 111\hellowrold.mdf', --数据库保存路径
size=10mb,  --初始大小
filegrowth=10mb  --增长速度
)
log on  --日志
(
name='helloworld_log',
filename='F:\sqlserver 111\helloworld_log.mdf',
size=5mb,  --初始大小
filegrowth=10%  --增长速度
)
