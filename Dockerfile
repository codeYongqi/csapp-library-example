FROM ubuntu:18.04

#-yqq 防止弹出xxx y/n? 中断操作 会自动选择yes
RUN apt-get -yqq update
RUN apt-get -yqq install gcc 

WORKDIR /opt/csapp

COPY . .

