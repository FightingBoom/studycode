2026/04/19 23:04，开始阅读

《ROS2机器人开发：从入门到实践》

http://github.fishros.org/，该网站已经进不去了。

![image-20260421084611703](https://cdn.jsdelivr.net/gh/FightingBoom/AllPicture@master/img/202604210846844.png)



https://fishros.org.cn/forum/，这个论坛还可以进去。



# 第1章 启程——让你的第一个机器人动起来

ROS，robot Operating System，机器人操作系统



## 1.1 ROS 部落的自我介绍

生态。

### 1.1.1 机器人与 ROS

ROS 在机器人中的作用就是将传感器的数据发送给决策系统，然后将决策系统的输出发送给执行器执行。



### 1.1.2 ROS 2 系统架构

分为 5 层：操作系统层、DDS 实现层、DDS 接口层、ROS2客户端层和应用层。

数据分发服务，Data Distribution Service，DDS；基于实时发布订阅协议，Real-time Publish-Subscribe，RTPS

RMW，ROS Middleware Interface，ROS 中间件接口

ROS2 客户端库，ROS 2 Client Library，RCL



### 1.1.3 ROS2的已发布版本

![image-20260424091531342](https://cdn.jsdelivr.net/gh/FightingBoom/AllPicture@master/img/202604240915460.png)



### 1.1.4 ROS2 机器人开发特色

1. 四大核心通信机制
    1. 话题通信，topic
    2. 服务通信，service
    3. 参数通信，parameter
    4. 动作通信，action
2. 丰富的调试工具
3. 建模与运动学工具
4. 强大的开源社区及应用框架



## 1.2 开发环境搭建

需要安装 Linux ，macOS 应该也能用



## 1.3 运行你的第一个机器人

海龟模拟器，我的 macOS 装不了好像，，难搞。

戴尔不知道还能不能跑起来，里边数据好久没用了，还没整备备份下，之前想着备份完，直接装 ubuntu 呢。



## 1.4 ROS 2 基础之 Linux

Linux 的基础知识。



## 1.5 小结与点评

本章基本都是环境的安装啥的。



# 第2章 ROS2 基础入门 —— 从第一个节点开始

节点除了可以订阅和发布话题外，还可以使用服务、配置参数和执行动作等。



ros2 pkg create 创建功能包的命令


