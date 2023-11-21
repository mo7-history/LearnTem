# 问题合集

## fetch first

1. 报错信息

```
! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'https://github.com/mo7Code/LearnTem/'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

2. 发生原因：

本地仓库与远程仓库的内容不一致所导致，团队成员修改了远程仓库，自己本地仓库没有同步拉取过来，以至于在git push提交时，会检测到之前从远程仓库的拉取的和现在的不一样，进而报错。

3. 解决方案

将远程仓库修改的内容更新到本地仓库：`git pull --rebase origin master`

再次进行提交`git push origin master`

若远程仓库上已经更新的地方与当前提交的修改的地方一致，那么此时本地仓库上的修改可能会被覆盖。这样可以使用`git fetch origin master`(不会自动合并)，然后查看更新情况再进行有选择的合并。或者将本地仓库修改过的内容备份，`git pull origin master`后在重新修改
