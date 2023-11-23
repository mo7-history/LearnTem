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

1. 配置密钥

```git
ssh-keygen -t rsa -c 'xxx@xxx.com'
找到生成的密钥
cd ~/.ssh/
将密钥复制在GitHub的SSHkey设置里面
用ssh命令检查是否配置成功
ssh git@github.com
```

## git常用命令

git clone 'ssh地址' #拷贝一个远程仓库，也就是下载一个项目

git add .    #添加文件到暂存区

git commit -m "改动说明"  # 提交暂存区到本地仓库

git push    #上传远程代码并合并

1. 常用与修改、

- git add ：添加文件到暂存区
- git status：查看仓库当前的状态，显示有变更的文件。
- git diff：比较文件的不同，即暂存区和工作区的差异。
- git commit：提交暂存区到本地仓库。
- git reset：回退版本。
- git rm：将文件从暂存区和工作区中删除。
- git mv：移动或重命名工作区文件。
- git checkout：分支切换。
- git switch （Git 2.23 版本引入）：更清晰地切换分支。
- git restore （Git 2.23 版本引入）：恢复或撤销文件的更改。

2. 提交日志

- git log：查看历史提交记录
- git blame "文件名"：以列表形式查看指定文件的历史修改记录

3. 远程操作

- git remote：远程仓库操作
- git fetch：从远程获取代码库
- git pull：下载远程代码并合并
- git push：上传远程代码并合并
