# git学习笔记

## 安装及配置

1. 在linux终端中输入`sudo apt-get install git`.
2. 使用`git --version`来检查安装是否完成
3. 配置相关信息
```git
git config --global user.name xxx  #配置你的用户名
git config --global user.email xxx@xx.com  #配置你的邮箱地址
git config --list  #查询配置是否成功
```
4. 配置密钥
```
ssh-keygen -t rsa -c 'xxx@xxx.com'
找到生成的密钥
cd ~/.ssh/
将密钥复制在GitHub的SSHkey设置里面
用ssh命令检查是否配置成功
ssh git@github.com
```

## git命令

git clone 'ssh地址'

git add .

git commit -m "改动说明"

git push