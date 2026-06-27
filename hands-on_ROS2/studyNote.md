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

